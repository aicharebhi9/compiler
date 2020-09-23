
%{
#include<stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "ts.h"
int yyerror(char*);
int yylex();
extern FILE* yyin; 
ts_t *ts = NULL;
int line=1;
int column=1;
int current_indent=0;
int indq=0;
int erreur = 0;
char idf_t[20];
char* inttostr(int i) {char* ss=malloc(100*sizeof(char)); sprintf(ss,"%d",i); return ss;}
char* floattostr(float i) {char* ss=malloc(100*sizeof(char)); sprintf(ss,"%f",i); return ss;}


typedef struct Quadruplet Quadruplet;

struct Quadruplet {
         char* opr;
         char* op1;
         char* op2;
         char* res;
       };
         
typedef struct QuadList QuadList;

 struct QuadList
  {
    Quadruplet val;
    QuadList *svt;
  };

 
  typedef struct QuadPile QuadPile;

struct QuadPile
  {
    int val;
    QuadPile *svt;
  };

  
  
int IsCompatible(char* i , char* d){
    if(strcmp(i,d) == 0 ){
        return 1;
    }else{
        return 0;
    }
}
void quadAppend();

QuadList* getQuadByOpr(char* opr);
QuadList* getQuadByRes(char* res);
void insertQuad (char o[],char o1[],char o2[],char r[]);
void afficherQuad();


void empiler (int val);
int depiler ();QuadPile *quadruplet_pile = NULL;

int isIdf(char* opr);
void MAJQuad (int indice , char* operand);
char** getAllIDFs();
QuadList *quadruplet_list = NULL;

void codeMachine ();
extern int yyleng;
extern char* yytext;



int nTemp = 1, quad_list_size = 0 ;
char tempC[12] = "";
int nTempTCond = 1;
char tempTCond[12] = "";

 char* BR = "";
 
%}
%error-verbose
%union
{
    int entier;
    float reel;
    char* nom ;
    struct 
    {
      char* nom ;
      char* type;
    }NT;
}
%token   IF elseif eLse WHILE  aff idf INTEGER NUMERIC CHAR  BOOLEEN BRACE_L and  or
		   greater_than less_than equal  not_equal gt_equal lt_equal parent_ouvert parent_ferme
		    cr_ouvert cr_ferm virgule cote space line_br BRACE_R     FOR  IN twopoint   mc_INTEGER  mc_NUMERIC mc_CHAR   IFELSE  mc_LOGICAL

           
%type <reel> NUMERIC
%type <entier> INTEGER
%type <BOOLEAN> mc_LOGICAL
%left plus moin
%left divi mul    
%type <NT> idf  plus  moin  mul  divi   CHAR  BOOLEEN VALUE  CONDITON   OPERATION_LOGIC IF_STATEMENT   WHILE_ST   FOR_ST 
%type <NT> OPERATION_ARITH   
%right  "endif" "endifded" "endelseif" "endelse" BRACE_R
%right "IF_CLAUSE" "INST" "INSTRUCTION"
%right line_br "AFF"


%start PGM 
%%
PGM : INSTRUCTION %prec  "INSTRUCTION" {insertQuad("FIN","","","");}  ;

VALUE : INTEGER { $$.nom = inttostr($1);  $$.type= "int"; }
| NUMERIC { $$.nom = floattostr($1); $$.type= "float"; } 
| CHAR { $$.nom = strdup($1.nom); $$.type="char"; }
| BOOLEEN { $$.nom = strdup($1.nom); $$.type="boolean"; }  
| idf { if(ts != NULL) {
                                                                 if(ts_get(ts, $1.nom) != NULL){
                                                              ts_value_t* value =(ts_value_t*)ts_get(ts, $1.nom);
                                                                                                                                                                                         
                                                                             $$.nom = strdup($1.nom); 
                                                                          $$.type =  value->EntityType;
                                                              }else{                                                                                                                                                                                                                                                                                                   
                                               printf("\n  Erreur line:%d     syntaqique IDF non declaré   Lors de laffectation  \n  IDF : :nom : %s",line, $1.nom);
                                                                                                                                                                                        
                                                       exit(0); } }else {
                       printf("\n   Erreur line:%d   syntaqique IDF non declaré  :: AFFECTATION  NON CORRECTE \n  IDF :: nom: %s",line, $1.nom);
			                              exit(0);
                                                                     }
              }                                              
	; 
	
	
	/*********************************************************************AFFECTATION*************************************************************************************/

AFFECTATION :  idf  aff  OPERATION_ARITH {                          
                                            if(ts == NULL) ts = ts_create(ts,100);                            

                                            if(ts_get(ts,$1.nom) == NULL ){
                                            insertQuad("<-",$3.nom,"",$1.nom);
                                            ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $1.nom);
                                       strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, $3.type);
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur, $3.nom);
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                 ts_value_t* value =(ts_value_t*)ts_get(ts, $1.nom);
                                                if(strcmp(value->EntityType,$3.type) == 0){
                                                     insertQuad("<-",$3.nom,"",$1.nom);
                                                ///en cas ou int + float  a rajouter samira  ///
                                                }
                                                else{
                                                 
													  printf("\n Erreur line:%d  Synatqique :: incomatible type     %s <- %s  expeceted  %s \n",line,$1.nom,$3.nom,value->EntityType);
 
                                                    exit(0);
                                                }
                                            }
                                         }

                    |mc_NUMERIC idf aff  OPERATION_ARITH{
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,$2.nom) == NULL ){ 
											if(strcmp($4.type,"float") == 0){
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $2.nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "float");
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur, $4.nom);
                                            ts_put(ts,value->EntityName,value); 
											insertQuad("<-",$4.nom,"",$2.nom);
                                            }else{ 
												
		                                   printf("\n  Erreur line:%d   Synatqique :: incompatible type  %s <- %s     expected NUMERIC  not  %s \n",line,$2.nom ,$4.nom,$4.type);
                                             exit(0)	;   }
                                            }    else{
                                              
                                                            printf("\n Erreur line:%d   Synatqique :: double declaration   NUMERIC   %s <- %s \n",line,$2.nom,$4.nom);
                                                    exit(0);
                                                }
                                           
                                            
					}
				
					|mc_CHAR idf aff  CHAR
					{
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,$2.nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $2.nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "char");
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur, $4.nom);
                                            ts_put(ts,value->EntityName,value); 
											insertQuad("<-",$4.nom,"",$2.nom);
                                            }  else{
                                              
                                                            printf("\n  Erreur line:%d   Synatqique :: double declaration   char  %s <- %s \n",line,$2.nom,$4.nom);
                                                    exit(0);
                                                }
					}
					|mc_INTEGER idf aff  OPERATION_ARITH {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,$2.nom) == NULL ){ 
											if(strcmp($4.type,"int") == 0){
                                                     insertQuad("<-",$4.nom,"",$2.nom);
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $2.nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "int");
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur, $4.nom);
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                 ts_value_t* value =(ts_value_t*)ts_get(ts, $2.nom);
                                                if(strcmp(value->EntityType,$4.type) == 0){
                                                     insertQuad("<-",$4.nom,"",$2.nom);
                                                ///en cas ou int + float  a rajouter samira  ///
                                                }
                                                else{
												  printf("\n Erreur line:%d   Synatqique :: incompatible type 		  %s %s <- %s  \n",line,$2.type,$2.nom ,$4.nom);
                                                    
                                                    exit(0);
                                                }
                                            }
                                                }
                                                else{
                      
											  printf("\n  Erreur line:%d  Synatqique :: double affectation  %s <- %s \n",line,$2.nom,$4.nom );
                                                    exit(0);
                                                }
					}
						|mc_LOGICAL  idf aff  BOOLEEN {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,$2.nom) == NULL ){ 
										
                                                     insertQuad("<-",$4.nom,"",$2.nom);
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $2.nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "boolean");
											 strcpy(value->Entityvalue, "1");
											 strcpy(value->Entityvaleur, $4.nom);
											 
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                 ts_value_t* value =(ts_value_t*)ts_get(ts, $2.nom);
                                                if(strcmp(value->EntityType,$4.type) == 0){
                                                     insertQuad("<-",$4.nom,"",$2.nom);
                                                ///en cas ou int + float  a rajouter samira  ///
                                                }
                                               
                                           
                                                
                                                else{
                      
											  printf("\n  Erreur line:%d  Synatqique :: double affectation  %s <- %s \n",line,$2.nom,$4.nom );
                                                    exit(0);
                                                } }
					}
					|mc_INTEGER idf  
					{
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,$2.nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $2.nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "int");
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                {  
												
                                                        printf("\n Erreur line:%d  Synatqique :: IDF deja declare   idf::%s\n",line,$2.nom);
                                                    exit(0);
                                                }
                                            }
                                                }
                                                
					
					|mc_NUMERIC idf 
					{
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,$2.nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $2.nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "float");
											 strcpy(value->Entityvalue, "1");
											   strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d   Synatqique :: IDF deja declare   idf::%s\n",line,$2.nom);
                                                 exit(0);
                                                
                                            }
                                                }
					|mc_CHAR idf 
							{
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,$2.nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $2.nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "char");
											 strcpy(value->Entityvalue, "1");
											   strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d  Synatqique :: IDF deja declare   idf::%s\n",line,$2.nom);
                                                 exit(0);
                                                
                                            }
                                                }
					|mc_INTEGER  idf  cr_ouvert  INTEGER cr_ferm {
					
					   if(ts == NULL) {ts = ts_create(ts,100);   } 
					   char* name    = $2.nom;                        
                                      //     
										   
										
                                            if(ts_get(ts,name) == NULL ){ 
                                           // insertQuad("<-",$3.nom,"",$1.nom);
                                            ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, name);
	                                        strcpy(value->EntityCode, "Tab"); 
                                            strcpy(value->EntityType, "int");
											 strcpy(value->Entityvalue, inttostr($4));
											   strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
										//	name = strcat($2.nom,inttostr(i));
											
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d   Synatqique :: idf  %s déja declaré \n",line,$2.nom);
                                                    exit(0);
                                                }
                             //          for(int i=1;i< $4; i++){  pour les quad     }
                                         }  
					
					
					|mc_NUMERIC  idf  cr_ouvert  INTEGER cr_ferm 
					
					{
					
					   if(ts == NULL) {ts = ts_create(ts,100);   } 
					   char* name    = $2.nom;                        
                                           
										   
										
                                            if(ts_get(ts,name) == NULL ){ 
                                           // insertQuad("<-",$3.nom,"",$1.nom);
                                            ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, name);
	                                        strcpy(value->EntityCode, "Tab"); 
                                            strcpy(value->EntityType, "float");
											 strcpy(value->Entityvalue, inttostr($4));
											 
											 		 strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
//printf("\n%s\n",i);
									//		name = strcat($2.nom,inttostr(i));
											
                                            }else{
                                                
                                                    printf("\n Erreur line:%d   Synatqique :: idf  %s déja declaré \n",line,$2.nom);
                                                    exit(0);
                                                }
                                    //    for(int i=1;i< $4; i++){    }
                                         }  
					
					
					|mc_CHAR  idf  cr_ouvert  INTEGER cr_ferm {
					
					   if(ts == NULL) {ts = ts_create(ts,100);   } 
					   char* name    = $2.nom;                        
                                         
										   
										
                                            if(ts_get(ts,name) == NULL ){ 
                                           // insertQuad("<-",$3.nom,"",$1.nom);
                                            ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, name);
	                                        strcpy(value->EntityCode, "Tab"); 
                                            strcpy(value->EntityType, "char");
											 strcpy(value->Entityvalue, inttostr($4));
											  strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
										
										//	name = strcat($2.nom,inttostr(i));
											
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d   Synatqique :: idf  %s déja declaré \n",line,$2.nom);
                                                    exit(0);
                                                }
                                    //       for(int i=1;i< $4; i++){   }
                                         } 
										 
										 
										 
				 		|mc_LOGICAL idf 
					{
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,$2.nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, $2.nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "boolean");
											 strcpy(value->Entityvalue, "1");
											   strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d  Synatqique :: IDF deja declare   idf::%s\n",line,$2.nom);
                                                 exit(0);
                                                
                                            }
                                                }
												

                  |idf plus aff INTEGER
                               { 
                                         if(ts == NULL) {ts = ts_create(ts,100);}
                                              if(ts_get(ts,$1.nom) == NULL ){
										               printf("\n Erreur line:%d   Synatqique :: idf  %s non affecte \n",line,$1.nom);
													   exit(0);
                                                                    }
																	else{
                                                        ts_value_t* value =(ts_value_t*)ts_get(ts, $1.nom);
                                                    if(strcmp(value->EntityType,"int") == 0){
													if ($4 > 0){
                                                             sprintf(tempTCond,"T%d",nTempTCond);
                                                                            nTempTCond ++;

                                                                 insertQuad("+",$1.nom, inttostr($4),tempTCond);
                                                                insertQuad("<-",tempTCond,"",$1.nom);
                                                                          tempTCond[0]='\0';

                                                                        }else {
																		printf("\n Erreur line:%d   Synatqique :: la valeur affecte  doit etre positive %s non affecte \n",line);
													   exit(0);
																		}
																		}
																		}
																		
																		
																	}



					  |idf moin aff INTEGER
                               { 
                                         if(ts == NULL) ts = ts_create(ts,100);
                                              if(ts_get(ts,$1.nom) == NULL ){
                                              printf("\n  Erreur line:%d   Synatqique :: idf  %s non affecte \n",line,$1.nom);
													   exit(0);
                                                                    }else{
                                                        ts_value_t* value =(ts_value_t*)ts_get(ts, $1.nom);
                                                    if(strcmp(value->EntityType,"int") == 0){
													if ($4 > 0){
                                        sprintf(tempTCond,"T%d",nTempTCond);
                                                                            nTempTCond ++;

                                                                 insertQuad("-",$1.nom, inttostr($4),tempTCond);
                                                                insertQuad("<-",tempTCond,"",$1.nom);
                                                                          tempTCond[0]='\0';

                                                                        }else {
																		printf("\n Erreur line:%d   Synatqique :: la valeur affecte  doit etre positive %s non affecte \n",line);
													   exit(0);
																		}}
																		}}
																		
																


                                                 |idf aff logic_expression  {}
																		   
				                                     	;
					

AFF_STATEMENT : AFFECTATION ;

/****************************************************************************************IF*************************************************************************/

IF_STATEMENT : IF   parent_ouvert  CONDITON  parent_ferme LINEBREAK BRACE_L  INSTRUCTION  BRACE_R  LINEBREAK  { //printf("IF_S ");
                                                                    $$.nom = strdup($3.nom);
                                                                    int last_quad = depiler(); 
                                                                    char quad_chaine[12] ;
                                                                    sprintf(quad_chaine,"@%d",quad_list_size+1);
                                                                 
                                                                    MAJQuad(last_quad,quad_chaine);} ;
																	
ELSEIF : elseif  parent_ouvert CONDITON parent_ferme LINEBREAK BRACE_L  INSTRUCTION   BRACE_R  LINEBREAK{ 
                                                            int last_quad = depiler(); 
                                                            char quad_chaine[12];
                                                            sprintf(quad_chaine,"@%d",quad_list_size+1);
                                                            //printf("MAJQUAD");
                                                            MAJQuad(last_quad,quad_chaine);} ; 

ELSE : LINEBREAK eLse BRACE_L  INSTRUCTION  BRACE_R | eLse  LINEBREAK BRACE_L  INSTRUCTION  BRACE_R LINEBREAK;

SINON : ELSEIF SINON | ELSE | ELSEIF  %prec "endelseif"  ;

CONDITON : OPERATION_LOGIC {$$.nom = strdup($1.nom) ;
                                                                  empiler(quad_list_size);
                                                               insertQuad(BR,"c1",$1.nom,"");}; 
															
							
			
															   
															   

IF_CLAUSE :   IF_STATEMENT  SINON %prec "endelse" {}
|   IF_STATEMENT %prec  "endif" {} ;
           
                
					
	/***********************************************************************WHILE*********************************************************************************************/	  
			 WHILE_ST: WHILE    parent_ouvert   CONDITON     parent_ferme   LINEBREAK  BRACE_L   INSTRUCTION  BRACE_R 	  {
                              			// printf("while");
                                                         
																 $$.nom = strdup($3.nom);
																 
															
                                                                  int last_quad = depiler(); 
                                                                    char quad_chaine[12];
                                                                    sprintf(quad_chaine,"@%d",quad_list_size+1);
                                                                    //printf("MAJQUAD");
                                                                    MAJQuad(last_quad,quad_chaine);
																	
																	 empiler(quad_list_size);
																	     sprintf(quad_chaine,"@%d",last_quad);
																	//   insertQuad("BR","","",inttostr(last_quad ));
																	      insertQuad("BR","","",quad_chaine);
																	   
																	
																	
																		 } ;
																	
																	
		/********************************************************************************FOR*********************************************************************************************/									
			  
			  FOR_ST: FOR  parent_ouvert idf   IN A   INTEGER twopoint  INTEGER   parent_ferme LINEBREAK BRACE_L INSTRUCTION BRACE_R  
			  {    
                             if(ts == NULL) ts = ts_create(ts,100);   
                                   if(ts_get(ts,$3.nom) == NULL ){                           
                                           printf("\n Erreur line:%d  Synatqique :: IDF  %s non declarer   \n",line,$3.nom);
                                                   exit(0);
								}else{
											 ts_value_t* value =(ts_value_t*)ts_get(ts, $3.nom);
                                                if(strcmp(value->EntityType,"int") == 0){
												  if($6>$8){
															  printf("\n Erreur line:%d   Synatqique :: la valeur  de born sup   doit etre superieur  \n",line);
															  
															  }else{
										
										$$.nom = strdup($3.nom);
										                 
																	      int last_quad = depiler(); 
                                                                    char quad_chaine[12];
                                                                    sprintf(quad_chaine,"@%d",quad_list_size+1);
                                                                    //printf("MAJQUAD");
                                                                    MAJQuad(last_quad,quad_chaine);
																	
																	 empiler(quad_list_size);
																	     sprintf(quad_chaine,"@%d",last_quad);
																	//   insertQuad("BR","","",inttostr(last_quad ));
																	      insertQuad("BR","","",quad_chaine);
                                                
                                                      
                                                }}
                                               else{
                                                  printf("\n Erreur line:%d  Synatqique :: incomatible type   \n",line);
                                                   exit(0);
                                                }
                                            }
								
											} ;
															   
				       
                                              
                         A:{empiler(quad_list_size);
                                                              	   insertQuad("BNZ","c1","","");}                	 
			 
		/************************************************************************************IFELSEIF****************************************************************************************/
			 
		IFELSE_STATEMENT : idf aff IFELSE parent_ouvert parent_ouvert CONDITON parent_ferme virgule  VALUE virgule VALUE parent_ferme{}	 
			 
			 
			 
			 
			 
			 
			 
			 
		/*******************************************************************************INSTRUCTION****************************************************************************************/	 
			 
			 
			 
			 INSTRUCTION : IF_CLAUSE %prec  "IF_CLAUSE"
			 | IF_CLAUSE INSTRUCTION %prec  "INST"  
			 | IF_CLAUSE
			 |  AFF_STATEMENT %prec  "AFF"
			 | AFF_STATEMENT LINEBREAK INSTRUCTION 
			 | AFF_STATEMENT LINEBREAK  
              |LINEBREAK INSTRUCTION
			  | WHILE_ST LINEBREAK 
			  |WHILE_ST  
			  | WHILE_ST INSTRUCTION %prec  "INST"
			  | IF_CLAUSE LINEBREAK
              |FOR_ST LINEBREAK 
			  |FOR_ST INSTRUCTION %prec  "INST"
			  |IFELSE_STATEMENT LINEBREAK 
			  | IFELSE_STATEMENT INSTRUCTION %prec  "INST" ;
		 ;
		
			  





			  
			  
			  
			  

					 
 
 
 
 
 
 
 
 
LINEBREAK : line_br | line_br LINEBREAK;

/************************************************************************************************OPERATION_LOGIC***************************************************************************/

OPERATION_LOGIC : VALUE OPERATOR_LOGIC VALUE {  
                                                if(IsCompatible($1.type,$3.type)){
                                                        //printf("%s - %s\n",$1.nom,$3.nom );
                                                        sprintf(tempTCond,"Tcond%d",nTempTCond);
                                                        nTempTCond ++;
                                                        $$.nom=strdup(tempTCond);
                                                        insertQuad("-",$1.nom,$3.nom,tempTCond);
                                                        tempTCond[0]='\0';
                                                }else{
                                                        printf("\n  Erreur line:%d  syntaqique   incompatible type ') \n",line);
                                                        exit(0);
                                                }
                                            } 
											|logic_expression
											;
											
											
		logical : parent_ouvert OPERATION_ARITH OPERATOR_LOGIC OPERATION_ARITH parent_ferme
| parent_ouvert OPERATION_ARITH OPERATOR_LOGIC VALUE parent_ferme
| parent_ouvert VALUE OPERATOR_LOGIC OPERATION_ARITH parent_ferme
| parent_ouvert VALUE OPERATOR_LOGIC VALUE parent_ferme
;

logic_expression: logical and logic_expression
|logical or logic_expression
|logical
;									

OPERATOR_LOGIC : greater_than {BR = strdup("BMZ");} | less_than {BR = strdup("BPZ");} |
                 equal {BR = strdup("BNZ");} | not_equal {BR = strdup("BZ");} | 
                 gt_equal {BR = strdup("BM");} | lt_equal {BR = strdup("BP");} ;
				 
				 
/*****************************************************************************************OPERATION_ARITH********************************************************************************/				 

OPERATION_ARITH :  
     OPERATION_ARITH plus OPERATION_ARITH  { 
                 
                    if(IsCompatible($1.type,$3.type)){
                      
                        sprintf(tempC,"T%d",nTemp);
                        nTemp++;
                        $$.nom=strdup(tempC);
                        $$.type = strdup($1.type);
                        tempC[0]='\0';
                        insertQuad ("+",$1.nom,$3.nom,$$.nom);
                    }else{
                        printf(" Erreur line:%d    syntaqique type no  compatiblite vous voulez additioner %s  avec %s   :') ",line,$1.type,$3.type);
                        exit(0);
                        
                    }
                    
                    } |
    OPERATION_ARITH moin OPERATION_ARITH  { 
                    if(IsCompatible($1.type,$3.type)){
                        sprintf(tempC,"T%d",nTemp);
                        nTemp++;
                        $$.nom=strdup(tempC);
                        $$.type = strdup($1.type);
                        tempC[0]='\0';
                        insertQuad ("-",$1.nom,$3.nom,$$.nom);
                    }else{
                        printf(" Erreur line:%d   syntaqique erreur de compatiblite  de type ** additioner %s  avec %s  no compatible **  :') ",line,$1.type,$3.type);
                        exit(0);                        
                    }
                    } |
    OPERATION_ARITH mul OPERATION_ARITH  { 
                    if(IsCompatible($1.type,$3.type)){
                        sprintf(tempC,"T%d",nTemp);
                        nTemp++;
                        $$.nom=strdup(tempC);
                        $$.type = strdup($1.type);
                        tempC[0]='\0';
                        insertQuad ("*",$1.nom,$3.nom,$$.nom);
                    }else{
                        printf(" Erreur line:%d   syntaqique no  compatiblite  de type ** additioner %s  avec %s  no compatible **   :') ",line, $1.type,$3.type);
                        exit(0);    
                    }
                    } |
    OPERATION_ARITH divi OPERATION_ARITH  { 
                    if(strcmp($3.nom,"0") == 0){printf("\n Erreur line:%d   syntaxique  !\t division par zero  %s / %s ", line,$1.nom , $3.nom); exit(0); }
                    if(IsCompatible($1.type,$3.type)){
                        sprintf(tempC,"T%d",nTemp);
                        nTemp++;
                        $$.nom=strdup(tempC);
                        $$.type = strdup($1.type);
                        tempC[0]='\0';
                        insertQuad("/",$1.nom,$3.nom,$$.nom);
                    }else{
                         printf("  Erreur line:%d   syntaqique non compatiblite  de type ** additioner %s  avec %s  no compatible **  :') ",line,$1.type,$3.type);
                         exit(0);  
                    }
                    } | 
                    VALUE {
                 
                    $$ = $1;                       

                    } | parent_ouvert OPERATION_ARITH parent_ferme { 
                                $$.nom = $2.nom;
                                $$.type = $2.type;
                    }  
  ;
%%
int yyerror(char* msg) {
printf("\n\nErreur line:%d column:%d %s\n\n",line , column-yyleng+1,msg);
erreur = 1;
}
int main()
{ 
    int option ;
    printf("\n *---------------------------BIENVENUE -------------------------------------------*\n");
    	  printf(" ouvrir  les fichier text   a tester   taper \n ");
       printf (  "1.Declaration des variables de type simple ::  nom de fichier -->formedeclaration.txt \n");
		printf(	"2.Declaration des variables de type Tableaux  ::nomdeficher -->declarationtab.txt \n");
		printf(	"3. tester les instuctions    \n");
		printf(	"4. Associativite et priorite des operateurs  \n");
		
    scanf("%d",&option);
    switch (option)
    {
    case 1:   
	yyin=fopen("formedeclaration.txt","r");
              break;
		
		case 2: 
             yyin=fopen("tabdeclaration.txt","r");
        break;
		case 3: 
            printf("ouvrir  les fichier text   a tester \n1.les condition IFELSEIF --> nom de fichier :  IFtouslescas.txt  \n2. Boucle  while --> nom defichier : whiletest.txt \n3. Boucle  FOR \n 4. Affectation avec  condition  \n ");
			  printf("5.Incrementation & Decrementation \n"); 
    scanf("%d",&option);
    switch (option)
    {
    case 1:   
	yyin=fopen("IFtouslescas.txt ","r");
              break;
		
		case 2: 
             yyin=fopen("whiletest.txt","r");
        break;
		case 3: 
              yyin=fopen("fortest.txt","r");
        break;
		
		case 4: 
              yyin=fopen("affcondtest.txt","r");
        break;
			
		case 5: 
              yyin=fopen("incrdecrtest.txt","r");
        break;
    
     
    default: printf(" \n :) s'il vous plait choisir le numéro  entre 1 et 5 \n");
    }
		
			
        break;
		
		case 4: 
		printf(	"Taper votre fichier txt a tester \n");
		printf(	"1.OPERATION ARITHMETIQUE   \n");
		printf(	"2. OPERATION LOGIQUE  \n");
		printf(	"3. DIVISION PAR ZERO  \n");
		
		
    scanf("%d",&option);
    switch (option)
    {
    case 1:   yyin=fopen("exprarith.txt","r");
	
              break;
		
		case 2: 
         yyin=fopen("explogique.txt","r");
			
        break;
		
		case 3:
		 yyin=fopen("divparzero.txt","r"); 
        break;
	
	default: printf(" \n :) s'il vous plait choisir le numéro entre 1 et 3 \n");
              }
         
    break;
    default: printf(" \n :) s'il vous plait choisir le numéro entre 1 et 4 \n");
    }
    yyparse();
    if (erreur == 0){
  printf("\n********************************************\n");
printf("*            Table des symboles            *\n");
printf("********************************************\n");
printf("_____________________________________________\n");
printf("|NomEntite |TYPE   |NATURE |TAILLE |VALEUR | \n");
printf("|_________ |_____  |________|______  |________| \n");
     /*   printf("\n NOM  \t TYPE   \t NATURE  \t  \t   \n"); */
        ts_elem_it it2 = TS_ITERATOR(ts);
        ts_value_t* k = (ts_value_t*)ts_iterate_values(&it2);
        while (k != NULL) {
printf("|%s\t%s\t %s\t%s\t%s\t\n", k->EntityName, k->EntityType,k->EntityCode, k-> Entityvalue,k-> Entityvaleur);
       
            k = (ts_value_t*)ts_iterate_values(&it2);
}
 printf("|__________|______|_______|_____|________| \n"); 
   }
        
		
		
		printf("\n --------------------------------\n");
        printf("\n**********************\n");
        printf("\n******QUADRUPLET ***\n");
        afficherQuad();
        printf("\n****ASSEMBLeur :: test.asm *****\n");
        codeMachine ();

        printf("\n 	Pour le  code machine  taper  test.asm \n");
     
        printf("\n MERCI  ------>  :D");
 

  printf("\n *---------------------------------------------------------------------------*");
    return 0;
}


void quadAppend(Quadruplet quad){
  QuadList *list_head = quadruplet_list;
  while ( (*list_head).svt != NULL){
      list_head = (*list_head).svt;
  }

  (*list_head).svt = (QuadList*)malloc(sizeof(QuadList));
  

}

void insertQuad (char* o,char* o1,char* o2,char* r ){
    Quadruplet quad;
    int first = 0;
    
   // printf( "******1******** o1:%s o2:%s s:%d\n",o1,o2,quad_list_size);
     if ( quadruplet_list == NULL){
      quadruplet_list = (QuadList*)malloc(sizeof(QuadList));
      (*quadruplet_list).svt = NULL;
      first = 1;
     }
     QuadList *list_head ;
     list_head = quadruplet_list;

  while ( (*list_head).svt != NULL){
      list_head =(*list_head).svt;
  }
 
  (*list_head).svt = (QuadList*)malloc(sizeof(QuadList));
  (*(*list_head).svt).svt = NULL; 
  (*list_head).val.opr = strdup(o);  
  (*list_head).val.op1 = strdup(o1); 
  (*list_head).val.op2 = strdup(o2); 
  (*list_head).val.res = strdup(r);

  quad_list_size ++;
 
}
   

void MAJQuad (int indice , char* operand){

    int i = 0;
    QuadList *list_head;
    list_head = quadruplet_list;
    while ( i < indice && list_head != NULL){
    list_head =(*list_head).svt;
    i++;}

    if (list_head != NULL){
        (*list_head).val.op1 = strdup(operand);
    //  printf(" s_maj:%d indice:%d o:%s o2:%s\n",quad_list_size , indice , (*list_head).val.op1 , (*list_head).val.op2);
    }

}

void afficherQuad()
{ 
   
  QuadList *list_head;
  list_head = quadruplet_list;
  int i = 1;
  while ( list_head != NULL && (*list_head).svt != NULL){
  if( !( strlen((*list_head).val.opr ) == 0 && strlen((*list_head).val.op1 ) == 0 && strlen((*list_head).val.op2 ) == 0 && strlen((*list_head).val.res ) == 0 ) )
    {
    printf("%d - ( %s , ",i,(*list_head).val.opr );
    printf("%s , ",(*list_head).val.op1 );
    printf("%s , ",(*list_head).val.op2 );
    printf("%s )\n",(*list_head).val.res );
    }
    list_head =(*list_head).svt;
    i++;
  }
}

void empiler (int val){
  
      QuadPile *pile_head ; 
      pile_head = (QuadPile*)malloc(sizeof(QuadPile));
      (*pile_head).svt = quadruplet_pile;
      (*pile_head).val = val;
      quadruplet_pile = pile_head ;      
}

int depiler (){

  int val = -1;

  if (quadruplet_pile != NULL){
 
    val = (*quadruplet_pile).val;
  
    quadruplet_pile = (*quadruplet_pile).svt;

    return val;
  }
    return val;
}

QuadList* getQuadAt(int i){
     QuadList *list_head;
  list_head = quadruplet_list;
  int cpt = 0;

  while ( cpt < i && list_head != NULL && (*list_head).svt != NULL){ 
       
        list_head =(*list_head).svt;
        cpt++;
      }
      return list_head;
}

QuadList* getQuadByRes(char* res){
      QuadList *list_head;
      list_head = quadruplet_list;
      while ( list_head != NULL && (*list_head).svt != NULL){
            if (strcmp((*list_head).val.res,res) == 0)
               {
                return list_head;}
            list_head =(*list_head).svt;
      }
      return NULL;
}

int isIdf(char* opr){

    if (strlen(opr)>0){
        if ((opr[0] >= '0' && opr[0]<= '9' ) || opr[0]=='"' || opr[0]=='@' ){
            return -1;
        }
        return 1;
    }

    return -1;

}

char** getAllIDFs(){

    QuadList *list_head;
    list_head = quadruplet_list;
    char** allIDFs= malloc(100 * sizeof(char*))
    ;int i = 0;
    while (i<100){
        allIDFs[i] = strdup("");i++;
    }
    i=0;
    int size = 0;
    int trouve = 0;
    while ( list_head != NULL && (*list_head).svt != NULL ){

        if( isIdf((*list_head).val.op1) == 1 ){
               while (trouve == 0 && i < size){
                    if (strcmp(allIDFs[i],(*list_head).val.op1)==0){
                        trouve = 1;}
                    i++ ;

               }
               i=0;
               if (trouve == 0){
                    allIDFs[size] = strdup((*list_head).val.op1);
                    size ++;
                    //printf(" add:%s",(*list_head).val.op1);

               }else {trouve = 0;}
        }
        if( isIdf((*list_head).val.op2) == 1 ){
                    //printf(" op2");
                     while (trouve == 0 && i < size){
                    if (strcmp(allIDFs[i],(*list_head).val.op2)==0){
                        trouve = 1;}
                    i++ ;

               }
               //printf(" trouve:%d ",trouve);
               i=0;
               if (trouve == 0){
                    allIDFs[size] = strdup((*list_head).val.op2);
                    size ++;
                   // printf(" add:%s",(*list_head).val.op2);

               }else {trouve = 0;}
        }
        if( isIdf( (*list_head).val.res) == 1 ) {
                   // printf(" res ");
                     while (trouve == 0 && i < size){
                    if (strcmp(allIDFs[i],(*list_head).val.res)==0){
                        trouve = 1;}
                    i++ ;

               }
               i=0;
              // printf(" trouve:%d ",trouve);
               if (trouve == 0){
                    allIDFs[size] = strdup((*list_head).val.res);
                    size ++;
                  //  printf(" add:%s",(*list_head).val.res);
               }else {trouve = 0;}
        }
        list_head =(*list_head).svt;
    }

    return allIDFs;
}

// *************  GENERATION CODE MACHINE
void codeMachine (){

        FILE* fichier = NULL;

        fichier = fopen("test.asm", "w+");

        fprintf(fichier,"\nTITLE : Test\n");

        //Pile declaration
        fprintf(fichier,"\nPILE SEGMENT stack\n");
        fprintf(fichier,"\t\t100 DD dup (?)\n");
        fprintf(fichier,"PILE ENDS\n");

        //DATA SEGMENT
        fprintf(fichier,"\nDATA SEGMENT\n");

        char**  allIDFs = getAllIDFs();
        int i = 0;
        while (strlen(allIDFs[i]) > 0 ){
            if(allIDFs[i][0] !='T')
                fprintf(fichier,"\t%s DW 0\n",allIDFs[i]);
            i++;
        }

	    fprintf(fichier,"DATA ENDS\n");
        fprintf(fichier,"\nCODE SEGMENT\n");
		fprintf(fichier,"BEGIN:\n");
		fprintf(fichier,"\t\tASSUME SS: PILE, DS: DATA, CS: CODE\n");
		fprintf(fichier,"\t\t\tMov AX,DATA\n");
		fprintf(fichier,"\t\t\tMov DX,AX\n\n");
		// etiques
		QuadList *list_head;
        list_head = quadruplet_list;
        int etique_list[100] = {0};
        int nb_etique = 0;
        char* op1;
        while ( list_head != NULL && (*list_head).svt != NULL ){
            if ((*list_head).val.opr[0] == 'B' ){
                op1 = strdup((*list_head).val.op1);
                op1[0] = '0';
                int cpt = 0;
                int trouve = 0;
                for(cpt=0;cpt<nb_etique;cpt++){
                    if(atoi(op1) == etique_list[cpt]){
                        trouve = 1;
                    }
                }
                if (trouve == 0){
                    etique_list[nb_etique] = atoi(op1);
                    trouve = 0;
                    nb_etique ++;}
            }
            list_head =(*list_head).svt;
        }
		char * operation = malloc(sizeof(char*));
        i = 1;
        list_head = quadruplet_list;
        while ( list_head != NULL && (*list_head).svt != NULL ){
            int ii=0;
            for(ii=0;ii<nb_etique;ii++)
            {
                if(i==etique_list[ii]){
                    fprintf(fichier,"etiq [ %d ] : \n",i); etique_list[ii] = -1;
                }
            }
            if ((*list_head).val.opr[0] == '='){
                if(isIdf((*list_head).val.op1) == 1){

                    if((*list_head).val.op1[0]=='T')
                        fprintf(fichier,"\t\t\tPOP AX\n");
                    else
                        fprintf(fichier,"\t\t\tMov AX,%s\n",(*list_head).val.op1);

                    if((*list_head).val.res[0]=='T')
                        fprintf(fichier,"\t\t\tPUSH AX\n");
                    else
                        fprintf(fichier,"\t\t\tMov %s,AX\n",(*list_head).val.res);

                }else {
                     if((*list_head).val.res[0]=='T')
                        fprintf(fichier,"\t\t\tPUSH %s\n",(*list_head).val.op1);
                     else
                        fprintf(fichier,"\t\t\tMov %s,%s\n",(*list_head).val.res,(*list_head).val.op1);
                }
            }
            else if (strlen((*list_head).val.opr) == 1){
                    if((*list_head).val.op1[0]=='T')
                        fprintf(fichier,"\t\t\tPOP AX\n");
                     else
                        fprintf(fichier,"\t\t\tMov AX,%s\n",(*list_head).val.op1);
                switch ((*list_head).val.opr[0]){

                    case '+':{
                        if((*list_head).val.op2[0]=='T'){
                            fprintf(fichier,"\t\t\tPOP BX\n");
                            fprintf(fichier,"\t\t\tADD AX BX\n");break;}
                        else   {
                            fprintf(fichier,"\t\t\tADD AX,%s\n",(*list_head).val.op2);break;}

                        }
                    case '-':
                    if((*list_head).val.op2[0]=='T'){
                            fprintf(fichier,"\t\t\tPOP BX\n");
                            fprintf(fichier,"\t\t\tSUB AX BX\n");break;}
                        else   {
                        fprintf(fichier,"\t\t\tSUB AX,%s\n",(*list_head).val.op2);break;}
                    case '/':
                    if((*list_head).val.op2[0]=='T'){
                            fprintf(fichier,"\t\t\tPOP BX\n");
                            fprintf(fichier,"\t\t\tDIV AX BX\n");break;}
                        else   {
                        fprintf(fichier,"\t\t\tDIV AX,%s\n",(*list_head).val.op2);break;}
                    case '*':
                    if((*list_head).val.op2[0]=='T'){
                            fprintf(fichier,"\t\t\tPOP BX\n");
                            fprintf(fichier,"\t\t\tMUL AX BX\n");break;}
                        else   {
                        fprintf(fichier,"\t\t\tMUL AX,%s\n",(*list_head).val.op2);break;}

                }
                if((*list_head).val.res[0]=='T')
                        fprintf(fichier,"\t\t\tPUSH AX\n");
                     else
                        fprintf(fichier,"\t\t\tMov %s,AX\n",(*list_head).val.res);
            }
            else if (strlen((*list_head).val.opr) > 1 && (*list_head).val.opr[0] == 'B' ){
                  char* adresse = strdup((*list_head).val.op1);
                  adresse[0] = ' ';
                 fprintf(fichier,"\t\t\tPOP AX\n\t\t\tCMP AX , 0\n",adresse);
                if( strcmp((*list_head).val.opr,"BNZ")== 0 ){
                    fprintf(fichier,"\t\t\tJNE  etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BPZ")== 0 ){
                    fprintf(fichier,"\t\t\tJGE etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BMZ")== 0 ){
                    fprintf(fichier,"\t\t\tJLE etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BM")== 0 ){
                    fprintf(fichier,"\t\t\tJL etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BP")== 0 ){
                    fprintf(fichier,"\t\t\tJG etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BZ")== 0 ){
                    fprintf(fichier,"\t\t\tJE etiq [ %s ] \n",adresse);
                }
            }
            i++;
            list_head =(*list_head).svt;
        }
fprintf(fichier,"END\n");
fclose(fichier);

}
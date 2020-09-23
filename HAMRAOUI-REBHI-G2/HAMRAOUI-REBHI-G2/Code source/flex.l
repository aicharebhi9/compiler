
%{
#include<stdio.h>
#include "bison.tab.h"
#include <string.h> 
#include <math.h>
extern YYSTYPE yylval;
extern int line;
extern int column;
extern YYSTYPE yylval;
extern char id [12];
extern int col;

#define YYSTYPE string;
int cmp=1;
%}
IDF  [A-Z]([a-z]|[0-9])* 
int    0|\(\-[1-9][0-9]*\)|[1-9][0-9]* 
float ([0-9]+)(\.[0-9]+)|\(\-([0-9]+)(\.[0-9]+)\)   
char   \'.\'   
comment \#.*                    
boolean FALSE|TRUE
tab \n+\t+
four_spaces \n+"    "+

%%



"\n" {
     printf("\n");
     column = column+yyleng;yylval.nom = strdup(yytext);
	 line++;column=0;
     return (line_br);
}	
{comment} {printf("comment \n"); column=1;}




"IF" {printf("IF ");column = column+yyleng;yylval.nom = strdup(yytext);return (IF);}
"ELSEIF" {printf("ELSEIF ");column = column+yyleng;yylval.nom = strdup(yytext);return (elseif);}
"ELSE" {printf("ELSE  ");column = column+yyleng;yylval.nom = strdup(yytext);return (eLse);}


"+" {printf("+  ");column = column+yyleng;yylval.nom = strdup(yytext);return (plus);}
"-" {printf("-  ");column = column+yyleng;yylval.nom = strdup(yytext);return (moin);}
"*" {printf("*  ");column = column+yyleng;yylval.nom = strdup(yytext);return (mul);}
"/" {printf("/  ");column = column+yyleng;yylval.nom = strdup(yytext);return (divi);}
">" {printf(">  ");column = column+yyleng;yylval.nom = strdup(yytext);return (greater_than);}
"<" {printf("<  ");column = column+yyleng;yylval.nom = strdup(yytext);return (less_than);}
"==" {printf("==  ");column = column+yyleng;yylval.nom = strdup(yytext);return (equal);}
"!=" {printf("!=  ");column = column+yyleng;yylval.nom = strdup(yytext);return (not_equal);}
">=" {printf(">=  ");column = column+yyleng;yylval.nom = strdup(yytext);return (gt_equal);}
"<=" {printf("<=  ");column = column+yyleng;yylval.nom = strdup(yytext);return (lt_equal);}
"<-" {printf("<-  ");column = column+yyleng;yylval.nom = strdup(yytext);return (aff);}
"(" {printf("(  ");column = column+yyleng;yylval.nom = strdup(yytext);return (parent_ouvert);}
"}" {  printf( "}"); 
     column = column+yyleng;yylval.nom = strdup(yytext);
     return (BRACE_R);
}
"{" {  
     printf( "{");
     column = column+yyleng;yylval.nom = strdup(yytext);
	return (BRACE_L);
}
")" {printf(") ");column = column+yyleng;yylval.nom = strdup(yytext);return (parent_ferme);}
"[" {printf("[ ");column = column+yyleng;yylval.nom = strdup(yytext);return (cr_ouvert);}
"]" {printf("] ");column = column+yyleng;yylval.nom = strdup(yytext);return (cr_ferm);}
"," {printf(", ");column = column+yyleng;yylval.nom = strdup(yytext);return (virgule);}
"\'" {printf("\' ");column = column+yyleng;yylval.nom = strdup(yytext);return (cote);}
":" {printf(": ");column = column+yyleng;yylval.nom = strdup(yytext);return (twopoint);}

"FOR" {printf("FOR ");column = column+yyleng;yylval.nom = strdup(yytext);return  (FOR);}
"IN" {printf("IN");column = column+yyleng;yylval.nom = strdup(yytext);return  (IN);}
"WHILE" {printf("WHILE  ");column = column+yyleng;yylval.nom = strdup(yytext);return  (WHILE);}
"INTEGER" {printf("INTEGER  ");column = column+yyleng;yylval.nom = strdup(yytext);return ( mc_INTEGER);}
"NUMERIC" {printf("NUMERIC  ");column = column+yyleng;yylval.nom = strdup(yytext);return (mc_NUMERIC);}
"CHAR" {printf("CHAR  ");column = column+yyleng;yylval.nom = strdup(yytext);return (mc_CHAR);}
"LOGICAL"  {printf("LOGICAL ");column = column+yyleng;yylval.nom = strdup(yytext);return (mc_LOGICAL);}
"IFELSE" {printf("IFELSE");column = column+yyleng;yylval.nom = strdup(yytext);return (IFELSE);}
"and" {printf("and ");column = column+yyleng;yylval.nom = strdup(yytext);return (and);}
"or" {printf("or ");column = column+yyleng;yylval.nom = strdup(yytext);return (or);}

{int} {printf("integer ");column = column+yyleng;yylval.entier = atoi(yytext);if ((atoi(yytext)>=-32768) && (atoi(yytext)<=32767)){return INTEGER ;}else printf("le chiffre n'est pas entre -32768 et 32767");}
{float} {printf("Numeric ");column = column+yyleng;yylval.reel = atof(yytext);if ((atoi(yytext)>=-3520.34)){return NUMERIC  ;}else printf("le chiffre n'est pas entre -3520.34 et 5210.17 ou plus ");}
{char} {printf("char  ");column = column+yyleng;yylval.nom = strdup(yytext);return (CHAR);}
{IDF} {  
          printf("IDF ");
          column = column+yyleng;
      if(yyleng<12)   { yylval.nom = strdup(yytext);
          return (idf);}
		  else {printf(" \n erreur lexical a la ligne %d\n la taille des IDF   doit etre  inferieur a   la taille maximale 12 \n",line);exit(0);}
}
{boolean} {printf("BOOLEAN  ");column = column+yyleng;yylval.nom = strdup(yytext);return (BOOLEEN);}

" " {printf(" ");column = column+yyleng;}
.  {printf("erreur lexical a la ligne %d\n  undefined token %c  \n",line,yytext[0]);exit(0);}
    


%%
int yywrap () {return 1;}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quad.h"
int indq=0;
QuadList *quadruplet_list = NULL;
quadruplet_list =(QuadList*)malloc(sizeof(QuadList));

void quadAppend(Quadruplet *quad){
	QuadList *list_head = quadruplet_list;
	while ( (*list_head).svt != NULL){
			list_head =(*list_head).svt
	}

	(*list_head).svt = quad;

}

void insertQuad (char* o,char*o1,char*o2,char*r ){
		Quadruplet *quad;

        quad=(Quadruplet*)malloc(sizeof(Quadruplet));
        (*quad).svt = NULL;
		(*quad).opr = o;
		(*quad).op1 = o1;
		(*quad).op2 = o2;
		(*quad).res = r;

		quadAppend( quad );

}


void afficherQuad()
{ 
	QuadList *list_head = quadruplet_list;
	int i = 1;
	while ( (*list_head).svt != NULL){
		printf ("%d-( %s , %s , %s , %s )\n",i,(*list_head).val.opr,(*list_head).val.op1,(*list_head).val.op2,(*list_head).val.res);
		list_head =(*list_head).svt;
		i++;
	}
}


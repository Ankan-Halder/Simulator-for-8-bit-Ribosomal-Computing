#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<input.h>
#include<binarytype.h>
#include<mrna.h>
#include<ribosome.h>
#include<util.h>
#include <operation.h>
#include <decimaltype.h>

extern FILE *fpmrna;
extern FILE *fpmuta;

void print_mRNA(mrna *rtmRNA){
	int i=0;

    //fprintf(fpmrna,"*******************************************======================================================************************************\n");
	printf("\nmRNA is created : ");
    fprintf(fpmrna,"\nmRNA is created : ");
    while(strcmp((*rtmRNA)[i], "UAA")){
		printf("|%s", (*rtmRNA)[i]);
        fprintf(fpmrna,"|%s", (*rtmRNA)[i]);
		i++;
	}
	printf("|%s", (*rtmRNA)[i]);
	printf("\n");
	printf("Number of codon present in mRNA is %d\n",i);	

    fprintf(fpmrna,"|%s", (*rtmRNA)[i]);
    fprintf(fpmrna,"\n");
    fprintf(fpmrna,"Number of codon present in mRNA is %d\n",i);
    fprintf(fpmrna,"\n\n");
}

void print_ribosome(ribosome *rtribo){

	if(!strcmp((rtribo->opname), "multshift")){
		printf("No mutation is there for this operation\n");
        fprintf(fpmuta,"No mutation is there for this operation\n");
	}
	else{
		printf("Ribosome created with mutations: %s\n", rtribo->mname);
        fprintf(fpmuta,"Ribosome created with mutations: %s\n", rtribo->mname);
	}

    fprintf(fpmrna,"\n*******************************************======================================================************************************\n");
}

/*void print_chain(char *chain){

}

void print_number_one(char *num){

}

void print_number_two(char *num1, char *num2){

}*/

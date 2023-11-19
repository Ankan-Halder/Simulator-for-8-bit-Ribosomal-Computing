
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<util.h>
#include<binarytype.h>

extern FILE *fpn;
extern FILE *fpddig;

/*
 * This function takes two number and check that if the length of this two number is same or not.
 * Input -> First input number may be in binary or decimal
            Second input number may be in binary or in decimal
 * Returns -> Two same length number
 */
char *adjust(number num, int flag, int t) {
	int len=0;
    int i, j, n, diff;
	char *temp, *value, sbit='0';
	
	temp = (number)malloc(sizeof(char)*10);
	value = (number)malloc(sizeof(char)*10);

    temp[0] = '\0';
    value[0] = '\0';
    fprintf(fpn,"The input number is %s\n",num);
    fprintf(fpddig,"The data value  %s is adjusted in 8 bit format here\n",num);
	
	if(flag == 1){
		n = atoi(num);
		temp = to_binary(n);
        sbit = '0';
	}
	else {
        if(strlen(num)<8)
            sbit = '0';
		strcpy(temp, num);
	}

	len = strlen(temp);

    printf("\nThe number(temp) is : %s\n",temp);
	printf("The length of the number is : %d \t", len);
    fprintf(fpddig,"The length of the number is : %d \n", len);

	if(len == 8) 
		strcpy(value, temp);
	
	else {
		if(len<8){

			diff = 8 -len;

			printf("difference is %d\t", diff);
            //fprintf(fpn,"difference is %d\n", diff);

			for(i=0; i<diff; i++){
				value[i] = sbit;
                value[i+1] ='\0';
				printf("\n value : %s", value);
                fprintf(fpn,"\n :%s",value);
                fprintf(fpddig,"\n value : %s", value);
			}
			for(i=diff, j=0; i<8; i++, j++){
				value[i] = temp[j];
                value[i+1] = '\0';
                printf("\n value : %s", value);
                fprintf(fpn,"\n :%s",value);
                fprintf(fpddig,"\nvalue : %s", value);
			}
		}

		printf("\nThe updated value is %s", value);
        fprintf(fpddig,"\nThe binary value in 8 bit format is : %s\n", value);
        fprintf(fpn,"\nThe binary value in 8 bit format is : %s\n", value);
	}
	return value;	
}

void oplist(){
    /*printf("\t\t||-------------------------------------------------------------||\n");
	printf("\t\t||\t Opcode  \t :\t Operation Name                ||\n");	
	printf("\t\t||-------------------------------------------------------------||\n");
	printf("\t\t||\t or      \t :\t Logic OR                      ||\n");
	printf("\t\t||-------------------------------------------------------------||\n");
	printf("\t\t||\t and     \t :\t Logic AND                     ||\n");
	printf("\t\t||-------------------------------------------------------------||\n");
	printf("\t\t||\t xor     \t :\t Logic XOR                     ||\n");
	printf("\t\t||-------------------------------------------------------------||\n");
    printf("\t\t||\t twoscom \t :\t Twoscomplement                ||\n");
    printf("\t\t||-------------------------------------------------------------||\n");
    printf("\t\t||\t add     \t :\t Addition                      ||\n");
    printf("\t\t||-------------------------------------------------------------||\n");
    printf("\t\t||\t sub     \t :\t Subtraction                   ||\n");
    printf("\t\t||-------------------------------------------------------------||\n");
    printf("\t\t||\t mult    \t :\t Multiplication                ||\n");
    printf("\t\t||-------------------------------------------------------------||\n");
    printf("\t\t||\t div     \t :\t Division                      ||\n");
    printf("\t\t||-------------------------------------------------------------||\n");
    printf("\t\t||-------------------------------------------------------------||\n");*/
	printf("*************************************************************************************\n");
}

int menu(int n){
    //int p;
//	char *ch;
    //ch = (char *)malloc(sizeof(char)*2);
	printf("\n\nTo continue enter [y]\t");
	printf("To exit enter [n]\n");
	printf("Enter your choice  : ");
	//scanf("%d", &p);
	//n = p;
	n=2;
	return n;
}

//void method(char *m){
    /*printf("\n********************************************* Mode of Operation **********************************************\n");
	printf("\t\t||--------------------------------------------------------------------------------------------------||\n");
	printf("\t\t||\t Code for mode of operation  \t :\t Name of the mode of operation                    ||\n");	
	printf("\t\t||--------------------------------------------------------------------------------------------------||\n");
	printf("\t\t||\t develop      \t :\t For development of the simulator                                ||\n");
	printf("\t\t||--------------------------------------------------------------------------------------------------||\n");
	printf("\t\t||\t operation     \t :\t For performing the operation already included in the simulator    ||\n");
	printf("\t\t||--------------------------------------------------------------------------------------------------||\n");
    printf("Enter your choice for performing the operation : ");*/
   // m= "operation";
    //scanf("%s",m);
//}

/*
* This function provide the user interface

* Input ->	To perform an operation user provide three differnt type input.
			First input is name of the operation
			Second input is a flag of what type of input value we are going to put
			Thrid input is the value(s) for the operation

* Output ->	Depending upon the operation the ouput(s) is (are) generated
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <input.h>
#include <output.h>
#include <util.h>
#include <mrna.h>
#include <ribosome.h>
#include <operation.h>
#include<decimaltype.h>
#include <main1.h>

/*For writing the outputs we assume these file pointers. They create and write on files*/

extern FILE *fpmrna;    /* File pointer for File mRNA */
extern FILE *fpmuta;    /* File pointer for File mutation */
extern FILE *fpp;       /* File pointer for File protein */

extern FILE *fpn;       /* File pointer for File input in output folder */
extern FILE *fpnop;     /* File pointer for File output */

extern FILE *fpdbio;    /* File pointer for File biology */
extern FILE *fpddig;    /* File pointer for File digital */

extern FILE *fpengy;    /* File pointer for File energy */
extern FILE *fptime;    /* File pointer for File time */

/*For taking the inputs we assume these file pointer to open the existing files*/

extern FILE *fip1;  /* File pointer for first input number */
extern FILE *fip2;  /* File pointer for first input number */
extern FILE *fon;   /* File pointer for mode of operation */
extern FILE *fom;   /* File pointer for name of operation */



void shiftip(char *name, int flag){
    char *result;
    int value = 0;
    result = (char *)malloc(sizeof(char)*20);
    number num;
    num = (number)malloc(MAX);
    mrna *rmrna = (mrna * )malloc(sizeof (mrna));
    ribosome *ribo = (ribosome *) malloc (sizeof (ribosome));
    //chain peptide_chain;
    int acti;

    if(fip1 == NULL)
        printf("\n ERROR -Cannot open the designated file \n");
    else{
        fscanf(fip1, "%s", num);
    }
    printf("First Number : %s", num);
    get_input_one(name, flag, num, rmrna, ribo);
    print_mRNA(rmrna);
    print_ribosome(ribo);
    result = operate(rmrna, ribo, &acti);

    printf("\n The final result is %s in binary\n",result);
    fprintf(fpnop,"\n The final result is %s in binary\n",result);
     fprintf(fpddig,"\n The final result is %s in binary\n",result);

    if(flag == 1){
        value = to_decimal(result);

        printf("\n The final result is %d in decimal\n",value);
        fprintf(fpnop,"\n The final result is %d in decimal\n",value);
        fprintf(fpddig,"\n The final result is %d in decimal\n",value);
    }
    //fprintf(fpdbio,"Last Activated %s \t", ribo->mlist[activated].name);
}

void comparatorip(char *name, int flag){

    char *result;
    int i, same = 0, value = 0;
    result = (char *)malloc(sizeof(char)*20);

    number num1, num2;
    num1 = (number)malloc(MAX);
    num2 = (number)malloc(MAX);

    mrna *rmrna = (mrna * )malloc(sizeof (mrna));
    ribosome *ribo = (ribosome *) malloc (sizeof (ribosome));
    chain peptide_chain = (chain)malloc (sizeof(char) * 20);

    int acti;

    if(fip1 == NULL)
        printf("\n ERROR -Cannot open the designated file \n");
    else{
        fscanf(fip1, "%s", num1);
    }
    printf("First Number : %s", num1);
    if(fip2 == NULL)
        printf("\n ERROR -Cannot open the designated file \n");
    else{
        fscanf(fip2, "%s", num2);
    }
    printf("Second Number : %s", num2);

    get_input_two(name, flag, num1, num2, rmrna, ribo);
    print_mRNA(rmrna);
    print_ribosome(ribo);
    peptide_chain = operate(rmrna, ribo, &acti);

    printf("\nThe prptide chain is : %s\n", peptide_chain);
    fprintf(fpdbio, "\nThe prptide chain is : %s\n", peptide_chain);
    i = 0;
    while(peptide_chain[i] != '\0'){
        if(peptide_chain[i] == 'A'){
            same = 1;
            break;
        }
        else if(peptide_chain[i] == 'L'){
            same = -1;
            break;
        }
        else {
            i++;
        }
    }
    if(same == 0){
        printf("Number is same\n");
        fprintf(fpddig, "Number is same\n");
        fprintf(fpnop, "Number is same\n");
    }
    else if(same < 0){
        printf("First number is larger than second number\n");
        fprintf(fpnop, "First number is larger than second number\n");
        fprintf(fpddig,"First number is larger than second number\n");
    }
    else if(same > 0){
        printf("First number is smaller than second number\n");
        fprintf(fpddig,"First number is smaller than second number\n");
        fprintf(fpnop, "First number is smaller than second number\n");
    }
}

void twoscomplementip(char *name, int flag){
    char *result;
    int i, value = 0;
    result = (char *)malloc(sizeof(char)*20);

    number num;
    num = (number)malloc(MAX);

    int acti;

    if(fip1 == NULL)
        printf("\n ERROR -Cannot open the designated file \n");
    else{
        fscanf(fip1, "%s", num);
    }
    printf("First Number : %s", num);

    mrna *rmrna = (mrna *)malloc(sizeof(mrna));
    ribosome *ribo = (ribosome *)malloc(sizeof(ribosome));

    if(!strcmp("twoscom",name)){
        get_inputs(name, flag, num, rmrna, ribo);

        print_mRNA(rmrna);
        print_ribosome(ribo);

        result = operate(rmrna, ribo, &acti);
    }

    fprintf(fpnop,"\n The binary value of the output of %s operation is %s", name, result);
    if(flag == 1)
    fprintf(fpnop,"\n The decimal value of the output of %s operation is %d",name, value);
}

void integer_basic_ip(char *name, int flag){
    char *result, *tcom;
    int i, value = 0;
    result = (char *)malloc(sizeof(char)*20);
    number num1, num2;
    num1 = (number)malloc(MAX);
    num2 = (number)malloc(MAX);

    int acti;

    tcom = (char *)malloc(sizeof(char)*20);

    mrna *trmrna = (mrna *)malloc(sizeof(mrna));
    ribosome *tribo = (ribosome *)malloc(sizeof(ribosome));
    mrna *rmrna = (mrna * )malloc(sizeof (mrna));
    ribosome *ribo = (ribosome *) malloc (sizeof (ribosome));
   // chain peptide_chain;

    if(fip1 == NULL)
        printf("\n ERROR -Cannot open the designated file \n");
    else{
        fscanf(fip1, "%s", num1);
    }
    printf("First Number : %s", num1);
    if(fip2 == NULL)
        printf("\n ERROR -Cannot open the designated file \n");
    else{
        fscanf(fip2, "%s", num2);
    }
    printf("Second Number : %s", num2);


    get_input_two(name, flag, num1, num2, rmrna, ribo);
    print_mRNA(rmrna);
    print_ribosome(ribo);

    result = operate(rmrna, ribo, &acti);
    fprintf(fpnop,"\n The binary value of the output of operation %s is %s ", name, result);
    //fprintf(fpnop,"is %s", result);

    i = acti;

    if(i == 11){
        fprintf(fpnop,"\n There is an Overflow\n");


        if(strcmp(name, "add")){
        //if(result[0] == '1'){
        //if(i == 11){
            printf("The result is a negative number\n");
            fprintf(fpnop,"The result is a negative number and there is a borrow\n");

            strcpy(name, "twoscom");
            flag = 0;
            get_inputs(name,flag,result,trmrna,tribo);
            tcom = operate(trmrna,tribo, &acti);
        //tcom = '\0';
            strcpy(result,tcom);
            fprintf(fpnop,"\n The binary value of the %s output is %s", name, tcom);
        //if(flag == 1){
        //value = to_decimal(tcom);
        //fprintf(fpnop,"\n The decimal value of the output is %d", value);
        //}
        //}
        }
        else{

            fprintf(fpnop,"There is a Carry\n");
        }

    }
    else{
         fprintf(fpnop, "There is no Overflow\n");
    }
        if(flag == 1){
            value = to_decimal(result);
            fprintf(fpnop,"\n The decimal value of the output is %d", value);
        }


}

void multiplicationip(char *name, int flag){
        char *result, *tcom;
        int value = 0;
        result = (char *)malloc(sizeof(char)*20);

        number num1, num2;
        num1 = (number)malloc(MAX);
        num2 = (number)malloc(MAX);

        int acti;

        tcom = (char *)malloc(sizeof(char)*20);
        mrna *trmrna = (mrna *)malloc(sizeof(mrna));
        ribosome *tribo = (ribosome *)malloc(sizeof(ribosome));
       /* mrna *rmrna = (mrna * )malloc(sizeof (mrna));
        ribosome *ribo = (ribosome *) malloc (sizeof (ribosome));
        chain peptide_chain;*/

        if(fip1 == NULL)
            printf("\n ERROR -Cannot open the designated file \n");
        else{
            fscanf(fip1, "%s", num1);
        }
        printf("First Number : %s", num1);
        if(fip2 == NULL)
            printf("\n ERROR -Cannot open the designated file \n");
        else{
            fscanf(fip2, "%s", num2);
        }
        printf("Second Number : %s", num2);

        result = get_inputmult(name, flag, num1, num2, &acti);

        if(acti == '1'){
            printf("\n The result is a negative number");
            fprintf(fpn,"%s\n",name);
            strcpy(name, "twoscom");
            flag = 0;
            get_inputs(name,flag,result,trmrna,tribo);
            tcom = operate(trmrna,tribo, &acti);
            value = to_decimal(tcom);
            fprintf(fpnop,"\n The decimal value of multiplication output is: %d",value);
        }
        else{
            value = to_decimal(result);

        fprintf(fpnop,"\n The binary value of multiplication output is %s", result);
        if(flag == 1)
            fprintf(fpnop,"\n The decimal value of multiplication output is %d",value);
        }
}

void divisionip(char *name, int flag){
        char *result, *tcom;
        int value1, value2;
        number num1, num2;
        num1 = (number)malloc(MIN);
        num2 = (number)malloc(MIN);
        result = (char *)malloc(sizeof(char)*20);
        tcom = (char *)malloc(sizeof(char)*20);
        //mrna *trmrna = (mrna *)malloc(sizeof(mrna));
        //ribosome *tribo = (ribosome *)malloc(sizeof(ribosome));
        number remainder = (number)malloc(sizeof(char)*20);

        if(fip1 == NULL)
            printf("\n ERROR -Cannot open the designated file \n");
        else{
            fscanf(fip1, "%s", num1);
        }
        printf("First Number : %s", num1);
        if(fip2 == NULL)
            printf("\n ERROR -Cannot open the designated file \n");
        else{
            fscanf(fip2, "%s", num2);
        }
        printf("Second Number : %s", num2);

        result = get_inputdiv(name, flag, num1, num2, remainder);

        if(!strcmp(result, "00000000")){
            fprintf(fpnop,"The Divisor is larger than Divident. So, the division is done but no change is occurred.");
            fprintf(fpnop,"The Quotient is not present.");
            fprintf(fpnop,"The Remainder is not present.");
        }

        else{
            if(remainder[0] == 'N'){
                fprintf(fpnop,"\n The Remainder is: %s", remainder);
                fprintf(fpddig,"\n The Remainder is: %s",remainder);
            }
            else{
                fprintf(fpnop,"\n The binary value of Remainder is: %s", remainder);
                fprintf(fpddig,"\n The binary value of Remainder is: %s",remainder);
            }

            if(result[0] == 'I'){
                fprintf(fpnop,"\n The Quotient is infinite as the Divisor is 0.");
                fprintf(fpddig,"The Quotient is: %s",result);
            }
            else if(result[0] == 'D'){
                fprintf(fpnop,"\n The Quotient is not present due to division by zero");
                fprintf(fpddig,"\n The Quotient is %s",result);
            }
            else{
                fprintf(fpnop,"\n The binary value of quotient is %s", result);
                fprintf(fpddig,"\n The binary value of quotient is %s",result);
            }

            if(flag == 1){
                if((result[0] != 'I') && (result[0] != 'D')){
                    value1 = to_decimal(result);
                    fprintf(fpnop,"\n The decimal value of quotient is: %d",value1);
                }
                if(remainder[0] != 'N'){
                //value2 = 0;
                    value2 = to_decimal(remainder);
                    fprintf(fpnop,"\n The decimal value of remainder is: %d",value2);
                }
                /*else{
                fprintf(fpnop,"\n The decimal value of remainder is %d",value2);
                }*/
            }
        }
}



void gateip(char *name, int flag){
    char *result;
    //char *tcom, ch1, ch2;
    //int i, value = 0;
	result = (char *)malloc(sizeof(char)*20);

	number num1, num2;
	num1 = (number)malloc(MAX);
	num2 = (number)malloc(MAX);

    int acti;

	mrna *rmrna = (mrna * )malloc(sizeof (mrna));
	ribosome *ribo = (ribosome *) malloc (sizeof (ribosome));
    //tcom = (char *)malloc(sizeof(char)*20);

    /*mrna *trmrna = (mrna *)malloc(sizeof(mrna));
	ribosome *tribo = (ribosome *)malloc(sizeof(ribosome));
    chain peptide_chain;*/

    if(fip1 == NULL)
		printf("\n ERROR -Cannot open the designated file \n");
	else{
        fscanf(fip1, "%s", num1);
    }
	
    printf("First Number : %s", num1);

    if(fip2 == NULL)
		printf("\n ERROR -Cannot open the designated file \n");
	else{
        fscanf(fip2, "%s", num2);
	}
	printf("Second Number : %s", num2);
    get_input_two(name, flag, num1, num2, rmrna, ribo);
    print_mRNA(rmrna);
    print_ribosome(ribo);
    result = operate(rmrna, ribo, &acti);

    fprintf(fpnop,"\n The binary output result of %s operation output is %s", name, result);
}

void gatenot(char *name, int flag){
    char *result;
    result = (char *)malloc(sizeof(char)*20);

    number num1;
    num1 = (number)malloc(MAX);
    int acti;

    mrna *rmrna = (mrna * )malloc(sizeof (mrna));
    ribosome *ribo = (ribosome *) malloc (sizeof (ribosome));

    if(fip1 == NULL)
        printf("\n ERROR -Cannot open the designated file \n");
    else{
        fscanf(fip1, "%s", num1);
    }

    printf("First Number : %s", num1);
    get_input_not(name, flag, num1, rmrna, ribo);
    print_mRNA(rmrna);
    print_ribosome(ribo);
    result = operate(rmrna, ribo, &acti);

    fprintf(fpnop,"\n The binary output result of %s operation output is %s", name, result);
}

int mode_of_operation(){
	int flag;
	char *name, *ch;
	name = (char *)malloc(sizeof(char)*20);
	ch = (char *)malloc(sizeof(char)*4);

	if(fom == NULL)
		printf("\n ERROR -Cannot open the designated file \n");
	else{
		fscanf(fom, "%s", ch);
	}
	flag = atoi(ch);
	printf("\nDecimal (1) or Binary (0) : %d\n", flag);
	
	if(flag == 1 || flag == 0){
		oplist();
		if(fon == NULL)
			printf("\n ERROR -Cannot open the designated file \n");
		else{
			fscanf(fon, "%s", name);
		}
		printf("\nName of the operation : %s", name);
		
        if(!strcmp(name, "and")){
			gateip(name, flag);
		}
		else if(!strcmp(name, "or")){
			gateip(name, flag);
		}
		else if(!strcmp(name, "xor")){
			gateip(name, flag);
		}

        else if(!strcmp(name, "nand")){
            gateip(name, flag);
        }
        else if(!strcmp(name, "nor")){
            gateip(name, flag);
        }
        else if(!strcmp(name, "xnor")){
            gateip(name, flag);
        }

        else if(!strcmp(name, "not")){
            gatenot(name, flag);
        }

        /*Twos complement Operation is called*/
        else if(!strcmp(name, "twoscomplement")){
            strcpy(name, "twoscom");
            twoscomplementip(name, flag);
        }
        /*Comparator operation is called*/
        else if((!strcmp(name, "COMPARATOR" ))||(!strcmp(name, "comparator" ))){
            strcpy(name, "compare");
            comparatorip(name, flag);
        }
        /*Logical Left Shifter operation is called*/
        else if((!strcmp(name, "LOGICALLEFTSHIFT" ))||(!strcmp(name, "logicalleftshift" ))){
            strcpy(name, "lls");
            shiftip(name, flag);
        }

        /*Logical Right Shifter operation is called*/
        else if((!strcmp(name, "LOGICALRIGHTSHIFT" ))||(!strcmp(name, "logicalrightshift" ))){
            strcpy(name, "lrs");
            shiftip(name, flag);
        }

        /*Arithmatic right Shifter operation is called*/
        else if((!strcmp(name, "ARITHMETICSHIFT" ))||(!strcmp(name, "arithmeticshift" ))){
            strcpy(name, "ars");
            shiftip(name, flag);
        }

        /*Circular Right Shifter operation is called*/
        else if((!strcmp(name, "CIRCULARLEFTSHIFT" ))||(!strcmp(name, "circularleftshift" ))){
            strcpy(name, "cls");
            shiftip(name, flag);
        }

        /*Circular Right Shifter operation is called*/
        else if((!strcmp(name, "CIRCULARRIGHTSHIFT" ))||(!strcmp(name, "circularrightshift" ))){
            strcpy(name, "crs");
            shiftip(name, flag);
        }

        /*Addition or Subtraction operation is called*/
        else if((!strcmp(name, "ADDITION" ))||(!strcmp(name, "addition" ))){
            strcpy(name, "add");
            integer_basic_ip(name, flag);
        }
        /*Subtraction operation is called*/
         else if((!strcmp(name, "SUBTRACTION"))||(!strcmp(name, "subtraction"))){
            strcpy(name, "sub");
            integer_basic_ip(name, flag);
        }
        /*Multiplication operation is called*/
        else if(!strcmp(name, "multiplication")){
            strcpy(name, "mult");
            multiplicationip(name, flag);
        }
        /*Division operation is called*/
        else if((!strcmp(name, "division")) || (!strcmp(name, "division"))){
            strcpy(name, "div");
            divisionip(name, flag);
        }
		else 
            printf("Operation name is wrong\n");
		return 0;
	}
	else {
		printf("Flag is not matched \n");
		printf("%d",flag);
		return 1;
	}
	
}

void mode_of_development(){
	printf("It is under development stage\n");
}


void main1(){
	char *result, *mode;
	
	
	mode = (char *)malloc(sizeof(char)*30);
	
	int n, p, q;
	int cond = 1;
	
    p=1;
	n = 1;

    //system("clear");
	while(cond){

        if(n == 1){

			printf("\n Enter the mode of the operation : ");
            n =2;            
            q = mode_of_operation();
            if(q == 1){
                n = menu(p);
            }

			else if(!strcmp(mode, "develop")){
				mode_of_development();
			}

			else{
				printf("Wrong Mode of operation : Try again \n");	
            }
       }
				
        else if(n == 2){
			printf("Exit from the program\n");
            cond = 0;
        }
		
        else if(n==0){
            //return 0;
        }
	
        else {
			printf("Wrong choice \n");
		}
        n = menu(p);
        printf("n = %d\n",n );
        //n = 2;
	}
	
}

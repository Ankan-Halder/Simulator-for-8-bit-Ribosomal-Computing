/*
 Here we prepare the input to create mRNA using this. We adjust the bit if two inputs are not in same lengh using a function 'adjust()'. We convert it into binary number using a function 'get_input()'. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<input.h>
#include<output.h>
#include<binarytype.h>
#include<mrna.h>
#include<ribosome.h>
#include<util.h>
#include <operation.h>
#include <decimaltype.h>

extern FILE *fpn;
extern FILE *fpddig;
extern FILE *fpnop;

extern FILE *fpmrna;
extern FILE *fpmuta;
extern FILE *fpp;

/*
 * This function takes input for four argument from user and prepare it to create mRNA. This function also creates ribosome with proper mutation according to operation.
 * Input -> First input is a string and it is a name of an operation
            Second input is a boolean value used as a flag if inputs are binary or not
            Third one is the string of first input number
            Fourth one is the string of second input number
 * Returns -> Two same length number
 */


void get_input_two(char *name, int flag, number number1, number number2, mrna *omrna, ribosome *oribo) {

    number num1, num2;
    //number temp1, temp2;
    number temp;
    //int i, j;
    int l1, l2;
    int t=0;
    char *opname;

    mrna *rmrnatc = (mrna *) malloc (sizeof(mrna));
	ribosome *ribotc = (ribosome *) malloc (sizeof (ribosome));	

	mrna *rmrnatc1 = (mrna *) malloc (sizeof(mrna));
	ribosome *ribotc1 = (ribosome *) malloc (sizeof (ribosome));

	mrna *rmrnatc2 = (mrna *) malloc (sizeof(mrna));
    ribosome *ribotc2 = (ribosome *) malloc (sizeof (ribosome));

    opname = (char *) malloc (MAX);
	num1 = (number)malloc(sizeof(char)*10);
	num2 = (number)malloc(sizeof(char)*10);

    fprintf(fpddig,"Two numbers provided by the user for performing operation are : %s \t and \t %s\n", number1, number2);

	num1 = adjust(number1, flag, t);
	num2 = adjust(number2, flag, t);

    l1 = strlen(num1);
    l2 = strlen(num2);
	
    printf("\n\nTwo number for comparison : %s %s\n", num1, num2);

    fprintf(fpddig, " '%s' operation is performed on the data\n", name);


	printf("\n Input numbers given : %s %s\n", num1, num2);


   /* if(!(strcmp(name,"sub"))){
            temp = (char *) malloc (sizeof(char)*l2);
            strcpy(temp,num2);
            strcpy(opname,"twoscom");
            flag = 0;
            get_inputs(opname, flag, temp, rmrnatc, ribotc);
            temp = operate(rmrnatc, ribotc);
            strcpy(num2,temp);
            strcpy(name, "add");
            printf("In SUB Operation is changed\n");
            fprintf(fpddig, "In SUB Operation is changed\n");
            fprintf(fpn, " In SUB Operation is changed\n");
        }*/

    if(!(strcmp(name,"add"))){
        mrna mrna1 = get_mrna_for_add(num1, num2);
        *omrna = mrna1;
        ribosome ribosome1 = get_ribosome_with_mutation(name);
        *oribo = ribosome1;
    }

    if(!(strcmp(name,"sub"))){
        printf("\n Operation Name in get input: %s \n \n", name);
        mrna mrna1 = get_mrna_for_sub(num1, num2);
        *omrna = mrna1;
        ribosome ribosome1 = get_ribosome_with_mutation(name);
        *oribo = ribosome1;
    }

    if(!strcmp(name, "compare")){
        mrna mrna1 = get_mrna_for_comparator(num1, num2);
        *omrna = mrna1;
        //print_mRNA(&mrna1);
        ribosome ribosome1 = get_ribosome_with_mutation(name);
        *oribo = ribosome1;
        //fprintf(fpn,"\nRibosome created :%s",oribo->mname);
    }

	if(!strcmp(name,"xor")){
		mrna mrna1 = get_mrna_for_xor(num1, num2);
		*omrna = mrna1;	
		ribosome ribosome1 = get_ribosome_with_mutation(name);
		*oribo = ribosome1;
	}

	if(!strcmp(name,"and")){
		mrna mrna1 = get_mrna_for_and(num1, num2);
		*omrna = mrna1; 	
		ribosome ribosome1 = get_ribosome_with_mutation(name);
		*oribo = ribosome1;
	}

	if(!strcmp(name,"or")){
		mrna mrna1 = get_mrna_for_or(num1, num2);
		*omrna = mrna1;	
		ribosome ribosome1 = get_ribosome_with_mutation(name);
		*oribo = ribosome1;
	}

    if(!strcmp(name,"xnor")){
        mrna mrna1 = get_mrna_for_xor(num1, num2);
        *omrna = mrna1;
        ribosome ribosome1 = get_ribosome_with_mutation(name);
        *oribo = ribosome1;
    }

    if(!strcmp(name,"nand")){
        mrna mrna1 = get_mrna_for_and(num1, num2);
        *omrna = mrna1;
        ribosome ribosome1 = get_ribosome_with_mutation(name);
        *oribo = ribosome1;
    }

    if(!strcmp(name,"nor")){
        mrna mrna1 = get_mrna_for_or(num1, num2);
        *omrna = mrna1;
        ribosome ribosome1 = get_ribosome_with_mutation(name);
        *oribo = ribosome1;
    }
}


/*
 * This function takes input for four argument from user and prepare it to create mRNA. This function also creates ribosome with proper mutation according to operation.
 * Input -> First input is a string and it is a name of an operation
            Second input is a boolean value used as a flag if inputs are binary or not
            Third one is the string of first input number
            Fourth is the referance of a blank mRNA
            Fifth is the referance of a blank Ribosome
 * Returns -> The mRNA and the Ribosome for NOT gate operation
 */


void get_input_not(char *name, int flag, number number1, mrna *omrna, ribosome *oribo) {

    number num1;
    //number temp1, temp2;
    //number temp;
    //int i, j;
    int l1;
    int t=0;
    //char *opname;

    //opname = (char *) malloc (MAX);
    num1 = (number)malloc(sizeof(char)*10);
    fprintf(fpddig,"Two number provided by the user for performing operation are : %s \t \n", number1);

    num1 = adjust(number1, flag, t);
    l1 = strlen(num1);

    printf("\n\nTwo number for comparison : %s\n", num1);
    fprintf(fpddig, " %s operation is performed on the data\n", name);
    printf("\n Input number given : %s \n", num1);

        mrna mrna1 = get_mrna_for_not(num1);
        *omrna = mrna1;
        ribosome ribosome1 = get_ribosome_with_mutation(name);
        *oribo = ribosome1;
}



/*
 * This function takes input for four argument from user and prepare it to create mRNA. This function also creates ribosome with proper mutation according to operation.
 * Input -> First input is a string and it is a name of an operation
            Second input is a boolean value used as a flag if inputs are binary or not
            Third one is the string of first input number
            Fourth is the referance of a blank mRNA
            Fifth is the referance of a blank Ribosome
 * Returns -> The mRNA and the Ribosome for shift operation
 */


void get_input_one(char *name, int flag, number number, mrna *omrna, ribosome *oribo) {
    char *num;
    //int i, j;
    int l, t=0;
    char *opname;
    opname = (char *) malloc (MAX);
    num = (char *)malloc(sizeof(char)*10);

    num = adjust(number, flag, t);
    l = strlen(num);

    printf("Input number for shifting : %s \n", num);
    fprintf(fpn,"Input number for shifting : %s \n", num);
    printf("Input number for shifting : %s \n", num);
    mrna mrna1 = get_mrna_for_shift(num, name);
    *omrna = mrna1;
    //print_mRNA(&mrna1);
    ribosome ribosome1 = get_ribosome_with_mutation(name);
    *oribo = ribosome1;    
    //fprintf(fpn,"Ribosome created :%s",oribo->mname);
}


/*
 * This function takes input for six argument from user and prepare it to create mRNA. This function also creates ribosome with proper mutation according to operation.
 * Input -> First input is a string and it is a name of an operation
            Second input is a boolean value used as a flag if inputs are binary or not
            Third one is the string of first input number
            Fourth one is the string of second input number
        Fifth one is the pointer of a mRNA
        Sixth one is the pointer of a Ribosome
 * Returns -> The proper mRNA and Ribosome through the variable sent by the main function
 */

void get_inputs(char *name, int flag, number number1, mrna *omrna, ribosome *oribo) {
    number num;
    //int i, j;
    int t=1;
    num = (number)malloc(sizeof(char)*10);
    num = adjust(number1, flag, t);
    printf("\nNumber : %s\n",num);
    fprintf(fpddig,"The number provided by the user for performing operation is : %s \t \n", num);
    fprintf(fpddig, " '%s' operation is performed on the data\n", name);

    if(!strcmp(name,"twoscom")){
        mrna mrna1 = get_mrna_for_twoscom(num);
        *omrna = mrna1;
        ribosome ribosome1 = get_ribosome_with_mutation(name);
        *oribo = ribosome1;
    }

}

/*
 * This function takes input for four argument from user and prepare it to create mRNA. This function also creates ribosome with proper mutation according to operation. Then perform the multiplication operation by executing the operations repetatively according to booths algorithm for multiplication for two 8 bit number
 * Input -> First input is a string and it is a name of an operation
            Second input is a boolean value used as a flag if inputs are binary or not
            Third one is the string of first input number
            Fourth one is the string of second input number
 * Returns -> The result of multiplication to the main function
 */

char *get_inputmult(char *name, int flag, char *number1, char *number2, int *actimult){
    number num1, num2, numP, numA;
    number temp1, temp2;
    int i, j, x, l1, l2, t=0;
    char *opname, *activemutaname, *result;

    int acti;

    opname = (char *) malloc (MAX);
    activemutaname = (char *) malloc (MIN);

    mrna *rmrnatc1 = (mrna *) malloc (sizeof(mrna));
    ribosome *ribotc1 = (ribosome *) malloc (sizeof (ribosome));

    mrna *rmrnatc2 = (mrna *) malloc (sizeof(mrna));
    ribosome *ribotc2 = (ribosome *) malloc (sizeof (ribosome));



    num1 = (number)malloc(sizeof(char)*10);
    num2 = (number)malloc(sizeof(char)*10);

    num1 = adjust(number1, flag, t);
    num2 = adjust(number2, flag, t);

    l1 = strlen(num1);
    l2 = strlen(num2);

    if (number1[0]=='-'){
        temp1 = (number)malloc(sizeof(char)*l1);
        strcpy(temp1,num1);

        strcpy(opname,"twoscom");
        flag = 0;
        get_inputs(opname, flag, temp1, rmrnatc1, ribotc1);
        temp1 = operate(rmrnatc1, ribotc1, &acti);
        strcpy(num1,temp1);
    }

    if(number2[0]=='-'){
        temp2 = (char *)malloc(sizeof(char)*l2);
        strcpy(temp2,num2);
        strcpy(opname,"twoscom");
        flag = 0;
        get_inputs(opname, flag, temp2, rmrnatc2, ribotc2);
        temp2 = operate(rmrnatc2, ribotc2, &acti);
        strcpy(num2,temp2);
    }

    printf("\n Input numbers given : %s %s\n", num1, num2);
    fprintf(fpddig,"Two numbers provided by the user for performing operation are : %s \t and \t %s\n", num1, num2);
    fprintf(fpddig, " '%s' operation is performed on the data\n", name);

    numA = (number)malloc(l1+l2+2);
    numP = (number)malloc(l1+l2+2);

    for(i=0, j=0; j<l1; j++){
        numA[i++] = num1[j];
    }
    for(j=0; j<l2; j++){
        numA[i++] = '0';
    }
    numA[i++] = '0';
    numA[i] = '\0';
    for(i=0, j=0; j<l1; j++){
        numP[i++] = '0';
    }
    for(j=0; j<l2; j++){
        numP[i++] = num2[j];
    }
    numP[i++] = '0';
    numP[i] = '\0';

    for(x=0; x<8; x++) {

        printf("\nThe operation time %d", x);
        printf("\n Input numbers given A:= %s and P:= %s\n", numA, numP);

        fprintf(fpmrna,"Number of iteration is %d in the multiplication \n",x);
        fprintf(fpmrna, "-------------------------------------------------------------- \n");
        fprintf(fpmuta,"Number of iteration is: %d in the multiplication \n",x);
        fprintf(fpmuta, "-------------------------------------------------------------- \n");
        fprintf(fpp, "Number of iteration is: %d in the multiplication \n",x);
        fprintf(fpp, "-------------------------------------------------------------- \n");

        mrna *rmrnad = (mrna *) malloc (sizeof(mrna));
        ribosome *ribod = (ribosome *) malloc (sizeof (ribosome));

        mrna *rmrnashift = (mrna *) malloc (sizeof(mrna));
        ribosome *riboshift = (ribosome *) malloc (sizeof (ribosome));

        mrna *rmrnaadd = (mrna *) malloc (sizeof(mrna));
        ribosome *riboadd = (ribosome *) malloc (sizeof (ribosome));

        mrna *rmrnasub = (mrna *) malloc (sizeof(mrna));
        ribosome *ribosub = (ribosome *) malloc (sizeof (ribosome));

        mrna *rmrnasame = (mrna *) malloc (sizeof(mrna));
        ribosome *ribosame = (ribosome *) malloc (sizeof (ribosome));

        mrna mrna1 = get_mrna_decision_for_mult(numP);
        *rmrnad = mrna1;
        print_mRNA(rmrnad);
        strcpy(name, "multd");
        ribosome ribosome1 = get_ribosome_with_mutation(name);

        *ribod = ribosome1;
        print_ribosome(ribod);
        activemutaname = operate(rmrnad,ribod, &acti);
        printf("The decision mRNA activates mutation : %s", activemutaname);

        if(strcmp(activemutaname, "M_L^{add}")==0){

            mrna mrnaadd = get_mrna_for_add(numP, numA);
            *rmrnaadd = mrnaadd;
            print_mRNA(rmrnaadd);

            strcpy(name, "add");
            ribosome ribosomeadd = get_ribosome_with_mutation(name);

            *riboadd = ribosomeadd;
            print_ribosome(riboadd);
            printf("The additon of two number P : %s and S : %s is ", numP, numA);
            numP = operate(rmrnaadd,riboadd, &acti);
            printf("The number after addition is : %s\n\n", numP);
        }

        else if(strcmp(activemutaname, "M_L^{sub}")==0){
            mrna mrnasub = get_mrna_for_sub(numP, numA);
            *rmrnasub = mrnasub;
            print_mRNA(rmrnasub);

            strcpy(name, "sub");
            ribosome ribosomesub = get_ribosome_with_mutation(name);

            *ribosub = ribosomesub;
            print_ribosome(ribosub);
            numP = operate(rmrnasub,ribosub, &acti);
            printf("\nThe number after subtraction is : %s\n", numP);
        }
        else if(strcmp(activemutaname, "M_d^{mult}")==0){
            mrna mrnasame = get_mrna_for_multsame(numP, numA);
            *rmrnasame = mrnasame;
            print_mRNA(rmrnasame);

            strcpy(name, "multsame");
            ribosome ribosomesame = get_ribosome_with_mutation(name);
            *ribosame = ribosomesame;
            print_ribosome(ribosame);
            numP = operate(rmrnasame, ribosame, &acti);
            printf("\nThe number remain same and it is : %s\n", numP);
        }

        mrna mrnashift1 = get_mrna_shift_for_mult(numP);
        *rmrnashift = mrnashift1;

        print_mRNA(rmrnashift);

        strcpy(name, "multshift");

        ribosome ribosomeshift1 = get_ribosome_with_mutation(name);
        *riboshift = ribosomeshift1;
        print_ribosome(riboshift);

        numP = operate(rmrnashift,riboshift, &acti);
        printf("The number after shifting : %s", numP);



        fprintf(fpmrna, "******************************************************************************* \n\n");
        fprintf(fpmuta, "******************************************************************************* \n\n");
        fprintf(fpp, "******************************************************************************* \n\n");

    } /* End of all interation in multiplication*/

    for(i=0; i<l1;i++){
        if(numP[i] == '1'){
        *actimult = acti;
            fprintf(fpnop,"\n Data Overflow in multiplication \n");
            break;
        }
    }

    result=(char *)malloc(sizeof(char)*20);
    for(i=l1,j=0; i<(l1+l2); i++,j++)
        result[j]=numP[i];
    result[j] = '\0';

    return result;

}

/*
 * This function takes five inputs and generates the remainder and quotientas output. Based on the condition a set of operation is performed in a repititive manner. To perform an operation the mRNA and ribosome is created. Then the function return the quotient and the remainder to the main funtion. This funtion operate on 8 bit number.
 * Input -> First input is a string and it is a name of an operation
        Second input is a boolean value used as a flag if inputs are binary or not
        Third one is the string of first input number
        Fourth one is the string of second input number
        Fifth one is the string of remainder which is send by the main function
 * Returns -> The result of division to the main function
*/

char *get_inputdiv(char *name, int flag, char *number1, char *number2, char *rem){

    number num1, num2, numR, numD, numQ;
    number temp1, temp2;
    int i, j, x, l1, l2, t=0, rempres = 1, dz=0, dv=0;
    char *opname, *activemutaname, *result;

    int acti;

    opname = (char *) malloc (MAX);
    activemutaname = (char *) malloc (MIN);

    mrna *rmrnatc1 = (mrna *) malloc (sizeof(mrna));
    ribosome *ribotc1 = (ribosome *) malloc (sizeof (ribosome));

    mrna *rmrnatc2 = (mrna *) malloc (sizeof(mrna));
    ribosome *ribotc2 = (ribosome *) malloc (sizeof (ribosome));



    num1 = (number)malloc(sizeof(char)*10);
    num2 = (number)malloc(sizeof(char)*10);

    num1 = adjust(number1, flag, t);
    num2 = adjust(number2, flag, t);

    l1 = strlen(num1);
    l2 = strlen(num2);

    if (number1[0]=='-'){
        temp1 = (number)malloc(sizeof(char)*l1);
        strcpy(temp1,num1);

        strcpy(opname,"twoscom");
        flag = 0;
        get_inputs(opname, flag, temp1, rmrnatc1, ribotc1);
        temp1 = operate(rmrnatc1, ribotc1, &acti);
        strcpy(num1,temp1);
    }

    if(number2[0]=='-'){
        temp2 = (char *)malloc(sizeof(char)*l2);
        strcpy(temp2,num2);
        strcpy(opname,"twoscom");
        flag = 0;
        get_inputs(opname, flag, temp2, rmrnatc2, ribotc2);
        temp2 = operate(rmrnatc2, ribotc2, &acti);
        strcpy(num2,temp2);
    }

    printf("\n Input numbers given : %s %s\n", num1, num2);
    fprintf(fpddig,"Two numbers provided by the user for performing operation are : %s \t and \t %s\n", num1, num2);
    fprintf(fpddig, " '%s' operation is performed on the data\n", name);

    numQ = (number)malloc(sizeof(char)*(l1+2));
    numR = (number)malloc(sizeof(char)*(l1+l2+2));
    numD = (number)malloc(sizeof(char)*(l1+l2+2));

    for(i=0; i<l1; i++){
        numQ[i] = '0';
    }
    numQ[i] = '\0';

    if(strcmp(num1, "00000000")==0){
        dz=1;
        rempres = 0;
    }

    if(strcmp(num2, "00000000")==0){
        dv=1;
        rempres = 0;
    }

    if(dz == 0 && dv == 0){

    for(i=0, j=0; j<l1; j++){
        numR[i++] = '0';
    }
    for(j=0; j<l2; j++){
        numR[i++] = num1[j];
    }
    numR[i] = '\0';

    for(i=0, j=0; j<l1; j++){
        numD[i++] = num2[j];
    }
    for(j=0; j<l2; j++){
        numD[i++] = '0';
    }
    numD[i] = '\0';

    for(x=0; x<l1; x++){
        printf("\nThe operation time %d", x);

        printf("\n Input numbers given Divident:= %s and Divisior:= %s\n", numR, numD);

        fprintf(fpmrna,"Number of iteration is %d in the division \n",x);
        fprintf(fpmrna, "-------------------------------------------------------------- \n");
        fprintf(fpmuta,"Number of iteration is: %d in the division \n",x);
        fprintf(fpmuta, "-------------------------------------------------------------- \n");
        fprintf(fpp, "Number of iteration is: %d in the division \n",x);
        fprintf(fpp, "-------------------------------------------------------------- \n");
        fprintf(fpddig, "\n\nNumber of iteration is: %d in the division", x);
        fprintf(fpddig, "-------------------------------------------------------------- \n");

        mrna *rmrnad = (mrna *) malloc (sizeof(mrna));
        ribosome *ribod = (ribosome *) malloc (sizeof (ribosome));

        mrna *rmrnashiftd = (mrna *) malloc (sizeof(mrna));
        ribosome *riboshiftd = (ribosome *) malloc (sizeof (ribosome));

        mrna *rmrnashiftq = (mrna *) malloc (sizeof(mrna));
        ribosome *riboshiftq = (ribosome *) malloc (sizeof (ribosome));

        mrna *rmrnasub = (mrna *) malloc (sizeof(mrna));
        ribosome *ribosub = (ribosome *) malloc (sizeof (ribosome));

        mrna *rmrnasame = (mrna *) malloc (sizeof(mrna));
        ribosome *ribosame = (ribosome *) malloc (sizeof (ribosome));

        mrna mrnashiftd1 = get_mrna_shift_for_div(numD);	//Shift the divisor
        *rmrnashiftd = mrnashiftd1;
        print_mRNA(rmrnashiftd);

        strcpy(name, "divshift");

        ribosome ribosomeshiftd = get_ribosome_with_mutation(name);
        *riboshiftd = ribosomeshiftd;
        print_ribosome(riboshiftd);

        numD = operate(rmrnashiftd,riboshiftd, &acti);
        printf("The number after shifting : %s", numD);

        fprintf(fpddig, "\nThe Remainder is %s \n", numR);
        fprintf(fpddig, "The Divisor is %s \n", numD);

        if(rempres == 1){
            mrna mrna1 = get_mrna_decision_for_div(numD, numR);
            *rmrnad = mrna1;
            print_mRNA(rmrnad);

            strcpy(name, "divd");

            ribosome ribosome1 = get_ribosome_with_mutation(name);
            *ribod = ribosome1;
            print_ribosome(ribod);

            activemutaname = operate(rmrnad,ribod, &acti);
            printf("The decision mRNA activates mutation : %s\n\n", activemutaname);
            fprintf(fpdbio,"\nActivated Mutation is %s\n", activemutaname);
            fprintf(fpddig,"\nActivated Mutation is %s\n", activemutaname);

            if(strcmp(activemutaname, "M_{sub}^{div}")==0){

                mrna mrnasub = get_mrna_for_sub(numR, numD);
                *rmrnasub = mrnasub;
                print_mRNA(rmrnasub);

                strcpy(name, "sub");

                ribosome ribosomesub = get_ribosome_with_mutation(name);
                *ribosub = ribosomesub;
                print_ribosome(ribosub);

                printf("The subtraction of two number R : %s and D : %s is ", numR, numD);
                numR = operate(rmrnasub,ribosub, &acti);
                printf("The number after subtraction is : %s\n\n", numR);
                //rempres = 0;
                fprintf(fpdbio, "\nSubtraction is done as the remainder is greater than divisor\n");
                fprintf(fpddig, "\nSubtraction is done as the remainder is greater than divisor\n");
            }

            else if(strcmp(activemutaname, "M_c^{div}")==0){
                mrna mrnasub1 = get_mrna_for_sub(numR, numD);
                *rmrnasub = mrnasub1;
                print_mRNA(rmrnasub);

                strcpy(name, "sub");

                ribosome ribosomesub = get_ribosome_with_mutation(name);
                *ribosub = ribosomesub;
                print_ribosome(ribosub);

                numR = operate(rmrnasub,ribosub, &acti);
                printf("\nThe number after subtraction is : %s\n", numR);
                //value = 0;
                rempres = 0;
                strcpy(activemutaname, "M_{sub}^{div}");

                fprintf(fpdbio, "\nSubtraction is done as the remainder is similar to divisor or divisor is 0\n");
                fprintf(fpddig, "\nSubtraction is done as the remainder is similar to divisor or divisor is 0\n");
            }

            else if(strcmp(activemutaname, "M_d^{div}")==0){
                mrna mrnasame2 = get_mrna_for_divsame2(numR, numD);
                *rmrnasame = mrnasame2;
                print_mRNA(rmrnasame);

                strcpy(name, "divsame");

                ribosome ribosomesame = get_ribosome_with_mutation(name);
                *ribosame = ribosomesame;
                print_ribosome(ribosame);

                numR = operate(rmrnasame,ribosame, &acti);
                printf("\nThe number reamin same. Remainder is : %s\n", numR);

                fprintf(fpdbio, "\nThe number is kept same for the operation\n");
                fprintf(fpddig, "\nThe number is kept same for the operation\n");
                //value = 0;
            }
        }

        printf("\n\nQuotient %s", numQ);
        mrna mrnashiftq1 = get_mrna_shift_for_quot(numQ, activemutaname);	//Shift the quotient
        *rmrnashiftq = mrnashiftq1;
        print_mRNA(rmrnashiftq);

        strcpy(name, "quotshift");

        ribosome ribosomeshiftq = get_ribosome_with_mutation(name);
        *riboshiftq = ribosomeshiftq;
        print_ribosome(riboshiftq);

        numQ = operate(rmrnashiftq,riboshiftq, &acti);
        printf("The number after shifting : %s", numQ);
        fprintf(fpdbio, "\nThe quotient is %s\n", numQ);
        fprintf(fpddig, "\nThe quotient is %s\n", numQ);

        /*if(!strcmp(activemutaname, "M_c^{div}")){
            //x = 8;
            rempres = 0;
        }
        else {
            rempres = 1;
        }*/
        if(rempres == 0){
            strcpy(activemutaname, "M_c^{div}");
        }
    }

    }/*End of Division Operation*/

    if (rempres == 1){
        result=(char *)malloc(sizeof(char)*20);
        for(i=l1,j=0; i<=(l1+l2); i++,j++)
            rem[j]=numR[i];
        rem[j] = '\0';
    }
    else{
        result=(char *)malloc(sizeof(char)*20);
        /*for(i=l1,j=0; i<=(l1+l2); i++,j++)
            rem[j]='0';
        rem[j] = '\0';*/
        strcpy(rem, "Not-Present");
    }
    //*rem = numR;

    if((dz==0) && (dv ==0)){
        for(i=0; i<l1; i++)
            result[i]=numQ[i];
        result[i] = '\0';
    }

    else if(dz==1){
        strcpy(result,"Div-by-0");
    }
    else if (dv==1){
        strcpy(result, "Infinity");
    }
    fprintf(fpnop, "\nThe Quotient is: %s", result);
    return result;
}


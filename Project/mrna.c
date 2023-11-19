/* Here we implement mRNA for a specific operation. Three types of structures are mentioned here. The mRNA for logic gates are created using 'get_interleaved()' function. The 2's complement function is created using 'get_singlebit_interleaved()' function. To implement mRNA for comparator function 'get_reverse_interleaved()' is used. Function 'get_interleaved()' and 'get_reverse_interleaved()' both take two inputs number where 'get_singlebit_interleaved()' function takes one input number.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mrna.h>
#include<util.h>

/*
 * This function creates mRNA from two number in bit inter leaved fashion in reverse direction. Useful for comparator.
 * Input : num1 -> First input number in binary format
 *         num2 -> Second input number in binary format
 * Returns : Created mRNA
 */

mrna get_interleaved(char *num1, char *num2, char *opname){
	int i, k=0, n, j, m=0, l=0;
	char *ip;

	ip = (char *)malloc(sizeof(char)*40);
	
    printf("1st number(P) : %s and 2nd number(A) : %s\n", num1, num2);
	n = strlen(num1);
	printf("Length of the first number is %d\n", n);
	l = 10 + n*8;
	printf("The allocated space for the mRNA %d\n", l);

	mrna reporter_mrna = (char **)malloc(sizeof(char *)*l);

	for(i=0;i<l;i++)
		reporter_mrna[i] = (char *)malloc(sizeof(char)*30);
	
    if(!strcmp(opname, "add"))
        reporter_mrna[k++] = "SD_add";
    else if(!strcmp(opname, "sub"))
        reporter_mrna[k++] = "SD_sub";
    else if(!strcmp(opname, "multsame"))
        reporter_mrna[k++] = "SD_multsame";
    else if(!strcmp(opname, "divd"))
        reporter_mrna[k++] = "SD_divd";
    else if(!strcmp(opname, "divsame{M_c}"))
        reporter_mrna[k++] = "SD_divsame";
    else if(!strcmp(opname, "divsame{M_d}"))
        reporter_mrna[k++] = "SD_divsame";

	if(!strcmp(opname, "and")){
		reporter_mrna[k++] = "SD_and";
		m=2;
	}
	else if(!strcmp(opname, "or")){
		reporter_mrna[k++] = "SD_or";
		m=2;
	}
	else if(!strcmp(opname, "xor")){
		reporter_mrna[k++] = "SD_xor";
		m=2;
	}

    else if(!strcmp(opname, "nand")){
        reporter_mrna[k++] = "SD_nand";
        m=2;
    }
    else if(!strcmp(opname, "nor")){
        reporter_mrna[k++] = "SD_nor";
        m=2;
    }
    else if(!strcmp(opname, "xnor")){
        reporter_mrna[k++] = "SD_xnor";
        m=2;
    }
	
	printf("\n Operational identifier : %s\n", reporter_mrna[0]);

	reporter_mrna[k++] = "AUG";	

    if((strcmp (opname, "add"))==0){
            reporter_mrna[k++] = "Activator_of_M_L^{add}";
            m=1;
    }

    else if((strcmp (opname, "sub"))==0){
        reporter_mrna[k++] = "Activator_of_M_L^{sub}";
        m=1;
    }
    else if((strcmp (opname, "multsame"))==0){
        reporter_mrna[k++] = "M_d^{mult}";
        m=0;
    }

    else if((strcmp (opname, "divd"))==0){
        reporter_mrna[k++] = "Activator_of_M_m^{div}";
    }
     else if((strcmp (opname, "divsame{M_c}"))==0){
        reporter_mrna[k++] = "Activator_of_M_c^{div}";
        m=0;
    }

    else if((strcmp (opname, "divsame{M_d}"))==0){
        reporter_mrna[k++] = "Activator_of_M_d^{div}";
        m=0;
    }

    if (!strcmp(reporter_mrna[0], "SD_divd")){
            for(i=0;i<n;i++){
                reporter_mrna[k++] = "SecM";
                if(num1[i]=='0'){
                    reporter_mrna[k++] = "B_1B_2B_3";
                }
                else{
                    reporter_mrna[k++] = "B_4B_5B_6";
                }

                if(num2[i]=='0'){
                    reporter_mrna[k++] = "B_1B_2B_3";
                }
                else{
                    reporter_mrna[k++] = "B_4B_5B_6";
                }

                reporter_mrna[k++] = "SecA";
            }
    }

			
    else{
        strcpy(ip, "");
        for(i=n-1;i>=0;i--){
            reporter_mrna[k++] = "SecM";

            if(num1[i]=='0'){
                reporter_mrna[k++] = "B_1B_2B_3";
                strcat(ip, "B_1B_2B_3");
            }
            else{
                reporter_mrna[k++] = "B_4B_5B_6";
                strcat(ip, "B_4B_5B_6");
            }

            if(num2[i]=='0'){
                reporter_mrna[k++] = "B_1B_2B_3";
                strcat(ip, "B_1B_2B_3");
            }
            else{
                reporter_mrna[k++] = "B_4B_5B_6";
                strcat(ip, "B_4B_5B_6");
            }

            reporter_mrna[k++] = "SecA";

            reporter_mrna[k++] = "B_4B_5B_6";
            reporter_mrna[k++] = "B_1B_2B_3";
            if(m==1){
                reporter_mrna[k++] = "SM_(S_A)";
                reporter_mrna[k++] = "SM_(S_L)";
            }
            else if(m==0){
                reporter_mrna[k++] = "SM";
            }
            else if(m==2){
                if(!(strcmp(opname, "xor"))){

                    if(!(strcmp(ip, "B_1B_2B_3B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_2";
                    }
                    if(!(strcmp(ip, "B_1B_2B_3B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_3";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_5";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_8";
                    }
                }

                if(!(strcmp(opname, "and"))){

                    if(!(strcmp(ip, "B_1B_2B_3B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_2";
                    }
                    if(!(strcmp(ip, "B_1B_2B_3B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_4";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_6";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_7";
                    }
                }

                if(!(strcmp(opname, "or"))){

                    if(!(strcmp(ip, "B_1B_2B_3B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_2";
                    }
                    if(!(strcmp(ip, "B_1B_2B_3B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_3";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_5";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_7";
                    }
                }

                if(!(strcmp(opname, "xnor"))){

                    if(!(strcmp(ip, "B_1B_2B_3B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_1";
                    }
                    if(!(strcmp(ip, "B_1B_2B_3B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_4";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_6";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_7";
                    }
                }

                if(!(strcmp(opname, "nand"))){

                    if(!(strcmp(ip, "B_1B_2B_3B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_1";
                    }
                    if(!(strcmp(ip, "B_1B_2B_3B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_3";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_5";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_8";
                    }
                }

                if(!(strcmp(opname, "nor"))){

                    if(!(strcmp(ip, "B_1B_2B_3B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_1";
                    }
                    if(!(strcmp(ip, "B_1B_2B_3B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_4";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_1B_2B_3"))){
                        reporter_mrna[k++]="SM_6";
                    }
                    if(!(strcmp(ip, "B_4B_5B_6B_4B_5B_6"))){
                        reporter_mrna[k++]="SM_8";
                    }
                }

            }
            strcpy(ip, "");
        }
    }
    reporter_mrna[k] = "UAA";	
	printf("\nThe value of K after the operation on a double bit%d\n",k);	
	return reporter_mrna;
}

/*
 * This function used to create mRNA from a two input numbers in reverse order. Useful for comparator logic.
 * Input : num1 -> First Input number in binary format
 *         num2 -> Second Input number in binary format
 * Returns : Created mRNA
 */

mrna get_reverse_interleaved(char *num1, char *num2){
    int i, k=0, n, l=0;

    n=strlen(num1);
    l = 10 + n*8;
    printf("Allocated space for mRNA is %d\n", l);
    mrna reporter_mrna = (char **)malloc(sizeof(char *)*l);

    for(i=0;i<l;i++)
        reporter_mrna[i] = (char *)malloc(sizeof(char)*30);

    reporter_mrna[k++] = "SD_comparator";
    reporter_mrna[k++] = "AUG";
    reporter_mrna[k++] = "Activator_of_CM_1";

    for(i=0;i<n;i++){
        reporter_mrna[k++]="SecM";

        if(num1[i]=='0')
            reporter_mrna[k++] = "B_1B_2B_3";
        else
            reporter_mrna[k++] = "B_4B_5B_6";

        if(num2[i]=='0')
            reporter_mrna[k++] = "B_1B_2B_3";
        else
            reporter_mrna[k++] = "B_4B_5B_6";

        reporter_mrna[k++] = "SecA";
        reporter_mrna[k++] = "B_1B_2B_3";
        reporter_mrna[k++] = "B_4B_5B_6";
        reporter_mrna[k++] = "B_7B_8B_9";
    }

    reporter_mrna[k]="UAA";
    printf("\n Number of codon present inthe mRNA is %d", k);
    i=0;
    return reporter_mrna;
}

/*
 * This function creates mRNA from single number num. Useful for Logical Left shift, Logical Right shift, Arithmetic left shift, Arithmetic right hift, Circular left shift, Circular right shift.
 * Input : num -> Input number in binary format
 * Returns : Created mRNA
 */

mrna get_singlebit(char *num, char *name){

    int i, k=0, n, l = 0;
    printf("\n NAME of operation %s \n", name);
    n=strlen(num);
    printf("n : %d\n",n);
     mrna reporter_mrna;
    char *ip;
    ip = (char *)malloc(sizeof(char)*20);


    if(!(strcmp(name, "not"))){
        l = 10 + n*8;
        reporter_mrna = (char **)malloc(sizeof(char *)*l);

        for(i=0;i<l;i++){
            reporter_mrna[i] = (char *)malloc(sizeof(char)*40);
        }
        reporter_mrna[k++] = "SD_not";
        reporter_mrna[k++] = "AUG";
        strcpy(ip,"");
        for(i=n-1;i>=0;i--){

            reporter_mrna[k++] = "SecM";
            if(num[i] == '0'){
                strcpy(ip, "B_1B_2B_3");
                reporter_mrna[k++]="B_1B_2B_3";
                reporter_mrna[k++]="B_1B_2B_3";
            }
            else{
                strcpy(ip, "B_4B_5B_6");
                reporter_mrna[k++]="B_4B_5B_6";
                reporter_mrna[k++]="B_4B_5B_6";
            }
            reporter_mrna[k++] = "SecA";

            reporter_mrna[k++] = "B_4B_5B_6";
            reporter_mrna[k++] = "B_1B_2B_3";


            if(!(strcmp(ip, "B_1B_2B_3"))){
                reporter_mrna[k++]="SM_1";
            }
            if(!(strcmp(ip, "B_4B_5B_6"))){
                reporter_mrna[k++]="SM_8";
            }
            strcpy(ip,"");
        }

        //reporter_mrna[k]="UAA";
    }

    else{
        l = 10 + n*1;
        reporter_mrna = (char **)malloc(sizeof(char *)*l);

        for(i=0;i<l;i++){
            reporter_mrna[i] = (char *)malloc(sizeof(char)*20);
        }

        reporter_mrna[k++] = "SD_shift";
        reporter_mrna[k++] = "AUG";

        if(!strcmp("lls", name) || !strcmp("als", name)){
            for(i=1;i<n;i++){
                if(num[i]=='0')
                    reporter_mrna[k++] = "B_1B_2B_3";
                else
                    reporter_mrna[k++] = "B_4B_5B_6";
            }
            reporter_mrna[k++] = "B_1B_2B_3";
        }

        else if(!strcmp("lrs", name)){
            reporter_mrna[k++] = "B_1B_2B_3";
            for(i=0;i<n-1;i++){
                if(num[i]=='0')
                    reporter_mrna[k++] = "B_1B_2B_3";
                else
                    reporter_mrna[k++] = "B_4B_5B_6";
            }
        }

        else if(!strcmp("ars", name)){
            if(num[0] == '0')
                reporter_mrna[k++] = "B_1B_2B_3";
            else if(num[0] == '1')
                reporter_mrna[k++] = "B_4B_5B_6";

            for(i=0;i<n-1;i++){
                if(num[i]=='0')
                    reporter_mrna[k++] = "B_1B_2B_3";
                else if(num[i]=='1')
                    reporter_mrna[k++] = "B_4B_5B_6";
            }
        }

        else if(!strcmp("cls", name)){
            for(i=1;i<n-1;i++){
                if(num[i]=='0')
                    reporter_mrna[k++] = "B_1B_2B_3";
                else
                    reporter_mrna[k++] = "B_4B_5B_6";
            }
            if(num[0]=='0')
                reporter_mrna[k++] = "B_1B_2B_3";
            else if(num[0] == '1')
                reporter_mrna[k++] = "B_4B_5B_6";
        }

        else if(!strcmp("crs", name)){
            if(num[n-1]=='0')
                reporter_mrna[k++] = "B_1B_2B_3";
            else if(num[n-2]=='1')
                reporter_mrna[k++] = "B_4B_5B_6";

            for(i=0;i<n-1;i++){
                if(num[i]=='0')
                    reporter_mrna[k++] = "B_1B_2B_3";
                else
                    reporter_mrna[k++] = "B_4B_5B_6";
            }
        }

    }
     reporter_mrna[k]="UAA";
    return reporter_mrna;
}

/*
 *This function creates mRNA from a single number in reverse order. This function is useful for twoscomplement, shift in multiplication, decision in multiplication, shift in division.
 * Input: Input number -> num1
 * Return: output -> reporter mRNA
 */

mrna get_single(char *num1, char *name){
    int i, k=0, n, l=0;
    mrna reporter_mrna;
    n = strlen(num1);

    if(!strcmp(name, "twoscom")){
        l = 10 + (n*7);
        printf("Space required for mRNA for twoscomplement %d string\n", l);
        reporter_mrna = (char **)malloc(sizeof(char *)*l);

        for(i=0;i<l;i++)
            reporter_mrna[i] = (char *)malloc(sizeof(char)*25);

        reporter_mrna[k++] = "SD_twoscom";
        reporter_mrna[k++]="AUG";
        reporter_mrna[k++]="Activator_of_C_1";

        for(i=n-1;i>=0;i--){

            reporter_mrna[k++]="SecM";
            if(num1[i]=='0'){
                reporter_mrna[k++] = "B_1B_2B_3";
            }
            else{
                reporter_mrna[k++] = "B_4B_5B_6";
            }

            reporter_mrna[k++] = "SecA";
            reporter_mrna[k++] = "B_4B_5B_6";
            reporter_mrna[k++] = "B_1B_2B_3";
            reporter_mrna[k++] = "SM_{S_0}";
            reporter_mrna[k++] = "SM_{S_1}";
        }
        reporter_mrna[k]="UAA";
    }

    else if(!strcmp(name, "multshift")){
        l = 10 + (n*1);
        printf("Space required for mRNA for shifter %d string\n", l);
        reporter_mrna = (char **)malloc(sizeof(char *)*l);

        for(i=0;i<l;i++)
            reporter_mrna[i] = (char *)malloc(sizeof(char)*25);

        reporter_mrna[k++] = "SD_multshift";
        reporter_mrna[k++]="AUG";

        i=0;
        if(num1[i]=='0'){
            reporter_mrna[k++] = "B_1B_2B_3";
        }
        else if(num1[i]=='1'){
            reporter_mrna[k++] = "B_4B_5B_6";
        }

        for(i=0;i<=(n-2);i++){

            if(num1[i]=='0'){
                reporter_mrna[k++] = "B_1B_2B_3";
            }
            else if(num1[i]=='1'){
                reporter_mrna[k++] = "B_4B_5B_6";
            }
        }
        reporter_mrna[k]="UAA";
    }

    else if(!strcmp(name, "multd")){
        l = 10 + 4;
        printf("Space required for mRNA for decision %d string\n", l);
        reporter_mrna = (char **)malloc(sizeof(char *)*l);

        for(i=0;i<l;i++){
            reporter_mrna[i] = (char *)malloc(sizeof(char)*25);
        }
        reporter_mrna[k++] = "SD_multd";
        reporter_mrna[k++]="AUG";
        reporter_mrna[k++] = "C_1C_2C_3";

        i = n-2;
        reporter_mrna[k++] = "SecM";
        if(num1[i]=='0'){
            reporter_mrna[k++] = "B_1B_2B_3";
        }
        else if(num1[i]=='1'){
            reporter_mrna[k++] = "B_4B_5B_6";
        }
        i = n-1;
        if(num1[i]=='0'){
            reporter_mrna[k++] = "B_1B_2B_3";
        }
        else if(num1[i] == '1'){
            reporter_mrna[k++] = "B_4B_5B_6";
        }
        reporter_mrna[k++] = "SecA";
        reporter_mrna[k]="UAA";
    }

    else if(!strcmp(name, "divshift")){
        l = 10 + (n*1);
        printf("Space required for mRNA for shifter %d string\n", l);
        reporter_mrna = (char **)malloc(sizeof(char *)*l);

        for(i=0;i<l;i++){
            reporter_mrna[i] = (char *)malloc(sizeof(char)*25);
        }
        reporter_mrna[k++] = "SD_divshift";
        reporter_mrna[k++]="AUG";

        i=0;
        reporter_mrna[k++] = "B_1B_2B_3";
        /*if(num1[i]=='0'){
            reporter_mrna[k++] = "B_1B_2B_3";
        }
        else if(num1[i]=='1'){
            reporter_mrna[k++] = "B_4B_5B_6";
        }*/

        for(i=0;i<=(n-2);i++){

            if(num1[i]=='0'){
                reporter_mrna[k++] = "B_1B_2B_3";
            }
            else if(num1[i]=='1'){
                reporter_mrna[k++] = "B_4B_5B_6";
            }
        }
        reporter_mrna[k]="UAA";
    }
    printf("\nThe value of K after the operation on a single bit%d\n",k);
    return reporter_mrna;
}

/*
 *This function creates mRNA from a single number with special type of codon. This function is useful for shift for quotient, dicision of division.
 * Input: Input number -> num1
 * Return: output -> reporter mRNA
 */
mrna get_single_cond(char *num1, char *name, char *activemname){
    int i, k=0, n, l=0;
    mrna reporter_mrna;
    n = strlen(num1);
    printf("\nThe quotient is %s",num1);
    if(!strcmp(name, "quotshift")){
        l = 10 + (n*1);
        printf("Space required for quotient mRNA to shift is : %d\n", l);
        printf("The activated mutation is : %s", activemname);
        reporter_mrna = (char **)malloc(sizeof(char *)*l);

        for(i=0;i<l;i++)
            reporter_mrna[i] = (char *)malloc(sizeof(char)*30);

        reporter_mrna[k++] = "SD_quotshift";
        reporter_mrna[k++] = "AUG";

        if (!strcmp(activemname, "M_c^{div}"))
            reporter_mrna[k++] = "G_{Activator}+M_c^{div}";

        else if (!strcmp(activemname, "M_d^{div}"))
            reporter_mrna[k++] = "G_{Activator}+M_d^{div}";

        else if (!strcmp(activemname, "M_{sub}^{div}"))
            reporter_mrna[k++] = "G_{Activator}+M_{sub}^{div}";

        for(i=1; i<n; i++){
            if(num1[i]=='0'){
                reporter_mrna[k++] = "B_1B_2B_3";
            }
            else if(num1[i]=='1'){
                reporter_mrna[k++] = "B_4B_5B_6";
            }
        }

        reporter_mrna[k++] = "G_{special}";
        reporter_mrna[k++] = "B_1B_2B_3";
        reporter_mrna[k++] = "B_4B_5B_6";
        reporter_mrna[k++] = "SM";

        reporter_mrna[k]="UAA";
    }
    return reporter_mrna;
}


/*
 * This function creates mRNA for XOR gate.
 */
mrna get_mrna_for_xor(char *num1, char *num2) {
	char *opname;
	opname = (char *)malloc(sizeof(char));
	strcpy(opname, "xor");
	return get_interleaved(num1, num2, opname);
}


/*
 * This function creates mRNA for AND gate.
 */
mrna get_mrna_for_and(char *num1, char *num2) {
	char *opname;
	opname = (char *)malloc(sizeof(char));
	strcpy(opname, "and");
	return get_interleaved(num1, num2, opname);
}


/*
 * This function creates mRNA for OR gate.
 */
mrna get_mrna_for_or(char *num1, char *num2) {
	char *opname;
	opname = (char *)malloc(sizeof(char));
	strcpy(opname, "or");
	return get_interleaved(num1, num2, opname);
}

/*
 * This function creates mRNA for XNOR gate.
 */
mrna get_mrna_for_xnor(char *num1, char *num2) {
    char *opname;
    opname = (char *)malloc(sizeof(char));
    strcpy(opname, "xnor");
    return get_interleaved(num1, num2, opname);
}


/*
 * This function creates mRNA for NAND gate.
 */
mrna get_mrna_for_nand(char *num1, char *num2) {
    char *opname;
    opname = (char *)malloc(sizeof(char));
    strcpy(opname, "nand");
    return get_interleaved(num1, num2, opname);
}


/*
 * This function creates mRNA for NOR gate.
 */
mrna get_mrna_for_nor(char *num1, char *num2) {
    char *opname;
    opname = (char *)malloc(sizeof(char));
    strcpy(opname, "nor");
    return get_interleaved(num1, num2, opname);
}

/*
 * This function creates mRNA for NOT gate.
 */
mrna get_mrna_for_not(char *num1) {
    char *opname;
    opname = (char *)malloc(sizeof(char));
    strcpy(opname, "not");
    return get_singlebit(num1, opname);
}


/*
 * This function creates mRNA for Two's complement (TWOSCOM).
 */
mrna get_mrna_for_twoscom(char *num) {
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "twoscom");
    return get_single(num, opname);
}

/*
 * This function creates mRNA for Addition (ADD).
 */
mrna get_mrna_for_add(char *num1, char *num2) {
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "add");
    return get_interleaved(num1, num2, opname);
}

/*
 * This function creates mRNA for Subtraction (SUB).
 */
mrna get_mrna_for_sub(char *num1, char *num2) {
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "sub");
    return get_interleaved(num1, num2, opname);
}

/*
 * This function creates mRNA for comparator.
 */
mrna get_mrna_for_comparator(char *num1, char *num2){
printf("\n\ntest mRNA compare1");
    return get_reverse_interleaved(num1, num2);
}

/*
 * This function creates mRNA for logical left shifter.
 */
mrna get_mrna_for_shift(char *num, char *name){
    return get_singlebit(num, name);
}

/*
 * This function creates mRNA for Multiplication(decision mRNA) (MULT).
 */

mrna get_mrna_for_multsame(char *num1, char *num2){
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "multsame");
    return get_interleaved(num1, num2, opname);
}

mrna get_mrna_decision_for_mult(char *num1){
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "multd");
    return get_single(num1, opname);
}

mrna get_mrna_shift_for_mult(char *num1){
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "multshift");
    return get_single(num1, opname);
}

/*
 * This function creates mRNA for Devision (DIV).
 */

mrna get_mrna_decision_for_div(char *num1, char *num2){
    char *opname;
    opname = (char *)malloc(MIN);
    strcpy(opname, "divd");
    return get_interleaved(num1, num2, opname);
}

mrna get_mrna_for_divsame1(char *num1, char *num2){
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "divsame{M_c}");
    return get_interleaved(num1, num2, opname);
}

mrna get_mrna_for_divsame2(char *num1, char *num2){
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "divsame{M_d}");
    return get_interleaved(num1, num2, opname);
}


mrna get_mrna_shift_for_div(char *num1){
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "divshift");
    return get_single(num1, opname);
}

mrna get_mrna_shift_for_quot(char *num1, char *activem){
    char *opname;
    opname = (char *)malloc(MAX);
    strcpy(opname, "quotshift");
    return get_single_cond(num1, opname, activem);
}



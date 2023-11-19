/*
Here we construct reporter mRNA for protein synthesis process to perform a operation. In this file we mention only variable and function declaration. We assume that the mRNA is a charater arrary and named as 'mrna'. Then to get a specific mRNA for a specific operation, the function definations are given, like to get mRNA for XOR operation 'get_mrna_for_xor()' is defined and it return a mrna type means a character array. 
*/

#ifndef MRNA_H_56789200
#define MRNA_H_56789200
	
	typedef char **mrna;

    /*Logical Operation*/

	mrna get_mrna_for_xor(char *, char *);

	mrna get_mrna_for_and(char *, char *);

	mrna get_mrna_for_or(char *, char *);

    mrna get_mrna_for_xnor(char *, char *);

    mrna get_mrna_for_nand(char *, char *);

    mrna get_mrna_for_nor(char *, char *);

    mrna get_mrna_for_not(char *);

    /*Extended Logical Operation */

    mrna get_mrna_for_shift(char *, char *);

    mrna get_mrna_for_comparator(char *, char *);

    /*Arithmatic Operation*/

    mrna get_mrna_for_twoscom(char *);

    mrna get_mrna_for_add(char *, char *);

    mrna get_mrna_for_sub(char *, char *);

    mrna get_mrna_for_multsame(char *, char *);

    mrna get_mrna_decision_for_mult(char *);

    mrna get_mrna_shift_for_mult(char *);

    mrna get_mrna_decision_for_div(char *, char *);

    mrna get_mrna_for_divsame1(char *, char *);

    mrna get_mrna_for_divsame2(char *, char *);

    mrna get_mrna_shift_for_div(char *);

    mrna get_mrna_shift_for_quot(char *, char *);
	
#endif

/*
In this header file two structure type data are taken. One is mutation and other is ribosome. mutation is a member of the structure ribosome. In this header file function for mutation for different operations are taken. Along with it a function ribosome get_ribosome_with_mutation() is taken. In this function the property of all mutation is described. 
*/

#ifndef RIBOSOME_H_986754
#define RIBOSOME_H_986754

	#define MUTA 40


	typedef struct {
		char *name;
		char **activator, **deactivator;
		int acount, dcount;
		int opt, stat;
	} mutation;

	typedef struct{
		char *opname, *mname;
		mutation *mlist;
		int selectorcount, activatorcount;
	}ribosome;

    /*Logical Operation*/

	mutation *get_mutation_for_xor(int *, int *);

	mutation *get_mutation_for_and(int *, int *);

	mutation *get_mutation_for_or(int *, int *);

    mutation *get_mutation_for_xnor(int *, int *);

    mutation *get_mutation_for_nand(int *, int *);

    mutation *get_mutation_for_nor(int *, int *);

    mutation *get_mutation_for_not(int *, int *);

    /*Arithmatic Operation*/

    mutation *get_mutation_for_twoscom(int *, int *);

    mutation *get_mutation_for_add(int *, int *);

    mutation *get_mutation_for_sub(int *, int *);

    mutation *get_mutation_for_multd(int *, int *);

    mutation *get_mutation_for_multsame(int *, int *);

    mutation *get_mutation_for_multshift(int *, int *);

    mutation *get_mutation_for_quotshift(int *, int *);

    mutation *get_mutation_for_divshift(int *, int *);

    mutation *get_mutation_for_divsame(int *, int *);

    mutation *get_mutation_for_divd(int *, int *);

    /*Extended Logical Operation*/

    mutation *get_mutation_for_comparator(int *, int *);

    mutation *get_mutation_for_shift(int *, int *);

	ribosome get_ribosome_with_mutation(char *);

#endif

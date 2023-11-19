/* Here we design the mutation for a operation.  The function 'get_ribosome_with_mutation()' gives the name of the mutation for each different operation. Then we define the mutations for each particular operation using the functions  'get_mutation_for_xor()', 'get_mutation_for_and()', and 'get_mutation_for_or()'.
*/

#include<string.h>
#include<stdlib.h>
#include<ribosome.h>

/*
 * Defination of mutation for XOR Operation in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation for XOR operation
 * Returns -> List of mutation for XOR operation
 */

mutation *get_mutation_for_xor(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_2");
    arrmuta[0].acount = arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[0].deactivator[0], "SM_2");
    arrmuta[0].opt = 0;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_3");
    arrmuta[1].acount = arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3B_4B_5B_6");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[1].deactivator[0], "SM_3");
    arrmuta[1].opt = 1;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_5");
    arrmuta[2].acount = arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_4B_5B_6B_1B_2B_3");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[2].deactivator[0], "SM_5");
    arrmuta[2].opt = 1;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_8");
    arrmuta[3].acount = arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_4B_5B_6B_4B_5B_6");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[3].deactivator[0], "SM_8");
    arrmuta[3].opt = 0;
    arrmuta[3].stat = 0;

    *countactivator = 0;

    *countselector = 4;
    return arrmuta;
}

/*
 * Defination of mutation for AND Operation in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation for AND operation
 * Returns -> List of mutation for AND operation
 */

mutation *get_mutation_for_and(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_2");
    arrmuta[0].acount = arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[0], "SM_2");
    arrmuta[0].opt = 0;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_4");
    arrmuta[1].acount = arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3B_4B_5B_6");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0]= (char *)malloc(sizeof(char) *40);
    strcpy(arrmuta[1].deactivator[0], "SM_4");
    arrmuta[1].opt = 0;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_6");
    arrmuta[2].acount = arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_4B_5B_6B_1B_2B_3");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0]= (char *)malloc(sizeof(char) *40);
    strcpy(arrmuta[2].deactivator[0], "SM_6");
    arrmuta[2].opt = 0;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_7");
    arrmuta[3].acount = arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_4B_5B_6B_4B_5B_6");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[3].deactivator[0], "SM_7");
    arrmuta[3].opt = 1;
    arrmuta[3].stat = 0;

    *countactivator = 0;

    *countselector = 4;
    return arrmuta;
}


/*
 * Defination of mutation for OR Operation in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 *Returns -> List of mutation for OR operation
 */

mutation *get_mutation_for_or(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 4);


    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_2");
    arrmuta[0].acount = arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[0].deactivator[0], "SM_2");
    arrmuta[0].opt = 0;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_3");
    arrmuta[1].acount = arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3B_4B_5B_6");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[1].deactivator[0], "SM_3");
    arrmuta[1].opt = 1;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_5");
    arrmuta[2].acount = arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_4B_5B_6B_1B_2B_3");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[2].deactivator[0], "SM_5");
    arrmuta[2].opt = 1;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_7");
    arrmuta[3].acount = arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_4B_5B_6B_4B_5B_6");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[3].deactivator[0], "SM_7");
    arrmuta[3].opt = 1;
    arrmuta[3].stat = 0;

    *countactivator = 0;

    *countselector = 4;
    return arrmuta;
}




/*
 * Defination of mutation for XNOR Operation in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation for XNOR operation
 * Returns -> List of mutation for XNOR operation
 */

mutation *get_mutation_for_xnor(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_1");
    arrmuta[0].acount = arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[0].deactivator[0], "SM_1");
    arrmuta[0].opt = 1;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_4");
    arrmuta[1].acount = arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3B_4B_5B_6");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[1].deactivator[0], "SM_4");
    arrmuta[1].opt = 0;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_6");
    arrmuta[2].acount = arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_4B_5B_6B_1B_2B_3");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[2].deactivator[0], "SM_6");
    arrmuta[2].opt = 0;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_7");
    arrmuta[3].acount = arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_4B_5B_6B_4B_5B_6");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[3].deactivator[0], "SM_7");
    arrmuta[3].opt = 1;
    arrmuta[3].stat = 0;

    *countactivator = 0;

    *countselector = 4;
    return arrmuta;
}

/*
 * Defination of mutation for NAND Operation in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation for NAND operation
 * Returns -> List of mutation for NAND operation
 */

mutation *get_mutation_for_nand(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_1");
    arrmuta[0].acount = arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[0], "SM_1");
    arrmuta[0].opt = 1;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_3");
    arrmuta[1].acount = arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3B_4B_5B_6");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0]= (char *)malloc(sizeof(char) *40);
    strcpy(arrmuta[1].deactivator[0], "SM_3");
    arrmuta[1].opt = 1;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_5");
    arrmuta[2].acount = arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_4B_5B_6B_1B_2B_3");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0]= (char *)malloc(sizeof(char) *40);
    strcpy(arrmuta[2].deactivator[0], "SM_5");
    arrmuta[2].opt = 1;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_8");
    arrmuta[3].acount = arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_4B_5B_6B_4B_5B_6");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[3].deactivator[0], "SM_8");
    arrmuta[3].opt = 0;
    arrmuta[3].stat = 0;

    *countactivator = 0;

    *countselector = 4;
    return arrmuta;
}


/*
 * Defination of mutation for NOR Operation in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation for NOR operation
 * Returns -> List of mutation for NOR operation
 */

mutation *get_mutation_for_nor(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 4);


    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_1");
    arrmuta[0].acount = arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[0].deactivator[0], "SM_1");
    arrmuta[0].opt = 1;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_4");
    arrmuta[1].acount = arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3B_4B_5B_6");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[1].deactivator[0], "SM_4");
    arrmuta[1].opt = 0;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_6");
    arrmuta[2].acount = arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_4B_5B_6B_1B_2B_3");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[2].deactivator[0], "SM_6");
    arrmuta[2].opt = 0;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_8");
    arrmuta[3].acount = arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_4B_5B_6B_4B_5B_6");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[3].deactivator[0], "SM_8");
    arrmuta[3].opt = 0;
    arrmuta[3].stat = 0;

    *countactivator = 0;

    *countselector = 4;
    return arrmuta;
}



/*
 * Defination of mutation for NOT Operation in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation for NOT operation
 * Returns -> List of mutation for NOT operation
 */

mutation *get_mutation_for_not(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 2);


    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_1");
    arrmuta[0].acount = arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[0].deactivator[0], "SM_1");
    arrmuta[0].opt = 1;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_8");
    arrmuta[1].acount = arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_4B_5B_6B_4B_5B_6");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[1].deactivator[0], "SM_8");
    arrmuta[1].opt = 0;
    arrmuta[1].stat = 0;

    *countactivator = 0;

    *countselector = 2;
    return arrmuta;
}




/*
 * Defination of mutation for Shift Operation in a ribosome
 * Input -> Input is two Integer variables which represent number of mutations for shifter
 * Returns -> List of mutation for Shift operation
 */

mutation *get_mutation_for_shift(int *activatorcount, int *selectorcount){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 0);

    *activatorcount = 0;
    *selectorcount = 0;
    return arrmuta;
}


/*
 * Defination of mutation for Comparison in a ribosome
 * Input -> Input is two Integer variables which represent number of mutations for Comparison
 * Returns -> List of mutation for comparison
 */

mutation *get_mutation_for_comparator(int *activatorcount, int *selectorcount){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 3);
    // First mutation

    arrmuta[0].name = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[0].name, "CM_1");
    arrmuta[0].acount = 2;
    arrmuta[0].dcount = 2;

    // Activators
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3+CM_1");
    arrmuta[0].activator[1] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[0].activator[1], "B_4B_5B_6B_4B_5B_6+CM_1");

    // Deactivators
    arrmuta[0].deactivator = (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[0].deactivator[0], "B_4B_5B_6B_1B_2B_3+CM_1");
    arrmuta[0].deactivator[1] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[0].deactivator[1], "B_1B_2B_3B_4B_5B_6+CM_1");

    arrmuta[0].opt = 10;
    arrmuta[0].stat = 0;


    // Second Mutation
    arrmuta[1].name = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[1].name, "CM_2");
    arrmuta[1].acount = 5;
    arrmuta[1].dcount = 0;

    // Activators
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[1].activator[0], "B_4B_5B_6B_1B_2B_3+CM_1");
    arrmuta[1].activator[1] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[1].activator[1], "B_1B_2B_3B_1B_2B_3+CM_2");
    arrmuta[1].activator[2] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[1].activator[2], "B_4B_5B_6B_4B_5B_6+CM_2");
    arrmuta[1].activator[3] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[1].activator[3], "B_4B_5B_6B_1B_2B_3+CM_2");
    arrmuta[1].activator[4] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[1].activator[4], "B_1B_2B_3B_4B_5B_6+CM_2");

    arrmuta[1].deactivator = (char **)malloc(sizeof(char *)*arrmuta[1].dcount);

    arrmuta[1].opt = 0;
    arrmuta[1].stat = 0;


    // Third Mutation
    arrmuta[2].name = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[2].name, "CM_3");
    arrmuta[2].acount = 5;
    arrmuta[2].dcount = 0;

    // Activators
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[2].activator[0], "B_1B_2B_3B_4B_5B_6+CM_1");
    arrmuta[2].activator[1] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[2].activator[1], "B_1B_2B_3B_1B_2B_3+CM_3");
    arrmuta[2].activator[2] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[2].activator[2], "B_4B_5B_6B_4B_5B_6+CM_3");
    arrmuta[2].activator[3] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[2].activator[3], "B_4B_5B_6B_1B_2B_3+CM_3");
    arrmuta[2].activator[4] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[2].activator[4], "B_1B_2B_3B_4B_5B_6+CM_3");

    arrmuta[2].deactivator = (char **)malloc(sizeof(char *)*arrmuta[2].dcount);

    arrmuta[2].opt = 1;
    arrmuta[2].stat = 0;


    *activatorcount = 0;
    *selectorcount = 3;

    return arrmuta;
}


/*
 * Defination of mutation for Addition in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation for Addition
 * Returns -> List of mutation for Addition
 */

mutation *get_mutation_for_add(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_L^{add}");
    arrmuta[0].acount = 4;
    arrmuta[0].dcount = 4;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_1B_2B_3+M_L^{add}");
    arrmuta[0].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[1], "B_1B_2B_3B_1B_2B_3+M_A^{add}");
    arrmuta[0].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[2], "B_1B_2B_3B_4B_5B_6+M_L^{add}");
    arrmuta[0].activator[3] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[3], "B_4B_5B_6B_1B_2B_3+M_L^{add}");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0]= (char *)malloc(sizeof(char) *40);
    strcpy(arrmuta[0].deactivator[0], "B_4B_5B_6B_4B_5B_6+M_L^{add}");
    arrmuta[0].deactivator[1]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[1], "B_4B_5B_6B_4B_5B_6+M_A^{add}");
    arrmuta[0].deactivator[2]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[2], "B_1B_2B_3B_4B_5B_6+M_A^{add}");
    arrmuta[0].deactivator[3]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[3], "B_4B_5B_6B_1B_2B_3+M_A^{add}");
    arrmuta[0].opt = 2;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_A^{add}");
    arrmuta[1].acount = 4;
    arrmuta[1].dcount = 4;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_4B_5B_6B_4B_5B_6+M_L^{add}");
    arrmuta[1].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[1], "B_4B_5B_6B_4B_5B_6+M_A^{add}");
    arrmuta[1].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[2], "B_1B_2B_3B_4B_5B_6+M_A^{add}");
    arrmuta[1].activator[3] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[3], "B_4B_5B_6B_1B_2B_3+M_A^{add}");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].deactivator[0], "B_1B_2B_3B_1B_2B_3+M_L^{add}");
    arrmuta[1].deactivator[1]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].deactivator[1], "B_1B_2B_3B_1B_2B_3+M_A^{add}");
    arrmuta[1].deactivator[2]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].deactivator[2], "B_1B_2B_3B_4B_5B_6+M_L^{add}");
    arrmuta[1].deactivator[3]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].deactivator[3], "B_4B_5B_6B_1B_2B_3+M_L^{add}");
    arrmuta[1].opt = 2;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "S_L^{add}");
    arrmuta[2].acount = 4;
    arrmuta[2].dcount = 1;

    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_1B_2B_3B_1B_2B_3+M_L^{add}");
    arrmuta[2].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[1], "B_4B_5B_6B_4B_5B_6+M_L^{add}");
    arrmuta[2].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[2], "B_1B_2B_3B_4B_5B_6+M_A^{add}");
    arrmuta[2].activator[3] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[3], "B_4B_5B_6B_1B_2B_3+M_A^{add}");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[2].deactivator[0], "SM_L^{add}");

    arrmuta[2].opt = 0;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "S_A^{add}");
    arrmuta[3].acount = 4;
    arrmuta[3].dcount = 1;

    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_1B_2B_3B_1B_2B_3+M_A^{add}");
    arrmuta[3].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[1], "B_4B_5B_6B_4B_5B_6+M_A^{add}");
    arrmuta[3].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[2], "B_1B_2B_3B_4B_5B_6+M_L^{add}");
    arrmuta[3].activator[3] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[3], "B_4B_5B_6B_1B_2B_3+M_L^{add}");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0]= (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[3].deactivator[0], "SM_A^{add}");

    arrmuta[3].opt = 1;
    arrmuta[3].stat = 0;


    *countactivator = 2;

    *countselector = 2;

    return arrmuta;
}

/*
 * Defination of mutation for Subtraction (sub) in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation for Subtraction
 * Returns -> List of mutation for Subtraction
 */

mutation *get_mutation_for_sub(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_L^{sub}");
    arrmuta[0].acount = 4;
    arrmuta[0].dcount = 4;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_4B_5B_6B_1B_2B_3+M_L^{sub}");
    arrmuta[0].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[1], "B_4B_5B_6B_1B_2B_3+M_A^{sub}");
    arrmuta[0].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[2], "B_1B_2B_3B_1B_2B_3+M_L^{sub}");
    arrmuta[0].activator[3] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[3], "B_4B_5B_6B_4B_5B_6+M_L^{sub}");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[0], "B_1B_2B_3B_4B_5B_6+M_L^{sub}");
    arrmuta[0].deactivator[1]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[1], "B_1B_2B_3B_4B_5B_6+M_A^{sub}");
    arrmuta[0].deactivator[2]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[2], "B_1B_2B_3B_1B_2B_3+M_A^{sub}");
    arrmuta[0].deactivator[3]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].deactivator[3], "B_4B_5B_6B_4B_5B_6+M_A^{sub}");
    arrmuta[0].opt = 2;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_A^{sub}");
    arrmuta[1].acount = 4;
    arrmuta[1].dcount = 4;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3B_4B_5B_6+M_L^{sub}");
    arrmuta[1].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[1], "B_1B_2B_3B_4B_5B_6+M_A^{sub}");
    arrmuta[1].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[2], "B_1B_2B_3B_1B_2B_3+M_A^{sub}");
    arrmuta[1].activator[3] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[3], "B_4B_5B_6B_4B_5B_6+M_A^{sub}");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].deactivator[0], "B_4B_5B_6B_1B_2B_3+M_L^{sub}");
    arrmuta[1].deactivator[1]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].deactivator[1], "B_4B_5B_6B_1B_2B_3+M_A^{sub}");
    arrmuta[1].deactivator[2]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].deactivator[2], "B_1B_2B_3B_1B_2B_3+M_L^{sub}");
    arrmuta[1].deactivator[3]= (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].deactivator[3], "B_4B_5B_6B_4B_5B_6+M_L^{sub}");
    arrmuta[1].opt = 2;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "S_A^{sub}");
    arrmuta[2].acount = 4;
    arrmuta[2].dcount = 1;

    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_1B_2B_3B_1B_2B_3+M_L^{sub}");
    arrmuta[2].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[1], "B_4B_5B_6B_4B_5B_6+M_L^{sub}");
    arrmuta[2].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[2], "B_1B_2B_3B_4B_5B_6+M_A^{sub}");
    arrmuta[2].activator[3] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[3], "B_4B_5B_6B_1B_2B_3+M_A^{sub}");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0]= (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].deactivator[0], "SM_L^{sub}");

    arrmuta[2].opt = 0;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "S_L^{sub}");
    arrmuta[3].acount = 4;
    arrmuta[3].dcount = 1;

    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_1B_2B_3B_1B_2B_3+M_A^{sub}");
    arrmuta[3].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[1], "B_4B_5B_6B_4B_5B_6+M_A^{sub}");
    arrmuta[3].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[2], "B_1B_2B_3B_4B_5B_6+M_L^{sub}");
    arrmuta[3].activator[3] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[3], "B_4B_5B_6B_1B_2B_3+M_L^{sub}");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0]= (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].deactivator[0], "SM_A^{sub}");

    arrmuta[3].opt = 1;
    arrmuta[3].stat = 0;


    *countactivator = 2;
    *countselector = 2;

    return arrmuta;
}


/*
 * Defination of mutation for TWO'S Complement in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 * Returns -> List of mutation for TWO'S Complement operation
 */

mutation *get_mutation_for_twoscom(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation)*4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "C_0");
    arrmuta[0].acount = 3;
    arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_4B_5B_6+C_1");
    arrmuta[0].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[1], "B_4B_5B_6+C_0");
    arrmuta[0].activator[2] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[2], "B_1B_2B_3+C_0");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char) *20);
    strcpy(arrmuta[0].deactivator[0], "SM_{C_0}");
    arrmuta[0].opt = 2;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "C_1");
    arrmuta[1].acount = arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3+C_1");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].deactivator[0], "B_4B_5B_6+C_1");
    arrmuta[1].opt = 2;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "S_0");
    arrmuta[2].acount = 2 ;
    arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_4B_5B_6+C_0");
    arrmuta[2].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[1], "B_1B_2B_3+C_1");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0] = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].deactivator[0], "SM_{S_0}");
    arrmuta[2].opt = 0;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "S_1");
    arrmuta[3].acount = 2;
    arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_4B_5B_6+C_1");
    arrmuta[3].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[1], "B_1B_2B_3+C_0");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0] = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].deactivator[0], "SM_{S_1}");
    arrmuta[3].opt = 1;
    arrmuta[3].stat = 0;

    *countactivator = 2;
    *countselector = 2;

    return arrmuta;
}

/*
 * Defination of mutation for Multiplication(Decision Ribosome) in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 * Returns -> List of mutation for decision operation of multiplication
 */

mutation *get_mutation_for_multd(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation)*4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_m^{mult}");
    arrmuta[0].acount = 1;
    arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].activator[0], "C_1C_2C_3");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[0].deactivator[0], "");
    arrmuta[0].opt = 2;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_d^{mult}");
    arrmuta[1].acount = 2;
    arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_1B_2B_3B_1B_2B_3+M_m^{mult}");
    arrmuta[1].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[1], "B_4B_5B_6B_4B_5B_6+M_m^{mult}");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[1].deactivator[0], "");
    arrmuta[1].opt = 2;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_L^{add}");
    arrmuta[2].acount = 1 ;
    arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[2].activator[0], "B_1B_2B_3B_4B_5B_6+M_m^{mult}");

    arrmuta[2].deactivator= (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[2].deactivator[0], "");
    arrmuta[2].opt = 2;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_L^{sub}");
    arrmuta[3].acount = 1;
    arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[3].activator[0], "B_4B_5B_6B_1B_2B_3+M_m^{mult}");

    arrmuta[3].deactivator= (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[3].deactivator[0], "");
    arrmuta[3].opt = 2;
    arrmuta[3].stat = 0;


    *countactivator = 4;
    *countselector = 0;

    return arrmuta;
}

/*
 * Defination of mutation for Multiplication(Decision Ribosome) in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 * Returns -> List of mutation for decision operation of multiplication
 */

mutation *get_mutation_for_multsame(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation) * 2);


    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_{p_1}^{mult}");
    arrmuta[0].acount = 2;
    arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_4B_5B_6+M_d^{mult}");
    arrmuta[0].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[0].activator[1], "B_1B_2B_3B_1B_2B_3+M_d^{mult}");

    arrmuta[0].deactivator= (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[0].deactivator[0], "SM");
    arrmuta[0].opt = 0;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_{p_2}^{mult}");
    arrmuta[1].acount = 2;
    arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[0], "B_4B_5B_6B_1B_2B_3+M_d^{mult}");
    arrmuta[1].activator[1] = (char *)malloc(sizeof(char)*40);
    strcpy(arrmuta[1].activator[1], "B_4B_5B_6B_4B_5B_6+M_d^{mult}");

    arrmuta[1].deactivator= (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[1].deactivator[0], "SM");
    arrmuta[1].opt = 1;
    arrmuta[1].stat = 0;


    *countactivator = 0;
    *countselector = 2;

    return arrmuta;
}

/*
 * Defination of mutation for Multiplication(Arithmetic Right Shift Ribosome for Multiplication) in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 * Returns -> List of mutation for decision operation of multiplication
 */
mutation *get_mutation_for_multshift(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation)*0);

    *countactivator = 0;
    *countselector = 0;
    return arrmuta;
}

/*
 * Defination of mutation for Division(Decision Ribosome) in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 * Returns -> List of mutation for decision operation of division
 */

mutation *get_mutation_for_divd(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation)*4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_m^{div}");
    arrmuta[0].acount = 1;
    arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[0].activator[0], "Activator_of_M_m^{div}");

    arrmuta[0].deactivator = (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[0].deactivator[0], "");
    arrmuta[0].opt = 2;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_{sub}^{div}");
    arrmuta[1].acount = 2;
    arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[1].activator[0], "B_4B_5B_6B_1B_2B_3+M_m^{div}");
    arrmuta[1].activator[1] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[1].activator[1], "B_1B_2B_3B_4B_5B_6+M_c^{div}");


    arrmuta[1].deactivator = (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[1].deactivator[0], "");
    arrmuta[1].opt = 2;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_c^{div}");
    arrmuta[2].acount = 2;
    arrmuta[2].dcount = 2;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[2].activator[0], "B_1B_2B_3B_1B_2B_3+M_m^{div}");
    arrmuta[2].activator[1] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[2].activator[1], "B_4B_5B_6B_4B_5B_6+M_m^{div}");

    arrmuta[2].deactivator = (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[2].deactivator[0], "B_4B_5B_6B_1B_2B_3");
    arrmuta[2].deactivator[1] = (char *)malloc(sizeof(char)*30);
    strcpy(arrmuta[2].deactivator[1], "B_1B_2B_3B_4B_5B_6");
    arrmuta[2].opt = 2;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_d^{div}");
    arrmuta[3].acount = 2;
    arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[3].activator[0], "B_1B_2B_3B_4B_5B_6+M_m^{div}");
    arrmuta[3].activator[1] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[3].activator[1], "B_4B_5B_6B_1B_2B_3+M_c^{div}");

    arrmuta[3].deactivator = (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[3].deactivator[0], "");
    arrmuta[3].opt = 2;
    arrmuta[3].stat = 0;


    *countactivator = 4;
    *countselector = 0;
    return arrmuta;
}

/*
 * Defination of mutation for Division(Ribosome to keep same the remainder) in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 * Returns -> List of mutation for comparison operation of division
 */

mutation *get_mutation_for_divsame(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation)*2);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_{P_1}^{div}");
    arrmuta[0].acount = 4;
    arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[0].activator[0], "B_1B_2B_3B_4B_5B_6+M_d^{div}");
    arrmuta[0].activator[1] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[0].activator[1], "B_1B_2B_3B_1B_2B_3+M_d^{div}");
    arrmuta[0].activator[2] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[0].activator[2], "B_1B_2B_3B_4B_5B_6+M_c^{div}");
    arrmuta[0].activator[3] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[0].activator[3], "B_1B_2B_3B_1B_2B_3+M_c^{div}");

    arrmuta[0].deactivator = (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[0].deactivator[0], "G_{SM}");
    arrmuta[0].opt = 0;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_{P_2}^{div}");
    arrmuta[1].acount = 4;
    arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[1].activator[0], "B_4B_5B_6B_1B_2B_3+M_d^{div}");
    arrmuta[1].activator[1] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[1].activator[1], "B_4B_5B_6B_4B_5B_6+M_d^{div}");
    arrmuta[1].activator[2] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[1].activator[2], "B_4B_5B_6B_1B_2B_3+M_c^{div}");
    arrmuta[1].activator[3] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[1].activator[3], "B_4B_5B_6B_4B_5B_6+M_c^{div}");

    arrmuta[1].deactivator = (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[1].deactivator[0], "G_{SM}");
    arrmuta[1].opt = 1;
    arrmuta[1].stat = 0;

    *countactivator = 0;
    *countselector = 2;
    return arrmuta;
}

/*
 * Defination of mutation for Division(Logical Right Shift Ribosome for Division) in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 * Returns -> List of mutation for logical left shift operation of division
 */

mutation *get_mutation_for_divshift(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation)*0);

    *countactivator = 0;
    *countselector = 0;
    return arrmuta;
}

/*
 * Defination of mutation for Division(Conditional logical left shift Ribosome for Quotient) in a ribosome
 * Input -> Input is an Integer variable which represents number of mutation
 * Returns -> List of mutation for Conditional logical left shift operation of division
 */

mutation *get_mutation_for_quotshift(int *countactivator, int *countselector){
    mutation *arrmuta = (mutation *)malloc(sizeof(mutation)*4);

    arrmuta[0].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[0].name, "M_{q_1}^{div}");
    arrmuta[0].acount = 2;
    arrmuta[0].dcount = 1;
    arrmuta[0].activator = (char **)malloc(sizeof(char *)*arrmuta[0].acount);
    arrmuta[0].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[0].activator[0], "G_{Activator}+M_c^{div}");
    arrmuta[0].activator[1] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[0].activator[1], "G_{Activator}+M_d^{div}");

    arrmuta[0].deactivator = (char **)malloc(sizeof(char *)*arrmuta[0].dcount);
    arrmuta[0].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[0].deactivator[0], "");
    arrmuta[0].opt = 2;
    arrmuta[0].stat = 0;


    arrmuta[1].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[1].name, "M_{q_2}^{div}");
    arrmuta[1].acount = 1;
    arrmuta[1].dcount = 1;
    arrmuta[1].activator = (char **)malloc(sizeof(char *)*arrmuta[1].acount);
    arrmuta[1].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[1].activator[0], "G_{Activator}+M_{sub}^{div}");

    arrmuta[1].deactivator = (char **)malloc(sizeof(char *)*arrmuta[1].dcount);
    arrmuta[1].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[1].deactivator[0], "");
    arrmuta[1].opt = 2;
    arrmuta[1].stat = 0;


    arrmuta[2].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[2].name, "M_{A_1}^{div}");
    arrmuta[2].acount = 1;
    arrmuta[2].dcount = 1;
    arrmuta[2].activator = (char **)malloc(sizeof(char *)*arrmuta[2].acount);
    arrmuta[2].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[2].activator[0], "G_{special}+M_{q_1}^{div}");

    arrmuta[2].deactivator = (char **)malloc(sizeof(char *)*arrmuta[2].dcount);
    arrmuta[2].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[2].deactivator[0], "");
    arrmuta[2].opt = 0;
    arrmuta[2].stat = 0;


    arrmuta[3].name = (char *)malloc(sizeof(char)*20);
    strcpy(arrmuta[3].name, "M_{A_2}^{div}");
    arrmuta[3].acount = 1;
    arrmuta[3].dcount = 1;
    arrmuta[3].activator = (char **)malloc(sizeof(char *)*arrmuta[3].acount);
    arrmuta[3].activator[0] = (char *)malloc(sizeof(char *)*40);
    strcpy(arrmuta[3].activator[0], "G_{special}+M_{q_2}^{div}");

    arrmuta[3].deactivator = (char **)malloc(sizeof(char *)*arrmuta[3].dcount);
    arrmuta[3].deactivator[0] = (char *)malloc(sizeof(char)*10);
    strcpy(arrmuta[3].deactivator[0], "");
    arrmuta[3].opt = 1;
    arrmuta[3].stat = 0;

    *countactivator = 2;
    *countselector = 2;
    return arrmuta;
}





/*
 * This function define the name of the mutation for each operation. Till now we only implement here the XOR, AND and OR operation
 * Input -> Input is a string that define the operation name
 * Returns -> List of mutation for performing an operation
 */
ribosome get_ribosome_with_mutation(char *sw){
    //int i,count;
    //char m[MUTA];
    //mutation *arrmut;
	ribosome r;

	r.mname= (char *) malloc (sizeof(char) * 70);
	r.opname= (char *) malloc (sizeof(char) * 10);
	strcpy(r.opname, sw);

	if(!strcmp(sw,"xor")){
		
		strcpy(r.mname, "M_2, M_3, M_5, M_8");
		r.mlist = get_mutation_for_xor(&r.activatorcount, &r.selectorcount);
	}

	if(!strcmp(sw,"and")){
		
		strcpy(r.mname, "M_2, M_4, M_6, M_7");
		r.mlist = get_mutation_for_and(&r.activatorcount, &r.selectorcount);
	}
	
	if(!strcmp(sw,"or")){
		
		strcpy(r.mname, "M_2, M_3, M_5, M_7");
		r.mlist = get_mutation_for_or(&r.activatorcount, &r.selectorcount);
	}

    if(!strcmp(sw,"xnor")){

        strcpy(r.mname, "M_1, M_4, M_6, M_7");
        r.mlist = get_mutation_for_xnor(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"nand")){

        strcpy(r.mname, "M_1, M_3, M_5, M_8");
        r.mlist = get_mutation_for_nand(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"nor")){

        strcpy(r.mname, "M_1, M_4, M_6, M_8");
        r.mlist = get_mutation_for_nor(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"not")){
        strcpy(r.mname, "M_1, M_8");
        r.mlist = get_mutation_for_not(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"compare")){
        strcpy(r.mname, "CM_1, CM_2, CM_3");
        r.mlist = get_mutation_for_comparator(&r.activatorcount, &r.selectorcount);
    }

    if((strcmp("lls", sw) == 0) || (strcmp("lrs",sw)==0) || (strcmp("ars",sw) == 0) || (strcmp("als",sw) == 0) || (strcmp("cls", sw) == 0) || (strcmp("crs",sw)==0)){
        strcpy(r.mname, "No mutation");
        r.mlist = get_mutation_for_shift(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"twoscom")){
        strcpy(r.mname, "C_0, C_1, S_0, S_1");
        r.mlist = get_mutation_for_twoscom(&r.activatorcount, &r.selectorcount);
    }

        if(!strcmp(sw,"add")){
        strcpy(r.mname, "M_L^{add}, M_A^{add}, S_L^{add}, S_A^{add}");
        r.mlist = get_mutation_for_add(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"sub")||!strcmp(sw,"SUB")){
        strcpy(r.mname, "M_L^{sub}, M_A^{sub}, S_L^{sub}, S_A^{sub}");
        r.mlist = get_mutation_for_sub(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"multd")){
        strcpy(r.mname, "M_m^{mult}, M_d^{mult}, M_L^{add}, M_L^{sub}");
        r.mlist = get_mutation_for_multd(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"multsame")){
        strcpy(r.mname, "M_{p_1}^{mult}, M_{p_2}^{mult}");
        r.mlist = get_mutation_for_multsame(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"multshift")){
        strcpy(r.mname, "");
        r.mlist = get_mutation_for_multshift(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"divd")){
        strcpy(r.mname, "M_m^{div}, M_{sub}^{div}, M_c^{div}, M_d^{div}");
        r.mlist = get_mutation_for_divd(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"divsame")){
        strcpy(r.mname, "M_{P_1}^{div}, M_{P_2}^{div}");
        r.mlist = get_mutation_for_divsame(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"divshift")){
        strcpy(r.mname, "");
        r.mlist = get_mutation_for_divshift(&r.activatorcount, &r.selectorcount);
    }

    if(!strcmp(sw,"quotshift")){
        strcpy(r.mname, "M_{q_1}^{div}, M_{q_2}^{div}, M_{A_1}^{div}, M_{A_2}^{div}");
        r.mlist = get_mutation_for_quotshift(&r.activatorcount, &r.selectorcount);
    }

	return r;
}

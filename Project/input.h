/*
Here we take user input. The first argument is the name of the operation. The second one is a flag value to check if inputs are binary or not. Then two input number as a string.  
*/

#ifndef INPUT_H_57469023
#define INPUT_H_57469023

	#include <mrna.h>
	#include <ribosome.h>

    void get_input_one(char *, int, char *, mrna *, ribosome *);

    void get_inputs(char *, int , char *, mrna *, ribosome *);

	void get_input_two(char *, int, char *, char *, mrna *, ribosome *);
    void get_input_not(char *, int, char *, mrna *, ribosome *);

    char *get_inputmult(char *, int , char *, char *, int *);
    char *get_inputdiv(char *, int , char *, char *, char *);

	

#endif

/*
 This header file is defined by us. In thi file we define two variable a 'number' and a 'chain'. Both variables are character array type variable. Variable 'number' represents a string of input number. The 'chain' represents the string of output amino acid chain. 
*/

#ifndef UTIL_H_69639640
#define UTIL_H_69639640
	
	#define MAX 100
	#define MIN 20

	typedef char *number;
	typedef char *chain;

	void oplist();

	int menu(int );

    //void method(char *);
	
    char *adjust(number , int , int );

#endif

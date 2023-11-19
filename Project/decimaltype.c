/*
 Convert a binary number(as a character) to integer
*/
#include<stdlib.h>
#include<binarytype.h>
#include<util.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

int power(int j){
	int v, i;
	v = 1;
	for(i=j-1; i>=0; i--)
		v = v*2;
	return v;
}

int to_decimal(char *num){
	int n, i, j, value = 0,p;

	n=strlen(num);
	for(i=n-1, j=0; i>=0; i--,j++){
		if(num[i]=='0')
			value = value + 0;
		else if(num[i]=='1'){
			p = power(j); 
			value = value + p;
		}
	}

	return value;
}

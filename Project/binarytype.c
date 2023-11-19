/*
 Convert a decimal number to binary
*/
#include<stdlib.h>
#include<binarytype.h>
#include<util.h>

char *to_binary(int n){
	char *ch, *ch1;
	ch = (char *)malloc(MAX);
	ch1 = (char *)malloc(MAX);

	int i=0,j,k;
	while(n != 0){
		if(n%2 == 0)
			ch[i] = '0';
		else
			ch[i] = '1';
		i++;
		n /= 2;
	}
	
	for(j=0, k=i-1; j<i; j++, k--)
		ch1[j]=ch[k];
	ch1[j]='\0';

	return ch1;
}

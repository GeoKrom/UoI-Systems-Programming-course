#include<stdio.h>

int main(void){
	
	int x = 1;
	char *p;

	p = (char *) &x;

	printf("The endianness of the system is %s\n", (*p == 1)?"Little":"Big");

	return 0;
}
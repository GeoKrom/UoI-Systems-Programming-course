#include<stdio.h>
#include<string.h>


int main(int argc, char *argv[]){
	
	int i, j;
	char CHR;
	
	printf("Please insert your desired character: ");
	scanf("%c", &CHR);
	
	for(i = 0; i < argc; i++){
		for(j = 0; j < strlen(argv[i]); j++){
			if(argv[i][j] == CHR){
				argv[i][j] = '#';
			}
		}
	}
	
	for(i = 0; i < argc; i++){
		printf("%s\t", argv[i]);
	}
	printf("\n");
	
	return 0;
}
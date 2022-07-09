#include<stdio.h>

void printbin(unsigned int num);

int main(void){
	
	unsigned int number;

	while(1){
		printf("Please enter the number: ");
		scanf("%d", &number);
		if(number != 502){
			printbin(number);
		}else{
			break;
		}
		
	}
	
	return 0;
}

void printbin(unsigned int num){
	
	int binArray[64], i, temp;
	
	printf("the binary form of the number %d is ", num);
	for(i = 63; i >= 0; i--){
		temp = num%2;
		num = num/2;
		binArray[i] = temp;
	}
	
	for(i = 0; i < 64; i++){
		printf("%d", binArray[i]);
	}
	printf("\n");
}
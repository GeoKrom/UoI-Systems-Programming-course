#include<stdio.h>

int main(void){
	
	int i, pos, letters_read = 0, numbers_read = 0;
	int nums[30];
	char ch, small_ch;
	
	while(ch != '$' && letters_read < 30){
		printf("Please insert your desired character!\n");
		scanf(" %c", &ch);
		if(ch >= 'A' && ch <= 'Z'){
			small_ch = (ch - 'A') + 'a';
			printf("The small of '%c' is '%c'\n", ch, small_ch);
		}else if(ch >= 'a' && ch <= 'z'){
			pos = (ch - 'a') + 1;
			printf("The position of the letter '%c' in the alphabet is %d\n", ch, pos);
		}else if(ch >= '0' && ch <= '9'){
			nums[numbers_read++] = ch - '0';
		}else{
			printf("Any other letter is %c\n", ch);
		}
		letters_read++;	
	}
	
	printf("The numbers that were read are: ");
	for(i = 0; i < numbers_read; i++){
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}
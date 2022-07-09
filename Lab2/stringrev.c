#include<stdio.h>

char *string_end(char *str);
void string_reverse(char *str);

int main(void){

	char s[100];
	printf("Please enter a string: ");
	fgets(s, 99, stdin);
	
	string_reverse(s);
	
	printf("The reversed string is: %s\n", s);
	return 0;
}

char *string_end(char *str){
	
	if(*str == '\0'){
		return str;
	}
	
	while(*(str+1) != '\0'){
		str++;
	}
	return str;
}

void string_reverse(char *str){
	char c, *t = string_end(str);
	
	for(; t > str; str++, t--){
		c = *str;
		*str = *t;
		*t = c;
	}
}
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int arr[26];

void charstats(char *str);

int main(void){

    char inputString[100];
    int i;

    printf("Please enter your desired sentences (until give ###)\n");
    do{
        fgets(inputString, 100, stdin);
        if(strncmp(inputString, "###", 3) != 0){
            charstats(inputString);
        }
    }while(strncmp(inputString, "###", 3) != 0);

    printf("The statistics of the characters are\n");
    printf("| a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z |\n");
    for(i = 0; i < 26; i++){
        printf("| %d ", arr[i]);
        if( i == 25){
            printf("|");
        }
    }
    printf("\n");
    return 0;
}


void charstats(char *str){
    
    int n;

    while(*str != '\0'){

        if(isalpha(*str)){
            n = tolower(*str) - 'a';
            arr[n]++;
        }
        str++;
    }
}
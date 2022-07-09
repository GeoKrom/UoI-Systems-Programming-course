#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *my_strndup(char *str, int size);

int main(){

    char *string = "Hello";
    char *news;
    int n;

    printf("Please enter your desired length. It should be less than strlen!\n");
    scanf("%d", &n);
    if(n <= strlen(string)){
        news = my_strndup(string, n);
    }else{
        printf("Error! Should not surpass the length of the input string!\n");
        return 1;
    }
    printf("%s\n", string);
    printf("%s\n", news);
    return 0;
}


char *my_strndup(char *str, int size){
    int i;
    char *newstr;
    int slen = strlen(str);
    newstr = (char *) malloc(size*sizeof(char));

    if(newstr == NULL){
        return NULL;
    }

    
    for(i = 0; i < size && size <= slen; i++){
        newstr[i] = *(str++);
    }
    if(slen >= size){
        newstr[size] = '\0';
    }
    return newstr;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[]){

    int i, pr;

    if(argc < 4){
        return 1;
    }

    if(strcmp(argv[1], "+") == 0){
        pr = 0;
        for(i = 2; i < argc; i++){
            pr += atoi(argv[i]);
        }
    }
    else if(strcmp(argv[1], "-") == 0){
        pr = 0;
        for(i = 2; i < argc; i++){
            pr -= atoi(argv[i]);
        }
    }
    
    else if(strcmp(argv[1], "x") == 0){
        pr = 1;
        for(i = 2; i < argc; i++){
            pr *= atoi(argv[i]);
        }
    }
    
    else if(strcmp(argv[1], "/") == 0){
        pr = atoi(argv[2]);
        for(i = 3; i < argc; i++){
            pr /= atoi(argv[i]);
        }
    }
    else{
        printf("Wrong Syntax!\n");
        return 1;
    }
    printf("The result is res = %d\n",pr);

    return 0;
}
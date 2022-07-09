#include <stdio.h>
#include <stdlib.h>

void printbin(int n);

int main(){

    int number;
    printf("Please enter a number!\n");
    scanf("%d", &number);

    printf("The binary form of number %d is: \n", number);
    printbin(number);
    printf("\n");

    return 0;
}

void printbin(int n){
    
    int i;
    int mask = 1 << 31;
    for(i = 0; i < 32; i++){
        if((n & mask) == 0){
            printf("0");
        }else{
            printf("1");
        }
        n = n << 1;
    }
}
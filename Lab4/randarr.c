#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    int i, num, MAXNUM;
    int *arr;

    printf("Please insert the size of the array!\n");
    scanf("%d", &MAXNUM);
    
    arr = (int *) malloc(MAXNUM*sizeof(int));
    
    srand(time(NULL));

    for(i = 0; i < MAXNUM; i++){
        num = rand() % MAXNUM;
        arr[i] = num;
    }

    printf("The new array is\n");

    for(i = 0; i < MAXNUM; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
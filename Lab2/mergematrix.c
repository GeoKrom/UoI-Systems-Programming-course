#include<stdio.h>

#define N 100 
void mergearrays(int *A, int na, int *B, int nb, int *C);
int readArray(int *matrix);

int main(void){
       
    int i, na, nb;
    int A[N], B[N], C[2*N];

    na = readArray(A);
    nb = readArray(B);

    mergearrays(A, na, B, nb, C);
    printf("The new matrix is:\n");

    printf("C = [");
    for(i = 0; i < na + nb; i++){
        if(i == 0){
            printf("%d ", C[i]);
        }
        printf(", %d ", C[i]);
    }
    printf("]");
    printf("\n");
    return 0;
}

void mergearrays(int *A, int na, int *B, int nb, int *C){
    int i, j;

    for(i = j = 0; i < na && j < nb; C++){

        if(*A < *B){
            *C = *(A++);
            i++;
        }else{
            *C = *(B++);
            j++;
        }
    }
    if(i < na){
        for(; i < na; i++){
            *(C++) = *(A++);
        }
    }

    if(j < nb){
        *(C++) = *(B++);
    }
}

int readArray(int *matrix){
    int i, num;

    do{
        printf("Please enter your elements of the array (at most %d)\n", N);
        scanf("%d", &num);
    }while(num > N);

    printf("Give the (%d sorted elements): \n", num);
    
    for(i = 0; i < num; i++){
        scanf("%d", &matrix[i]);
    }

    return num;
}
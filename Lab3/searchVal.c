#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void search(int *arr, int n, int k, int **element);

int main(void){
    int a[10], i, l;
	int *element, *q;
	printf("Please enter your desired numbers!\n");
	
	for(i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	
	printf("The matrix is A[");
	for(i = 0; i < 10; i++){
		if(i == 0){
			printf("%d", a[i]);
		}else if(i >= 1){
		    printf(",%d", a[i]);
        }
	}
	printf("]\n");
	printf("Please enter your desired value!\n");
	scanf("%d", &l);
    q = &a[0];
	search(a, 10, l, &element);
	
	printf("The element is %d with its position in the memory %ld\n", *element, (element-q));


    return 0;
}


void search(int *arr, int n, int k, int **element){
    int i;
	int *p = arr;

    if(p == NULL){
        exit(1);
    }
	for(i = 0; i < n; i++){
		if(*(p+i) == k){
			*element = &(p[i]);
		}
    }
}
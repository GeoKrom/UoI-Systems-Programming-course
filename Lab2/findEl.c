#include<stdio.h>


int *search(int *arr, int n, int k);

int main(){
	int a[10], i, l;
	int *q;
	printf("Please enter your desired numbers!\n");
	
	for(i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	
	printf("The matrix is A[");
	for(i = 0; i < 10; i++){
		if(i == 0){
			printf("%d", a[i]);
		}
		printf(",%d", a[i]);
	}
	printf("]\n");
	printf("Please enter your desired value!\n");
	scanf("%d", &l);
	q = search(a, 10, l);
	
	printf("The element is %d with its position in the memory %p\n", *q, &q);
	return 0;
}


int *search(int arr[], int n, int k){
	int i;
	int *p = arr;
	for(i = 0; i < n; i++){
		if(*(p+i) == k){
			return &p[i];
		}
	}
	return NULL;
}
#include<stdio.h>

double minmaxavg(double array[], int num, double *min, double *max);

int main(){
	int i;
	double avg, matrix[15], min, max;
	printf("Please enter your desired numbers!\n");
	
	for(i = 0; i < 15; i++){
		scanf("%lf", &matrix[i]);
	}
	
	printf("The matrix is \nA = [");
	for(i = 0; i < 15; i++){
		if(i == 0){
			printf("%lf", matrix[i]);
		}
		printf(",%lf", matrix[i]);
	}
	printf("]\n");
	
	avg = minmaxavg(matrix, 15, &min, &max);
	
	printf("The average is avg = %.2lf\n", avg);
	printf("The min = %.2lf and the max = %.2lf\n", min, max);
	return 0;
}

double minmaxavg(double array[], int num, double *min, double *max){
	int i, sum, res;
	
	*min = array[0];
	*max = array[0];
	for(i = 0; i < num; i++){
		if(*min > array[i]){
			*min = array[i];
		}
		if(*max < array[i]){
			*max = array[i];
		}
	}
	
	for(i = 0; i < num; i++){
		sum += array[i];
	}
	res = sum/(double)num;

	return res;
}
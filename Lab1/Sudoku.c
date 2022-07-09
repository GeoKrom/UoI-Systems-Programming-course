#include<stdio.h>

int sudokuMatrix[9][9] = {{8,2,7,1,5,4,3,9,6},
					         {9,6,5,3,2,7,1,4,8},
					         {3,4,1,6,8,9,7,5,2},
							 {5,9,3,4,6,8,2,7,1},
							 {4,7,2,5,1,3,6,8,9},
							 {6,1,8,9,7,2,4,3,5},
							 {7,8,6,2,3,5,9,1,4},
							 {1,5,4,7,9,6,8,2,3},
							 {2,3,9,8,4,1,5,6,7}};
int M[9][9] = {{5,8,1,4,2,7,6,9,3},
               {3,7,4,5,9,6,8,1,2},
               {9,6,2,1,3,8,4,7,5},
               {6,2,9,3,8,5,7,4,1},
               {1,5,7,9,6,4,3,2,8},
               {8,4,3,2,7,1,5,6,9},
               {4,1,8,7,5,2,9,3,6},
               {2,9,5,6,4,3,1,8,7},
               {7,3,6,8,1,9,2,5,4}};

int main(void){
	
	int check_solution(int arr[9][9]);
	
	if(check_solution(M) == 0){
		printf("Correct Solution!\n");
	}else{
		printf("Wrong Solution!\n");
	}
	
	return 0;
}
int check_solution(int arr[9][9]){
	int i, j, m, l, k, d;
	int temp[10];
	
	// Check every row of the matrix
	for(i = 0; i < 9; i++){
		printf("Check row -> %d\n", i);
		for(j = 0; j < 10; j++){
			temp[j] = 0;
		}
		
		for(j = 0; j < 9; j++){
			if(temp[arr[i][j]] >= 1){
				return 1;
			}else{
				temp[arr[i][j]]++;
			}
		}
	}
	// Check every column of the matrix
	for(i = 0; i < 9; i++){
		printf("Check column -> %d\n", i);
		for(j = 0; j < 10; j++){
			temp[j] = 0;
		}
		
		for(j = 0; j < 9; j++){
			if(temp[arr[j][i]] >= 1){
				return 1;
			}else{
				temp[arr[j][i]]++;
			}
		}
	}
	// Check every 3x3 sub matrix of the original 9x9 matrix 
	for(l = 0; l < 3; l++){
		for(k = 0; k < 3; k++){
			printf("Check sub matrix (%d,%d)\n", l, k);
			for(j = 0; j < 10; j++){
				temp[j] = 0;
			}
			
			for(j = 0; j < 3; j++){
				for(m = 0; m < 3; m++){
					if(temp[arr[j+3*l][m+3*k]] >= 1){
						return 1;
					}else{
						temp[arr[j+3*l][m+3*k]]++;
					}
				}
			}
			
		}
	}
	
	// Check the two diagonals of the matrix
	for(j = 0; j < 10; j++){
		temp[j] = 0;			
	}
	
	printf("Checking First Diadonal!\n");
	for(j = 0; j < 9; j++){
		printf("Checking Fist diagonal element(%d,%d)\n", j,j);
		if(temp[arr[j][j]] == 0){
			temp[arr[j][j]]++;
		}else{
			return 1;
		}	
	}
	for(j = 0; j < 10; j++){
		temp[j] = 0;			
	}
	printf("Checking Second Diadonal!\n");

	for(j = 0; j < 9; j++){
		d = 8-j;
		printf("Checking Fist diagonal element(%d,%d)\n", j, d);
		if(temp[arr[j][8-j]] == 0){
			temp[arr[j][8-j]]++;
		}else{
			return 1;
		}
	}

	return 0;
}
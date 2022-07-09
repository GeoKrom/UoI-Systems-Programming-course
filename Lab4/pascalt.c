#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int **pascal(int n);

int main(int argc, char *argv[]){
    int **p;
    int i, j;
    
    if(argc < 1){
        return 1;
    }

    int k = atoi(argv[1]);
    
    p = pascal(k);
    
    if(p == NULL){
        return 1;
    }
    
    for (i = k-1; i >= 0; i--){
		for( j = 0; j < k-i; j++){
			printf("%d ",p[i][j] );
            
		}
        free(p[i]);
		printf("\n");
	}
    free(p);
    return 0;
}

int **pascal(int n){
    int i,j;
    int **trig;

    trig = (int **) malloc(n*sizeof(int *));

    for(i = 0; i < n; i++){
        trig[i] = (int *) malloc((n-i)*sizeof(int));
    }

    for(i = n-1; i >= 0; i--){
        for(j = 0; j < n-i; j++){
            if(j == 0){
                trig[i][j] = 1;
            }
            else if(j == n-i-1){
                trig[i][j] = 1;
            }
            else{
                trig[i][j] = trig[i+1][j] + trig[i+1][j-1];
            }
        }
    }

    return trig;
}
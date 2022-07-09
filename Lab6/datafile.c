#include <stdio.h>
#include <stdlib.h>


int main(void){

    int pos_nums, neg_nums, i;
    int sum = 0;
    int *ptr, *p;
    int fileSize, sizePos;
    FILE *fp, *infile;
    FILE *pos_fp, *neg_fp;
    
    fp = fopen("data.txt", "r");
    if(fp  == NULL){
        return 1;
    }
    
    fseek(fp, 0L, SEEK_END);
    fileSize = (int) ftell(fp);
    rewind(fp);
    
    pos_fp = fopen("positive.txt", "w");
    if(pos_fp == NULL){
        return 1;
    }

    neg_fp = fopen("negative.txt", "w");
    if(neg_fp == NULL){
        return 1;
    }
    
    ptr = (int *) malloc(fileSize*sizeof(int));
    
    for(i = 0; i < fileSize; i++){
        if(ptr[i] < 0){
            neg_nums++;
        }else{
            pos_nums++;
        }
    }
    
    fprintf(pos_fp, "%d", pos_nums);
    fprintf(neg_fp, "%d", neg_nums);
    
    for(i = 0; i < fileSize; i++){
        if(ptr[i] < 0){
            fprintf(neg_fp, "%d", ptr[i]);
        }else{
            fprintf(pos_fp, "%d", ptr[i]);
        }
    }
    fclose(fp);
    fclose(pos_fp);
    fclose(neg_fp);
    free(ptr);

    /*infile = fopen("positive.txt", "r");
    if(infile == NULL){
        return 1;
    }
    fscanf(infile, "%d", &sizePos);
    p = (int *) malloc(fileSize*sizeof(int));

    for(i = 0; i < sizePos; i++){
        fscanf(pos_fp, "%d", &p[i]);
    }

    for(i = 0; i < sizePos; i++){
        sum += p[i];
    }
    printf("The sum of positive numbers is sum = %d\n", sum);
    fclose(infile);
    free(p);*/
    return 0;
}
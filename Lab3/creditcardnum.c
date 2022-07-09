#include<stdio.h>
#include<string.h>

int check_credit_card(char *str);

int main(int argc, char *argv[]){

    int i, n;
    for(i = 1; i < argc; i++){
        n = check_credit_card(argv[i]);

        if(n == 1){
            printf("The credit card %s is valid!\n", argv[i]);
        }else{
            printf("The credit card %s is invalid!\n", argv[i]);
        }
    }
    return 0;
}

int check_credit_card(char *str){
    
    int credit_num, k;
    int i = 2, j = 0;
    for(credit_num = 15; credit_num > 0; credit_num--){
        if(i%2 == 0){
            k = 2*(*(str + credit_num) - '0');
            if( k >= 10){
                k = k - 9;
            }
            j += k;
        }else{
            j = (*(str + credit_num) - '0');
        }
        if(j%10 == 0){
            return 1;
        }
    }

    return 0;
}
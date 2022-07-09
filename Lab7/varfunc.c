#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

void printnums(int n, ...);

int main(){

    printnums(4, 'i', 12, 'd', 23.4, 'i', 14, 'd', 2.345);
    return 0;
}


void printnums(int n, ...){
   
    va_list args;
    int integer;
    double real;
    int i, t;

    va_start(args, n);
    for(i = 0; i < n; i++){
        t = va_arg(args, int);
        if(t == 'i'){
            integer = va_arg(args, int);
            printf("An int number %d\n", integer);
        }
        else if(t == 'd'){
            real = va_arg(args, double);
            printf("A real number %.5lf\n", real);
        }else{
            perror("Var Func");
            exit(1);
        }
    }
    va_end(args);
}
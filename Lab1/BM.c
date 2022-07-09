#include<stdio.h>

int main(){
	int A, ap;
	double PR1, PR2, BE, TE, GR;
	
	printf("Please enter the number of apousies: ");
	scanf("%d", &ap);
	
	if(ap == 0){
		A = 10;
	}else if(ap == 1){
		A = 5;
	}else{
		A = 0;
	}
	
	printf("Please enter the grade of first mid-term exam: ");
	scanf("%lf", &PR1);
	printf("Please enter the grade of second mid-term exam: ");
	scanf("%lf", &PR2);
	
	BE = 0.2*A + 0.4*PR1 + 0.4*PR2;
	
	if(BE < 4.5){
		printf("Failure in Laboratoty!");
		return -1;
	}
	
	printf("Please enter the exam grade: ");
	scanf("%lf", &TE);
	
	GR = 0.5*BE + 0.5*TE;
	
	printf("Success in MYY502 with grade %lf\n", GR);
	
	return 0;
}
/* Skeleton file for LAB5, Problem 1 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STUDENT_NUM 15


struct student {
	char *name;
	int am;
	float grade;
};

typedef struct student student_t;


/* Specify return type */
student_t *create_struct_table(char *s_name[], int s_am[], float s_grade[]){
	
	int i;
	student_t *std;
	std = (student_t *) malloc(STUDENT_NUM*sizeof(student_t));
	for(i = 0; i < STUDENT_NUM; i++){
		std[i].name = strdup(s_name[i]);
		std[i].am = s_am[i];
		std[i].grade = s_grade[i];
	}

	return std;

}

void show_struct_table(student_t *std){
	
	int i;
	printf("The struct table is\n");
	
	for(i = 0; i < STUDENT_NUM; i++){
		printf("----------------------------------------------------------------------------\n");
		printf("Name: %s AM: %d Grade: %.2f \n", std[i].name, std[i].am, std[i].grade);
		
	}
	printf("----------------------------------------------------------------------------\n");
}

float compute_average_grade(student_t *std){

	int i;
	float avg, sum = 0.0;
	for(i = 0; i < STUDENT_NUM; i++){
		sum += std[i].grade;
	}
	avg = sum/((float) STUDENT_NUM);
	return avg;
}

void print_failed_names(student_t *std){
	
	int i;
	printf("The students who failed are\n");
	for(i = 0; i < STUDENT_NUM; i++){
		if(std[i].grade < 10.0){	
			printf("Name: %s\n", std[i].name);
		}
	}
}

void change_failed_names(student_t *std){

	int i;
	
	for(i = 0; i < STUDENT_NUM; i++){
		if(std[i].grade < 10.0){
			std[i].name = (char *) realloc(std[i].name, (strlen(std[i].name)+10)*sizeof(char));
			strcat(std[i].name, " (failed)");
		}
	}
}
void write_students_stats(FILE *infile, student_t *std){
	int i;
	fprintf(infile, "%d\n", STUDENT_NUM);
	for(i = 0; i < STUDENT_NUM; i++){
		fprintf(infile, "Name: %s AM: %d Grade: %.2f\n", std[i].name, std[i].am, std[i].grade);
	}

}
int main(void){

	char *name[] = {
		"Georgios Georgiou", "Vasilios Vasiliou", "Ioanna Ioannidou", 
		"Nikos Nikolaou", "Kiriakos Kiriakidis", "Kwstas Kwstantinidis", 
		"Spyros Spyropoulos", "Dimitris Dimitropoulos", "Dimitra Dimitriadi", 
		"Areti Aretidou", "Ilias Iliopoulos", "Kwstas Kwstoglou",
    	"Aimilia Aimilianou", "Xristina Xristopoulou", "Theodoros Theodorou"
	};
    
	int am[] = {
		120, 122, 142, 130, 156, 132, 145, 133, 131, 140, 141, 150, 155, 134, 146
	};

	float grade[] = {
		12, 8.5, 15.5, 20, 7.5, 1, 19.5, 12, 17, 17.5, 15.5, 18, 19, 18, 19
	};
	
	student_t *class;
	float grade_avg;
	FILE *fp;
	long int size_file;
	class = create_struct_table(name, am, grade);
	show_struct_table(class);
	grade_avg = compute_average_grade(class);
	printf("The average grade of the class is avg = %.2f\n\n", grade_avg);
	change_failed_names(class);
	printf("After changing names...\n");
	print_failed_names(class);
	
	if((fp = fopen("students.txt", "w+")) == NULL){
		printf("Couldn't open the text file!\n");
		return 1;
	}

	write_students_stats(fp, class);
	fseek(fp, 0L, SEEK_END);
	size_file = ftell(fp);
	printf("The size of the file is size = %ld Bytes\n", size_file);
	rewind(fp);
	fclose(fp);
	return 0;
}

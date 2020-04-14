#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// male vector
typedef struct male {
	char name[10];
} m;

void processMale(m);

// female vecotr
typedef struct female {
	char name[10];
} f;

// couple vector
typedef struct couple {
	char mname[10];
	char fname[10];
} c; 

void processFemale(f);

// function prototype
void generateAllCouples(struct male m, struct female f);

FILE* pMale;
FILE* pFemale;
FILE* pCouples;
errno_t err;
m m1 = { 0 }; // initialize members
f f1 = { 0 }; // initialize members
c c1 = { 0 }; // initialize members

int main() {
	// declare variables
	int x = 0;

	// get male names
	err = fopen_s(&pMale, "males.dat", "w");
	if (pMale == NULL)
		goto ErrorHandler;
	else
		for (x = 0; x < 5; x++) {
			printf("\nPlease enter the name of the male\n");
			scanf_s("%s", m1.name, 10);
			fprintf(pMale, "%s\n", m1.name);
		} // end for loop
	fclose(pMale);

	// get female names
	err = fopen_s(&pFemale, "females.dat", "w");
	system("cls");
	if (pFemale == NULL)
		goto ErrorHandler;
	else
		for (x = 0; x < 5; x++) {
			printf("\nPlease enter the name of the female\n");
			scanf_s("%s", f1.name, 10);
			fprintf(pFemale, "%s\n", f1.name);
		} // end for loop
	fclose(pFemale);

	// call the function
	generateAllCouples(m1, f1);

	exit(EXIT_SUCCESS); // exit program normally

	ErrorHandler: perror("The following error occured");
	exit(EXIT_FAILURE); // exit program with error

} // end main

void generateAllCouples(struct male m1, struct female f1) {
	err = fopen_s(&pMale, "males.dat", "r");
	err = fopen_s(&pFemale, "females.dat", "r");
	err = fopen_s(&pCouples, "couples.dat", "w");
	while (fscanf_s(pMale, "%s", m1.name, 10) != EOF && fscanf_s(pFemale, "%s", f1.name, 10) != EOF) {
		strcpy_s(c1.mname, 10, m1.name);
		strcpy_s(c1.fname, 10, f1.name);
		fprintf(pCouples, "%s\t%s\n", c1.mname, c1.fname);
	} // end loop
	fclose(pMale);
	fclose(pFemale);
	fclose(pCouples);
	err = fopen_s(&pCouples, "couples.dat", "r");
	system("cls");
	printf("The cross product of male and female names are: \n");
	while (fscanf_s(pCouples, "%s %s", c1.mname, 10, c1.fname, 10) != EOF) {
		printf("%s\t%s\n", c1.mname, c1.fname);
	} // end loop
	fclose(pCouples);
} // end generateAllCouples

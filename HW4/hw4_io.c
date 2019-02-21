/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
#include<stdio.h>
/* takes values for 3. degree polynomial */
int read_polynomial3(double *a0, double *a1, double *a2, double *a3)
{
	printf("please enter 4 numbers as the coefficients of a degree-3 polynomial; first one must be different than 0!\n");
	scanf("%lf %lf %lf %lf", a3, a2, a1, a0);
	
	while(*a3==0){ /* a3 mustn't be 0 or it can't be 3. degree */
		printf("first one must be different than 0!\n");
		scanf("%lf", a3);
	}
	
return 0;
}
/* takes values for 4. degree polynomial */
int read_polynomial4(double *a0, double *a1, double *a2, double *a3, double *a4)
{
	printf("please enter 5 numbers as the coefficients of a degree-4 polynomial; first one must be different than 0!\n");
	scanf("%lf %lf %lf %lf %lf", a4, a3, a2, a1, a0);
	
	while(*a4==0){ /* a3 mustn't be 0 or it can't be 4. degree */
		printf("first one must be different than 0!\n"); 
		scanf("%lf", a4);
	}
	
return 0;
}
/*prints 3. degree polynomial */
void write_polynomial3(double a0, double a1, double a2, double a3)
{
	read_polynomial3( &a0, &a1, &a2, &a3); /*we take values to write our polynomial in read_polynomial3*/
	if(a3==1){
		printf("x³"); /*to not print 1 or -1*/
	}
	else if(a3==-1){
		printf("-x³"); 
	} else {
	printf("%gx³", a3); 
	}

	if(a2==1){
		printf("+x²"); 
	}else if(a2==-1){
		printf("-x²");
	}
	else if (a2==0){
		printf(" ");
	} else {
	printf("%+gx²", a2);  /* %g throws useless 0's, + prints sign of number*/
	}

	if(a1==1){
		printf("+x"); 
	}
	else if(a1==-1){
		printf("-x");
	}
	else if (a1==0){
		printf(" ");
	} else {
	printf("%+gx", a1);
	}

	if (a0==0){
		printf(" ");
	} else {
	printf("%+g", a0);
	}
}
/*prints 4. degree polynomial */
void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
	read_polynomial4( &a0, &a1, &a2, &a3, &a4);  /*we take values to write our polynomial in read_polynomial3*/
	if(a4==1){
		printf("x⁴"); /*to not print 1 or -1*/
	}
	else if(a4==-1){
		printf("-x⁴");
	} else {
	printf("%gx³", a4);
	}

	if(a3==1){
		printf("+x³");
	}
	else if(a3==-1){
		printf("-x³");
	}
	else if (a3==0){
		printf(" ");
	} else {
	printf("%+gx³", a3);
	}

	if(a2==1){
		printf("+x²");
	}
	else if(a2==-1){
		printf("-x²");
	}
	else if (a2==0){
		printf(" ");
	} else {
	printf("%+gx²", a2); /* %g throws useless 0's, + prints sign of number*/
	} 

	if(a1==1){
		printf("+x");
	}
	else if(a1==-1){
		printf("-x");
	}
	else if (a1==0){
		printf(" ");
	} else {
	printf("%+gx", a1);
	}

	if (a0==0){
		printf(" ");
	} else {
	printf("%+g", a0);
	}
}

/*
** main.c:
**
** The test program for the homework.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.14
** 
*/


#include <stdio.h>


#include "hw4_lib.h"
#include "hw4_io.h"



/*
** Testing derivative calculations..
**
*/
void test_compare_derivatives() {
	double f(double x) { return x*x; }
	double d1(double x) { return 2.0*x; }
	double d2(double x) { return 2.0; }
	double e1, e2;
	int res = compare_derivatives(f, d1, d2, 1.0, 0.0001, &e1, &e2);
	printf("%.14lf %.10lf \n",e1,e2);
}
void test_int()
{
	double f(double x) { return x; }
	double res = integral(f, 2, 8, 0.0001);
	printf("%lf\n", res);	
}

/*
** main function for testing the functions...
**
*/
int main(void) {
	test_compare_derivatives();
	test_int();
	return (0);
} /* end main */

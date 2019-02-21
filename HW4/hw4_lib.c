/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include<stdio.h>
/* derivative function*/
int derivatives(double f(double a), double x, double eps, double *d1, double *d2)
{

	*d1 = (f(x+eps)-f(x-eps))/ (2*eps); /*first derivative*/
	if(eps==0){
		return -1;/*if divider is 0 , it means there is a problem;return -1*/
	}
	*d2 = (f(x+eps)-(2*f(x))+f(x-eps))/ (eps*eps);
	if(eps==0){
		return -1; /*if divider is 0 , it means there is a problem;return -1*/
	}
return 1;
}
/*compare actual and numeric derivatives*/
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double *e1, double *e2)
{
	/* error = |x0 - x|*/

	double d_1, d_2;
	derivatives(f, x, eps, &d_1, &d_2);
	*e1 = d_1 - d1(x); 
	if(*e1<0){
		*e1 *= -1; /* to take absolute */
	}
	*e2 = d_2 - d2(x);
	if(*e2<0){
		*e2 *= -1; /* to take absolute */
	}
return 0;
}
/* Calculate integral*/
double integral(double f(double x), double xs, double xe, double delta)
{
	double total=0;
	for(double i=xs; i<(xe-delta); i=i+delta) 
	{
		total+=f(i)*delta; /* left riemann sum*/
	}
return total;
}

double integral2(double f(double x, double y), double xs, double xe, double ys, double ye,double delta)
{
	double total = 0;

	for(double j=ys; j<(ye); j=j+delta) /*to be three dimensional it must change on y coordinate, too*/
	{
			for(double i=xs; i<(xe); i=i+delta)
		{
			 total+=f(i,j); /* left riemann sum*/
		}
	
	}
	total*= delta*delta;
return total;
}

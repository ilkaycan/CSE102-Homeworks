#include <stdio.h>
#include <math.h>
#define PI 3.14
int side1;
int side2;
double radius;

double circle_area(double radius);
double calc_hypotenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(double radius);
double calc_area_of_largest_circle(double radius);
double calc_area_of_square(int side);
double calc_area_of_smallest_square(int side1,int side2);
double calc_area_of_largest_square(int side1,int side2);
void display_results(double largest_circle ,double largest_square, double smallest_circle, double smallest_square);

int main()
{
	double largest_circle, largest_square, smallest_circle, smallest_square;

	printf("Enter the first side of rectangle\n");
	scanf("%d", &side1);
	printf("Enter the second side of rectangle\n");
	scanf("%d", &side2);

	display_results(largest_circle ,largest_square,smallest_circle,smallest_square);
return 0;
}

double circle_area(double radius) /* calculates area of a circle*/
{
	double area;
	area = pow(radius,2) *PI;
return area;
}

double calc_hypotenuse(int side1, int side2) /* calculates hypotenuse of rectangle to find diameter of smallest circle that surrounds the same rectangle */
{
	double hypotenuse, temp1, temp2;
	temp1 = pow(side1, 2);
	temp2 = pow(side2, 2);
	hypotenuse = sqrt(temp1+temp2);
return hypotenuse;
}

double calc_radius_of_smallest_circle(int side1, int side2) /* calculates radius of smallest circle that surrounds the rectangle*/
{
	double radius_small;
	radius_small = calc_hypotenuse(side1, side2) / 2;
return radius_small;
}

double calc_radius_of_largest_circle(int side1, int side2) /* calculates radius of largest circle that fits inside the rectangle*/
{
	double radius_large;
	if(side1<=side2){
		radius_large = (double)side1/2;
	} else {
		radius_large = (double)side2/2;
	}
return radius_large;
}

double calc_area_of_smallest_circle(double radius)/* calculates area of smallest circle that surrounds the rectangle*/
{
	double area;
	area = circle_area(calc_radius_of_smallest_circle(side1,side2));
return area;
}

double calc_area_of_largest_circle(double radius)/* calculates area of smallest circle that surrounds the rectangle*/
{
	double area;
	area = circle_area(calc_radius_of_largest_circle(side1,side2));
return area;
}

double calc_area_of_square(int side) /* calculates area of a square */
{
	double area;
	area = pow(side,2);
return area;
}

double calc_area_of_smallest_square(int side1,int side2)/* The area of the smallest square that surrounds the rectangle */
{
	double area;
	if(side1>=side2){
		area = calc_area_of_square(side1);
	} else {
		area = calc_area_of_square(side2);
	}
return area;
}

double calc_area_of_largest_square(int side1,int side2)/* The area of the largest square that fits inside a rectangle */
{
	double area;
	if(side1<=side2){
		area = calc_area_of_square(side1);
	} else {
		area = calc_area_of_square(side2);
	}
return area;
}

void display_results(double largest_circle ,double largest_square, double smallest_circle, double smallest_square)/* prints the results */
{
	
	largest_circle = calc_area_of_largest_circle(radius);
	printf("\nThe area of the largest circle that fits inside a rectangle:        %.2lf", largest_circle);
	largest_square = calc_area_of_largest_square(side1,side2);
	printf("\nThe area of the largest square that fits inside a rectangle:        %.2lf", largest_square);
	smallest_circle = calc_area_of_smallest_circle(radius);
	printf("\nThe area of the smallest circle that surrounds the same rectangle:  %.2lf", smallest_circle);
	smallest_square = calc_area_of_smallest_square(side1,side2);
	printf("\nThe area of the smallest square that surrounds the same rectangle:  %.2lf\n", smallest_square);
}




































































































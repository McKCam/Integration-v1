/*	[Name Redacted]
	[Course Name Redacted]
	11/05/19
	IntegrationV1.cpp
	Program asks for a and b limits to calculate the integral using rectangular method.
	If b < a, the program ends. 
	Otherwise program calculates & displays 
	the approximate and exact calculation of integral.
*/

#include "pch.h"	
#include <iostream>	
#include <cmath>

using namespace std;

double exactIntegral(double a, double b);

int main()
{
	double lowerLimit = 0.0, upperLimit = 0.0;	// Variables for a & b
	double theExactIntegral = 0.0;
	const double deltaX = 0.01;	// Length of each rectangle
	int n = 0;		// Variable for finding amount of rectangles
	double function = 0.0;	// Variable for f(x)
	double approxIntegral = 0.0;	// Variable for approximate integral
	double rectangle = 0.0,		// Variable for holding a rectangle
		rectangleCount = 0.0;	// Variable for counting the rectangles

	cout << "------Numerical Integration------" << endl;
	cout << "----of f(x) = x^3 - 4x^2 + 11----";		
	cout << endl;	
	cout << "First, enter the lower Limit: ";
	cout << "a = ";
	cin >> lowerLimit;
	cout << "Next, enter the upper limit: ";
	cout << "b = ";
	cin >> upperLimit;

	if (upperLimit < lowerLimit)
	{
		cout << endl;
		cout << "Invalid limits of integration." << endl;
		cout << "Program has exited." << endl;
		return 1;
	}
	else
	{
		cout << endl;	
		cout << "-------------Results-------------" << endl;
		cout << "The exact integral: ";		
		theExactIntegral = exactIntegral(lowerLimit, upperLimit);	
		cout << theExactIntegral << endl;

		n = (upperLimit - lowerLimit) / deltaX; // Calculating number of rectangles

		for (rectangleCount = 0; rectangleCount < n; rectangleCount++)
		{
			function = pow(lowerLimit, 3) - (4 * pow(lowerLimit, 2)) + 11;  // Get the height of current rectangle, f(lowerLimit)
			lowerLimit += deltaX;	// Adding deltaX to lowerLimit for every iteration
			rectangle = function * deltaX;	// Find the area of each rectangle

			approxIntegral += rectangle;	// Adding up all the rectangle areas iteratively
		}

		cout << "The approximate integral: ";
		cout << approxIntegral << endl;	
		cout << "---------------------------------";
	}
     
}

double exactIntegral(double a, double b)
{
	double integralFTC = 0.0; 

	double integralB = (1.0 / 4.0) * pow(b, 4) -	
		(4.0 / 3.0) * pow(b, 3) + 11.0 * b;		
	double integralA = (1.0 / 4.0) * pow(a, 4) -	
		(4.0 / 3.0) * pow(a, 3) + 11.0 * a;			

	integralFTC = integralB - integralA;	// FTC = F(b) - F(a)

	return integralFTC;
}

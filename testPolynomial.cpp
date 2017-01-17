//===============================================================================================================//
//=10/31/2016                                                                                    Alexander Alava=//
//=testPolynomial.cpp                                                                                  U35432961=//
//=                                                                                                             =//
//=                           This is the driver class for the polynomial class                                 =//
//===============================================================================================================//

#include "polynomial.h"
#include <iostream>
using namespace std;

int main (void)
{
	// Instantiating three Polynomial objects //
	Polynomial poly1;
	Polynomial poly2;
	Polynomial poly3;

	// Calling the set function to initialize two polynomials //
	poly1.setPoly();
	poly2.setPoly();

	// Printing the first polynomial inputted by the user //
	cout << "\nYour Polynomial 1 is: ";
	poly1.printPoly();
	
	// Printing the second polynomial inputted by the user //
	cout << "\nYour Polynomial 2 is: ";
	poly2.printPoly();
	
	// Performing addition with the overloaded + operator and printing the result //
	cout << "\n\n\nPolynomial 1 + Polynomial 2: ";
	poly3 = poly1 + poly2;
	poly3.printPoly();

	// Resetting the value of poly3 through the overloaded assignment operator = //
	poly3 = poly1;
	
	// Performing addition assignment with the overloaded += operator and printing the result //
	cout << "\nPolynomial 1 += Polynomial 2: ";
        poly3 += poly2;
        poly3.printPoly();
	
	// Performing substraction with the overloaded - operator and printing the result //
	cout << "\nPolynomial 1 - Polynomial 2: ";
        poly3 = poly1 - poly2;
        poly3.printPoly();

	// Resetting the value of poly3 through the overloaded assignment operator = //
	poly3 = poly1;
	
	// Performing substraction assignment with the overloaded -= operator and printing the result //
	cout << "\nPolynomial 1 -= Polynomial 2: ";
        poly3 -= poly2;
        poly3.printPoly();
	
	// Performing multiplication with the overloaded * operator and printing the result //
	cout << "\nPolynomial 1 * Polynomial 2: ";
        poly3 = poly1 * poly2;
        poly3.printPoly();	

	// Resetting the value of poly3 through the overloaded assignment operator = //
	poly3 = poly1;

	// Performing multiplication assignment with the overloaded *= operator and printing the result //
	cout << "\nPolynomial 1 *= Polynomial 2: ";
        poly3 *= poly2;
        poly3.printPoly();

	// Printing a disclaimer to let the user know the limits of the program //
	cout << "\n\n*** Disclaimer: This program will only be accurate if the highest degree is x^100 ***\n\n\n";

	return 0;
}


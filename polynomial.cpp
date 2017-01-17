//===========================================================================================================================================//
//=10/31/2016                                                                                                                Alexander Alava=//
//=polynomial.cpp                                                                                                                  U35432961=//
//=                                                                                                                                         =//
//=                                       This is the implementation file for the polynomial class                                          =//
//===========================================================================================================================================//

#include "polynomial.h"
#include <iostream>
using namespace std;

// Defining the constructor for the class Polynomial //
Polynomial::Polynomial()
{
	// Establishing a for loop that will initialize 101 elements in the array //
	for (int i = 0; i <= 100; i++)
	{
		// Initializing each element in the array to zero //
		polyTerms[i] = 0;
	}
}

// Defining the set function for the class Polynomial //
void Polynomial::setPoly()
{
	// Prompting for and reading in user input for the degree of the polynomial //
	cout << "\nPlease enter the degree of your polynomial: ";
	cin >> degree;
	
	// Establishing a for loop that will let the user set the coefficients of the polynomial //
	for (int i = 0; i <= degree; i++)
	{
		// Prompting for and reading in user input for each coefficient //
		cout << "\nPlease enter the coefficient of your term of degree x^" << i << ": ";
		cin >> polyTerms[i];
	}
}

// Defining the get function for the class Polynomial //
int Polynomial::getPoly(int term)
{
	return polyTerms[term];
}

// Defining the print function for the class Polynomial //
void Polynomial::printPoly()
{
	bool isZero = false;

	// Establishing a for loop that will run through all the members of the array backwards //
	for (int i = degree; i >= 0; i--)
	{	
		// Checking if the coefficient is zero to avoid printing the term //
		if (polyTerms[i] == 0)
		{
			continue;
		}
		// Checking if the coefficient is negative and is not the last term //
		else if (polyTerms[i] < 0 && i != 0)
		{
			cout << "(" << polyTerms[i] << "x^" << i << ") + ";
		}
		// Printing terms with the degree greater than zero and coefficient greater than one //
		else if (i > 0 && polyTerms[i] > 1)
		{
			cout << polyTerms[i] << "x^" << i << " + ";
		}
		// Printing the last term with the degree equal to zero //
		else if (i == 0 && polyTerms[i] > 0)
		{
			cout << polyTerms[i] << "\n" << endl;
		}
		// Checking if it is the last term and the coefficient is negative //
		else if (i == 0 && polyTerms[i] < 0)
		{
			cout << "(" << polyTerms[i] << ")\n" << endl;
		}
		// Checking if the coefficient is one to avoid printing it //
		else if(polyTerms[i] == 1)
		{
			cout << "x^" << i << " + ";
		}
	}

	// Establishing a for loop that will run through all the members of the array backwards //
	for (int i = degree; i >= 0; i--)
	{
		// Checking if the coefficient at i is zero //
		if (polyTerms[i] == 0)
		{
			isZero = true;
		}
		// Checking if the coeeficient at i is non-zero and breaking the loop in that case //
		else
		{
			isZero = false;
			break;
		}
	}

	// Checking if the polynomial is all zeros //
	if (isZero)
	{
		cout << "0\n" << endl;
	}
}

// Defining the overloaded assignment operator //
Polynomial & Polynomial::operator = (Polynomial &polyOverload)
{
	// Establishing a for loop to run through all the elements of the arrays //
	for (int i = 0; i <= 100; i++)
	{
		// Assigning each coefficient of the polynomial //
		this->polyTerms[i] = polyOverload.polyTerms[i];
		
		// Assigning the degree of the polynomial //
		this->degree = polyOverload.degree;
	}
	return *this;
} 

// Defining the overloaded addition operator //
Polynomial & Polynomial::operator + (Polynomial & polyOverload)
{
	// Instatiating a Polynomial object and declaring a Polynomial pointer  //
	Polynomial temp, *tempPt;

	// Checking which degree should be assigned to the temp polynomial //
	if (this->degree > polyOverload.degree)
	{
		temp.degree = this->degree;
	}
	else
	{
		temp.degree = polyOverload.degree;
	}

	// Establishing a for loop to run through all the elements of the arrays //
	for (int i = 0; i <=100 ; i++)
	{	
		// Assigning the addition values to each of the array elements //
		temp.polyTerms[i] = this->getPoly(i) + polyOverload.getPoly(i);
	}

	// Assigning the address of the temp Polynomial object to the Polynomial pointer //
	tempPt = &temp;

	return *tempPt;
}

Polynomial & Polynomial::operator - (Polynomial & polyOverload)
{
	// Instantiating a Polynomial object and declaring a Polynomial pointer //
        Polynomial temp, *tempPt;

	bool isEqual = false;

	// Checking which degree should be assigned to the temp polynomial //
        if (this->degree > polyOverload.degree)
        {
                temp.degree = this->degree;
        }
        else
        {
                temp.degree = polyOverload.degree;
        }

	// Establishing a for loop to run through all the elements of the arrays //
	for (int i = 0; i <=100 ; i++)
        {
		// Assigning the substraction values to each of the array elements //
                temp.polyTerms[i] = this->getPoly(i) - polyOverload.getPoly(i);
        }

	// Assigning the address of the temp Polynomial object to the Polynomial pointer //
	tempPt = &temp;	

        return *tempPt;
}

// Defining the overloaded multiplication operator //
Polynomial & Polynomial::operator * (Polynomial & polyOverload)
{
	// Declaring an object of class Polynomial and declaring a Polynomial pointer //
        Polynomial temp, *tempPt;

	// Assigning the degree data member of the object created //
        temp.degree = this->degree + polyOverload.degree;
	
	// Establishing a for loop to run through all the elements of the first array //
        for (int i = 0; i <=100 ; i++)
        {
		// Establishing a for loop to run through all the elements of the second array //
        	for (int j = 0; j <=100; j++)
		{
			// Assigning values to each index that results from the multiplication //
			temp.polyTerms[i + j] += (this->getPoly(i) * polyOverload.getPoly(j));
		}
	}
	
	// Assigning the address of the temp Polynomial object to the Polynomial pointer //
	tempPt = &temp;
	
        return *tempPt;
}

// Declaring the overload addition assignment operator //
Polynomial & Polynomial::operator += (Polynomial & polyOverload)
{
	// Checking if the current degree of the polynomial is the correct one //
	if (this->degree < polyOverload.degree)
        {
		// Assigning the degree of the second polynomial to the first one //
                this->degree = polyOverload.degree;
        }

	// Establishing a for loop to run through all the elements of the arrays //
	for (int i = 0; i <=100 ; i++)
        {
		// Assigning the addition values to each one of the array elements //
                this->polyTerms[i] = this->getPoly(i) + polyOverload.getPoly(i);
        }
	
	return *this;
}

Polynomial & Polynomial::operator -= (Polynomial & polyOverload)
{
	// Checking if the current degree of the polynomial is the correct one //
        if (this->degree < polyOverload.degree)
        {
                this->degree = polyOverload.degree;
        }

	// Establishing a for loop to run through all the elements of the arrays //
        for (int i = 0; i <=100 ; i++)
        {
                this->polyTerms[i] = this->getPoly(i) - polyOverload.getPoly(i);
        }

        return *this;
}

// Declaring the overloaded function multiplication assignment operator //
Polynomial & Polynomial::operator *= (Polynomial & polyOverload)
{
	// Calling the overloaded multiplication operator //
       	(*this) = (*this) * polyOverload;

        return *this;
}

// Defining the destructor for the class Polynomial //
Polynomial::~Polynomial()
{
	// Empty body for the destructor //
}

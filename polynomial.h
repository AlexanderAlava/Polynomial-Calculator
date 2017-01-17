//=========================================================================================================//
//=10/31/2016                                                                              Alexander Alava=//
//=polynomial.cpp                                                                                U35432961=//
//=                                                                                                       =//
//=                         This is the header file for the polynomial class                              =//
//=========================================================================================================//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
	private:

	// Declaring an integer variable and an integer array variable //
	int degree;
	int polyTerms[100];

	public:

	// Declaring non-overloading member functions//
	Polynomial();
	void setPoly();
	int getPoly(int term);
	void printPoly();
	~Polynomial();
	
	// Declaring overloading member functions //	
	Polynomial & operator + (Polynomial &polyOverload);
	Polynomial & operator - (Polynomial &polyOverload);
	Polynomial & operator = (Polynomial &polyOverload);
	Polynomial & operator * (Polynomial &polyOverload);
	Polynomial & operator += (Polynomial &polyOverload);
	Polynomial & operator -= (Polynomial &polyOverload);
	Polynomial & operator *= (Polynomial &polyOverload);
	
};
#endif

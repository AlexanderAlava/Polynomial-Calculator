#######################################################################################
##10/31/2016                                                	      Alexander Alava##
##makefile                                                        	    U35432961##
## This program is the makefile for the file "testPolynomial.cpp" and its dependants ##
#######################################################################################

calculator: testPolynomial.o polynomial.o
	g++ -o calculator testPolynomial.o polynomial.o

testPolynomial.o: testPolynomial.cpp polynomial.cpp polynomial.h
	g++ -c testPolynomial.cpp polynomial.cpp

polynomial.o: polynomial.cpp polynomial.h
	g++ -c polynomial.cpp 

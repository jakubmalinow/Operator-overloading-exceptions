// zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"

int main()
{

	Matrix y( 2, 2);
	Matrix z( 2, 2 );
	z(1,1) = 217;
	cout << z( 6, 2 ) << endl;
	y = z;
	cout << y.data[1][1] << endl;
	cout << y[1][1] << endl;
	y[1][1] = 218;
	cout << y[1][3] << endl;

	return 0;
}
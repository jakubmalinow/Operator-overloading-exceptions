#pragma once
#include <iostream>
using namespace std;

class Matrix
{

	unsigned int width;
	unsigned int height;
	
	static unsigned int allocated; // liczba bajt�w u�ywana
	static unsigned int total; // liczba ca�kowita bajt�w kt�ra moze by� u�ywana przez obiekty klasy
public:
	int** data; // wska�nik na dane (jako public zeby latwiej bylo testowac)

	Matrix( int w, int h );
	~Matrix();

	void *operator new(size_t size);	// zlicza ile bajt�w zosta�o zaalokowane i je�li zbyt du�o to rzuca wyj�tek kt�ry dziedziczy po klasie std::bad_alloc 
	void operator delete(void *pointer);

	int& operator()(unsigned int x, unsigned int y ); // pozwala uzyska� element z tablicy znajduj�cy si� na wsp�rz�dnych x i y, w przypadku przekroczenia wymiar�w tablicy, rzucany jest wyj�tek
	Matrix& operator=( const Matrix & m ); // przepisuje elementy z innej macierzy o ile wymiary si� zgadzaj�, w innym wypadku rzucany jest wyj�tek
	int* operator[]( unsigned int x);
};


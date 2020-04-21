#pragma once
#include <iostream>
using namespace std;

class Matrix
{

	unsigned int width;
	unsigned int height;
	
	static unsigned int allocated; // liczba bajtów u¿ywana
	static unsigned int total; // liczba ca³kowita bajtów która moze byæ u¿ywana przez obiekty klasy
public:
	int** data; // wskaŸnik na dane (jako public zeby latwiej bylo testowac)

	Matrix( int w, int h );
	~Matrix();

	void *operator new(size_t size);	// zlicza ile bajtów zosta³o zaalokowane i jeœli zbyt du¿o to rzuca wyj¹tek który dziedziczy po klasie std::bad_alloc 
	void operator delete(void *pointer);

	int& operator()(unsigned int x, unsigned int y ); // pozwala uzyskaæ element z tablicy znajduj¹cy siê na wspó³rzêdnych x i y, w przypadku przekroczenia wymiarów tablicy, rzucany jest wyj¹tek
	Matrix& operator=( const Matrix & m ); // przepisuje elementy z innej macierzy o ile wymiary siê zgadzaj¹, w innym wypadku rzucany jest wyj¹tek
	int* operator[]( unsigned int x);
};


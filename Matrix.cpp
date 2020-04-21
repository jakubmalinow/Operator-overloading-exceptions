#include "Matrix.h"

unsigned int Matrix::allocated = 0;
unsigned int Matrix::total = 100;

Matrix::Matrix( int w, int h ) : width( w ), height( h )
{
	int toAllocate = sizeof( int ) * w * h;
	try
	{
		if( toAllocate + allocated > total )
		{
			throw 101;
		}
		else
		{
			data = new int*[width];
			if(data!= nullptr)
				for( unsigned int i = 0; i < height; i++ )
				{
					data[i] = (int*)calloc(height,sizeof(int));
					if( data[i] == nullptr ) throw 103;
				}
			else throw 102;
		}
		allocated += toAllocate;
		cout << "[+] Succesfuly allocated " << toAllocate << " bytes of memory. Total allocated: " << allocated << endl;
	}
	catch(int exNo)
	{
		if(exNo == 101) cout << "[-] Tried to allocate more than " << total << " bytes of memory! [code " << exNo << "]"<< endl;
		else cout << "[-] Error occured when trying to allocate memory! [code " << exNo << "]" << endl;
	}
}

Matrix::~Matrix()
{
	if( data != nullptr )
	{
		for( unsigned int i = 0; i < width; i++ )
		{
			delete[] data[i] ;
		}
		delete[] data;
		data = NULL;

		int toFree = sizeof( int ) * width * height;
		allocated -= toFree;

		cout << "[+] Succesfuly freed " << toFree << " bytes of memory. Total allocated: " << allocated << endl;
	}
}

void* Matrix::operator new(size_t size)
{
	void* pRet = nullptr;
	try
	{

		if( size + allocated > total )
		{
			bad_alloc exc;
			throw exc;
		}
		else
		{
			pRet = calloc( size, sizeof( char )); //because char is 1 byte so we allocate exactly *size* bytes;
			if( pRet == nullptr ) throw 105;
			else
			{
				allocated += size;
				cout << "[+] operator [new]: Succesfuly allocated " << size << " bytes of memory for Matrix object pointer. Total allocated: " << allocated << endl;
				
			}
		}
		
	}
	catch( bad_alloc exc )
	{
		cout << "[-] Error occured when trying to allocate memory! [" << exc.what() << "]" << endl;
	}

	return pRet;
}

void Matrix::operator delete(void* pointer)
{
	allocated -= sizeof( Matrix );
	delete pointer;
	cout << "[+] operator [delete]: Successfuly deleted " << sizeof( Matrix ) << " bytes of memory. Total allocated: " << allocated << endl;
}

int& Matrix::operator()( unsigned int x, unsigned int y )
{
	try
	{
		if( data == nullptr ) throw 108;
		else if( x > width || y > width )
		{
			throw 107;
		}
		else return data[x][y];
	}
	catch( int exNo )
	{
		cout << "[-] Tried to access memory out of Matrix scope. code[" << exNo << "]" << endl;
	}
}

Matrix& Matrix::operator=( const Matrix & m )
{
	try
	{
		if( width == m.width && height == m.height )
		{
			for( unsigned int i = 0; i < width; i++ )
			{
				for( unsigned int j = 0; j < height; j++ )
				{
					data[i][j] = m.data[i][j];
				}
			}
			
		}
		else
		{
			throw 109;
		}	
	}
	catch(int exNo)
	{
		cout << "[-] Matrixes are not the same size, aborting. code[" << exNo << "]" << endl;
	}
	return *this;
}

int* Matrix::operator[]( unsigned int x)
{
	try
	{
		if( x > width )
		{
			throw 110;
		}
		else
		{
			return data[x];
		}
	}
	catch (int exNo)
	{
		cout << "[-] Tried to access memory out of Matrix scope. code[" << exNo << "]" << endl;
	}
}

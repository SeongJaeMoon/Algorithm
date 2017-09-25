#include <iostream>
using namespace std;

class Matrix {
	int ar[4];
public:
	Matrix() { for(int i=0; i<4; i++) ar[i] = 0; }
	Matrix(int a1, int a2, int b1, int b2) {
		ar[0] = a1;
		ar[1] = a2;
		ar[2] = b1;
		ar[3] = b2;
	}
	void show() {
		cout << "Matrix = { ";
		for(int i=0; i<4; i++) cout << ar[i] << ' ';
		cout << "}" << endl;
	}
	Matrix operator+(Matrix matrix);
	Matrix operator+=(Matrix matrix);
	bool operator==(Matrix matrix);
};

Matrix Matrix::operator+(Matrix matrix) {
	Matrix tmp;
	for(int i=0; i<4; i++) 
		tmp.ar[i] = ar[i] + matrix.ar[i];

	return tmp;
}

Matrix Matrix::operator+=(Matrix matrix) {
	for(int i=0; i<4; i++) 
		ar[i] += matrix.ar[i];

	return *this;
}

bool Matrix::operator==(Matrix matrix) {
	for(int i=0; i<4; i++) {
		if(ar[i] != matrix.ar[i])
			return false;
	}
	return true;
}

int main() {
	Matrix a(1,2,3,4), b(2,3,4,5), c;
	c = a + b;
	a += b;
	a.show(); 	b.show(); c.show();
	if(a == c) 
		cout << "a and c are the same" << endl;
}
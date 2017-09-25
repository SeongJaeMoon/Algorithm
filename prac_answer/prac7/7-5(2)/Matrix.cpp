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
	friend Matrix operator+(Matrix matrix1, Matrix matrix2);
	friend Matrix operator+=(Matrix& matrix1, Matrix matrix2);
	friend bool operator==(Matrix matrix1, Matrix matrix2);
};

Matrix operator+(Matrix matrix1, Matrix matrix2) {
	Matrix tmp;
	for(int i=0; i<4; i++) 
		tmp.ar[i] = matrix1.ar[i] + matrix2.ar[i];

	return tmp;
}

Matrix operator+=(Matrix& matrix1, Matrix matrix2) {
	for(int i=0; i<4; i++) 
		matrix1.ar[i] += matrix2.ar[i];

	return matrix1;
}

bool operator==(Matrix matrix1, Matrix matrix2) {
	for(int i=0; i<4; i++) {
		if(matrix1.ar[i] != matrix2.ar[i])
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
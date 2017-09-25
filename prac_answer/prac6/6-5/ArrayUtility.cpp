#include <iostream>
using namespace std;

class ArrayUtility {
public:
	static void intToDouble(int source [], double dest [], int size); // int 배열을 double 배열로 변환
	static void doubleToInt(double source [], int dest [], int size); // double 배열을 int 배열로 변환
};

void ArrayUtility::intToDouble(int source [], double dest [], int size) {
	for(int i=0; i<size; i++)
		dest[i] = (double)source[i];
}

void ArrayUtility::doubleToInt(double source [], int dest [], int size) {
	for(int i=0; i<size; i++)
		dest[i] = (int)source[i];
}

int main() {
	int x[] = {1,2,3,4,5};
	double y[5];
	double z[] = {9.9, 8.8, 7.7, 6.6, 5.6};

	ArrayUtility::intToDouble(x, y, 5); // x[] -> y[]
	for(int i=0; i<5; i++) cout << y[i] << ' ';
	cout << endl;

	ArrayUtility::doubleToInt(z, x, 5); // z[] -> x[]
	for(int i=0; i<5; i++) cout << x[i] << ' ';
	cout << endl;
} 

/* 아래는 참고로
	정수 배열과 실수 배열을 키로 입력받아 변환하는 코드를 보여준다.

int main() {
	int x[5];
	double y[5], z[5];

	cout << "정수를 5 개 입력하라. 배열에 삽입한다>>";
	for(int i=0; i<5; i++) cin >> x[i];
	
	cout << "정수 배열을 double 배열에 저장하고 결과를 출력한다->";	
	ArrayUtility::intToDouble(x, y, 5); // x[] -> y[]

	for(int i=0; i<5; i++) cout << y[i] << ' ';
	cout << endl;

	cout << "실수를 5 개 입력하라. 배열에 삽입한다>>";
	for(int i=0; i<5; i++) cin >> z[i];

	cout << "실수 배열을 int 배열에 저장하고 결과를 출력한다->";	
	ArrayUtility::doubleToInt(z, x, 5); // z[] -> x[]
	
	for(int i=0; i<5; i++) cout << x[i] << ' ';
	cout << endl;
} 

*/

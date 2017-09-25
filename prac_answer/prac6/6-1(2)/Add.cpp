#include <iostream>
using namespace std;

int add(int x[], int size,  int y[] = NULL) {
	int s = 0;
	for(int i=0; i<size; i++) // 배열 a의 합을 구한다.
		s += x[i];
	if(y == NULL) 
		return s;

	for(int i=0; i<size; i++) // 배열 b를 합한다.
		s += y[i];
	return s;
}

int main() {
	int a[] = {1,2,3,4,5};
	int b[] = {6,7,8,9,10};
	int c = add(a, 5); // 배열 a의 정수를 모두 더한 값 리턴
	int d = add(a, 5, b); // 배열 a와 b의 정수를 모두 더한 값 리턴
	cout << c << endl; // 15 출력 
	cout << d << endl; // 55 출력
}
#include<iostream>

using namespace std;

int main(void) {
	int a[5][5] = { 0, };
	int b[5][5] = { 0, };
	int i = 0;
	int j = 0;
	int num = 0;
	int num2 = 0;
	for (i; i < 5; i++) { 
		for (j; j < 5; j++) {
			num++;
			a[i][j] = num;
			std::cout << a[i][j] << "";
		}std::cout << endl;
	}
	std::cout << endl;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			num2++;
			b[j][i] = num2;
			std::cout << b[j][i] << "";
		}std::cout << endl;
	}
	std::cout << endl;
	
	return 0;
}
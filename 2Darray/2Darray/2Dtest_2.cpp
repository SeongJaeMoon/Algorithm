#include<iostream>

using namespace std;

int main(void) {
	int i, j;
	int arrA[5][5] = { 0, };
	int num = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			num++;
			arrA[i][j] = num;
		}
	}
	
	cout << "A" << endl;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i == j)
			{
				cout << arrA[i][j];
			}
			else
			{
				arrA[i][j] = 0;
				cout << arrA[i][j];
			}
		}cout << endl;
	}
	return 0;
}

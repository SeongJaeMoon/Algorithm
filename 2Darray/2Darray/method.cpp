#include <iostream>
#include "2Dheader.h"

using namespace std;

/*
* 12345
* 678910	
* 1112131415
* 1617181920
* 202122232425
*/

/*
* 10000
* 07000
* 001300
* 000190
* 000025
*/

void output::out() {
	int arrA[5][5] = { 0, };
	int num = 0, i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			num++;
			arrA[i][j] = num;
			std::cout << arrA[i][j];
		}std::cout << endl;
	}
	std::cout << "A" << endl;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i == j)
			{
				std::cout << arrA[i][j];
			}
			else
			{
				arrA[i][j] = 0;
				std::cout << arrA[i][j];
			}
		}std::cout << endl;
	}
}

/*
* 12345
* 078910
* 00131415
* 0001920
* 000025
*/
void output::out2() {
	int arrA[5][5];
	int num = 0, i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			num++;
			arrA[i][j] = num;
		}
	}
		std::cout << "배열 출력" << endl;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (i < j || i == j)
				{
					std::cout << arrA[i][j];
				}
				else
				{
					arrA[i][j] = 0;
					std::cout << arrA[i][j];
				}
			}std::cout << endl;
		}
}

/*
* 00000
* 00000
* 001300
* 01718190
* 2122232425
*/

void output::out3() {
	int arrA[5][5];
	int num = 0, i, j;

	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			arrA[i][j] = 0;
		}
	}
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			num++;
			arrA[i][j] = num;
		}
	}

	for (i = 0; i<5; i++)
	{
		if (i == 0 || i == 1)
		{
			for (j = 0; j<5; j++)
			{
				arrA[i][j] = 0;
			}
		}
		if (i == 2)
		{
			for (j = 0; j<5; j++)
			{
				if (j == 2)
					continue;
					arrA[i][j] = 0;
			}
		}
		if (i == 3)
		{
			for (j = 0; j<5; j++)
			{
				if (j == 0 || j == 4)
					arrA[i][j] = 0;
			}
		}
	}
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			std::cout << arrA[i][j];
		}
		std::cout << endl;
	}

}

/* --A--
* 12345
* 678910
* 1112131415
* 1617181920
*/

/* --B--
* 481216
* 371115
* 261014
* 15913
*/

void output::out4() {
	int arrA[][4] = { { 1,2,3,4, },{ 5,6,7,8 },{ 9,10,11,12 },{ 13,14,15,16 } };
	int arrB[][4] = { { 0000 },{ 0000 },{ 0000 },{ 0000 } };

	int i, j;

	std::cout << "A" << endl;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			std::cout << arrA[i][j];
		}std::cout << endl;
	}
	std::cout << endl;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arrB[j][i] = arrA[i][3 - j];
		}
	}

	std::cout << "B" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			std::cout << arrB[i][j];
		}std::cout << endl;
	}

}

/*
* 12345
* 0789
* 00101112
* 0001314
* 000015
*/

void output::out5() {
	int arrA[5][5] = { 0, };

	int i, j;
	int num = 1;

	for (i = 0; i<5; i++)
	{
		for (j = i; j<5; j++)
		{
			arrA[i][j] = num;
			num++;
		}
	}
	for (i = 0; i<5; i++) {
		for (j = 0; j<5; j++) {
			std::cout << arrA[i][j];
		}
		std::cout << endl;
	}

}

/*
* 000011
* 000712
* 004813
* 025914
* 1361015
*/

void output::out6() {
	int arr[5][5];
	int x = 4;
	int num = 0, i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (j = 0; j < 5; j++)
	{
		for (i = x; i < 5; i++)
		{
			num++;
			arr[i][j] = num;
		}
		x--;
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << endl;
	}
}

/*
* 1000025
* 280002026
* 39130172127
* 4101416182228
* 511150192329
* 6120002430
* 70000031
*/

void output::out7() {
	int arr[7][7] = { 0 };
	int count = 1;
	int i, j;
	int x = 0, y = 7;

	for (i = 0; i < 7; i++)
	{
		for (j = x; j < y; j++)
		{
			arr[i][j] = count;
			count++;
		}
		if (i < 3)
		{
			x++;
			y--;
		}
		else
		{
			x--;
			y++;
		}
	}

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << endl;
	}
}

/*
* 1234567
* 0891011120
* 0013141500
* 00016000
* 0017181900
* 020212223240
* 25262728293031
*/

void output::out8() {
	int arr[7][7] = { 0 };
	int count = 1;
	int i, j;
	int x = 0, y = 7;

	for (i = 0; i < 7; i++)
	{
		for (j = x; j < y; j++)
		{
			arr[i][j] = count;
			count++;
		}
		if (i < 3)
		{
			x++;
			y--;
		}
		else
		{
			x--;
			y++;
		}
	}

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << endl;
	}
}

/*
* 1234567
* 091011121314
* 001718192021
* 00025262728
* 003132333435
* 0373839404142
* 43444546474849
*/

void output::out9() {
	int arr[7][7];
	int num = 0, i, j;

	for (i = 0; i<7; i++)
	{
		for (j = 0; j<7; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (i = 0; i<7; i++)
	{
		for (j = 0; j<7; j++)
		{
			num++;
			arr[i][j] = num;
		}
	}
	for (i = 1; i < 6; i++)
	{
		j = 0;
		arr[i][j] = 0;
	}
	for (i = 2; i < 5; i++)
	{
		j = 1;
		arr[i][j] = 0;
	}
	i = 3;
	j = 2;
	arr[i][j] = 0;

	for (i = 0; i<7; i++)
	{
		for (j = 0; j<7; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << endl;
	}
}


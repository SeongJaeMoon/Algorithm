/*
*selfnumber Test
*양의 정수 n에 대해서 d(n)을 n과 n의 각 자리수를 더하는 함수 ex. d(75) = 75+7+5 =87
*양의 정수 n이 주어졌을 때, 이 수를 시작해서 n, d(n), d(d(n), d(d(d(n)))...과 같은 무한 수열을 만들 수 있다.
*n을 d(n)의 생성자라고 한다. 생성자가 없는 숫자를 셀프 넘버라고 한다.
*10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
*/
#include <iostream>
#define MAX 15000

using namespace std;

int sum(int, int);
int main(void)
{
	int arr[MAX] = { 0, };
	int i1, i2, i3, i4, n = 0;
	int j1, j2, j3;
	for (i4 = 0; i4 < 10; i4++) {
		for (i3 = 0; i3 < 10; i3++) {
			j3 = i3 + i4;
			for (i2 = 0; i2 < 10; i2++) {
				j2 = j3 + i2;
				for (i1 = 0; i1 < 10; i1++) {
					arr[j2 + i1 + n++] = 1;
				}
			}
		}
	}
	for (n = 1; n <= 10000; n++) {
		if (!arr[n]) {
			std::cout << n << endl;
		}
	}
	return 0;
	}
}
/*
bool v[1000000];
long non_self = 0;
  for(long i = 1; i < 1000000; ++i) {
    if(!(v[i])) std::cout << i << '\n';
		// 다중 % 연산 비 효울적
    non_self = i + (i%10) + (i/10)%10 + (i/100)%10 + (i/1000)%10 + (i/10000)%10 +(i/100000)%10;
    v[non_self] = 1;
  }
  std::cout << "1000000" << '\n';
*/

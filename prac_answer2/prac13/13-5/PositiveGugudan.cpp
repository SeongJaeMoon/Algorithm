#include <iostream>
using namespace std;

/* 문제의 원본 프로그램 코드

int main() {
	int n;
	while(true) {
		cout << "양수 입력 >> ";
		cin >> n; 
		for(int i=1;i<=9; i++)
			cout << n << 'x' << i << '=' << n*i << ' ';
		cout << endl;
	}
} */

// 수정된 정답 프로그램
int main() {
	int n;
	while(true) {
		cout << "양수 입력 >> ";
		try {
			cin >> n; 
			if(cin.fail()) // failbit이 1로 셋되어 있는 경우, 포맷에 맞지 않는 입력 발생
				throw "정수가 아닌 값 입력";
			if(n <= 0 || n > 9)
				throw n;
			for(int i=1; i<=9; i++)
				cout << n << 'x' << i << '=' << n*i << ' ';
			cout << endl;
		}
		catch(int e) {
			cout << "잘못된 입력입니다. 1~9 사이의 정수만 입력하세요" << endl;		
		}
		catch(char *s) {
			cout << "입력 오류가 발생하여 더 이상 입력되지 않습니다. 프로그램을 종료합니다" << endl;	
			return 0;
		}
	}
}
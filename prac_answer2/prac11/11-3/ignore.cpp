#include <iostream>
using namespace std;

int main() {
	int ch;
	cin.ignore(100, ';'); // 영어 문장이 최대 99개의 문자로 입력된다고 가정한다.
	while((ch=cin.get()) != EOF) {
		cout << (char)ch;
		if(ch == '\n') {
			cin.ignore(100, ';'); // 영어 문장이 최대 99개의 문자로 입력된다고 가정한다.
		}
	}
}
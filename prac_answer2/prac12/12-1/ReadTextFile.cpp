#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\test.txt");
	if(!fin) {
		cout << "열기 오류" << endl;
		cout << "경로명이 옳은지 파일이 있는지 확인하세요" << endl;
		return 0;
	}
	int ch;
	while((ch=fin.get()) != EOF) {
		cout.put(ch);
	}

	fin.close();
}
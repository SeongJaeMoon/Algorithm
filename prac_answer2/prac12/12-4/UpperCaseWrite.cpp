#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char* firstFile = "c:\\student.txt";
	char* secondFile = "c:\\sindows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);
	if(!fout) {
		cout <<firstFile << "�������";
		return 0;

}

	fstream fin(secondFile, ios::in);
	if(!fn){
		cout << secondFile << "�������";
		return 0;
	}

	int c;
	while(c=fin.get()) ! = EOF) {
		fout.put(c);
	}


	fin.close();
	fout.close();
}
#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text;
	int histo[26]; // 26개의 알파벳에 대해 각 글자당 개수 저장
public:
	Histogram();
	Histogram(string text); // 생성자에 히스토그램으로 분석할 문자열 전달
	void putc(char c); // 히스토그램에 문자 삽입
	void put(string text); // 히스토그램에 string 문자열 삽입
	void print(); // 히스토그램의 화면 출력
	~Histogram() {}
};

Histogram::Histogram() {
	this->text = "";
}

Histogram::Histogram(string text) {
	this->text = text;
}

void Histogram::put(string text) {
	this->text.append(text); // 기존의 텍스트에 text 문자열 덧붙임
	//this->text += text; //와 동일
}

void Histogram::putc(char c) {
	char buf[] = {c, '\0'};
	this->text.append(buf); // 기존의 텍스트에 text 문자열 덧붙임

	// text += c; //와 동일
}

void Histogram::print() {
	for(int i=0; i<26; i++)
		histo[i] = 0; // histo 배열을 0으로 초기화

	cout << text << endl << endl;

	for(int i=0; i<text.length(); i++) {
		if(isalpha(text[i])) { // 알파벳에 대해서만 처리
			char c = tolower(text[i]);
			histo[c - 'a']++;
		}
	}
		
	int n =0;
	for(int i=0; i<26; i++) n += histo[i]; // 전체 알파벳 수 더하기
	cout << "총 알파벳 수 " << n << endl;
	cout << endl;

	for(int i=0; i<26; i++) {
		cout << char('a'+i) << " (" << histo[i] << ")" << '\t' << ": ";
		for(int j=0; j<histo[i]; j++)
			cout << '*';
		cout << endl;
	}
}

int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, \n");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}
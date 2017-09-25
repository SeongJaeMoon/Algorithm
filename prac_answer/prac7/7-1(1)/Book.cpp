#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title="", int price=0, int pages=0) {
		this->title = title; this->price = price; 	this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " <<pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	Book operator +=(int price);
	Book operator -=(int price);
};

Book Book::operator +=(int price) {
	this->price += price;
	return *this;
}

Book Book::operator -=(int price) {
	this->price -= price;
	return *this;
}

int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show();
	b.show();
}

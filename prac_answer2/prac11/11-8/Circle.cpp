#include <iostream>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius=1, string name="") { 
		this->radius = radius; this->name = name;
	}
	double getArea() { return 3.14*radius*radius; }
	string getName() { return name; } 
	friend ostream& operator << (ostream& outs, Circle c); // << 연산자를 프렌드로 선언
	friend istream& operator >> (istream& ins, Circle& c); // >> 연산자를 프렌드로 선언
};

ostream& operator << (ostream& outs, Circle c) { // 스트림에 객체 c 출력
	outs << "(반지름" << c.radius << "인 " << c.name << ")";
	return outs;
}
istream& operator >> (istream& ins, Circle& c) { // 스트림으로부터 읽어 객체 c 완성
	cout << "반지름 >> ";
	int radius;
	ins >> radius;
	c.radius = radius;
	cout << "이름 >> ";
	string name;
	ins >> name;
	c.name = name;
	return ins;
}

int main() {
	Circle d, w;
	cin >> d >> w; // 키보드 입력을 받아 객체 d와 w를 완성
	cout << d << w << endl; // 객체 d, w 출력
}
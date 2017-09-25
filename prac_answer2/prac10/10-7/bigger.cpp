#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius=1) { this->radius = radius; }
	int getRadius() { return radius;}
};

template <class T>
T bigger(T a, T b) { // 두 개의 매개 변수를 비교하여 큰 값을 리턴
	if(a > b) return a; 
	else return b;
}


/* 오류를 수정하기 위해 작성된 bigger() 함수
	이 함수가 선언되어 있지 않으면,
	bigger 템플릿 코드에서 오류가 발생한다.		
*/
Circle bigger(Circle a, Circle b) {
	if(a.getRadius() > b.getRadius()) return a;
	else return b;
}

int main() {
	int a=20, b=50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}

/* 주어진 문제의 오류는 main() 함수의 다음 라인에서 비롯된다.
	y = bigger(waffle, pizza);

	이 호출을 위해, bigger 템플릿을 Circle 타입으로 구체화하면 다음과 같이 된다.
	Circle bigger(Circle a, Circle b) {
		if(a > b) return a; 
		else return b;
	}

	그렇지만 이 코드에서 if(a > b)문의 연산자 > 가 작성 되어 있지 않기 때문에,
	컴파일 오류가 발생한다.
	이 문제를 해결하기 위해, 이 정답에서는 Circle bigger(Circle a, Circle b);의 함수를
	따로 중복 작성한다.
*/
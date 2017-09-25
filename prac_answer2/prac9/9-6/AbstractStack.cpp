#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0; // 스택에 n을 푸시한다. 스택이 full이면 false 리턴
	virtual bool pop(int& n) = 0; // 스택에서 팝한 정수를 n에 리턴한다. 스택이 empty이면 false 리턴
	virtual int size() = 0; // 현재 스택에 저장된 정수의 개수 리턴
};

class IntStack : public AbstractStack {
	int capacity;
	int tos;
	int *p;
public:
	IntStack(int size);
	~IntStack();
	bool push(int n);
	bool pop(int& n);
	int size() { return tos; } // tos는 현재 스택에 삽입된 정수의 개수와 동일
};

IntStack::IntStack(int size) {
	p = new int [size];
	this->capacity = size;
	tos = 0;
}

IntStack::~IntStack() {
	if(p) 
		delete [] p;
}

bool IntStack::push(int n) {
	if(tos >= capacity) // full
		return false;

	p[tos] = n;
	tos++;
	return true;
}

bool IntStack::pop(int& n) {
	if(tos == 0) // empty
		return false;

	tos--;
	n = p[tos];
	return true;
}

int main() {
	IntStack a(5);
	for(int i=0; i<10; i++)  { // 처음 5 개를 성공적으로 push되고 다음 5 개는 스택 full로 push 실패
		if(a.push(i)) cout << "push 성공" << endl;
		else cout << "스택 full" << endl;
	}

	int n;
	for(int i=0; i<10; i++)  { // 처음 5 개를 성공적으로 pop되고 다음 5 개는 스택 empty로 pop 실패
		if(a.pop(n)) cout << "pop 성공 " << n << endl;
		else cout << "스택 empty" << endl;
	}
}
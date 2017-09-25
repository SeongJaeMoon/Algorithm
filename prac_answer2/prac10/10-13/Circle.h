#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
using namespace std;

class Circle {
	string name; // 이름
	int radius; //반지름
public:
	Circle(int radius, string name) { 
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14*radius*radius; }
	string getName() { return name; }
};

#endif
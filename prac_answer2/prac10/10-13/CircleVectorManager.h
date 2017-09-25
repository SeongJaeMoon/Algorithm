#ifndef CIRCLEVECTORMANAGER_H
#define CIRCLEVECTORMANAGER_H

#include <vector>
using namespace std;

class Circle;

class CircleVectorManager {
	enum {EDIT=1, REMOVE=2, PAINT=3, EXIT=4};
	vector<Circle*> v;
	void edit();
	void remove();
	void paint();
public:
	CircleVectorManager();
	~CircleVectorManager();
	void run();

};

#endif
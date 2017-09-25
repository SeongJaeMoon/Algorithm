#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

class UI {
public:
	static int getMainMenu();
	static void getCircle(int&, string&);
	static string getCircleName();
	static void println(string="");
	static void print(string);
	static void print(int);
};

#endif
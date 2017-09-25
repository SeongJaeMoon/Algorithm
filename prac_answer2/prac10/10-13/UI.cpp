#include <iostream>
using namespace std;

#include "UI.h"

int UI::getMainMenu() {
	cout << "삽입:1, 삭제:2, 모두보기:3. 종료:4 >> ";

	int menu;
	cin >> menu;

	return menu;
}

void UI::getCircle(int& radius, string& name) {
	cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
	cin >> radius >> name;
}

string UI::getCircleName() {
	cout << "삭제하고자 하는 원의 이름은 >> ";

	string name;
	cin >> name;

	return name;
}

void UI::println(string msg) {
	cout << msg << endl;
}

void UI::print(string msg) {
	cout << msg;
}

void UI::print(int msg) {
	cout << msg;
}
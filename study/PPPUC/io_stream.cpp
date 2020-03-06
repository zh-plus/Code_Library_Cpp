//
// Created by 10578 on 2/23/2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <error.h>

using namespace std;

class Point {
public:
	int x{}, y{};

	friend ostream &operator<<(ostream &os, const Point &obj) {
		return os << '(' << obj.x << ',' << obj.y << ')';
	}

	friend istream &operator>>(istream &is, Point &obj){
		char sep1, sep2, sep3;
		return is >> sep1 >> obj.x >> sep2 >> obj.y >> sep3;
	}
};


int main() {
	string name = "in.txt";
	ifstream ist{name};

	if (!ist.good()) {
		cout << "Can not open " << name << endl;
	} else {
		cout << "Good!" << endl;
	}

	vector<Point> points;
	for(Point p; ist >> p;){
		points.push_back(p);
	}

	for (auto &&p: points) {
		cout << p << endl;
	}

	ist.close();

	fstream fs;

	fs.open("in.txt", ios_base::in);

	vector<Point> points_2;
	for(Point p; ist >> p;){
		points.push_back(p);
	}

	fs.close();
	fs.open("in2.txt", ios_base::out);

	for (auto &&p: points) {
		fs << p << endl;
	}

	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		char c;
		cin >> c;
		cout << "Recover from fail()! " << c << endl;
	}


	return 0;
}
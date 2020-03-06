//
// Created by 10578 on 3/5/2020.
//

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Point {
public:
	Point(int x, int y) : x{x}, y{y} {}

private:
	int x, y;
};

class Shape {
public:
	void draw() const {
		cout << "Draw!" << endl;
	}

	virtual void move(int dx, int dy) {}

protected:
	Shape() = default;

	Shape(initializer_list<Point> lst) : points{lst} {}

	// Copy assignment deleted
	Shape &operator=(const Shape &obj) = delete;

	virtual ~Shape() = default;

private:
	vector<Point> points;
};

class Circle : public Shape {
private:
	float radius;
};

void draw(const Shape &s){
	s.draw();
}

int main(){
	Circle c{};

	draw(c);

	return 0;
}
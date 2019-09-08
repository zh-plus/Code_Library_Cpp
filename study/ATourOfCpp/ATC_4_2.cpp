//
// Created by 10578 on 2019/8/16.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <map>
#include <complex>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

class Point {
public:
    Point(int x, int y) : x{x}, y{y} {};

private:
    int x, y;
};


class Shape {
public:
    virtual Point center() const = 0;

    virtual void move(Point to) = 0;

    virtual void draw() const = 0;

    virtual void rotate(int angle) = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    Point x;
    int r;

public:
    Circle(Point p, int radius);

    Point center() const override { return x; }

    void move(Point to) override { x = to; }

    void draw() const override;

    void rotate(int angle) override;
};


class Smiley : public Circle {
private:
    vector<Shape *> eyes;
    Shape *mouth;

public:

    Smiley(Point p, int radius) : Circle{p, r}, mouth{nullptr} {};

    ~Smiley() {
        delete mouth;
        for (auto p: eyes) {
            delete p;
        }
    }

    void move(Point to) override;

    void draw() const override;

    void rotate(int angle) override;

    void add_eye(Shape *shape) {
        eyes.push_back(shape);
    }

    void set_mouth(Shape *shape);

    virtual void wink(int i);
};

void Smiley::draw() const {
    Circle::draw();
    for (auto p: this->eyes) {
        p->draw();
    }
    mouth->draw();
}


void rotate_all(vector<Shape *> &v, int angle) {
    for (auto p: v) {
        p->rotate(angle);
    }
}


int main() {
    BOOST_IO;


    return 0;
}
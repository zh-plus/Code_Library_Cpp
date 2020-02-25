//
// Created by 10578 on 2/14/2020.
//

#include <iostream>

using namespace std;

class T;

class V {
public:
	explicit V(int i) {
		value = i;
	}

	operator T();

	int value;
};

class T {
public:
	T(V v) {
		value = v.value;
	}

private:
	int value;
};

V::operator T() {
	return T(*this);
}

T f() {
	V v(1);
	return (T)v;
}

void print(int i){
	cout << i << endl;
}

void print(double i){
	cout << i << endl;
}

int main() {
	print(1);

	return 0;
}
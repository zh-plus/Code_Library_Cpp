//
// Created by 10578 on 3/5/2020.
//

#include <iostream>
#include <vector>

using namespace std;

class MyClass{
public:
	[[nodiscard]] const vector<int>& x() const {
		return x_;
	}

	[[nodiscard]] int& y() const{
		return y_;
	}

private:
	vector<int> x_;

	int y_;
};

int main(){
	MyClass x;

	vector<int> temp = x.x();
	temp.push_back(0);
	cout << temp.max_size() << endl;

	x.y() = 1;

	return 0;
}
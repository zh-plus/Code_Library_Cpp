//
// Created by 10578 on 3/5/2020.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Integer {
public:
	explicit Integer(int v) {
		value = v;
	}

	friend ostream &operator<<(ostream &os, const Integer &obj) {
		return os << obj.value;
	}

	int value;
};

int main() {
	Integer *origin[3];
	origin[0] = new Integer{2};
	origin[1] = new Integer{1};
	origin[2] = new Integer{3};

	Integer *new_arr[3];
	std::copy(begin(origin), end(origin), begin(new_arr));

	// sort
	std::sort(begin(new_arr), end(new_arr), [](const Integer *a, const Integer *b){
		return a->value < b->value;
	});

	// print
	cout << "Origin:" << endl;
	for (auto &&x: origin) {
		cout << x << ": " << *x << endl;
	}

	cout << "New:" << endl;
	for (auto &&x: new_arr) {
		cout << x << ": " << *x << endl;
	}

	return 0;
}
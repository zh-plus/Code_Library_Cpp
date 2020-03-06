//
// Created by 10578 on 11/19/2019.
//

/**
 * https://stackoverflow.com/a/3279550
 */

#include <iostream>
#include <vector>
#include <algorithm> // std::copy
#include <cstddef> // std::size_t

using namespace std;

class DumbArray {
public:
	// (default) constructor
	explicit DumbArray(std::size_t size = 0)
			: mSize(size),
			  mArray(mSize ? new int[mSize]() : nullptr) {
	}

	// copy-constructor
	DumbArray(const DumbArray &other)
			: mSize(other.mSize),
			  mArray(mSize ? new int[mSize] : nullptr) {
		cout << "Copy constructor" << endl;
		// note that this is non-throwing, because of the data
		// types being used; more attention to detail with regards
		// to exceptions must be given in a more general case, however
		std::copy(other.mArray, other.mArray + mSize, mArray);
	}

	// copy-assignment
	DumbArray &operator=(DumbArray other) {
		cout << "Copy assignment" << endl;
		swap(*this, other);

		return *this;
	}

	// move-constructor
	DumbArray(DumbArray &&other) noexcept : DumbArray() {
		cout << "Move constructor" << endl;
		swap(*this, other);
	}

//	// move-assignment
//	DumbArray &operator=(DumbArray &&other) noexcept {
//		cout << "Move assignment" << endl;
//		swap(*this, other);
//
//		return *this;
//	}

	// swap idiom
	friend void swap(DumbArray &first, DumbArray &second) {
		cout << "Swap" << endl;

		std::swap(first.mSize, second.mSize);
		std::swap(first.mArray, second.mArray);
	}

	// destructor
	~DumbArray() {
		delete[] mArray;
	}

	std::size_t mSize;
	int *mArray;
};


template<typename Sequence>
void print_vector(Sequence s) {
	using namespace std;

	for (auto &x: s) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	using namespace std;

	vector v1{1, 2, 3, 4};
	vector v2{5, 6, 7};
	swap(v1, v2);

	print_vector(v1);
	print_vector(v2);

	DumbArray a1(2);
	DumbArray a3(3);
	a3 = move(a1);
	cout << a1.mSize << endl;
	cout << a3.mSize << endl;

	return 0;
}
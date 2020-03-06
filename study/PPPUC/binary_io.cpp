//
// Created by 10578 on 3/3/2020.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<typename T>
char *as_bytes(T &x) {
	void *address = &x;

	return static_cast<char *>(address);
}

int main() {
	// Create new binary file
	ifstream ifs("binary.bin", ios_base::binary);

	vector<int> content;

	int x;
	char *address = as_bytes(x);
	while (ifs.read(address, sizeof(x))) {
		content.push_back(x);
	}

	for (auto &&c: content) {
		cout << c << " ";
	}
	cout << endl;

	return 0;
}
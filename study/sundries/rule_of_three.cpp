//
// Created by 10578 on 11/18/2019.
//

/**
 * https://stackoverflow.com/a/4172724
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Person {
public:
	char *name;
	int age;

	// the constructor acquires a resource:
	// in this case, dynamic memory obtained via new[]
	Person(const char *the_name, int the_age) {
		name = new char[strlen(the_name) + 1];
		strcpy(name, the_name);
		age = the_age;
	}

	Person(const Person &other) {
		cout << "Copy constructor" << endl;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}

	Person &operator=(const Person &other) {
		cout << "Copy assignment" << endl;
		char *new_name = new char[strlen(other.name) + 1];
		strcpy(new_name, other.name);

		delete[](name);
		name = new_name;
		age = other.age;

		return *this;
	}


	// the destructor must release this resource via delete[]
	~Person() {
		delete[] name;
	}
};

int main() {
	Person a("Bjarne Stroustrup", 60);
	Person b(a);   // What happens here?
	Person c(b);         // And here?
	c = c;

	cout << "a:" << a.name << " -- " << "b:" << b.name << " -- " << "c:" << c.name << endl;
	strcpy(a.name, "zhenghao");
	cout << "a:" << a.name << " -- " << "b:" << b.name << " -- " << "c:" << c.name << endl;


	return 0;
}
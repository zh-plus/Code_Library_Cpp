//
// Created by 10578 on 2/22/2020.
//

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

enum class Month {
	jan = 0, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month &month) {
	month = (month == Month::dec) ? Month::jan : Month(int(month) + 1);

	return month;
}

Month operator++(Month &month, int) {
	month = (month == Month::dec) ? Month::jan : Month(int(month) + 1);

	return month;
}

ostream &operator<<(ostream &os, Month month) {
	return os << std::underlying_type<Month>::type(month);
}

struct Date {
public:
	Date() {
		cout << "Using default constructor!" << endl;
	}

	Date(int y, Month m, int d) {
		this->y = y;
		this->m = m;
		this->d = d;
	}

	void test(){
		cout << max << min << endl;
	}

	void print() {
		cout << y << " " << m << " " << d << endl;
	}

private:
	int y{};
	Month m{};
	int d{};

	static const int max = 100;
	static const int min = 0;
};


int main() {
	Date today(1, Month::mar, 3);
	Date d;

	d.print();

	vector<int> v;

	today.print();
	today.test();

	Month a = Month::jan;
	Month b = Month::feb;
	auto c = Month::dec;

	istream is(cin.rdbuf());
	is.clear(istream::failbit);


	cout << a << " " << b << " " << (++c) << endl;

	return 0;
}
//
// Created by 10578 on 3/3/2020.
//

#include <iostream>
//#include <fstream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
	fstream fs("in.txt");

	cout << fs.rdbuf() << endl;

	return 0;
}
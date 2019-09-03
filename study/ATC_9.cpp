//
// Created by 10578 on 9/3/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());

using namespace std;


int return_one(int i) { return 1; }

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    string name{"zheng hao"};
    istringstream iss("zhenghao, he is");
    string token;
    while (getline(iss, token, ','))
        cout << token << endl;

    transform(name.begin(), name.end(), name.begin(), ::toupper);
    cout << name << endl;

    {
        string token = "test";
        cout << token << endl;
    }

    cout << token << endl;

}
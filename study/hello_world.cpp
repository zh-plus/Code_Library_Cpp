//
// Created by 10578 on 2019/8/16.
//

#include <iostream>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)

int main() {
    BOOST_IO;

    cout << "Hello World!" << "123" << "end" << endl;

    int i;
    cin >> i;

    return 0;
}

void print(const string& s){
    cout << s << endl;
}
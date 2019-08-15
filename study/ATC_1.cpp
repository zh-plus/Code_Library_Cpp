//
// Created by 10578 on 2019/8/16.
//

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(0)


void print(int i, double d) {
    cout << i << d << endl;
}

int main() {
    BOOST_IO;
    unsigned int a = ~0;
    cout << a << endl;
    cout << (unsigned int)(pow(2, 32) - 1) << endl;
    cout << bitset<32>(0).to_string() << endl;

    return 0;
}
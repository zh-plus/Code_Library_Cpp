//
// Created by 10578 on 9/16/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
//#define LOCAL

using namespace std;

int main(){
    BOOST_IO;

    for (int i = 0; i < 26; ++i) {
        cout << (char)('A' + i) << "*";
    }
}
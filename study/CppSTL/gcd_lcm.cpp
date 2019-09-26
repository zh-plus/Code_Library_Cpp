//
// Created by 10578 on 9/26/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stl_algo.h>
#include <tuple>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;

int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    cout << lcm(3, 7) << endl;

    return 0;
}
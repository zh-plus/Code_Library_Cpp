//
// Created by 10578 on 9/9/2019.
//

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;

int main(){
    vector<int> v {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

    make_heap(v.begin(), v.end());
    for (auto &x: v) {
        cout << x << " ";
    }

    make_pair()
}
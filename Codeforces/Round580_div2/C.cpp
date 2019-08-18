//
// Created by 10578 on 2019/8/18.
//
#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


vector<int> solve(int n) {
    double mean = (1.0 + 2.0 * n) * n / 2.0;
    int a = floor(mean), b = ceil(mean);


}


int main() {
    BOOST_IO;

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES";

    vector<int> result = solve(n);
    for (auto x: result) {
        cout << x << " ";
    }

    return 0;
}


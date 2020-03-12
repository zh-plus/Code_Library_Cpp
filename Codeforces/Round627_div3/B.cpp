//
// Created by 10578 on 3/12/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

bool solve(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] == nums[j] && j - i > 1) {
                return true;
            }
        }
    }

    return false;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int T = 0;
    cin >> T;
    vector<int> v;
    int temp = 0;
    int n = 0;
    while (T--) {
        cin >> n;

        v.clear();
        v.reserve(n);

        for (int i = 0; i < n; ++i) {
            cin >> temp;
            v.push_back(temp);
        }

        cout << (solve(v) ? "YES" : "NO") << endl;
    }

    return 0;
}
//
// Created by 10578 on 3/12/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

bool solve(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<int> new_nums(nums.size());
    transform(begin(nums), end(nums), begin(new_nums), [&](int x) {
        return x - nums.front();
    });

    bool result = all_of(begin(new_nums), end(new_nums), [](int x) {
        return x % 2 == 0;
    });

    return result;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int T;
    cin >> T;
    vector<int> v;
    int temp;
    int n;
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
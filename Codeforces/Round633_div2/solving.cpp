//
// Created by 10578 on 4/12/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

using vi = vector<int>;

int solve(int n, const vi &v) {
    vi diff(n);
    adjacent_difference(v.begin(), v.end(), diff.begin());
    diff.erase(diff.begin());

    int consecutive_num_max = 0;
    int consecutive_min = 0;

    int temp_consecutive_num = 0;
    int temp_consecutive = 0;
    for (int i = 0; i < n; ++i) {
        if (diff[i] >= 0 || i == n - 1) {
            consecutive_num_max = max(consecutive_num_max, temp_consecutive_num);
            consecutive_min = min(consecutive_min, temp_consecutive);

            temp_consecutive_num = 0;
            temp_consecutive = 0;
        } else {
            ++temp_consecutive_num;
            temp_consecutive += diff[i];
        }
    }

    int num = abs(consecutive_min);
    double times = log(num) / log(2);
    if (int t = floor(times); pow(2, t) == num) {
        times = t;
    }

    int log_result = ceil(times) + 1;

    return max(consecutive_num_max, log_result);
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("../in.txt");
#endif

    int T;
    int n;
    vi v;

    cin >> T;
    while (T--) {
        cin >> n;
        v.resize(n);
        copy_n(istream_iterator<int>(cin), n, v.begin());

        cout << solve(n, v) << endl;
    }

    return 0;
}
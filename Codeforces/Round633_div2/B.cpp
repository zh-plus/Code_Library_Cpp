//
// Created by 10578 on 4/12/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <random>
#include <chrono>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

using vi = vector<int>;

bool check(const vi &v);

vi solve(int n, vi &v) {
    sort(v.begin(), v.end());

    int middle = n / 2;
    auto mi = v.begin() + middle;
    vi left = vi(v.begin(), mi);
    vi right = vi(mi, v.end());

    reverse(left.begin(), left.end());

    vi result;
    result.reserve(n);
    result.push_back(right[0]);

    int i = 0, j = 1;
    while (i < left.size() || j < right.size()) {
        if (i < j) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }

    return result;
}

bool check(const vi &v){
    vi diff(v.size());
    adjacent_difference(v.begin(), v.end(), diff.begin());
    diff.erase(diff.begin());
    transform(diff.begin(), diff.end(), diff.begin(), [](int x) { return abs(x); });

    return is_sorted(diff.begin(), diff.end());
}

void gen(int N = 10000000){
    auto gen = []() {
        static auto engine = mt19937_64{static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count())};
        return engine() % 1000000;
    };

    vi v;
    size_t sz;
    while (N--) {
        sz = max(3ull, gen() % 20ull);
        v.resize(sz);
        generate(v.begin(), v.end(), gen);

        auto result = solve(sz, v);

        if (!check(result)) {
            cout << "Wrong!" << endl;
            copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
            exit(0);
        } else {
            cout << N << endl;
        }
    }
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("../in.txt");
#endif

//    gen();

    int T = 0;
    cin >> T;
    int n;
    vi result;
    vi v;
    while (T--) {
        cin >> n;
        v.resize(n);
        copy_n(istream_iterator<int>(cin), n, v.begin());

        result = solve(n, v);

        copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
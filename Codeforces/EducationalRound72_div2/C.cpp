//
// Created by 10578 on 2019/8/20.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_set>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL
#define MAX_LEN (int)2e5 + 10

using namespace std;

vector<string> good{""};

int count_substr(const string &s, const string &target) {
    int occurrences = 0;
    string::size_type pos = 0;

    while ((pos = s.find(target, pos)) != std::string::npos) {
        ++occurrences;
        ++pos;
    }

    return occurrences;
}

vector<int> solve(const vector<string> &ss) {
    vector<int> result(ss.size());

    int cnt;
    for (int i = 0, sz = ss.size(); i < sz; ++i) {
        cnt = 0;
        for (int j = 1, jsz = min(ss[i].size() + 1, good.size()); j < jsz; ++j) {
            if (int count = count_substr(ss[i], good[j])) {
                cnt += count;
            }
        }
        result[i] = cnt;
    }

    return result;
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;
    vector<string> ss(T);
    string s;

    int max_size = 0;
    for (int i = 0; i < T; ++i) {
        cin >> s;
        max_size = max(max_size, (int) s.size());
        ss[i] = s;
    }

    good.reserve(max_size);
    string temp_str;
    for (int i = 1; i <= max_size; ++i) {
        temp_str = bitset<MAX_LEN>(i).to_string();
        temp_str.erase(0, min(temp_str.find_first_not_of('0'), temp_str.size() - 1));
        good.push_back(temp_str);
    }

    vector<int> result = solve(ss);
    for (const auto &r: result) {
        cout << r << endl;
    }

    return 0;
}
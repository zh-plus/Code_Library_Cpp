//
// Created by 10578 on 9/2/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream f_in(filename); cin.rdbuf(f_in.rdbuf());
#define LOCAL

using namespace std;

unsigned int popcount(unsigned int x) {
    unsigned int result = 0;
    while (x) {
        result += (x & 1u);
        x >>= 1u;
    }

    return result;
}

class Solution {
public:
    vector<bool> canMakePaliQueries(const string &s, vector<vector<int>> &queries) {
        /**
         * O(q) exclusive-or approach.
         */
        vector<bool> result;
        result.reserve(queries.size());

        vector<unsigned int> prefix_sum{0};
        prefix_sum.reserve(s.size());
        unsigned int mask = 0;
        for (const auto &c: s) {
            prefix_sum.push_back(mask ^= (1u << (unsigned) (c - 'a')));
        }

        unsigned int odd;
        for (auto &q: queries) {
            odd = popcount(prefix_sum[q[1] + 1] ^ prefix_sum[q[0]]);
            result.push_back((odd - ((q[1] - q[0] + 1) % 2 ? 1 : 0)) <= 2u * q[2]);
        }

        return result;
    }

    vector<bool> canMakePaliQueries1(string s, vector<vector<int>> &queries) {
        /**
         * O(26 * q ^ 2) naive algorithm, cannot pass the 29-th test case.
         */
        vector<bool> result;
        result.reserve(queries.size());

        int k, length, odd_num = 0;
        bool temp_result;
        vector<int> counter(26, 0);
        for (const auto &q: queries) {
            k = q[2];
            length = q[1] - q[0] + 1;
            fill(counter.begin(), counter.end(), 0);

            for (int i = q[0]; i <= q[1]; ++i) {
                counter[s[i] - 'a']++;
            }

            odd_num = 0;
            for (const auto &c: counter) {
                if (c % 2) {
                    odd_num++;
                }
            }

            temp_result = (odd_num - (length % 2 ? 1 : 0)) <= 2 * k;

            result.push_back(temp_result);
        }

        return result;
    }
};

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    string s;
    cin >> s;

    vector<vector<int>> queries;
    int left, right, k;
    string line;
    istringstream ist;
    while (getline(cin, line)) {
        ist.clear();
        ist.str(line);

        cin >> left >> right >> k;
        queries.push_back({left, right, k});
    }

    Solution solution;
    vector<bool> result = solution.canMakePaliQueries(s, queries);
    for (auto r: result) {
        cout << (r ? "true" : "false") << endl;
    }
}
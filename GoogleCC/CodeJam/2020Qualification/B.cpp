//
// Created by 10578 on 4/4/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <set>
#include <tuple>
#include <utility>

//#define DEBUG

#define ALTER_IN(filename) std::fstream in_f(filename); std::cin.rdbuf(in_f.rdbuf());
#define BOOST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;

void add_parentheses(string &s, int first, int last) {
    int real_first, real_last = s.size();
    int index = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '(' && s[i] != ')') {
            ++index;

            if (index == first) {
                real_first = i;
            } else if (index == last) {
                real_last = i;
            }
        }
    }

    s.insert(s.begin() + real_first, '(');
    s.insert(s.begin() + real_last + 1, ')');
}

string solve(const string &digits) {
    string result = digits;
    vector<int> nums(digits.size());
    transform(digits.begin(), digits.end(), nums.begin(), [](char c) -> int {
        return c - '0';
    });

    int satisfied = count(digits.begin(), digits.end(), '0');
    int layer = 1;
    int sz = digits.size();

    while (satisfied != sz) {
        int first = 0;
        bool is_start = false;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == layer) {
                ++satisfied;
            }

            if (is_start) {
                if (nums[i] < layer) {
                    add_parentheses(result, first, i);
                    is_start = false;
                }
            } else if (nums[i] >= layer) {
                first = i;
                is_start = true;
            }

            if (i == sz - 1 && nums[i] >= layer) {
                add_parentheses(result, first, i + 1);
            }
        }

        ++layer;
    }

    return result;
}

int main() {
    BOOST_IO;

#ifdef DEBUG
    ALTER_IN("../in.txt");
#endif

    int T;
    cin >> T;

    string s;
    for (int i = 1; i <= T; ++i) {
        cin >> s;
        cout << "Case #" << i << ": " << solve(s) << endl;
    }
}
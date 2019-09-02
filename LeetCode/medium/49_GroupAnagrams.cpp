//
// Created by 10578 on 8/28/2019.
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> result{};
        unordered_map<string, vector<string>> result_map;

        string temp;
        for (auto &str: strs) {
            temp = str;
            sort(temp.begin(), temp.end());

            if (result_map.find(temp) == result_map.end()) {
                result_map[temp] = vector<string>{str};
            } else {
                result_map[temp].push_back(str);
            }
        }

        result.reserve(result_map.size());
        for (const auto &r: result_map) {
            result.push_back(r.second);
        }

        return result;
    }
};

static auto const magic = []() { BOOST_IO };

int main() {
    BOOST_IO;

#ifdef LOCAL
    fstream in("in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<string> strs;
    string temp;
    while (cin >> temp) {
        strs.push_back(temp);
    }

    Solution s;
    auto result = s.groupAnagrams(strs);
    for (const auto &v: result) {
        for (const auto &str: v) {
            cout << str << " ";
        }
    }
}
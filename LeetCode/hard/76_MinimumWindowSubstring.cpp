//
// Created by 10578 on 9/1/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream fin(filename); cin.rdbuf(fin.rdbuf());
#define LOCAL

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        for (auto &c: t) {
            if (t_map.find(c) == t_map.end()) {
                t_map[c] = 1;
            } else {
                t_map[c]++;
            }
        }

        int min_begin = 0, min_dist = INT32_MAX, p = 0, q = 0, counter = 0;
        while (q != s.length()) {
            if (t_map.find(s[q]) != t_map.end()) {
                t_map[s[q]]--;

                if (t_map[s[q]] >= 0)
                    counter++;
            }

            while (counter == t.length()) {
                if (int dist = q - p + 1; dist < min_dist) {
                    min_begin = p, min_dist = dist;
                }

                if (t_map.find(s[p]) != t_map.end()) {
                    t_map[s[p]]++;

                    if (t_map[s[p]] == 1)
                        counter--;
                }
                p++;
            }

            q++;
        }

        return min_dist == INT32_MAX ? "" : s.substr(min_begin, min_dist);
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

    string s, t;
    cin >> s >> t;

    cout << Solution().minWindow(s, t) << endl;
}

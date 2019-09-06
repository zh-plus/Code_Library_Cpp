//
// Created by 10578 on 9/3/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <cmath>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;


class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
        /**
         * O(m * n + 2^6 * m) HashMap solution.
         */

        unordered_map<int, int> words_num_map;
        vector<int> result;

        for (const auto &word: words) {
            unsigned int word_bit = 0;
            int cnt = 0;

            for (const auto &c: word) {
                if (!(word_bit & (1u << (unsigned) (c - 'a')))) {
                    cnt++;
                    if (cnt > 7) {
                        break;
                    }
                    word_bit |= (1u << (unsigned) (c - 'a'));
                }
            }

            if (cnt <= 7) {
                if (words_num_map.find(word_bit) == words_num_map.end()) {
                    words_num_map[word_bit] = 1;
                } else {
                    words_num_map[word_bit]++;
                }
            }
        }

        for (const auto &puzzle: puzzles) {
            int ans = 0;

            vector<unsigned int> all_matched{(1u << (unsigned) (puzzle[0] - 'a'))};
            for (const auto &c: puzzle) {
                // Back Tracking
                for (int i = 0, sz = all_matched.size(); i < sz; ++i) {
                    if (!(all_matched[i] & (1u << (unsigned) (c - 'a')))) {
                        all_matched.push_back(all_matched[i] | (1u << (unsigned) (c - 'a')));
                    }
                }
            }

            for (const auto &match: all_matched) {
                if (words_num_map.find(match) != words_num_map.end()) {
                    ans += words_num_map[match];
                }
            }

            result.push_back(ans);
        }

        return result;
    }


    vector<int> findNumOfValidWords1(vector<string> &words, vector<string> &puzzles) {
        /**
         * O(m * n) bit operation (Set like) solution.
         */
        vector<int> result(puzzles.size(), 0);

        vector<unsigned int> base;
        unordered_set<char> tmp;
        unsigned int bit;
        for (auto &word: words) {
            tmp.clear();
            bit = 0;

            for (auto &c: word) {
                tmp.insert(c);
                bit |= (1u << (unsigned) (c - 'a'));
            }

            if (tmp.size() <= 7) {
                base.push_back(bit);
            }
        }

        unordered_set<char> puzzle_set;
        for (int i = 0, sz = puzzles.size(); i < sz; ++i) {
            unsigned int puzzle_bit = 0;
            for (auto &c: puzzles[i]) {
                puzzle_bit |= (1u << (unsigned) (c - 'a'));
            }

            unsigned int first_bit = 1u << (unsigned) (puzzles[i][0] - 'a');
            for (auto &word_bit : base) {
                if ((word_bit & puzzle_bit) == word_bit && (word_bit & first_bit) == first_bit) {
                    result[i]++;
                }
            }
        }

        return result;
    }
};

 __attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
    printf("BOOST_IO done!\n");
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in2.txt");
#endif

    vector<string> words, puzzles;
    string line;
    getline(cin, line);

    istringstream ist(line);
    for (string s; ist >> s;) {
        words.push_back(s);
    }

    getline(cin, line);
    ist.clear();
    ist.str(line);
    for (string s; ist >> s;) {
        puzzles.push_back(s);
    }

    Solution s;
    vector<int> result = s.findNumOfValidWords(words, puzzles);
    for (auto x: result) {
        cout << x << " ";
    }
}

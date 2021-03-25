//
// Created by 10578 on 2021/3/24.
//

#include "iostream"
#include "fstream"
#include "sstream"
#include "vector"
#include "algorithm"
#include "iterator"
#include "deque"
#include "string"
#include "utility"
#include "list"
#include "tuple"

#define ALTER_IN(filename) std::fstream fs(filename); std::cin.rdbuf(fs.rdbuf());

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<pair<int, int>> vp(A.size());
        for (auto i = 0; i < B.size(); ++i) {
            vp[i] = pair<int, int>(B[i], i);
        }

        sort(A.begin(), A.end());
        sort(vp.begin(), vp.end(), [](const auto a, const auto b) {
            return a.first < b.first;
        });

        list<int> l(A.begin(), A.end());

        for (auto [it, j, num] = make_tuple(l.begin(), 0, 0); it != l.end() && num < l.size(); ++num) {
            if (*it > vp[j].first) {
                ++j;
                ++it;
            } else {
                int temp = *it;
                it = l.erase(it);
                l.push_back(temp);
            }
        }

        auto result = vector<int>(A.size());
        for (auto[it, i] = make_tuple(l.begin(), 0); it != l.end(); ++it, ++i) {
            result[vp[i].second] = *it;
        }

        return result;
    }
};

int main(){
    ALTER_IN("in.txt");

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    Solution s;

    while (T--) {
        getline(cin, line);
        istringstream issA(line);
        vector<int> A{istream_iterator<int>(issA), istream_iterator<int>()};

        getline(cin, line);
        istringstream issB(line);
        vector<int> B{istream_iterator<int>(issB), istream_iterator<int>()};

        for (auto &&x: s.advantageCount(A, B)) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
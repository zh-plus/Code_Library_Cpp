//
// Created by 10578 on 2021/3/26.
//

#include "iostream"
#include "fstream"
#include "sstream"
#include "iterator"
#include "utility"
#include "vector"
#include "unordered_set"
#include "algorithm"
#include "stack"
#include "limits"
#include "string"

#define ALTER_IN(filename) std::fstream fs(filename); std::cin.rdbuf(fs.rdbuf());

using pii = std::pair<int, int>;
using namespace std;

namespace std {
    template<>
    struct hash<pii> {
        size_t operator()(const pii &p) const {
            hash<int> hash_fn;
            size_t seed = hash_fn(p.first);
            return hash_fn(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
    };
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        auto m = matrix.size(), n = matrix.front().size();
        vector<vector<unordered_set<pii>>> adj(m, vector<unordered_set<pii>>(n));

        unordered_set<pii> pac_set;
        unordered_set<pii> atl_set;

        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                int elem = matrix[i][j];

                if (i - 1 >= 0 && matrix[i - 1][j] >= elem) {
                    adj[i][j].emplace(i - 1, j);
                }

                if (i + 1 < m && matrix[i + 1][j] >= elem) {
                    adj[i][j].emplace(i + 1, j);
                }

                if (j - 1 >= 0 && matrix[i][j - 1] >= elem) {
                    adj[i][j].emplace(i, j - 1);
                }

                if (j + 1 < n && matrix[i][j + 1] >= elem) {
                    adj[i][j].emplace(i, j + 1);
                }
            }
        }

        stack<pii> s;

        // pacific ocean
        for (auto i = 0; i < m; ++i) {
            s.emplace(i, 0);
        }
        for (auto j = 1; j < n; ++j) {
            s.emplace(0, j);
        }
        while (!s.empty()) {
            auto curr = s.top();
            s.pop();

            pac_set.insert(curr);
            for (auto &&x: adj[curr.first][curr.second]) {
                if (pac_set.count(x) == 0) {
                    s.push(x);
                }
            }
        }

        // atlantic ocean
        for (auto i = 0; i < m; ++i) {
            s.emplace(i, n - 1);
        }
        for (auto j = 0; j < n - 1; ++j) {
            s.emplace(m - 1, j);
        }
        while (!s.empty()) {
            auto curr = s.top();
            s.pop();

            atl_set.insert(curr);
            for (auto &&x: adj[curr.first][curr.second]) {
                if (atl_set.count(x) == 0) {
                    s.push(x);
                }
            }
        }

        auto result = vector<pii>();

        copy_if(pac_set.begin(), pac_set.end(), back_inserter(result), [&](const pii &p) {
            return atl_set.count(p) != 0;
        });

        auto final_result = vector<vector<int>>(result.size());
        transform(result.begin(), result.end(), begin(final_result), [](pii x) {
            return vector<int>{x.first, x.second};
        });

        return final_result;
    }
};

int main() {
    ALTER_IN("in.txt");

    int m, n;
    cin >> m >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(m);
    for (auto &x: matrix) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        x = vector<int>{istream_iterator<int>(iss), istream_iterator<int>()};
    }

    Solution s;
    for (auto p: s.pacificAtlantic(matrix)) {
        cout << p[0] << " " << p[1] << endl;
    }

    return 0;
}
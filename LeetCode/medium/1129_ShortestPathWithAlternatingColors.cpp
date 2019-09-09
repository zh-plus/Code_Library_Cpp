//
// Created by 10578 on 9/2/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <queue>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream f_in(filename); cin.rdbuf(f_in.rdbuf());
#define LOCAL

using namespace std;

class ColorDG {
public:
    int N;
    vector<unordered_set<int>> red_adj;
    vector<unordered_set<int>> blue_adj;

    ColorDG(int N) : N{N}, red_adj(N, unordered_set<int>{}), blue_adj(N, unordered_set<int>{}) {};

    void add_redge(const int &u, const int &v) {
        red_adj[u].insert(v);
    }

    void add_bedge(const int &u, const int &v) {
        blue_adj[u].insert(v);
    }
};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges) {
        ColorDG colorDg(n);
        for (const auto &p: red_edges) {
            colorDg.add_redge(p[0], p[1]);
        }

        for (const auto &p: blue_edges) {
            colorDg.add_bedge(p[0], p[1]);
        }

        vector<int> red_distance(n, INT32_MAX);
        red_distance[0] = 0;
        unordered_set<int> r_visited, b_visited;
        queue<int> q;
        q.push(0);

        vector<int> levels(n, 0);
        bool red = true;
        int front, this_level;
        while (!q.empty()) {
            front = q.front();
            this_level = levels[front];
            if (red) {
                for (auto &x: colorDg.red_adj[front]) {
                    if (r_visited.find(x) == r_visited.end()) {
                        red_distance[x] = min(red_distance[x], this_level + 1);
                        levels[x] = this_level + 1;
                        r_visited.insert(x);
                        q.push(x);
                    }
                }
            } else {
                for (auto &x: colorDg.blue_adj[front]) {
                    if (b_visited.find(x) == b_visited.end()) {
                        red_distance[x] = min(red_distance[x], this_level + 1);
                        levels[x] = this_level + 1;
                        b_visited.insert(x);
                        q.push(x);
                    }
                }
            }

            q.pop();
            red = not red;
        }

        vector<int> blue_distance(n, INT32_MAX);
        blue_distance[0] = 0;
        r_visited.clear();
        b_visited.clear();
        q = {};
        q.push(0);

        fill(levels.begin(), levels.end(), 0);
        red = false;
        while (!q.empty()) {
            front = q.front();
            this_level = levels[front];
            if (red) {
                for (auto &x: colorDg.red_adj[front]) {
                    if (r_visited.find(x) == r_visited.end()) {
                        blue_distance[x] = min(blue_distance[x], this_level + 1);
                        levels[x] = this_level + 1;
                        r_visited.insert(x);
                        q.push(x);
                    }
                }
            } else {
                for (auto &x: colorDg.blue_adj[front]) {
                    if (b_visited.find(x) == b_visited.end()) {
                        blue_distance[x] = min(blue_distance[x], this_level + 1);
                        levels[x] = this_level + 1;
                        b_visited.insert(x);
                        q.push(x);
                    }
                }
            }

            q.pop();
            red = not red;
        }

        vector<int> distance(n);
        for (int i = 0; i < n; ++i) {
            distance[i] = min(red_distance[i], blue_distance[i]);

            if (distance[i] == INT32_MAX)
                distance[i] = -1;
        }

        return distance;
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

    int n;
    cin >> n;
    cin.ignore(256, '\n');

    vector<vector<int>> red_edges;
    vector<vector<int>> blue_edges;
    red_edges.reserve(100);
    blue_edges.reserve(100);

    string line;
    istringstream ist;

    getline(cin, line);
    ist.str(line);
    for (int u, v; ist >> u >> v;) {
        red_edges.push_back({u, v});
    }

    getline(cin, line);
    ist.clear();
    ist.str(line);
    for (int u, v; ist >> u >> v;) {
        blue_edges.push_back({u, v});
    }

    Solution s;
    vector<int> result = s.shortestAlternatingPaths(n, red_edges, blue_edges);
    for (auto r: result) {
        cout << r << " ";
    }
}
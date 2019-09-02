//
// Created by 10578 on 2019/8/18.
//
#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


class Graph {
public:
    vector<vector<int>> adj;

    Graph(int n) {
        adj = vector<vector<int>>(n);
    };

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> get_connect(int a) {
        return adj[a];
    }

    bool is_connect(int a, int b) {
        for (auto x: adj[a]) {
            if (x == b) {
                return true;
            }
        }

        return false;
    }
};


int solve(int n, const vector<unsigned int> &A) {
    Graph graph(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] & A[j]) {
                graph.add_edge(A[i], A[j]);
            }
        }
    }


}


int main() {
    BOOST_IO;

    int n;
    cin >> n;

    vector<unsigned int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int result = solve(n, A);
    cout << result;

    return 0;
}


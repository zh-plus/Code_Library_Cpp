//
// Created by 10578 on 8/27/2019.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

#define LOCAL

using namespace std;

int *p;

int find(int n) {
    int i = n;
    while (i != p[i]) {
        p[i] = p[p[i]];
        i = p[i];
    }

    return i;
}

void _union(int u, int v) {
    int p_u = find(u), p_v = find(v);
    if (p_u > p_v) {
        p[p_u] = p_v;
    } else {
        p[p_v] = p_u;
    }
}

int solve(int n, int m, int k, vector<pair<int, int>> info) {
    for (auto &[u, v]:info) {
        v += n;
    }

    p = new int[n + m + 1];
    for (int i = 0; i <= n + m; ++i) {
        p[i] = i;
    }

    for (auto &[u, v]:info) {
        _union(u, v);
    }

    int result = 0;
    for (int i = 1; i <= n + m; ++i) {
        if (p[i] == i) {
            result++;
        }
    }

    unordered_set<int> used;
    for (auto &[u, v]: info) {
        used.insert(v);
    }
    int useless_lang = m - used.size();

    return result - useless_lang - 1;
}


int main() {

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> info;
    int u, v;
    while (k--) {
        cin >> u >> v;
        info.emplace_back(u, v);
    }

    int result = solve(n, m, k, info);
    cout << result;
}
//
// Created by 10578 on 9/14/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
//#define LOCAL

using namespace std;

class UDG {
private:
    int N;

public:

    vector<vector<pair<int, int>>> adj;

    UDG(int N) : N{N}, adj(N, vector<pair<int, int>>{}) {};

    int size() { return N; }

    void add_edge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
};

vector<int> get_path(vector<int> parent, int source, int target) {
    if (parent[target] == INT32_MAX) {
        return vector<int>{-1};
    }

    vector<int> path;
    path.reserve(parent.size());
    while (target != -1) {
        path.push_back(target);
        target = parent[target];
    }

    return path;
}


vector<int> dijkstra(UDG graph, int source) {
    vector<int> min_distance(graph.size(), INT32_MAX);
    min_distance[source] = 0;
    vector<int> parent(graph.size(), INT32_MAX);
    parent[source] = -1;

    vector<bool> visited(graph.size(), false);

    auto cmp = [](pair<int, int> p1, pair<int, int> p2) { return p1.second > p2.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    pq.emplace(source, 0);

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        int to = cur.first, cur_distance = cur.second;
        if (visited[to])
            continue;

        visited[to] = true;
        for (auto &x: graph.adj[to]) {
            if (int new_dis = cur_distance + x.second; !visited[x.first] && new_dis < min_distance[x.first]) {
                min_distance[x.first] = new_dis;
                pq.emplace(x.first, new_dis);
                parent[x.first] = to;
            }
        }
    }

    return parent;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int n, m;
    cin >> n >> m;

    UDG graph(n + 1);
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        graph.add_edge(u, v, w);
    }

    auto result = get_path(dijkstra(graph, 1), 0, n);
    reverse(result.begin(), result.end());

    for (auto &x: result) {
        cout << (x != INT32_MAX ? x : -1) << " ";
    }
}

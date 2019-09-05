//
// Created by 10578 on 2019/8/20.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_set>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

class UDG{
public:
    int V;
    vector<unordered_set<int>> edges;
    vector<vector<bool>> available;

    UDG(int V): V{V}, edges(V + 1), available(V + 1, vector<bool>(V + 1, false)) {}

    void add_edge(int u, int v){
        edges[u].insert(v);
        edges[v].insert(u);

        for (int i = 1; i < V + 1; ++i) {
            for (int j = 1; j < V + 1; ++j) {
                if (not available[i][j]){
                    available[i][j] =  (available[i][u] and available[v][j]) or (available[i][v] and available[u][j]);
                    available[j][i] =  available[i][j];
                }
            }
        }
    }

    void remove_edge(int u, int v){
        edges[u].erase(v);
        edges[v].erase(u);
    }


};

int solve(string s) {

}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<int> D, H;
    int T;
    string s;
    cin >> T;

    while (T--) {
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
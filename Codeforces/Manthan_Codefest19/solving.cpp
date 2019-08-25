//
// Created by 10578 on 8/25/2019.
//

//
// Created by 10578 on 2019/8/20.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

int get_max(vector<int> v, int left, int right) {
    int max = v[left];

    for (int i = left + 1; i < right; ++i) {
        if (v[i] > max) {
            max = v[i];
        }
    }

//    if (right - left != v.size()) {
//        max = 0;
//    }

    return max;
}

vector<int> solve(int n, int w, vector<vector<int>> &rows, vector<vector<int>> &tables) {
    int left, right;
    vector<int> r;
    int size;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < w; ++j) {
            r = rows[i];
            size = r.size();
            left = max(0, size - w + j);
            right = min(size - 1, j);
            tables[i][j] = get_max(r, left, right + 1);
        }
    }

    vector<int> result(w);
    int sum;
    for (int j = 0; j < w; ++j) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += tables[i][j];
        }
        result[j] = sum;
    }

    return result;
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, w;
    cin >> n >> w;
    vector<vector<int>> rows(n);
    int l, num;
    for (int j = 0; j < n; ++j) {
        vector<int> temp;
        cin >> l;
        for (int i = 0; i < l; ++i) {
            cin >> num;
            temp.push_back(num);
        }

        rows[j] = temp;
    }

    vector<vector<int>> tables(n);
    for (auto &v: tables) {
        v = vector<int>(w, 0);
    }

    vector<int> result = solve(n, w, rows, tables);
    for (auto &v: result) {
        cout << v << " ";
    }

    return 0;
}
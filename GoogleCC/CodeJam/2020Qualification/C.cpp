//
// Created by 10578 on 4/4/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <set>
#include <tuple>
#include <utility>

//#define DEBUG

#define ALTER_IN(filename) std::fstream in_f(filename); std::cin.rdbuf(in_f.rdbuf());
#define BOOST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;

string solve(vector<pair<int, int>> &A) {
    string result = "IMPOSSIBLE";

    vector<pair<int, int> *> A_ptr(A.size());
    transform(A.begin(), A.end(), A_ptr.begin(), [](auto &x) { return &x; });

    sort(A_ptr.begin(), A_ptr.end(), [](auto *a, auto *b) {
        return *a < *b;
    });

    set<pair<int, int> *> cameron;
    set<pair<int, int> *> jamie;

    int start, end;
    int c_end, j_end;
    for (auto *i : A_ptr) {
        tie(start, end) = *i;
        if (cameron.empty() || start >= c_end) {
            cameron.insert(i);
            c_end = i->second;
        } else if (jamie.empty() || start >= j_end) {
            jamie.insert(i);
            j_end = i->second;
        } else {
            return result;
        }
    }

    result.clear();
    for (auto &a: A) {
        result += (cameron.find(&a) != cameron.end()) ? 'C' : 'J';
    }

    return result;
}

int main() {
    BOOST_IO;

#ifdef DEBUG
    ALTER_IN("../in.txt");
#endif

    int T;
    cin >> T;

    vector<pair<int, int>> activities;
    int N;
    int s, e;
    for (int i = 1; i <= T; ++i) {
        activities.clear();
        cin >> N;

        while (N--) {
            cin >> s >> e;
            activities.emplace_back(s, e);
        }

        cout << "Case #" << i << ": " << solve(activities) << endl;
    }
}
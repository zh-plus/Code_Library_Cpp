//
// Created by 10578 on 8/28/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        vector<int> prefix_sum(distance.size() + 1, 0);
        for (int sum = 0, i = 1, sz = distance.size(); i <= sz; ++i) {
            sum += distance[i - 1];
            prefix_sum[i] = sum;
        }

        if (destination < start) {
            swap(destination, start);
        }
        int forward = prefix_sum[destination] - prefix_sum[start];

        return forward < prefix_sum.back() - forward ? forward : prefix_sum.back() - forward;
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

    vector<int> distances;
    distances.reserve(100);
    string line;
    getline(cin, line);
    istringstream ist(line);
    for (int num; ist >> num;) {
        distances.push_back(num);
    }
    int s, d;
    cin >> s >> d;

    Solution solution;
    int result = solution.distanceBetweenBusStops(distances, s, d);
    cout << result;
}
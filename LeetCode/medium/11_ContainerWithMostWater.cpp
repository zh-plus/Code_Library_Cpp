//
// Created by 10578 on 8/29/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL
#define ALTER_IN(name) fstream in(name); cin.rdbuf(in.rdbuf());

using namespace std;

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
    printf("BOOST_IO done!\n");
}

class Solution {
public:
    int maxArea(vector<int> &height) {
        int p = 0, q = (int) height.size() - 1;

        int a_max = min(height[p], height[q]) * (q - p);
        while (p < q) {
            if (height[p] < height[q]) {
                while (p < q && height[p + 1] < height[p]) {
                    p++;
                }
                p++;
            } else {
                while (p < q && height[q - 1] < height[q]) {
                    q--;
                }
                q--;
            }
            a_max = max(a_max, min(height[p], height[q]) * (q - p));
        }

        return a_max;
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<int> A;
    A.reserve(100);
    for (int num; cin >> num;) {
        A.push_back(num);
    }

    Solution s;
    cout << s.maxArea(A);
}

//
// Created by 10578 on 2021/3/23.
//

#include "iostream"
#include "vector"
#include "iterator"
#include "string"
#include "algorithm"
#include "numeric"
#include "limits"
#include "sstream"
#include "fstream"

#define ALTER_IN(filename) std::fstream fs(filename); std::cin.rdbuf(fs.rdbuf());

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        auto num_repr = get_num_repr(N);

        for (auto i = 0; i < 30; ++i) {
            if (get_num_repr(pow(2, i)) == num_repr) {
                return true;
            }
        }

        return false;
    }

    vector<int> get_num_repr(int N) {
        if (N == 0) {
            return vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        }

        // 0123456789 frequency
        vector<int> v(10, 0);
        while (N != 0) {
            ++v[N % 10];
            N /= 10;
        }

        return v;
    }
};

int main() {

    Solution s;
    cout << s.reorderedPowerOf2(10);

    return 0;
}
//
// Created by 10578 on 2019/8/24.
//

#include <vector>
#include <iostream>
#include <fstream>


#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL


using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        digits.insert(digits.begin(), 0);
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if ((digits[i] += carry) == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if (not digits[0]) {
            digits.erase(digits.begin());
        }

        return digits;
    }
};


int main() {
    BOOST_IO;

#ifdef LOCAL
    fstream in("in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<int> digits;
    int d;
    while (cin >> d) {
        digits.push_back(d);
    }

    Solution s;
    auto add_one = s.plusOne(digits);

    for (auto x: add_one) {
        cout << x << " ";
    }
}
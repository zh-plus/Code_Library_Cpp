//
// Created by 10578 on 9/26/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

static inline void rstrip(string &s, char value) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [&value](char c) { return c != value; }));
}

class Solution {
public:
    string addBinary(string a, string b) {
        string result(max(size(a), size(b)) + 1, '0');
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        int temp;
        for (int i = 0, sz_a = size(a), sz_b = size(b), sz = max(sz_a, sz_b); i <= sz; ++i) {
            temp = carry + (i < sz_a ? a[i] - '0' : 0) + (i < sz_b ? b[i] - '0' : 0);
            if (temp > 1) {
                carry = 1;
                temp -= 2;
            } else {
                carry = 0;
            }

            result[i] = '0' + temp;
        }

        reverse(result.begin(), result.end());
        rstrip(result, '0');

        if (result.empty()) {
            result = "0";
        }

        return result;
    }
};


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    string num1, num2;
    cin >> num1 >> num2;

    cout << Solution().addBinary(num1, num2);

    return 0;
}
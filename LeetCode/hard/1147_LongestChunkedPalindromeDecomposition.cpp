//
// Created by 10578 on 9/3/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

typedef long long ll;

using namespace std;

ll modpow(ll base, ll exp, ll modulus) {
    /**
     * Calculate the power(base, exp) using fast power algorithm,
     * with modulus.
     */

    ll result = 1;
    base %= modulus;

    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % modulus;
        }

        base = (base * base) % modulus;
        exp >>= 1;
    }

    return result;
}

class Solution {
public:
    int longestDecomposition1(string text) {
        /**
         * O(n^2) greedy algorithm.
         */
        int sz = text.size();
        if (sz <= 1) {
            return sz;
        }

        for (int i = 1; i <= sz / 2; ++i) {
            if (text.substr(0, i) == text.substr(sz - i, i)) {
                return 2 + longestDecomposition1(text.substr(i, sz - 2 * i));
            }
        }

        return 1;
    }

    int longestDecomposition(string text) {
        /**
         * O(n) in practice using a big enough magic_prime.
         * O(n^2) in theory.
         */

        ll magic_prime = 32416189573;

        int lo = 0, hi = text.size() - 1;
        ll lo_hash = 0, hi_hash = 0, hash_length = 0;
        int hi_char;

        ll result = 0;
        while (lo < hi) {
            lo_hash *= 26;
            lo_hash += text[lo] - 'a';

            hi_char = text[hi] - 'a';
            hi_hash += hi_char * modpow(26, hash_length, magic_prime);

            lo++;
            hi--;
            hash_length++;

            if (lo_hash == hi_hash) {
                result += 2;

                lo_hash = 0;
                hi_hash = 0;
                hash_length = 0;
            }
        }

        if ((hash_length == 1 and lo == hi) or hash_length > 0) {
            result++;
        }

        return result;
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

    string text;
    cin >> text;
    Solution s;
    cout << s.longestDecomposition(text);

    return 0;
}

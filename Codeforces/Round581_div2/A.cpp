//
// Created by 10578 on 2019/8/20.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bitset>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//#define LOCAL
#define MAX 100

using namespace std;


bool only_one(bitset<MAX> nums, int &pos) {
    bool found = false;
    for (int i = 0; i < MAX; ++i) {
        if (found & nums[i])
            return false;

        if (nums[i]) {
            found = true;
            pos = i;
        }
    }

    return found;
}

int solve(bitset<MAX> nums) {
    if (int pos = 0; only_one(nums, pos) && pos % 2 == 0) {
        return pos / 2;
    }

    //compute ceil(log_4^num)
    int max = 0;
    while (nums.any()) {
        nums >>= 2;
        max++;
    }

    return max;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string bit_string;

    getline(cin, bit_string);
    bitset<MAX> bs(bit_string);

    int result = solve(bs);

    cout << result;

    return 0;
}
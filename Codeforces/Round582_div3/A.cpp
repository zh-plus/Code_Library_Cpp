//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

int solve(int n, const vector<int>& nums){
    int odd = 0, even = 0;
    for (int num: nums) {
        if (num % 2) {
            odd ++;
        } else {
            even ++;
        }
    }

    int smaller = min(odd, even);
    return smaller;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<int> nums;
    int n;
    cin >> n;
    nums.reserve(n);
    int temp;
    while (n--) {
        cin >> temp;
        nums.push_back(temp);
    }

    int result = solve(n, nums);
    cout << result;

    return 0;
}
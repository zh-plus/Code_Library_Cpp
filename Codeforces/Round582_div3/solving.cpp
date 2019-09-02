//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

typedef long long ll;

using namespace std;

bool check_already(ll k, const vector<int> &nums) {
    unordered_map<int, int> um;
    for (int num: nums) {
        if (um.find(num) == um.end()) {
            um.insert(make_pair(num, 0));
        } else {
            um[num]++;
        }

        if (um[num] == k) {
            return true;
        }
    }

    return false;
}

ll find_min_op(vector<int> exps, int i, int k) {
    int total = 0;
    int same = 0;
    int last;
    int j = i;
    while (same < k) {
        last = exps[j];
        same += last;
        total += last * (j - i + 1);
        j++;
    }
    j--;

    if (int diff = same - k; diff > 0) {
        int extra = diff * (j - i + 1);
        total -= extra;
    }

    return total;
}


ll solve(ll n, ll k, const vector<int> &nums) {
    if (check_already(k, nums)) {
        return 0;
    }

    int max_num = *max_element(nums.begin(), nums.end());
    vector<int> exps(floor(log2(max_num)) + 1, 0);

    double index;
    for (const int num: nums) {
        index = log2(num);
        if (index - int(index) != 0) {
            index--;
        }

        exps[index]++;
    }

    int last = exps.size() - 1;
    int post_sum = 0;
    for (; last >= 0; --last) {
        if (post_sum >= k) {
            last++;
            break;
        }

        post_sum += exps[last];
    }

    vector<ll> operations(last + 1, 0);
    for (int i = 0; i <= last; ++i) {
        operations[i] = find_min_op(exps, i, k);
    }

    return *min(operations.begin(), operations.end());
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<int> nums;
    int n, k, temp;
    ll result;
    cin >> n >> k;
    nums.reserve(n);
    while (n--) {
        cin >> temp;
        nums.push_back(temp);
    }

    result = solve(n, k, nums);
    cout << result << endl;

    return 0;
}
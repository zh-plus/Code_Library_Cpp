//
// Created by 10578 on 2019/8/19.
//
#include <vector>
#include <iostream>
//#include <fstream>
#include <sstream>
#include <fstream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {


    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<int> nums;

    string line;
    istringstream ss(line);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    for (auto x: nums) {
        cout << x << " ";
    }

    return 0;
}
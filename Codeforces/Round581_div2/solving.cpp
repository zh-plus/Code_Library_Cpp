//
// Created by 10578 on 2019/8/20.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

typedef long long ll;

using namespace std;

//int solve1(bitset<MAX> nums){
//    //add one
//    bool carry = true;
//    bool temp_bool;
//    for (int i = 0; i < MAX; i++)
//    {
//        temp_bool = nums[i] ^ carry;
//        carry = nums[i] & carry;
//        nums[i] = temp_bool;
//
//        if(!carry)
//            break;
//    }
//
//    //change to base-4
//    bitset<MAX> temp;
//    int last = 1;
//    for (int j = 0; j < MAX; j += 2) {
//        temp = nums << (MAX - j - 2);
//        temp >>= (MAX - 2);
//        if (auto value = temp.to_ulong())
//            last = j / 2;
//    }
//
//    return last;
//}

int main() {
    BOOST_IO;

//    ll
//    for (int i = 0; i < 51; ++i) {
//
//    }

    return 0;
}
//
// Created by 10578 on 2021/3/16.
//

#include "iostream"
#include "fstream"
#include "sstream"
#include "vector"
#include "algorithm"
#include "map"
#include "set"
#include "numeric"
#include "string"
#include "limits"
#include "iterator"
#include "utility"

#define ALTER_IN(filename) std::fstream in_f(filename); std::cin.rdbuf(in_f.rdbuf());
#define BOOST_IO std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

//__attribute__((constructor))
//void my_startup(){
//    BOOST_IO;
//}

class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        map<int, long long> m;
        set<int> s;

        int item, factor_limit;
        for (int i = 0; i < arr.size(); ++i) {
            item = arr[i];
            m[item] = 1;
            s.insert(item);

            factor_limit = int(item / 2);
            for (int j = 0; j < i; ++j) {
                if (arr[j] > factor_limit) {
                    break;
                }

                if (item % arr[j] == 0 && s.find(item / arr[j]) != s.end()) {
                    m[item] += m[arr[j]] * m[item / arr[j]]; // Left * Right
                    m[item] %= 1000000007;
                }
            }
        }

        return accumulate(m.begin(), m.end(), 0,
                          [](long long val, const pair<const int, int> &right) {
                              return (val + right.second) % 1000000007;
                          });
    }
};

int main() {
    ALTER_IN("in.txt");

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Solution s;
    string line;

    while (T--) {
        getline(cin, line);
        istringstream iss(line);

        vector<int> arr((istream_iterator<int>(iss)), istream_iterator<int>());

        cout << s.numFactoredBinaryTrees(arr) << endl;
    }
}
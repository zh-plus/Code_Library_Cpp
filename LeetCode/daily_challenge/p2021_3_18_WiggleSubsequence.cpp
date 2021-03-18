//
// Created by 10578 on 2021/3/18.
//

#include "iostream"
#include "fstream"
#include "sstream"
#include "iterator"
#include "algorithm"
#include "numeric"
#include "vector"
#include "string"
#include "limits"

#define ALTER_IN(filename) std::fstream fs(filename); std::cin.rdbuf(fs.rdbuf());

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> adj(nums.size());
        adjacent_difference(nums.begin(), nums.end(), adj.begin());

        int result = 1;
        bool is_pos, first = true;
        for (int i = 1; i < adj.size(); ++i) {
            if (adj[i] == 0) {
                continue;
            }

            if (first) {
                is_pos = adj[i] > 0;
                first = false;
                ++result;
            }

            if (adj[i] > 0 && !is_pos) {
                ++result;
                is_pos = true;
            } else if (adj[i] < 0 && is_pos) {
                ++result;
                is_pos = false;
            }
        }

        return result;
    }
};

int main(){
    ALTER_IN("in.txt");

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    Solution s;

    while (T--) {
        getline(cin, line);
        istringstream iss(line);
        vector<int> nums((istream_iterator<int>(iss)), istream_iterator<int>());

        cout << s.wiggleMaxLength(nums) << endl;
    }

    return 0;
}
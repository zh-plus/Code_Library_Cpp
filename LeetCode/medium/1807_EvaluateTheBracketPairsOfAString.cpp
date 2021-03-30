//
// Created by 10578 on 2021/3/30.
//

#include "vector"
#include "string"
#include "unordered_map"
#include "queue"

using namespace std;

class Solution {
public:
    string evaluate(const string& s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> k;
        for (auto &&item : knowledge) {
            k[item[0]] = item[1];
        }

        deque<char> dq;
        for (auto &&c: s) {
            dq.push_back(c);
            if (dq.back() == ')') {
                // pop the ")"
                dq.pop_back();

                string key;
                key.reserve(10);

                char c;
                do {
                    c = dq.back();
                    dq.pop_back();
                    key += c;
                } while (dq.back() != '(');

                // pop the "("
                dq.pop_back();

                reverse(key.begin(), key.end());

                string value = k.count(key) == 0 ? "?" : k[key];
                for (auto &&ch: value) {
                    dq.push_back(ch);
                }
            }
        }

        string result(dq.begin(), dq.end());

        return result;
    }
};

int main(){

    return 0;
}
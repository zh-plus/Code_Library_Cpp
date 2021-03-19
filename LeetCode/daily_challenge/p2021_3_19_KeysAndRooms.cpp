//
// Created by 10578 on 2021/3/19.
//

#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "iterator"
#include "algorithm"
#include "vector"
#include "unordered_set"
#include "stack"

#define ALTER_IN(filename) std::fstream fs(filename); std::cin.rdbuf(fs.rdbuf());
#define BOOST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

__attribute__((constructor))
void my_startup(){
    BOOST_IO;
}

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> accessed;

        stack<int> s;
        s.push(0);
        accessed.insert(0);

        int current;

        while (!s.empty()) {
            current = s.top();
            s.pop();

            for (auto &&x: rooms[current]) {
                if (!accessed.count(x)) {
                    s.push(x);
                    accessed.insert(x);

                    if (accessed.size() == rooms.size()) {
                        return true;
                    }
                }
            }
        }

        return accessed.size() == rooms.size();
    }
};

int main(){


    return 0;
}
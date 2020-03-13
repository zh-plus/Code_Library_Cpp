//
// Created by 10578 on 3/13/2020.
//

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

/**
 * unique_ptr
 * You cannot assign one unique_ptr to another to get two unique_ptr to the same object.
 * The origin one would be set to nullptr inside.
 * @return
 */
unique_ptr<vector<int>> make_vec() {
    unique_ptr<vector<int>> p{new vector<int>{1, 2, 3}};

    p->push_back(0);
    p.get();

    return p;
}

int main() {
    auto v = make_vec();

    for (auto &&x: *v) {
        cout << x << " ";
    }
    cout << endl;

    shared_ptr<int> si;

    float i = 1.4;
    float m = fmod(i, 1);
    cout << m;

    return 0;
};
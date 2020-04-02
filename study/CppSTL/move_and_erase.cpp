//
// Created by 10578 on 4/2/2020.
//

#include "move_and_erase.h"

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};

    erase(v, 3);
    print(v);

    return 0;
}
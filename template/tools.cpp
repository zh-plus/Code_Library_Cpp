//
// Created by 10578 on 3/14/2020.
//

#include <sstream>
#include "boost/function.hpp"
#include "boost/predef.h"
#include "tools.h"

int main() {
    using namespace std;

    vector<float> v{1, 2, 3, 4};

    auto r = tools::apply(v, [](auto x) { return x * 2; });

    tools::print(r);

    if (BOOST_OS_WINDOWS) {
        cout << "In windows!" << endl;
    }

    auto *d = new double[3]{1, 2, 3};

    cout << d[2] << endl;

    return 0;
}
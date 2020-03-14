//
// Created by 10578 on 3/14/2020.
//

#ifndef CODE_LIBRARY_TOOLS_H
#define CODE_LIBRARY_TOOLS_H

#include <vector>
#include <iostream>
#include <algorithm>

namespace tools {
    template<typename Container, typename Function>
    Container apply(const Container &container, Function &&function) {
        using std::begin, std::end, std::transform;

        Container result(container.size());

        transform(begin(container), end(container), begin(result), function);

        return result;
    }

    template<typename Container>
    void print(Container container) {
        for (auto &&x: container) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

}

#endif //CODE_LIBRARY_TOOLS_H

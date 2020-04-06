//
// Created by 10578 on 4/6/2020.
//

#include <vector>
#include <iostream>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

class Generator {
public:
    static inline auto engine = mt19937_64{
            static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count())
    };

    double operator()() const {
        return normal_distribution<double>(15, 4.0)(engine);
    }
};


int main() {
    auto gen = []() {
        static auto engine = mt19937_64{static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count())};
        return normal_distribution<double>(15, 4.0)(engine);
    };

    vector<int> hist(2 * 15);
    for (int i = 0; i < 1000; ++i) {
        ++hist[int(round(gen()))];
    }

    for (auto &&h: hist) {
        string s(h, '*');
        cout << s << endl;
    }

    return 0;
}
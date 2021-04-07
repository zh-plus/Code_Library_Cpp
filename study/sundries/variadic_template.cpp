//
// Created by 10578 on 2021/4/2.
//

#include "vector"
#include "iostream"

using namespace std;

template<typename T, size_t N1>
auto make_vector_2() {
    return vector<T>(N1);
}

template<typename T, size_t N1, size_t N2, size_t... Ns>
auto make_vector_2() {
    auto inner = make_vector_2<T, N2, Ns...>();

    return vector<decltype(inner)>(N1, inner);
}


template<typename T, size_t N, size_t... Ns>
auto make_vector_1() {
    if constexpr(sizeof...(Ns) > 0) {
        auto inner = make_vector_1<T, Ns...>();

        return vector<decltype(inner)>(N, inner);
    } else {
        return vector<T>(N);
    }
}


template<typename T>
vector<T> make_vector(size_t size) {
    return vector<T>(size);
}

template<typename T, typename... Rest>
auto make_vector(size_t f, Rest... rests) {
    auto inner = make_vector<T>(rests...);
    return vector<decltype(inner)>(f, inner);
}

template<typename T, size_t N, size_t... Ns>
struct MulVector {
    using inner_t = typename MulVector<T, Ns...>::type;
    inner_t inner_v = MulVector<T, Ns...>().value;
    using type = vector<inner_t>;
    type value = type(N, inner_v);
};

template<typename T, size_t N>
struct MulVector<T, N>{
    using type = vector<T>;
    type value = type(N);
};

template<typename T, size_t N, size_t... Ns>
using MulVector_t = typename MulVector<T, N, Ns...>::type;

//template<typename T, size_t N, size_t... Ns>
//using MulVector_v = MulVector<T, N, Ns...>().value;

int main() {
    integer_sequence<int, 1, 2, 3> is;

    auto v1 = make_vector<int>(1, 2, 3, 4);
    auto v2 = make_vector_1<int, 1, 2, 3, 4>();
    auto v3 = make_vector_2<int, 1, 2, 3, 4>();

    auto v4 = MulVector<int, 1, 2, 3, 4>().value;

    std::cout << "pause!" << endl;

    return 0;
}
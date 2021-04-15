//
// Created by 10578 on 2021/4/7.
//

#include "iostream"
#include "vector"
#include "utility"
#include "string"

using namespace std;

template<typename T>
void print(T t){
    cout << t << endl;
}

template<typename T, typename... Ts>
void print(T t, Ts... ts){
    cout << t << " ";
    print(ts...);
}

/**
 * @brief Not work for template parameter pack.
 * @return
 */
//template<int T>
//void print(){
//    cout << T << endl;
//}
//
//template<int T, int... Ts>
//void print(){
//    cout << T << endl;
//    print<Ts...>();
//}

template<typename... T>
auto fold_sum(T... s){
    return (0 + ... + s);
}

template<typename T, typename... Ts>
void fold_push_back(vector<T> &v, Ts... ts){
    (v.push_back(ts), ...);
}

template<typename T>
void print_v(vector<T> v){
    for (auto &&x: v){
        cout << x << " ";
    }
    cout << endl;
}

template<typename C, typename... Idx>
void print_elems(C const &c, Idx... idx){
    (print(c[idx]), ...);
}

int main(){
    print(1, 2, 3, 4);

//    print<1, 2, 3, 4>();
    cout << fold_sum(1, 2, 3, 4, 5) << endl;

    auto v = vector<int>{0, 1, 3};
    fold_push_back(v, 2, 3, 4);
    print_v(v);

    print_elems(v, 1, 3, 4);
}
//
// Created by 10578 on 2021/4/7.
//

#include "iostream"
#include "vector"

using namespace std;

template<auto Val, typename T = decltype(Val)>
T add_value(T t){
    return t + Val;
}

template<int V, int... Vs>
struct sum{
    const static int value = V + sum<Vs...>::value;
};

template<int V>
struct sum<V>{
    const static int value = V;
};


int main(){
    cout << add_value<10>(100.1) << endl;
    cout << sum<1, 2, 3, 4, 5>::value << endl;

    return 0;
}
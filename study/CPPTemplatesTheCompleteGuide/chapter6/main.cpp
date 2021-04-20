//
// Created by 10578 on 2021/4/15.
//

#include "iostream"
#include "utility"
#include "vector"

#include "person.h"

using namespace std;

void g(vector<int> &x){
    cout << "Using variable" << endl;
}

void g(vector<int> const &x){
    cout << "Using constant" << endl;
}

void g(vector<int> &&x){
    cout << "Using movable object" << endl;
}

void g(vector<int> const &&x){
    cout << "Using constant movable object" << endl;
}

/**
* Without perfect forwarding.
*/

void f(vector<int> &x){
    g(x);
}

void f(vector<int> const &x){
    g(x);
}

void f(vector<int> &&x){
    g(move(x));
}

template<typename T>
void f(T &&x){
    g(forward<T>(x));
}

template<typename T>
typename std::enable_if<(sizeof(T) > 4)>::type
foo () {}


int main(){
    string name = "sname";
    Person p1(name);
    Person p2("name2");

    Person p3(p1);

    extent

    return 0;
}
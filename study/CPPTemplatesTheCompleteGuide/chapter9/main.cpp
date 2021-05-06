//
// Created by 10578 on 2021/5/6.
//

#include "utility"
#include "string"
#include "unordered_set"

using namespace std;

class Customer{
private:
    string name;

public:
    explicit Customer(string  n): name(std::move(n)) {}

    string get_name() const{
        return name;
    }
};

namespace std{
    template<>
    struct hash<Customer>{
        auto operator() (const Customer& c) const{
            return hash<string>()(c.get_name());
        }
    };
}

int main(){
    unordered_set<Customer> c;

    return 0;
}
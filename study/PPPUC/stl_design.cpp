//
// Created by 10578 on 3/15/2020.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename Element>
class Link{
public:
    Element *prev;
    Element *succ;
    Element val;
};

template <typename Element>
class List{
    Link<Element> *first;
    Link<Element> *last;
};

template <typename Iterator>
Iterator get_max(Iterator first, const Iterator last){
    Iterator max = first;
    for (Iterator p = first; p < last; ++p) {
        if (*p > *max) {
            max = p;
        }
    }

    return max;
}

int main(){
    int jack_count = 3;
    auto *jack = new double[jack_count]{1, 5, 3};
    auto *jill = new vector<double>{4, 2, 3};

    auto jack_max = get_max(jack, jack + jack_count);
    double *p = &(*jill)[0];
    auto jill_max = get_max(p, p + jill->size());

    cout << "jack max: " << *jack_max << endl;
    cout << "jill max: " << *jill_max << endl;

    delete[] jack;
    delete jill;

    list<int> l{};
    auto first = l.begin();
    auto last = l.end();
    l.empty();

    vector<int> v{1, 2, 3};
    v.shrink_to_fit();

    advance(first, 2);
}
//
// Created by 10578 on 2021/2/28.
//

#include "iostream"
#include "fstream"
#include "vector"
#include "algorithm"
#include "string"
#include "sstream"
#include <iterator>

#define BOOST_IO std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) std::fstream f_in(filename); std::cin.rdbuf(f_in.rdbuf());

using namespace std;

template<typename C>
class MaxHeap{
public:
    C *container;

    explicit MaxHeap(C container) {
        this->container = new C(container);
    }

    void max_heapify(const int i){
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l <= this->container->length() && this->container[l] > this->container[i]) {
            largest = l;
        }

        if (r <= this->container->length() && )
    }



    int parent(const int i){ return i << 1; }

    int left(const int i) { return i >> 1; }

    int right(const int i) { return (i >> 1) + 1; }
};

int main(){
    BOOST_IO
    ALTER_IN("in.txt")

    vector<vector<int>> matrix;

    int N;
    cin >> N;
    matrix.resize(N);

    for (auto &row: matrix) {
        copy_n(istream_iterator<int>(cin), N, back_inserter(row));
    }

    for (auto &row: matrix) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
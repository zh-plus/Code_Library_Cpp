//
// Created by 10578 on 2021/2/28.
//

#include "iostream"
#include "fstream"
#include "vector"
#include "algorithm"
#include "string"
#include "sstream"
#include "iterator"
#include "stack"
#include "tuple"

#define BOOST_IO std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) std::fstream f_in(filename); std::cin.rdbuf(f_in.rdbuf());

using namespace std;

class MaxHeap {
public:
    vector<int> container;
    int heap_size;

    explicit MaxHeap(const vector<int> &container) : container(container.size() + 1), heap_size(container.size()) {
        this->container[0] = -1;
        copy_n(begin(container), container.size(), begin(this->container) + 1);

        // O(n) Heap Building.
        for (int i = (heap_size >> 1); i >= 1; --i) {
            max_heapify(i);
        }
    }

    vector<int> sort() {
        for (int i = heap_size; i >= 2; --i) {
            swap(container[1], container[heap_size]);

            // Reduce heap size, then heapify
            --heap_size;
            max_heapify(1);
        }

        return vector<int>(begin(container) + 1, end(container));
    }

    void max_heapify(const int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l <= heap_size && container[l] > container[i]) {
            largest = l;
        }

        if (r <= heap_size && container[r] > container[largest]) {
            largest = r;
        }

        if (largest != i) {
            swap(container[i], container[largest]);
            max_heapify(largest);
        }
    }

    void max_heapify__loop(const int i) {
        stack<int> s;
        s.push(i);

        int l, r, largest, current;

        while (!s.empty()) {
            current = s.top();
            s.pop();

            tie(l, r) = get_lr(i);
            largest = current;

            if (l < heap_size && container[l] > container[current]) {
                largest = l;
            }

            if (r < heap_size && container[r] > container[largest]) {
                largest = r;
            }

            if (largest != i) {
                swap(container[current], container[largest]);
                s.push(largest);
            }
        }
    }

    int parent(const int i) { return i >> 1; }

    int left(const int i) { return i << 1; }

    int right(const int i) { return (i << 1) + 1; }

    tuple<int, int> get_lr(const int i) {
        return make_tuple(left(i), right(i));
    }
};

class Test {
public:
    explicit Test(vector<int> vec) {
        copy(begin(vec), end(vec), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
};

int main() {
    BOOST_IO
    ALTER_IN("in.txt")

    vector<vector<int>> matrix;

    int N;
    cin >> N;
    matrix.resize(N);

    for (auto &row: matrix) {
        copy_n(istream_iterator<int>(cin), N, back_inserter(row));
        MaxHeap heap(row);
        row = heap.sort();
    }

    for (auto &row: matrix) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
//
// Created by 10578 on 3/16/2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <list>

using namespace std;

using Line = vector<char>;

class Text_iterator {
public:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp) : ln{ll}, pos{pp} {}

    char &operator*() { return *pos; }

    Text_iterator &operator++() {
        ++pos;
        if (pos == ln->end()) {
            ++ln;
            pos = ln->begin();
        }

        return *this;
    }

    bool operator==(const Text_iterator &other) const {
        return ln == other.ln && pos == other.pos;
    }

    bool operator!=(const Text_iterator &other) const {
        return !(*this == other);
    }

private:
    list<Line>::iterator ln;
    Line::iterator pos;
};

class Document {
public:
    using iterator = Text_iterator;

    Document() {
        lines.emplace_back();
    }

    iterator begin() {
        return Text_iterator(lines.begin(), lines.begin()->begin());
    }

    iterator end() {
        auto last = lines.end();
        last--;
        return Text_iterator(last, last->end());
    }

    friend istream &operator>>(istream &is, Document &document) {
        using std::begin;
        using std::end;

        string line;
        while (getline(is, line)) {
            document.lines.back().resize(line.size() + 1);
            copy(begin(line), end(line), back_inserter(document.lines.back()));
            document.lines.back().push_back('\n');
            document.lines.emplace_back();
        }

        return is;
    }

    friend ostream &operator<<(ostream &os, Document &document) {
        for (auto &&c: document) {
            os << c;
        }

        return os;
    }

    void erase_line(int n) {
        if (n < 0 || n >= lines.size()) return;

        auto p = lines.begin();
        advance(p, n);
        lines.erase(p);
    }

private:
    list<Line> lines;
};

int main() {
    fstream in("../in.txt");

    if (!in.good()) {
        cout << "Fail!" << endl;
    }

    Document d;
    in >> d;

    d.erase_line(1);

    cout << d;

    return 0;
}
//
// Created by 10578 on 4/3/2020.
//

#include <vector>
#include <regex>
#include <iostream>
#include <fstream>

#define ALTER_IN(filename) std::fstream in_f(filename); std::cin.rdbuf(in_f.rdbuf());
#define BOOST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;

int main() {
    BOOST_IO;
    ALTER_IN("../in.txt");

    if (!cin) {
        cout << "Input not good!" << endl;
        exit(1);
    }

    regex pattern{R"(\w{2}\s*\d{5}(-\d{4})?)"};

    int lineno = 0;
    for (string line; getline(cin, line); ++lineno) {
        smatch matches;
        regex_match(line, matches, pattern);
        if (regex_search(line, matches, pattern)) {
            cout << lineno << ": " << "match size: " << matches.size() << endl;
            cout << matches.str(); // get first sub-match
            cout << endl;
        }
    }

    string s = "123 456 789";
    regex ws_re(R"(\s+)");
    for (auto i = sregex_token_iterator(s.begin(), s.end(), ws_re, -1); i != sregex_token_iterator(); ++i) {
        cout << *i << endl;
    }

    return 0;
}
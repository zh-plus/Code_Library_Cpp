//
// Created by 10578 on 9/19/2019.
//

#include <iostream>
#include <fstream>
#include <regex>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;

using ll = long long;

int main(){
    BOOST_IO;

    ALTER_IN("in.txt");

    string input;
    regex integer("\\<cat", regex_constants::icase);

    while (true){
        smatch result;

//        cout << "Give me an string!" << endl;

        if (! getline(cin, input)) {
            break;
        }

        cout << (regex_match(input, integer) ? "match:" : "not match");
        regex_search(input, result, integer);

        while (regex_search(input, result, integer)) {
            cout << result[0] << " : ";
            input = result.suffix();
        }

        cout << endl;
    }
}
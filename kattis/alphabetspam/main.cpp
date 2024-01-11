#include <ios>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>
#include <iomanip>

using namespace std;

int main() {
    // Your code goes here
    int whitespace = 0, upper = 0, lower = 0, symbols = 0;

    string s; cin >> s;

    for (char c : s) {
        if (c == '_') { // whitespace
            // cout << "w: " << c << endl;
            whitespace++;
        } else if (c <= 90 && c >= 65) { // uppercase
            // cout << "u: " << c << endl;
            upper++;
        } else if (c <= 122 && c >= 97) { // lowercase 
            // cout << "l: " << c << endl;
            lower++;
        } else { // symbol
            // cout << "s: " << c << endl;
            symbols++;
        }
    }

    // compute
    cout << fixed << setprecision(7); 
    int total = s.size();
    cout << 1.0 * whitespace / s.size() << endl;
    cout << 1.0 * lower / s.size() << endl;
    cout << 1.0 * upper / s.size() << endl;
    cout << 1.0 * symbols / s.size() << endl;


    return 0;
}


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
#include <bits/stdc++.h>

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    // a few test cases, at most 100 symbols
    // 5 different symbols so 32 possible combinations
    // Around 3200 max operations per test case, so brute force is possible
    
    string str;

    while (getline(cin, str)) {
        if (str == "0") break;

//        cout << str << endl;

        bool valid = true;

        for (int i=0;i<=1;i++) {
            if (!valid) break;
            for (int j=0;j<=1;j++) {
                if (!valid) break;
                for (int k=0;k<=1;k++) {
                    if (!valid) break;
                    for (int l=0;l<=1;l++) {
                        if (!valid) break;
                        for (int m=0;m<=1;m++) {
                            if (!valid) break;

                            stack<int> stack;
                            // use a stack
                            umap<char, int> map;
                            map.insert({'p', i});
                            map.insert({'q', j});
                            map.insert({'r', k});
                            map.insert({'s', l});
                            map.insert({'t', m});

                            int res;

                            for (int n = str.length()-1; n >= 0; n--) { // parse the string and evaluate
                                char c = str[n];

                                if (c == 'K') { // AND
                                    int x = stack.top();
                                    stack.pop();
                                    int y = stack.top();
                                    stack.pop();
                                    res = x & y;

                                    stack.push(res);
                                } else if (c == 'A') { // OR
                                    int x = stack.top();
                                    stack.pop();
                                    int y = stack.top();
                                    stack.pop();
                                    res = x | y;
                                    stack.push(res);
                                } else if (c == 'N') { // NOT
                                    int x = stack.top();
                                    stack.pop();
                                    res = x^1;
                                    stack.push(res);
                                } else if (c == 'C') { // IMPLIES
                                    int x = stack.top();
                                    stack.pop();
                                    int y = stack.top();
                                    stack.pop();
                                    if (x == 0 && y == 1) {
                                        res = 0;
                                    } else {
                                        res = 1;
                                    }
                                    stack.push(res);
                                } else if (c == 'E') { // EQUALS
                                    int x = stack.top();
                                    stack.pop();
                                    int y = stack.top();
                                    stack.pop();
                                    res = (x == y);
                                    stack.push(res);
                                } else if (c == 'p') {
                                    stack.push(map['p']);
                                } else if (c == 'q') {
                                    stack.push(map['q']);
                                } else if (c == 'r') {
                                    stack.push(map['r']);
                                } else if (c == 's') {
                                    stack.push(map['s']);
                                } else if (c == 't') {
                                    stack.push(map['t']);
                                }
                            }
                            res = stack.top();
                            if (res == 0) {
                                valid = false;
                            }
                        }
                    }
                }
            }
        }

        if (!valid) {
            cout << "not" << endl;
        } else {
            cout << "tautology" << endl;
        }

    }

    return 0;
}


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

using namespace std;

int main() {
        int count = 0;
        string s;
        bool hiss = false;

        cin >> s;

        for (char c : s) {
                if (c == 's') {
                        if (count == 1) {
                                cout << "hiss";
                                hiss = true;
                                break;
                        } else if (count == 0) {
                                count = 1;
                        }
                } else {
                        count = 0;
                }
        }
        if (!hiss) {
                cout << "no hiss";
        }

        return 0;
}

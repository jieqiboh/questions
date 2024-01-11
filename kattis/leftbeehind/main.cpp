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
    // Your code goes here
    int a, b;
    while (scanf("%d %d\n", &a,&b) != EOF) {
            if (a==0 && b==0) break;
            if (a + b == 13) {
                cout << "Never speak again." << endl;
            }
            else if (a < b) {
                cout << "Left Beehind" << endl;
            } else if (a > b) {
                cout << "To the convention." << endl;
            } else if (a == b) {
                cout << "Undecided." << endl;
            }
    }

    return 0;
}


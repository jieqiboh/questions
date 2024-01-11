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
    int n; 
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
            string a, b;
            getline(cin, a);
            getline(cin, b);
            int count = 0;
            int unknowns = 0;
            for (int j = 0; j < a.size(); j++) {
                if (a[j] == '?') {
                       unknowns++; 
                } else if (a[j] != b[j]) {
                        count++;
                } 
            }
            if (count % 2 == 0) {
                cout << "Case " << i+1 << ": " << (count/2) + unknowns << endl;
            } else if (unknowns != 0) {
                cout << "Case " << i+1 << ": " << (count/2) + unknowns << endl;
            } else {
                cout << "Case " << i+1 << ": " << "-1" << endl;
            }
    }
       
    return 0;
}


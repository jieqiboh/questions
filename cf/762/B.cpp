#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast();
    int a, b, c;
    cin >> a >> b >> c;  // a: USB-only, b: PS/2-only, c: universal ports
    int m;
    cin >> m;  // number of mice
    int sum = a + b + c;

    vector<pair<int, string>> mice;

    // Reading the price and type of each mouse
    while (m--) {
        pair<int, string> p;
        cin >> p.first >> p.second;
        mice.push_back(p);
    }

    // Sort the mice based on price (ascending order)
    sort(mice.begin(), mice.end());

    long long cost = 0;

    // Process each mouse from cheapest to most expensive
    for (const auto& mse : mice) {
        // Determine which type of computer to assign the mouse to
        if (mse.second == "USB") { // a
            if (a!=0) {
                cost += mse.first;
                a--;
            } else if (c!=0) {
                cost += mse.first;
                c--;
            }
        } else if (mse.second == "PS/2") { // b
            if (b!=0) {
                cost += mse.first;
                b--;
            } else if (c!=0) {
                cost += mse.first;
                c--;
            }
        }
    }

    // Output the total number of equipped computers and total cost
    cout << sum - (a+b+c) << " " << cost << "\n";

    return 0;
}

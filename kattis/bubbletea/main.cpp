#include <climits>
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

void printVec(vector<int>);

int main() {
    // Your code goes here
    int num_tea, num_top;
    vector<int> tea_prices;
    vector<int> top_prices;
    vector<int> tea_compat; // stores the min total price of each tea + topping it is compatible with

    cin >> num_tea;
    cin.ignore();

    for (int i = 0; i < num_tea; i++) {
            int price;
            cin >> price;
            tea_prices.push_back(price);
    }
    cin.ignore();

    cin >> num_top;
    cin.ignore();

    for (int i = 0; i < num_top; i++) {
            int price;
            cin >> price;
            top_prices.push_back(price);
    }

    for (int i = 0; i < num_tea; i++) {
        int num_compat;
        int min_teatop_price = INT_MAX;
        cin >> num_compat;
        for (int j = 0; j < num_compat; j++) {
           int top; cin >> top;
           if ((top + tea_prices[i]) < min_teatop_price) {
               min_teatop_price = top + tea_prices[i];
           }
        }

        tea_compat.push_back(min_teatop_price);
        cin.ignore();
    };

    int money; cin >> money;

    // then find the cheapest between all teatops
    auto min_price = min_element(tea_compat.begin(), tea_compat.end());

    cout << money/(*min_price) - 1 << endl;

    return 0;
}

void printVec(vector<int> s) {
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
}


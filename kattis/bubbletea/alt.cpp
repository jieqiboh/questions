#include <cinttypes>
#include <climits>
#include <cstdio>
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
    int num_tea, num_top;
    vector<int> tea_prices, top_prices;

    cin >> num_tea;
    cin.ignore();
    while (num_tea--) {
        int price; cin >> price;
        tea_prices.push_back(price);
    }
    cin.ignore();
    cin >> num_top;
    cin.ignore();
    while (num_top--) {
        int price; cin >> price;
        top_prices.push_back(price);
    }
    cin.ignore();

    int min = INT_MAX;

   for (int i=0;i<tea_prices.size();i++) {
       int n; cin >> n;
       for (int j=0;j<n;j++) {
           int top; cin >> top; 
           if ((tea_prices[i] + top_prices[top-1]) < min) {
               min = tea_prices[i] + top_prices[top-1];
           }
       } 
       cin.ignore();
   }

    int money = 0;
    scanf("%d", &money);

    const int students = (money / min) - 1;
    printf("%d\n", students < 0 ? 0 : students);
    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
/*
    stockbroker
    A greedy question
    General approach: You don't have to do any sorting, or consider future outcomes
    For any given day, if the previous day's price is lower, you want to make sure you buy as many stocks as possible on that day, then sell them all on this day.
    Simply credit the profit to money, and repeat.

    Since there is a cap on the number of stocks you can buy, for any given day, the max number of stocks you can buy is:
    min(money/prev, (ll)100000)
    And the profit you want to credit to your account is min(money/prev, (ll)100000) * (curr - prev)
*/
int main() {
    fast();
    
    ll prev = 0;
    ll n = 0;

    cin >> n >> prev;
    
    ll money = 100;
    for (int i = 0; i < n - 1; i++) {
        ll curr; cin >> curr;
        // cout << curr << endl;

        if (curr > prev) {
            money += min(money/prev, (ll)100000) * (curr - prev);
        }

        prev = curr;
    }
    cout << money;
    return 0;
}


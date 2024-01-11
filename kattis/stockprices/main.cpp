#include <iostream>
#include <unordered_map>
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

template <typename T, typename Container, typename Compare>
void printQueue(std::priority_queue<T, Container, Compare>& q) {
    for (; !q.empty(); q.pop()) {
        std::cout << q.top() << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Your code goes here
    int cases; cin >> cases;
    // cout << cases << endl;

    while (cases--) {
        int no_orders; cin >> no_orders;

        // cout << no_orders << endl;

        priority_queue<int> buy_q; // contains order prices
        unordered_map<int, int> buy_amt; // maps order prices to its amt
        priority_queue<int, vector<int>, greater<>> sell_q; // contains order prices
        unordered_map<int, int> sell_amt; // maps order prices to its amt

        int cur = -1;

        while (no_orders--) {
            string type;
            int price, amt;
            string skip;
            cin >> type >> amt >> skip >> skip >> price;

//            cout << type << " " << amt << " " << price << " " << endl;

            if (type == "buy") {
                // insert
                // skip buy_q insertion if it contains it already
                if (buy_amt.find(price) != buy_amt.end()) {
                    buy_amt[price] += amt;
                } else {
                    buy_q.push(price);
                    buy_amt.insert({price, amt});
                }
            } else if (type == "sell") {
                // insert
                // skip sell_q insertion if it contains it already
                if (sell_amt.find(price) != sell_amt.end()) {
                    sell_amt[price] += amt;
                } else {
                    sell_q.push(price);
                    sell_amt.insert({price, amt});
                }

            }


            if (!(buy_q.empty() || sell_q.empty()) && (buy_q.top() >= sell_q.top())) {
                int maxbid = buy_q.top();
                int minsell = sell_q.top();
                // cout << "maxbid: " << maxbid << " minsell: " << minsell << endl;
                int sprice_amt = sell_amt[minsell];
                int bprice_amt = buy_amt[maxbid];

                cur = minsell;
                if (sprice_amt > bprice_amt) {
                   // pop from b priceq, rem from b_amt, minus from s_amt
                   buy_q.pop(); buy_amt.erase(maxbid);
                   sell_amt[minsell] -= bprice_amt;
                } else if (bprice_amt > sprice_amt) {
                    // pop from s priceq, rem from s_amt, minus from b_amt
                    sell_q.pop(); sell_amt.erase(minsell);
                    buy_amt[maxbid] -= sprice_amt;
                } else {
                    // pop from s and b price q, rem from both maps
                    sell_q.pop(); sell_amt.erase(minsell);
                    buy_q.pop(); buy_amt.erase(maxbid);
                }
            }
            string ask = (!sell_q.empty()) ? to_string(sell_q.top()) : "-";
            string bid = (!buy_q.empty()) ? to_string(buy_q.top()) : "-";
            string stockprice = (cur != -1) ? to_string(cur) : "-";
            cout << ask << " " << bid << " " << stockprice << endl;
        }
    }
    return 0;
}


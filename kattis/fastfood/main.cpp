#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printVec(vector<int>);
void printVecVec(vector<vector<int>>);

int main() {
    // Your code goes here
    int num_cases; cin >> num_cases;
    cin.ignore();

    while (num_cases--) {
        int num_prizes, num_stickers;
        
        vector<vector<int>> prize_stickers; // idx maps to each prize, contains list of stickers needed
        vector<int> prize_amt; // idx maps to prize_amt
        vector<int> my_stickers; // idx maps to num of stickers you have

        int res = 0;

        cin >> num_prizes; 
        cin >> num_stickers; cin.ignore();

        while (num_prizes--) {
            int n; cin >> n;
            vector<int> stickers;
            while (n--) {
                int sticker; cin >> sticker;
                stickers.push_back(sticker);
            }
            prize_stickers.push_back(stickers);
            int amt; cin >> amt; cin.ignore();
            prize_amt.push_back(amt);
        }
        
        while (num_stickers--) {
            int x; cin >> x;
            my_stickers.push_back(x);
        }
        // printVec(prize_amt);
        // printVec(my_stickers);
        // printVecVec(prize_stickers);

        // compute
        for (int i = 0; i < prize_stickers.size(); i++) {
            int min = INT_MAX;
            vector<int> p = prize_stickers[i];
            for (int x : p) {
                if (my_stickers[x-1] < min) {
                    min = my_stickers[x-1];
                }
            }
            res += prize_amt[i] * min;
        }
        cout << res << endl;
    }
    return 0;
}

void printVec(vector<int> x) {
    for (int i : x) {
        cout << i << " ";
    }
    cout << endl;
}

void printVecVec(vector<vector<int>> y) {
    for (vector<int> j : y) {
        printVec(j);
    }
}

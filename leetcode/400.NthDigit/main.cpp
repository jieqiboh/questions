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
#include <numeric>
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int findNthDigit(int n) {

        int x = 0;
        int tot = 0;
        while (tot < n) {
            x++;
            tot += x * 9 * pow(10, x - 1);
        }
//        cout << "tot is: " << tot << "\n";
//        cout << "x is: " << x << "\n";

        int y = tot - (x * 9 * pow(10, x - 1));
        n -= y; // reduce n to be the number of digits within the range we are considering
//        cout << "n is now: " << n << "\n";
        int nbr = pow(10, x - 1) + ceil(double(n) / double(x)) - 1;
        int idx = (n - 1) % x;

        return (to_string(nbr)[idx]) - '0';
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.findNthDigit(3) << "\n"; // 3
    cout << sol.findNthDigit(10) << "\n"; // 1
    cout << sol.findNthDigit(11) << "\n"; // 0
    cout << sol.findNthDigit(13) << "\n"; // 1

    cout << sol.findNthDigit(189) << "\n"; // 9 (last digit of 99)
    cout << sol.findNthDigit(190) << "\n"; // 1 (first digit of 100)
    cout << sol.findNthDigit(191) << "\n"; // 0 (second digit of 100)
    cout << sol.findNthDigit(192) << "\n"; // 0 (third digit of 100)


    cout << sol.findNthDigit(250) << "\n";   // 1 (digit inside 125)
    cout << sol.findNthDigit(1000) << "\n";  // 3 (digit inside 370)
    cout << sol.findNthDigit(2889) << "\n";  // 9 (last digit of 999)
    cout << sol.findNthDigit(2890) << "\n";  // 1 (first digit of 1000)

    return 0;
}


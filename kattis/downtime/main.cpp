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

int main() {
    // Your code goes here
    // Approach: Compute max number of servers needed for first 1000ms
    // Then for every ms from [1000,100000], compute the number of servers needed for each 1000 ms interval
    // seen is a map mapping each second to if a new request is seen
    //

    unordered_map<int, int> seen;
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) { // initialise a map of request times
        int time; cin >> time;
        seen[time]++;
    }
    
    int max_req = 0;
    for (int i=0;i<1000;i++) {
        max_req += seen[i];
    }
    
    int best = max_req;
    for (int i=1000;i<=100000;i++) { // for [1000,100000]
        max_req += seen[i];
        max_req -= seen[i-1000];
        best = max(max_req, best);
    }

    best = (best + k - 1) / k;

    cout << best << endl;
    

    return 0;
}


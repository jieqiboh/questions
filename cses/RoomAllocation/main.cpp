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
using ll = long long;
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    int n; cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a,b,i});
    }

    sort(v.begin(), v.end()); // sort by arrival time in ascending

    int id = 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // end time, room id

    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        int arrivalTime = v[i][0];
        int departureTime = v[i][1];
        int idx = v[i][2];

        if (!pq.empty() && pq.top().first < arrivalTime) {
            // reuse room
            auto cur = pq.top();
            pq.pop();
            pq.emplace(make_pair(departureTime, cur.second));
            res[idx] = cur.second;
        } else {
            // assign new room
            pq.emplace(make_pair(departureTime, id));
            res[idx] = id;
            id++;
        }
    }

    cout << id - 1 << "\n";
    for (int x : res) cout << x << " ";

    return 0;
}


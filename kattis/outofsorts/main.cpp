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

#define ll long long

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<ll> vi;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

ll compute(ll m, ll a, ll c, ll x) {
    return ((a * x) + c) % m;
}

bool ann_binary_search(vector<ll>& nums, ll num) {
    ll lo = 0;
    ll hi = nums.size()-1;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (nums[mid] == num) {
            return true;
        } else if (nums[mid] < num) {
            lo = mid + 1;
        } else if (nums[mid] > num) {
            hi = mid - 1;
        }
    }
    return false;
}

int main() {
    fast();
    
    ll n,m,a,c,x;
    cin >> n >> m >> a >> c >> x;

    vector<ll> nums;
    while (n--) { // generate [x1..xn]
        x = compute(m,a,c,x);
        nums.push_back(x);
    }
    // for each number in nums, do a binary search on it
    int found = 0;
    for (auto& x : nums) {
//        cout << "searching for: " <<  x << endl;
        bool b = ann_binary_search(nums, x);
        found = b ? found+=1 : found;
//        cout << b << endl;
    }

    cout << found;

    return 0;
}


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

// ─── Binary Search (manual) ──────────────────────────────────────────────────

// Standard: find exact target, returns -1 if not found
int binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

// Leftmost: first index where arr[i] >= target  (equivalent to std::lower_bound)
int lowerBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1, ans = arr.size();
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= target) {
            ans = mid; hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// Rightmost: first index where arr[i] > target  (equivalent to std::upper_bound)
int upperBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1, ans = arr.size();
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] > target) {
            ans = mid; hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// ─── Binary Search (STL) ─────────────────────────────────────────────────────

// All STL functions take iterators and return iterators.
// Subtract arr.begin() to get index.
// arr must be sorted.
//
// lower_bound(arr.begin(), arr.end(), target)
//   -> iterator to first element >= target
//   -> returns arr.end() if all elements < target
//
// upper_bound(arr.begin(), arr.end(), target)
//   -> iterator to first element > target
//   -> returns arr.end() if all elements <= target
//
// binary_search(arr.begin(), arr.end(), target)
//   -> returns true/false, does NOT return index
//
// Common patterns:
//
//   auto it = lower_bound(arr.begin(), arr.end(), target);
//   if (it != arr.end() && *it == target) { /* target exists */ }
//   int idx = it - arr.begin();                // convert to index
//
//   // Count occurrences of target in sorted arr:
//   int cnt = upper_bound(arr.begin(), arr.end(), target)
//           - lower_bound(arr.begin(), arr.end(), target);
//
//   // First index where arr[i] >= target:
//   int lo = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
//
//   // First index where arr[i] > target:
//   int hi = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

// ─────────────────────────────────────────────────────────────────────────────

int main() {
    fast();

    return 0;
}
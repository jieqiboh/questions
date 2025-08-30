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

// Define the comparator function
bool compareByX(const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0];
}
class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        stack<vector<int>> st; // contains mountain
        map<pair<int,int>,int> freq;
        for (vector<int> v : peaks) {
            freq[{v[0],v[1]}]++;
        }

        std::sort(peaks.begin(), peaks.end(), compareByX);

        st.push(peaks[0]);
        for (int i = 1; i < peaks.size(); i++) {
            vector<int> a = st.top();
            vector<int> b = peaks[i];

            while (!st.empty() && aOverlapB(b, a)) {
                st.pop();
            }
            if (st.empty() || !aOverlapB(st.top(), b)) {
                st.push(b);
            }
        }
        int res = 0;
        while (!st.empty()) {
            vector<int> top = st.top();
            if (freq[{top[0],top[1]}] == 1) res++;
            st.pop();
        }
        return res;
    }

    bool aOverlapB(const std::vector<int>& pa, const std::vector<int>& pb) {
        int x_a = pa[0];
        int y_a = pa[1];
        int x_b = pb[0];
        int y_b = pb[1];

        // Calculate the horizontal distance between peaks
        int d = std::abs(x_b - x_a);
        // Determine Peak A's height at Peak B's position
        int height_at_b = y_a - d;
        // Check if Peak A's height at B's position is greater than or equal to Peak B's height
        return height_at_b >= y_b;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> peaks = {{3,19},{39,7},{15,39},{23,13},{8,28},{2,26},{38,15},{38,7},{16,17}};
    cout << sol.visibleMountains(peaks) << "\n"; // 1

    return 0;
}


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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 1 <= heights.length <= 10^5
        // 0 <= heights[i] <= 10^4
        stack<int> s;
        s.push(-1);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (s.top() != -1 && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int width = i - s.top() - 1; // Corrected width [
                maxArea = max(maxArea, h * width);
            }
            s.push(i);
        }
        while (s.top() != -1) { // last loop
            int h = heights[s.top()];
            s.pop();
            int width = heights.size() - s.top() - 1; // Corrected width
            maxArea = max(maxArea, h * width);
        }
        return maxArea;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> heights = {2,3,4,5,3};
//    cout << sol.largestRectangleArea(heights) << "\n"; // 12
//
//    heights = {2,4};
//    cout << sol.largestRectangleArea(heights) << "\n"; // 4
//
//    heights = {2,1,5,6,2,3};
//    cout << sol.largestRectangleArea(heights) << "\n"; // 10
//
//    heights = {2,1,5,6,2,300};
//    cout << sol.largestRectangleArea(heights) << "\n"; // 300
//
//    heights = {0,0,1};
//    cout << sol.largestRectangleArea(heights) << "\n"; // 1
//
//    heights = {0};
//    cout << sol.largestRectangleArea(heights) << "\n"; // 0
//
//    heights = {1,2,3,1};
//    cout << sol.largestRectangleArea(heights) << "\n"; // 4
//
//    heights = {1,2,0,1};
//    cout << sol.largestRectangleArea(heights) << "\n"; // 2

    heights = {2,1,2};
    cout << sol.largestRectangleArea(heights) << "\n"; // 3
    return 0;
}


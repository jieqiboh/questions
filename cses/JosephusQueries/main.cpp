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

// Function to calculate the kth child to be removed
long long calculateRemovedChild(long long totalChildren,
                                long long kthChild)
{
    // Base case: if there's only one child left, it's the
    // one to be removed
    if (totalChildren == 1) return 1;

    // If n is even, the starting point remains the same
    // If k is less than or equal to half the total number
    // of children
    if (kthChild <= (totalChildren + 1) / 2) {
        // If 2*k is greater than the total number of
        // children, return the remainder of 2*k divided by
        // the total number of children
        if (2 * kthChild > totalChildren)
            return (2 * kthChild) % totalChildren;
        else
            // Otherwise, return 2*k
            return 2 * kthChild;
    }
    // Calculate the kth child to be removed for half the
    // total number of children
    long long temp = calculateRemovedChild( totalChildren / 2, kthChild - (totalChildren + 1) / 2);
    // If the total number of children is odd, return 2*temp
    // + 1
    if (totalChildren % 2 == 1)
        return 2 * temp + 1;
    // Otherwise, return 2*temp - 1
    return 2 * temp - 1;
}

int main()
{
    long long totalChildren, kthChild;

    totalChildren = 7;
    kthChild = 1;
    cout << calculateRemovedChild(totalChildren, kthChild) << "\n";

    totalChildren = 7;
    kthChild = 3;
    cout << calculateRemovedChild(totalChildren, kthChild) << "\n";

    totalChildren = 7;
    kthChild = 4;
    cout << calculateRemovedChild(totalChildren, kthChild) << "\n";
}


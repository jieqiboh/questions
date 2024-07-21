#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Custom comparator for the priority queue
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second) {
            return a.first > b.first; // Compare by the first element if seconds are equal
        }
        return a.second > b.second; // Compare by the second element
    }
};

int main() {
    // Define a priority queue with pairs of integers and the custom comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    // Insert some elements into the priority queue
    pq.push({1, 3});
    pq.push({2, 2});
    pq.push({3, 2});
    pq.push({4, 1});
    pq.push({5, 3});

    // Pop and print elements from the priority queue
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        cout << "(" << top.first << ", " << top.second << ")\n";
        pq.pop();
    }

    return 0;
}


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

struct Compare {
    bool operator()(const pair<string,int>& a, const pair<string,int>& b) const {
        if (a.second != b.second) return a.second < b.second; // higher first
        return a.first > b.first;                              // lexicographically smaller first
    }
};

class FoodRatings {
public:
    unordered_map<string, string> foodCuisines; // maps foods to their cuisines
    unordered_map<string, int> foodRatings; // maps foods to their ratings
    unordered_map<string, priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>> cuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodCuisines[foods[i]] = cuisines[i];
            foodRatings[foods[i]] = ratings[i];
            cuisineMap[cuisines[i]].push(make_pair(foods[i], ratings[i]));
        }
    }

    void changeRating(string food, int newRating) {
        // update foodRatings
        foodRatings[food] = newRating;

        // first find the cuisine the food is associated with
        string cuisine = foodCuisines[food];
        cuisineMap[cuisine].push(make_pair(food, newRating));

//        // pop from its cuisine heap until the food is found
//        vector<pair<string, int>> toPush;
//        while (!cuisineMap[cuisine].empty() && cuisineMap[cuisine].top().first != food) {
//            pair<string, int> cur = cuisineMap[cuisine].top();
//            cuisineMap[cuisine].pop();
//
//            toPush.push_back(cur);
//        }
//
//        // update the rating of the food, and push it back into the heap
//        pair<string, int> cur = cuisineMap[cuisine].top();
//        cuisineMap[cuisine].pop();
//        cur.second = newRating;
//        cuisineMap[cuisine].push(cur);
//        for (auto& x : toPush) {
//            cuisineMap[cuisine].push(x);
//        }
    }

    string highestRated(string cuisine) {
        // if the rating of the top element doesn't match, drop it from the heap
        while (cuisineMap[cuisine].top().second != foodRatings[cuisineMap[cuisine].top().first]) {
            cuisineMap[cuisine].pop();
        }

        return cuisineMap[cuisine].top().first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
    fast();

    return 0;
}


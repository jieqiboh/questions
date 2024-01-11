#include <iostream>
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

#define uset unordered_set
#define umap unordered_map
#define pq priority_queue

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

// Custom comparator for pairs of string and int (max heap based on int)
// Custom comparator for pairs of string and int
struct PairComparator {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
        // Compare integers in descending order
        if (a.second != b.second) {
            return a.second > b.second; // Change to < for ascending order
        }

        // If integers are equal, compare strings in ascending alphabetical order
        return a.first < b.first;
    }
};

int main() {
    auto compareByInt = [](const std::string& lhs, const std::string& rhs) {
        // Compare the int values associated with the keys
        return lhs < rhs;
    };

   map<string, int, decltype(compareByInt)> cats(compareByInt);

   pq<pair<string, int>, vector<pair<string, int>>, PairComparator> q;

    int num; cin >> num; cin.ignore();
    pair<string, int> topcat;
    while (num--) {
        string s; getline(cin, s);

        istringstream iss(s);

        int op;
        iss >> op;

        string name; int value;
        if (op == 0) { // Arrive at Clinic
            iss >> name >> value;
            cats.insert({name, value});
            q.push({name, value});
        } else if (op == 1) { // Update Infection Level
            iss >> name >> value;
            cats[name] += value;
        } else if (op == 2) { // Treated
            iss >> name;
            cats.erase(name);
        } else if (op == 3) {
            pair<string, int> curtopcat = q.top();

            if (q.empty()) {
                cout << "The clinic is empty" << endl;
                continue;
            }

            while ((cats.find(curtopcat.first) == cats.end()) || (curtopcat.second != cats[curtopcat.first])) {
                // while the topcat cannot be found in map OR the curtopcat's infectionlvl is not updated

                if (cats.find(curtopcat.first) == cats.end()) { // cat has been treated and is no longer present in cats
                    q.pop();
                    if (q.empty()) {
                        break;
                    } else {
                        curtopcat = q.top(); // remove top from pq and check next cat
                    }
                }

                if (curtopcat.second != cats[curtopcat.first]) { // cat's value is not equal to that reflected in cats
                    // reassign value and push back into pq
                    int actualval = cats[curtopcat.first];
                    q.pop(); // remove the top entry
                    q.push({curtopcat.first, actualval}); // reinsert with updated value
                    curtopcat = q.top();
                }
            }

            if (q.empty()) {
                cout << "The clinic is empty" << endl;
                continue;
            } else {
                cout << curtopcat.first << endl;
            }
        }
    }
    return 0;
}


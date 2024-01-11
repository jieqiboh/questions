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

int main() {
    auto compareByInt = [](const std::string& lhs, const std::string& rhs) {
        // Compare the int values associated with the keys
        return lhs < rhs;
    };

   map<string, int, decltype(compareByInt)> cats(compareByInt);

    int num; cin >> num; cin.ignore();
    pair<string, int> topcat;
    while (num--) {
        string s; getline(cin, s);

        istringstream iss(s);

        int op;
        iss >> op;

        string name;
        int infectionlvl;
        if (op == 0) { // Arrive at Clinic
            iss >> name;
            iss >> infectionlvl;
            cats.insert({name, infectionlvl});

            if (infectionlvl > topcat.second) { // update infectionlvl if necessary
                topcat.first = name; topcat.second = infectionlvl;
            }
        } else if (op == 1) { // Update Infection Level
            iss >> name;
            int value; iss >> value;

            cats[name] += value;

            int newinfectionlvl = cats[name] + value;

            if (newinfectionlvl > topcat.second) { // update infectionlvl if necessary
                topcat.first = name; topcat.second = newinfectionlvl;
            }
        } else if (op == 2) { // Treated
            string name; iss >> name;

            auto& nextcat = ++cats.find(name);

            cats.erase(name);
            if (topcat.first == name) { // if topcat is treated, reset it to 0 and replace with second cat
                topcat.second = nextcat->second;
                topcat.first = nextcat->first;
            }
        } else if (op == 3) {
            if (cats.empty()) {
                cout << "The clinic is empty";
            } else {
                cout << topcat.first << endl;
            }
        }
    }
    return 0;
}


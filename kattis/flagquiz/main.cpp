#include <climits>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
void printVecMap(vector<unordered_map<string, int>>&);
void printMap(unordered_map<string, int>&);

void printMap(unordered_map<string, int>& m) {
    // Display the contents of the map in a generic format
    for (auto& pair : m) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    cout << endl;
}

void printVecMap(vector<unordered_map<string, int>>& v) {
    for (unordered_map<string, int> m : v) {
        printMap(m);
    }
}

void printVec(vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int min_changes(unordered_map<string, int> opt1, unordered_map<string, int> opt2) {
    // compute min no of changes to convert opt1 to opt2
    // or vice versa
    int difftype = 0;
    int difforder = 0;
    for (auto& pair : opt1) {
        // for each pair, see if type exists in opt2
        if (opt2.find(pair.first)==opt2.end()) {
            difftype++;
        } else if (opt2.find(pair.first)->second != pair.second) {
            difforder++;
        }
        // else correct type and correct order.
    }
//    difforder = (difforder > 1) ? difforder - 1 : difforder;
    return difforder + difftype;
    
}

int main() {
    // Your code goes here
    string qn;
    getline(cin, qn);
//   cout << qn;

    int opt_size; cin >> opt_size;
    cin.ignore();
    vector<unordered_map<string, int>> arr;
    
    string opt;
    vector<string> options;

    while (getline(cin, opt)) { // parse each option
        
//        cout << opt << endl;
        options.push_back(opt);
        unordered_map<string, int> opt_map;

        istringstream ss(opt);
        int count = 0;
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');

            opt_map.insert({substr, count});
            count++;
        }

        arr.push_back(opt_map);
    }

    // printVecMap(arr);
    // process question
    // for each option, compute max amt to change to any other
    //

    vector<int> max_amt(arr.size());

    int min_max = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i+1; j < arr.size(); j++) {
            int min = min_changes(arr[i], arr[j]);
            max_amt[i] = max(max_amt[i], min);
            // max_amt[j] = max(max_amt[j], min);

            // set min_max Value
            min_max = std::min(min, min_max);
        }
    }

    printVec(max_amt);

    for (int i = 0; i < max_amt.size();i++) {
        if (max_amt[i] == min_max) {
            cout << options[i] << endl;
        }
    }


    return 0;
}


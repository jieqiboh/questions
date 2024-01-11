#include <iostream>
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

void printVec(vector<string>& v) {
    for (string s : v) {
        cout << s << " ";
    }
    cout << endl;
}

bool str_compare(const std::string& a, const std::string& b) {
    return a.size() < b.size();
}

int main() {
    // Your code goes here
    string s;
    bool first = true;
    while (getline(cin, s)) { // getline until EOF
        
        vector<string> strings; // contains the reversed strings
        unordered_map<string, string> strmap; // key is reversed string, value is normal string

        if (!first) {
            cout << endl;
        } else {
            first = false;
        }
        while (s.length() != 0) { // repeat for each section

            // cout << s << " " << s.length() << endl;
            string rev_str = s; reverse(rev_str.begin(), rev_str.end());

            
            strings.push_back(rev_str);
            strmap.insert({rev_str, s});

            // sort the array of reversed strings
            sort(strings.begin(), strings.end());

            getline(cin, s);
        }

        // printVec(strings);
        const auto result = std::max_element(strings.begin(), strings.end(), str_compare);

        for (string s : strings) {
            string gap = "";
            for (int i = 0; i < (result->size() - s.size()); i++) {
                gap += " ";
            }
            auto it= strmap.find(s);
            string original;
            if (it == strmap.end()) {
                original = "Not found";
            } else {
                original = it->second;
            }
            cout << gap << original << endl;
        }

    }

    return 0;
}


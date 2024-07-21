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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    int no_names; cin >> no_names;

    umap<char, set<string>> names; // maps the first letter to names that start with that letter
    umap<string, int> duplicate_nns; // maps each nickname to its count
    
    while (no_names--) {
        string name; cin >> name;
        char first_letter = name[0];

        if (names.find(first_letter) == names.end()) { // letter not encountered before
            set<string> new_set = {name};
            pair<char, set<string>> new_pair = make_pair(first_letter, new_set);
            names.insert(new_pair);
        } else { // letter encountered before
            set<string> set_names = names.find(first_letter)->second;
            set_names.insert(name);
            names[first_letter] = set_names; // replace with updated set_names
        }
    }

    int no_nicknames; cin >> no_nicknames;
    
    while (no_nicknames--) {
        // for each nickname, first check if it exists in duplicates already and get its count
        // otherwise, find all names that it is a substring of
        string nn; cin >> nn;
        if (duplicate_nns.find(nn) != duplicate_nns.end()) {
            cout << duplicate_nns.find(nn)->second << "\n";
        } else {
            char first_letter = nn[0];
            int count = 0;
            if (names.find(first_letter) == names.end()) {
                duplicate_nns.insert(make_pair(nn, 0));
            } else {
                set<string> set_names = names.find(first_letter)->second;
                // for each name in set_names, check if nn is a substring of it
                for (string n : set_names) {
//                    cout << n << " ";
                    if ((n.size() >= nn.size()) && (n.substr(0, nn.size()) == nn)) {
                        count++;
                    }
                }
                duplicate_nns.insert(make_pair(nn, count));
            }
            cout << count << "\n";
        }
    }
    

    return 0;
}


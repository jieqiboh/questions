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

bool customComparator(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);

bool customComparator(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    // First, compare by int component
    if (a.second != b.second) {
        return a.second < b.second;
    }

    // If ints are equal, compare by string component in alphabetical order
    return a.first < b.first;
}

int main() {
    int msgs = 0; cin >> msgs; cin.ignore();

    unordered_map<string, int> wc; // maps words to their word count
    unordered_map<string, int> word_user_count; // maps words to number of unique users
    unordered_set<string> users; // set of unique users

    while (msgs--) {
        string s; getline(cin, s);

        istringstream iss(s);

        string name; iss >> name;

        bool new_user = false;
        // check if user is new
        if (users.find(name) == users.end()) {
            users.insert(name);
            new_user = true;
        }

        string word;

        unordered_set<string> unique_words; // stores the unique words for this msg

        while (iss >> word) {
            if (wc.find(word)==wc.end()) { // word not seen before in entire forum
                wc.insert({word, 0});
            }

            wc[word]++;

            if (unique_words.find(word) == unique_words.end()) { // word not seen in msg before
                unique_words.insert(word);
            }

//            cout << word << " ";
        }

        if (new_user) { // if this is a new user, add one to word_user_count for unique words
            for (string w : unique_words) {
                word_user_count[w]++;
            }
        }
        cout << endl;
    }

    vector<pair<string, int>> topwords;
    int total_users = users.size();
    for (auto& x : word_user_count) {
        if (x.second == total_users) {
            topwords.push_back({x.first, x.second});
        }
    }

    sort(topwords.begin(), topwords.end(), customComparator);

    for (auto& y : topwords) {
        cout << y.first << " ";
    }
    return 0;
}

//

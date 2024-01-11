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

#define umap unordered_map
#define uset unordered_set

bool customComparator(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);

bool customComparator(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    // First, compare by int component
    if (a.second != b.second) {
        return a.second > b.second;
    }

    // If ints are equal, compare by string component in alphabetical order
    return a.first < b.first;
}

int main() {
    int msgs = 0; cin >> msgs; cin.ignore();

    umap<string, int> wc; // maps words to their word count
    umap<string, uset<string>> users_unique_words; // map of users to their set of unique words spoken

    // for each word in each message
    // add to their absolute wc in wc
    // insert into the set users

    while (msgs--) {
        string s; getline(cin, s);

        istringstream iss(s);

        string name; iss >> name;
        
        if (users_unique_words.find(name) == users_unique_words.end()) {
            users_unique_words.insert({name, uset<string>(0)});
        }

        string word;

        while (iss >> word) {
            wc[word]++;

            users_unique_words.find(name)->second.insert(word);
        }
        
    }

    vector<string> topwords; // words used by all users
    bool firstuser = true;
    for (auto& x : users_unique_words) {
        uset<string> setofwords = x.second;
        string name = x.first;
        if (firstuser) {
            for (string word : setofwords) {
                topwords.push_back(word);
            }
            firstuser = false;
        }
        vector<string> toremove;
        for (string word : topwords) {
            if (setofwords.find(word) == setofwords.end()) {
                toremove.push_back(word);
            }
        }
        for (string w : toremove) {
            topwords.erase(std::remove(topwords.begin(), topwords.end(), w), topwords.end());
        }
    }

    vector<pair<string, int>> ranking;
    for (string word : topwords) {
        ranking.push_back({word, wc[word]});
    }

    sort(ranking.begin(), ranking.end(), customComparator);

    if (ranking.size() == 0) {
        cout << "ALL CLEAR";
    } else {
        for (auto& w : ranking) {
            cout << w.first << endl;
        }
    }


    return 0;
}


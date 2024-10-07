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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector<string> split(const string &str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        if (!token.empty())
            tokens.push_back(token);
    }
    return tokens;
}

string trim(string& str) {
    const auto strBegin = str.find_first_not_of(' ');
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(' ');
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

// Function to strip trailing whitespaces
string rstrip(const string& s) {
    auto end = find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(); // Convert reverse iterator to normal iterator

    return string(s.begin(), end);
}

// Function to strip leading whitespaces
string lstrip(const string& s) {
    auto start = find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    });

    return string(start, s.end());
}

string getTag(string s) {
    // tag1 value = "HelloWorld"
    return s.substr(0, s.find(" "));
}

string removeTag(string s) {
    // tag1 value = "HelloWorld"
    return s.substr(s.find(" ") + 1);
}

unordered_map<string,string> getAttrs(string s) {
    // value = "HelloWorld" name = "hello"
    unordered_map<string, string> res;
    if (s.empty()) {
        return {};
    } else {
        s = trim(s);
//        s = lstrip(s);
//        s = rstrip(s);
        vector<string> vals = split(s, ' ');
        for (int i = 0; i < vals.size(); i+=3) {
            // vals size is a multiple of 3
            string key = vals[i];
            string value = vals[i + 2].substr(1, vals[i+2].length() - 2);
            res.insert({key, value});
        }
    }
    return res;
}

int main() {
    fast();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q; // N: no lines, Q: no queries
    cin >> N >> Q;
    cin.ignore();

    // tag1 : . : tag2
    // tag1 : value : HelloWorld
    stack<string> tags;
    unordered_map<string, unordered_map<string, string>> m;

    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        if (s.substr(0, 2) == "</") { // closing tag
            tags.pop();
        } else { // opening tag
            string new_s = s.substr(1, s.length() - 2); // remove < and >
            string tag = getTag(new_s);
            if (!tags.empty()) {
                m[tags.top()]["."] = tag; // assign child
            }
            tags.push(tag);
            string rem_tag_s = removeTag(new_s);

            unordered_map<string, string> attrs = getAttrs(rem_tag_s);
            for (pair<string,string> attr : attrs) {
                m[tag][attr.first] = attr.second;
            }
        }
    }
//    for (pair<string, unordered_map<string,string>> p : m) {
//        for (pair<string,string> x : m[p.first]) {
//            cout << p.first << " " << x.first << " " << x.second << "\n";
//        }
//    }
    for (int i = 0; i < Q; i++) {
        string query;
        getline(cin, query);
        vector<string> v = split(query, '~');
        vector<string> dotPos = split(v[0], '.');
        bool notFound = false;
        for (int i = 0; i < dotPos.size() - 1; i++) {
            if (m[dotPos[i]]["."] != dotPos[i+1]) {
                cout << "Not Found!" << "\n";
                notFound = true;
                break;
            }
        }
        if (notFound) continue;

        if (m[dotPos[dotPos.size() - 1]].find(v[1]) == m[dotPos[dotPos.size() - 1]].end()) {
            cout << "Not Found!" << "\n";
        } else {
            cout << m[dotPos[dotPos.size() - 1]][v[1]] << "\n";
        }

    }

    return 0;
}


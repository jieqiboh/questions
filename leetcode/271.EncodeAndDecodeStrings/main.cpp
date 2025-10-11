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

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string str : strs) {
            encoded += str;
            encoded += "\t";
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        while (s.find("\t") != string::npos) {
            int pos = s.find("\t");
            res.push_back(s.substr(0, pos));
            s.erase(s.begin(), s.begin() + pos + 1);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
    fast();
    Codec codec;
    vector<string> strs = {"Hello", "World"};
    string enc = codec.encode(strs);
    cout << enc;
    vector<string> dec = codec.decode(enc);






    return 0;
}


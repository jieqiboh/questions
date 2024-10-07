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

int main() {
    fast();
    return 0;
}


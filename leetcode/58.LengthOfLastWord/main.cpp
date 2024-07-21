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

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string word;
        int length = 0;
        while (iss >> word) {
            length = word.size();
        }
        return length;
    }
};

int main() {
    fast();
    Solution sol;

    return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
    public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        string out = "";

        for (int i = words.size() - 1; i > 0; i--) {
            out += words[i] + " ";
        }

        return out + words[0];   
    }
};

int main() {
    string s = " the sky is blue";

    Solution sol;
    
    cout << sol.reverseWords(s);
    return 0;
}

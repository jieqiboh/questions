#include <string>
#include <iostream>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int idx1 = 0;
    int idx2 = 0;
    string res = "";
    int cur = 0;
    while (word1[idx1] != '\0' && word2[idx2] != '\0') {
        if (cur % 2 == 0) {
            res += word1[idx1];
            idx1++;
        } else {
            res += word2[idx2];
            idx2++;
        }
        cur++;
    }
    if (word1[idx1] == '\0') {
        res+=word2.substr(idx2);
    } else if (word2[idx2] == '\0') {
        res+=word1.substr(idx1);
    }
    return res;
}

int main() {
    string word1 = "ab";
    string word2 = "pqrs";
    cout << mergeAlternately(word1, word2);

    return 0;
}
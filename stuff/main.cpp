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

//
//Given a sequence of M and N, form smallest possible number under following
//        condition ->
//
//M denotes the sequence is decreasing, N denotes the sequence is increasing.
//
//Constraints / Assumptions:
//1] Digits must not repeat.
//2] Allowable digits are 1-9.
//3] Maximum length of input sequence will be 8 characters.
//4] No characters other than M & N will be there in the input.
//
//Example:
//Input: M        Output: 21
//Input: N        Output: 12
//Input: MM       Output: 321
//Input: NN       Output: 123
//Input: MNMN     Output: 21435
//Input: NNMMM    Output: 126543
//Input: MMNMMNNM Output: 321654798

// Time Complexity: O(n)
//string solve(string& s) {
//    string res = "123456789";
//
//    int j = 0; // marks end of range
//    for (int i = 0; i <= s.size(); i++) {
//        if (s[i] == 'N' || i == s.size()) {
//            reverse(res.begin() + j, res.begin() + i + 1);
//            j = i + 1;
//        }
//    }
//    return res.substr(0, s.size() + 1);
//}

string solve(string& s) {
    stack<int> st;
    string result = "";
    int num = 1;

    for (int i = 0; i <= s.length(); i++) {
        st.push(num++);

        if (i == s.length() || s[i] == 'N') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    return result;
}

int main() {
    fast();
    string s = "M";
    cout << solve(s) << "\n"; // 21

    s = "N";
    cout << solve(s) << "\n"; // 12

    s = "MM";
    cout << solve(s) << "\n"; // 321

    s = "NN";
    cout << solve(s) << "\n"; // 123

    s = "MNMN";
    cout << solve(s) << "\n"; // 21435

    s = "NNMMM";
    cout << solve(s) << "\n"; // 126543

    s = "MMNMMNNM";
    cout << solve(s) << "\n"; // 321654798

    return 0;
}


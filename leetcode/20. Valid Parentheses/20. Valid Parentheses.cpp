#include "string"
#include "map"
#include "set"
#include "stack"
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            map<char, char> parenMap;
            parenMap['('] = ')';
            parenMap['['] = ']';
            parenMap['{'] = '}';

            int N = s.size();
            set<char> keys = {'(', '{', '['};

            stack<char> stk;
            for (char c : s) {
                if (keys.find(c) != keys.end()) { //left
                    stk.push(c);
                } else if (!stk.empty() && parenMap[stk.top()] == c) {//stk not empty and top matches
                        stk.pop();
                } else { //right paren and no match
                    return false;
                }
            }
            return stk.empty();
        }
};
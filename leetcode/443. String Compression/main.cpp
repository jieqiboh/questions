#include "iostream"
#include "string"
#include "vector"

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int curidx = 0;
        char curchar = chars[0];
        int cnt = 0;
        int i = 0;

        while (i < chars.size()) {
            while (curchar == chars[i]) {
                cnt++;
                i++;
            }
            curchar = chars[i];
            chars[curidx] = chars[i];
            if (cnt != 1) {
               std::string s = std::to_string(cnt);
               curidx++;
               for (char x : s) {
                   chars[curidx] = x;
                   curidx++;
               }
            }
            cnt = 0;
        }
        return curidx;
    }
};

void printvec(std::vector<char>& vec) {
   for (char x : vec) {
       std::cout << x << " ";
   }
}

int main() {
    auto sol = Solution();
    std::vector<char> vec1 = {'a','a','a','a','a','a','a','a','a','a','a','a','a','b','b','b','b','b','b','b','b','b'};
    std::vector<char> vec2 = {'a'};

    std::cout << sol.compress(vec1) << std::endl;
    std::cout << sol.compress(vec2) << std::endl;

    printvec(vec1);
    std::cout << std::endl;
    printvec(vec2);

    return 0;
}
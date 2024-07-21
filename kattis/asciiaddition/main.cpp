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

int main() {
    fast();
    // umap<int,tuple<tuple<char>>> int2ascii; // maps integers to ascii vectors
    // umap<tuple<tuple<char>>,int> ascii2int; // maps sets of ascii to their integers
    // 0123456789+
    umap<string, char> ascii2char;
    ascii2char.insert(make_pair("xxxxxx...xx...xx...xx...xx...xxxxxx",'0'));
    ascii2char.insert(make_pair("....x....x....x....x....x....x....x",'1'));
    ascii2char.insert(make_pair("xxxxx....x....xxxxxxx....x....xxxxx",'2'));
    ascii2char.insert(make_pair("xxxxx....x....xxxxxx....x....xxxxxx",'3'));
    ascii2char.insert(make_pair("x...xx...xx...xxxxxx....x....x....x",'4'));
    ascii2char.insert(make_pair("xxxxxx....x....xxxxx....x....xxxxxx",'5'));
    ascii2char.insert(make_pair("xxxxxx....x....xxxxxx...xx...xxxxxx",'6'));
    ascii2char.insert(make_pair("xxxxx....x....x....x....x....x....x",'7'));
    ascii2char.insert(make_pair("xxxxxx...xx...xxxxxxx...xx...xxxxxx",'8'));
    ascii2char.insert(make_pair("xxxxxx...xx...xxxxxx....x....xxxxxx",'9'));
    ascii2char.insert(make_pair(".......x....x..xxxxx..x....x.......",'+'));

    umap<char, string> char2ascii;
    char2ascii.insert(make_pair('0',"xxxxxx...xx...xx...xx...xx...xxxxxx"));
    char2ascii.insert(make_pair('1',"....x....x....x....x....x....x....x"));
    char2ascii.insert(make_pair('2',"xxxxx....x....xxxxxxx....x....xxxxx"));
    char2ascii.insert(make_pair('3',"xxxxx....x....xxxxxx....x....xxxxxx"));
    char2ascii.insert(make_pair('4',"x...xx...xx...xxxxxx....x....x....x"));
    char2ascii.insert(make_pair('5',"xxxxxx....x....xxxxx....x....xxxxxx"));
    char2ascii.insert(make_pair('6',"xxxxxx....x....xxxxxx...xx...xxxxxx"));
    char2ascii.insert(make_pair('7',"xxxxx....x....x....x....x....x....x"));
    char2ascii.insert(make_pair('8',"xxxxxx...xx...xxxxxxx...xx...xxxxxx"));
    char2ascii.insert(make_pair('9',"xxxxxx...xx...xxxxxx....x....xxxxxx"));
    char2ascii.insert(make_pair('+',".......x....x..xxxxx..x....x......."));

    vector<string> input;

    // read in inputs into a list of lists
    for (int i=0; i < 7; i++) {
        string line;
        getline(cin, line);
        input.push_back(line);
    }
    int linesize = input[0].size();
    int size = (linesize + 1) / 6;

    vector<string> proc_input(size);
    for (int k = 0; k < 7; k++) {
        int idx = 0; // index of the word
        int j = 0;
        string tmp = "";
        for (int i = 0; i <= linesize; i++) {
            if (j == 5) {
                j = 0;
                i++; // skip the '.'
                proc_input[idx] += tmp;
                idx++;
                tmp = "";
            }
            j++;
            tmp += input[k][i];
        }
    }

    string a_string;
    string b_string;
    bool is_a = true;
    for (string x : proc_input) {
        char c = ascii2char[x];
        if (c == '+') {
            is_a = false;
        }
        if (is_a) {
            a_string += c;
        } else {
            b_string += c;
        }
    }

    int a = stoi(a_string);
    int b = stoi(b_string);
    int res = a + b;

    string res_string = to_string(res);
    vector<string> output(7);

    for (int i = 0; i < res_string.size(); i++) {
        char c = res_string[i];
        string ascii = char2ascii[c];
        for (int i = 0; i < 7; i++) {
            int j = 0;
            while (j < 5) {
                output[i] += ascii[5 * i + j];
                j++;
            }

            output[i] += '.';
        }
    }
    for (int j = 0; j < output.size(); j++) {
        string s  = output[j];
        for (int i = 0; i < s.size() - 1; i ++) {
            cout << s[i];
        }
        if (j < output.size()-1) {
            cout << endl;
        }
    }

    return 0;
}


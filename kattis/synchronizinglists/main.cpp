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
    
    int size;
    while (cin >> size && size != 0) {

        vi list1;
        vi list2;

        for (int i = 0; i < size; i++) {
            int num; cin >> num;
            list1.push_back(num);
        }
        for (int i = 0; i < size; i++) {
            int num; cin >> num;
            list2.push_back(num);
        }

        vector<int> tmplist1(list1);

        // sort list 1
        sort(list1.begin(), list1.end());
        // based on the indexes of the sorted list, generate a hashmap
        umap<int, int> list1map, list2map;
        for (int i = 0; i < list1.size(); i++) {
            list1map[list1[i]] = i;
        }
        // sort list 2
        sort(list2.begin(), list2.end());
        
        for (int i = 0; i < list2.size(); i++) {
            list2map[i] = list2[i];
        }

        // list1 number - maps to list1 index - maps to list 2 number
        for (int num : tmplist1) {
            cout << list2map[list1map[num]] << endl;
        }
        cout << endl;
        // cout << "l1" << endl;
        // for (int x : list1) {
        //     cout << x << endl;
        // }
        // cout << "l2" << endl;
        // for (int x : list2) {
        //     cout << x << endl;
        // }
    }
    short c = (1 << 15) - 1;
    c = c + 1;
    printf("%d", c);

    return 0;
}


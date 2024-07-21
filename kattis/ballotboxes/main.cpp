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
    
    float n_cities, n_boxes;
    cin >> n_cities >> n_boxes;
    while (true) {
//        cout << n_cities << " " << n_boxes << endl;

        priority_queue<pair<float, float>> q; // queue of popn and boxes allocated
        float tmp_n_cities = n_cities;
        while (n_cities--) {
            float pop; cin >> pop;
            q.emplace(pop, 1);
        }
        n_boxes -= tmp_n_cities; // every city needs at least 1 box

        while (n_boxes--) {
            pair<float, float> city = q.top();

            float popn = city.first;
            float boxes = city.second;
            q.pop();
            float original_popn = popn * boxes;
            float new_popn = original_popn / (boxes + 1);
            q.push(make_pair(new_popn, boxes + 1));
        }
        pair<float, float> city = q.top();

        cin >> n_cities >> n_boxes;
        // we want to return an integer reflecting the max no allocated to a box, so take ceil
        int count = ceil(city.first);
        if (n_cities == -1 && n_boxes == -1) {
            cout << count;
            break;
        } else {
            cout << count << endl;
        }
//        << " " << city.second << endl;
//        cout << endl;
    }
    
    return 0;
}


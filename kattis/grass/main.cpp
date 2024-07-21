#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

// Custom comparison function
bool cmp(const std::pair<float, float> &lhs, const std::pair<float, float> &rhs) {
    if (lhs.first != rhs.first) {
        return lhs.first < rhs.first; // Sort by decreasing left value
    } else {
        return lhs.second > rhs.second; // If left values are equal, sort by increasing right value
    }
}

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();
    float n, l, w;

    while (cin >> n >> l >> w) {
//        cout << n << " " << l << " " << w << endl;
        vector<pair<float, float>> sprinklers; // a list of the sprinklers and their ranges
        while (n--) {
            int dist, rad;
            cin >> dist >> rad;
//            cout << dist << " " << rad << endl;

            // compute the actual distance covered from l to r
            float dx = sqrt(pow(rad, 2) - pow(w / 2, 2));
            pair<float, float> interval = make_pair(dist - dx, dist + dx);

            sprinklers.push_back(interval);
        }
        std::sort(sprinklers.begin(), sprinklers.end(), cmp);
//        std::pair<float, float> prev = std::make_pair(0.0f, 0.0f);

//        for (pair<float, float> x : sprinklers) {
//            cout << x.first << " " << x.second << endl;
//        }

        // minimum number of intervals to cover an entire range
        int res = 0;
        float end = 0.0;
        float max = 0.0;
        int i = 0;
        bool canCover = true;
        pair<float, float> cur = sprinklers[i];
        while (i < sprinklers.size()) {
            cur = sprinklers[i];

            if (cur.first <= end) {
                max = fmax(cur.second, max);
                i++;
                continue;
            } else if (cur.first > max) {
                canCover = false;
                break;
            }
            res++;
            end = max;
        }
        if (max < l || !canCover) {
            cout << -1 << endl;
        } else if (max > end) {
            res++;
            cout << res << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    int t; cin >> t;
    cin.ignore(); // ignore newline
    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;
        // prefix sum tables for ss and es
        vector<int> ss(n+1); // each idx rep number of jobs started until including tdy
        vector<int> es(n+1); // each idx rep nbr of jobs ended up until including tdy

        for (int i = 0; i < k; i++) {
            int s, e; cin >> s >> e;
            ss[s]++;
            es[e]++;
        }
        for (int i=0;i<n;i++) ss[i+1] += ss[i];
        for (int i=0;i<n;i++) es[i+1] += es[i];

        int l = 1e9;
        int h = 0;
        int bro = 0;
        int mom = 0;
        for (int i = d; i <= n; i++) {
            int cur = ss[i] - es[i-d]; // number of active jobs on this day
            if (cur > h) bro = i-d+1; h = cur;
            if (cur < l) mom = i-d+1; l = cur;
        }
        cout << bro << " " << mom << "\n";
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))                    // the key operation

typedef long long ll;                            // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;
#define endl '\n'

class FenwickTree {
private:
    vi ft;
public:

    FenwickTree(int m) {
        for (int i = 0; i < m+1; i++) {
            ft.push_back(0);
        }
    }

    int rsq(int j) {
        int sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
        // the key operation
        // index 0 is not used
        // create empty FT
        // returns RSQ(1, j)
    }

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, int v) {
        cout << ft.size() << endl;
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }
};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();
    int len, numops;
    scanf("%d%d\n", &len, &numops);
    FenwickTree f(len);

    while (numops--) {
        char op;
        scanf("%c", &op);

        if (op == '?') {
            int x;
            scanf("%d\n", &x);
            cout << f.rsq(x) << '\n';
        } else if (op == '+') {
            int idx, x;
            scanf("%d%d\n", &idx, &x);
            f.update(idx, x);
        }
    }
    return 0;
}

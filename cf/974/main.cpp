#include <iostream>
#include <vector>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    int n; cin >> n;
    cin.ignore(); // ignore newline
    while (n--) {
        int n, k;
        cin >> n >> k; // Read n and k for the current test case
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Read the gold amounts for each person
        }

        int robinGold = 0; // Initialize Robin's gold
        int peopleGivenGold = 0; // Count of people who receive gold
        for (int i : a) {
            if (i >= k) {
                robinGold += i;
            } else if (i == 0){
                if (robinGold > 0) {
                    robinGold--;
                    peopleGivenGold++;
                }
            }
        }
        cout << peopleGivenGold << "\n";
    }

    return 0;
}


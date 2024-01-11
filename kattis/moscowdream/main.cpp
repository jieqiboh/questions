#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    cin >> a >> b >> c >> n;
    if (n < 3) {
        cout << "NO";
    } else if (a < 1 || b < 1 || c < 1) {
        cout << "NO";
    } else if ((a + b + c) < n) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}
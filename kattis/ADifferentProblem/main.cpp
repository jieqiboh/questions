#include "iostream"
using namespace std;

int main() {
  long long a, b;
  while (cin >> a >> b) {
    long long r = abs(a - b); 
    cout << r << endl;
  }
  return 0;
}

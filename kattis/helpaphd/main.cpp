#include <iostream> // Input and output operations.
#include <vector> // Dynamic Arrays
#include <queue> // Queues
#include <stack> // Stacks
#include <set> // Sets
#include <map>
#include <algorithm> 
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>

using namespace std;

int main() {
    // Your code goes here
    int count; scanf("%d", &count);
    cin.ignore();

    for (int i = 0; i < count; i++) {
       string s; getline(cin, s); 
       if (s == "P=NP") {
               cout <<  "skipped" << endl;
       } else {
               istringstream iss(s);
               char op;
               int a, b;
               iss >> a >> op >> b;
               cout << a + b << endl;
       }
    }

    return 0;
}


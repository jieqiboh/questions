#include "string"
#include "iostream"
int main() {
    int a = 0;
    int b;
    while (scanf("%d", &b) != EOF) {
        a+=b;
    }
    std::cout << a;
    return 0;
}
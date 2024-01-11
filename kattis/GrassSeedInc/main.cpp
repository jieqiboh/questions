#include "string"
#include "iostream"

int main() {
    int num;
    double cost;
    scanf("%lf", &cost);
    scanf("%d", &num);

    double a, b;
    int i = 0;
    double res = 0;

    while (i < num) {
        scanf("%lf %lf", &a, &b);
        res += a * b * cost;
        i++;
    }
    std::cout.precision(10);
    std::cout << res;
    return 0;
}
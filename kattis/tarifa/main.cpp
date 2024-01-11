#include "iostream"

int main() {
    int spent = 0;
    int mpermth, mths;

    std::cin >> mpermth;
    std::cin >> mths;

    for (int i = 0; i < mths; i++) {
        int d;
        scanf("%d", &d);
        spent += d;
    }
    std::cout << mpermth*(mths+1) - spent << std::endl;
    return 0;

}
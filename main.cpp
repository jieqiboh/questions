#include <iostream>
using namespace std;

class obj
{
public:
    obj() { std::cout << 1; }
    obj(const obj&) { std::cout << 2; }
    void operator=(const obj&) { std::cout << 3; }
};

int main()
{
    obj a;
    obj b{};
    obj c();
    obj d = a;
    d = b;
    auto e = obj{};
    obj f{a};
    obj g(a);
    auto h = b;
    obj(i);
}

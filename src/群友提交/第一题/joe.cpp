#include <iostream>
#include <vector>
#include <functional>

std::vector<int>& operator|(std::vector<int>& v, auto&& func)
{
    for (int& x : v)
    {
        func(x);
    }
    return v;
}

int main()
{
    std::vector v{1, 2, 3};
    std::function f{[](const int& i) { std::cout << i << ' '; }};
    auto f2 = [](int& i) { i *= i; };
    v | f2 | f;
}

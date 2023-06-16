#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/debug_template.hpp"

#include "../../template/template.hpp"

int main() {
    int a, b;
    std::cin >> a >> b;
    debug(a, b, a + b);
    std::cout << a + b << '\n';
}
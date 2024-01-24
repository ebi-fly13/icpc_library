#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../string/z_algorithm.hpp"

#include "../../template/template.hpp"

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    auto z = z_algorithm(s);
    rep(i, 0, n) {
        std::cout << z[i] << " \n"[i == n - 1];
    }
}
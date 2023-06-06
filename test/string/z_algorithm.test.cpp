#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../template/template.hpp"
#include "../../string/z_algorithm.hpp"

using namespace lib;

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    auto z = z_algorithm(s);
    rep(i,0,n) {
        std::cout << z[i] << " \n"[i == n-1];
    }
}
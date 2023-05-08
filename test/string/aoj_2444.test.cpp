#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444&lang=jp"

#include "../../string/RollingHash.hpp"
#include "../../template/template.hpp"

int main() {
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;
    lib::RollingHash rh(s);
    int l = 0, r = 1;
    std::set<ull> set;
    rep(i, 0, m) {
        std::string q;
        std::cin >> q;
        if (q == "L++") {
            l++;
        } else if (q == "L--") {
            l--;
        } else if (q == "R++") {
            r++;
        } else {
            r--;
        }
        set.insert(rh.get(l, r));
    }
    std::cout << set.size() << '\n';
}
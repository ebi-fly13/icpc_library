#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../string/suffix_array.hpp"

#include "../../template/template.hpp"

void main_() {
    string s;
    cin >> s;
    auto sa = suffix_array(s);
    rep(i, 0, s.size()) {
        cout << sa[i] << " \n"[i == s.size() - 1];
    }
}

int main() {
    int t = 1;
    // std::cin >> t;
    while (t--) {
        main_();
    }
    return 0;
}
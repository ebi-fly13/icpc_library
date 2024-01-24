#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../string/suffix_array.hpp"
#include "../../template/template.hpp"

void main_() {
    string s;
    cin >> s;
    auto sa = suffix_array(s);
    auto lcp = lcp_array(s, sa);
    ll n = s.size();
    ll ans = n * (n + 1) / 2;
    rep(i, 0, n - 1) {
        ans -= lcp[i];
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        main_();
    }
    return 0;
}
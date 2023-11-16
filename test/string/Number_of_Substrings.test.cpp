#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../template/template.hpp"
#include "../../string/suffix_array.hpp"

namespace lib {

void main_() {
    string s;
    cin >> s;
    auto sa = suffix_array(s);
    auto lcp = lcp_array(s, sa);
    ll n = s.size();
    ll ans = n * (n + 1) / 2;
    rep(i,0,n-1) {
        ans -= lcp[i];
    }
    cout << ans << '\n';
}

}  // namespace ebi

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        lib::main_();
    }
    return 0;
}
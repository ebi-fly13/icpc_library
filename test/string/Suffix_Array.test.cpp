#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../template/template.hpp"
#include "../../string/suffix_array.hpp"

namespace lib {

void main_() {
    string s;
    cin >> s;
    auto sa = suffix_array(s);
    rep(i,0,s.size()) {
        cout << sa[i] << " \n"[i == s.size()-1];
    }
}

}  // namespace ebi

int main() {
    int t = 1;
    // std::cin >> t;
    while (t--) {
        lib::main_();
    }
    return 0;
}
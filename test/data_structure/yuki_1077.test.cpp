#define PROBLEM "https://yukicoder.me/problems/no/1077"

#include "../../data_structure/slope_trick.hpp"
#include "../../template/template.hpp"

namespace lib {

void main_() {
    int n;
    std::cin >> n;
    slope_trick<ll> st;
    rep(i, 0, n) {
        ll y;
        std::cin >> y;
        st.left_cumulative_min();
        st.add_abs(y);
    }
    std::cout << st.min() << '\n';
}

}  // namespace lib

int main() {
    int t = 1;
    // std::cin >> t;
    while (t--) {
        lib::main_();
    }
    return 0;
}
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../../template/template.hpp"
#include "../../data_structure/dualsegtree.hpp"

using namespace lib;

int op(int a, int b) {
    return a + b;
}

int e() {
    return 0;
}

int main() {
    int n,q;
    std::cin >> n >> q;
    dualsegtree<int, op, e> seg(n);
    while(q--) {
        int flag;
        std::cin >> flag;
        if(flag == 0) {
            int s,t,x;
            std::cin >> s >> t >> x;
            s--;
            seg.apply(s, t, x);
        }
        else {
            int t;
            std::cin >> t;
            t--;
            std::cout << seg.get(t) << '\n';
        }
    }
}
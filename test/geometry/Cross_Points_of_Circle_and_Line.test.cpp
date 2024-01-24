#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D"
#define ERROR 0.0000001

#include "../../geometry/circle.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(15);
    auto input = [](vec &p) {
        ld x, y;
        std::cin >> x >> y;
        p = {x, y};
    };
    circle c;
    {
        vec p;
        ld r;
        input(p);
        std::cin >> r;
        c = {p, r};
    }
    int q;
    cin >> q;
    while (q--) {
        line l;
        vec a, b;
        input(a);
        input(b);
        l = {a, b};
        auto ps = cross_point(c, l);
        if (ps.size() == 1) ps.emplace_back(ps.back());
        std::sort(all(ps), [](auto lhs, auto rhs) {
            return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag()
                                            : lhs.real() < rhs.real();
        });
        std::cout << ps[0].real() << " " << ps[0].imag() << " " << ps[1].real()
                  << " " << ps[1].imag() << '\n';
    }
}
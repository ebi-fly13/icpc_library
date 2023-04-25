#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
#define ERROR 0.0000001

#include "../../geometry/circle.hpp"

using namespace lib;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    auto input = [](vec &p) {
        ld x, y;
        std::cin >> x >> y;
        p = {x, y};
    };
    circle c1, c2;
    {
        vec p;
        ld r;
        input(p);
        std::cin >> r;
        c1 = {p, r};
    }
    {
        vec p;
        ld r;
        input(p);
        std::cin >> r;
        c2 = {p, r};
    }
    auto ps = cross_point(c1, c2);
    if (ps.size() == 1) ps.emplace_back(ps.back());
    std::sort(all(ps), [](auto lhs, auto rhs) {
        return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag()
                                        : lhs.real() < rhs.real();
    });
    for(auto p: ps) {
        std::cout << p.real() << " " << p.imag() << " ";
    }
    std::cout << '\n';
}
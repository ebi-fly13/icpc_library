#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C"
#define ERROR 0.0000001

#include "../../geometry/segment.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(15);
    int q;
    std::cin >> q;
    while (q--) {
        vec p0, p1, p2, p3;
        auto input = [](vec &p) {
            ld x, y;
            std::cin >> x >> y;
            p = {x, y};
        };
        input(p0);
        input(p1);
        input(p2);
        input(p3);
        segment s1 = {p0, p1};
        segment s2 = {p2, p3};
        vec p = cross_point(s1, s2);
        std::cout << p.real() << " " << p.imag() << '\n';
    }
}
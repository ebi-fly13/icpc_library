#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR 0.0000001

#include "../../geometry/line.hpp"
#include "../../template/template.hpp"

using namespace lib;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    line l;
    {
        ld x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        l.a = {x1, y1};
        l.b = {x2, y2};
    }
    int q;
    std::cin >> q;
    while (q--) {
        ld x, y;
        std::cin >> x >> y;
        vec p = refl(l, {x, y});
        std::cout << p.real() << " " << p.imag() << '\n';
    }
}
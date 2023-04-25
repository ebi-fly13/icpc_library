#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C"
#define ERROR 0.0000001

#include "../../geometry/circle.hpp"

using namespace lib;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    vec a,b,c;
    auto input = [](vec &p) {
        ld x, y;
        std::cin >> x >> y;
        p = {x, y};
    };
    input(a);
    input(b);
    input(c);
    circle cir = circumscribed_circle_of_triangle(a, b, c);
    std::cout << cir.c.real() << " " << cir.c.imag() << " " << cir.r << '\n';
}
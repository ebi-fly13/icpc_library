#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B"
#define ERROR 0.0000001

#include "../../geometry/base_ld.hpp"
#include "../../geometry/circle.hpp"
#include "../../template/template.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(15);
    auto input = [](vec &a) {
        ld x, y;
        std::cin >> x >> y;
        a = {x, y};
    };
    vec a, b, c;
    input(a);
    input(b);
    input(c);
    circle in = incircle_of_triangle(a, b, c);
    std::cout << in.c.real() << " " << in.c.imag() << " " << in.r << '\n';
}
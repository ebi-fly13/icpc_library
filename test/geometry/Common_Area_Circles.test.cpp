#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I"
#define ERROR 0.00000001

#include "../../geometry/base_ld.hpp"
#include "../../geometry/circle.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    circle c1, c2;
    auto input = [](circle &c) -> void {
        ld x, y, r;
        std::cin >> x >> y >> r;
        c.c = {x, y};
        c.r = r;
    };
    input(c1);
    input(c2);
    std::cout << common_area(c1, c2) << '\n';
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}
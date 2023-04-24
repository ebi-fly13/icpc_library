#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

#include "../../geometry/circle.hpp"

using namespace lib;

int main() {
    ld c1x, c1y, c1r;
    ld c2x, c2y, c2r;
    std::cin >> c1x >> c1y >> c1r;
    std::cin >> c2x >> c2y >> c2r;
    circle c1 = {{c1x, c1y}, c1r};
    circle c2 = {{c2x, c2y}, c2r};
    std::cout << intersection(c1, c2) << '\n';
}
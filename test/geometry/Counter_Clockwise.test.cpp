#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "../../geometry/base_ld.hpp"
#include "../../template/template.hpp"

using namespace lib;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    long double x1,y1,x2,y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    vec p0(x1, y1), p1(x2, y2);
    int q;
    std::cin >> q;
    while(q--) {
        double x,y;
        std::cin >> x >> y;
        int flag = isp(p0, p1, vec(x,y));
        std::string ans;
        if(flag == 1) {
            ans = "COUNTER_CLOCKWISE";
        }
        else if(flag == -1) {
            ans = "CLOCKWISE";
        }
        else if(flag == -2) {
            ans = "ONLINE_BACK";
        }
        else if(flag == 2) {
            ans = "ONLINE_FRONT";
        }
        else {
            ans = "ON_SEGMENT";
        }
        std::cout << ans << std::endl;
    }
}
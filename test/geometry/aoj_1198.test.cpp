#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1198"

#include"../../template/template.hpp"

#include"../../geometry/Partition_by_Circles.hpp"

using namespace lib;

int main(){
    while (true){
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        Partition_by_Circles pc;
        while (n--){
            ld x, y, r; cin >> x >> y >> r;
            pc.add_circle(circle({vec(x,y),r}));
        }
        pc.build_graph();
        string ans = "";
        while (m--){
            ld px, py, qx, qy; cin >> px >> py >> qx >> qy;
            int ip = pc.get_area_idx(vec(px,py));
            int iq = pc.get_area_idx(vec(qx,qy));
            ans += (ip == iq ? "YES" : "NO");
            ans += (m == 0 ? '\n' : ' ');
        }
        cout << ans;
    }
}
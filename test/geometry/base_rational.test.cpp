#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1623&lang=jp"

#include"../../template/template.hpp"
#include"../../utility/rational.hpp"
#include"../../geometry/base_arbitary.hpp"

using namespace lib;
using vec = Vec<rational>;
using line = Line<rational>;

const vector<vector<int>> order = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};

int main(){
    while (true){
        vector<vec> ia(3), b(3);
        rep(i,0,6){
            ll x, y; cin >> x >> y;
            if (!cin) return 0;
            (i < 3 ? ia[i] : b[i-3]) = vec(x,y);
        }
        int ans = 5;
        for (auto fid : order) for (auto tid : order) rep(j,0,2){
            auto a = ia;
            int cur = 0;
            rep(i,0,3){
                int f = fid[i], t = tid[i];
                if (a[f] == b[t]) continue;
                cur++;
                int p = (f+1)%3, q = (f+2)%3;
                if (cross(a[p]-a[q],b[t]-a[f]) == 0){
                    a[f] = b[t];
                    continue;
                }
                cur++;
                if (j == 1) swap(p,q);
                line l1({a[p],a[p]+a[f]-b[t]}), l2({a[q],a[q]+a[f]-a[p]});
                if (intersection(l1,l2) == 1){
                    a[q] = cross_point(l1,l2);
                    a[f] = b[t];
                }
                else {
                    cur = 5;
                    break;
                }
            }
            chmin(ans,cur);
        }
        if (ans == 5) cout << "Many" << endl;
        else cout << ans << endl;
    }
}
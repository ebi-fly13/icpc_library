#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2827"
#define ERROR 0.001

#include"../../template/template.hpp"
#include"../../geometry/convex_hull.hpp"
#include"../../geometry/segment.hpp"
using namespace lib;

const ld dinf = 2e12;

void solve(int n){
    vector<vector<vec>> a(n);
    vector<ld> hs(n);
    rep(i,0,n){
        int m; cin >> m >> hs[i];
        a[i].resize(m);
        rep(j,0,m){
            ld x, y; cin >> x >> y;
            a[i][j] = vec(x,y);
        }
    }
    ld rad1, rad2; cin >> rad1 >> rad2;
    rad1 *= M_PI/180, rad2 *= M_PI/180;
    ld sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    vec sv(sx,sy), tv(tx,ty);
    vector<vector<vec>> hulls(n);
    rep(i,0,n){
        vec pl = rot(vec(hs[i]/tanl(rad2),0),rad1+M_PI);
        vector<vec> b = a[i];
        rep(j,0,a[i].size()) b.emplace_back(a[i][j]+pl);
        hulls[i] = convex_hull(b);
    }
    vector<vector<ld>> ds(n+2,vector<ld>(n+2,dinf));
    rep(i,0,n) rep(j,0,n){
        if (i >= j){
            ds[i][j] = ds[j][i];
            continue;
        }
        int si = hulls[i].size(), sj = hulls[j].size();
        rep(p,0,si) rep(q,0,sj){
            segment iseg({hulls[i][p],hulls[i][(p+1)%si]});
            segment jseg({hulls[j][q],hulls[j][(q+1)%sj]});
            chmin(ds[i][j],dist(iseg,jseg));
        }
    }
    ds[n][n+1] = abs(sv-tv); ds[n+1][n] = ds[n][n+1];
    auto dist_hull_vec = [&](int id, vec v){
        bool in = true;
        ld res = dinf;
        int isiz = hulls[id].size();
        rep(i,0,isiz){
            vec iv = hulls[id][i];
            vec jv = hulls[id][(i+1)%isiz];
            chmin(res,dist(segment({iv,jv}),v));
            if (cross(jv-iv,v-iv) < 0) in = false;
        }
        if (in) return ld(0);
        return res;
    };
    rep(i,0,n){
        ds[i][n] = dist_hull_vec(i,sv);
        ds[n][i] = ds[i][n];
        ds[i][n+1] = dist_hull_vec(i,tv);
        ds[n+1][i] = ds[i][n+1];
    }
    vector<ld> ans(n+2,dinf); ans[n] = 0;
    using pdi = pair<ld,int>;
    priority_queue<pdi,vector<pdi>,greater<pdi>> pque;
    pque.push(pdi(ans[n],n));
    while (!pque.empty()){
        auto [idist, f] = pque.top(); pque.pop();
        if (ans[f] < idist) continue;
        rep(i,0,n+2){
            if (chmin(ans[i],idist+ds[f][i])){
                pque.push(pdi(ans[i],i));
            }
        }
    }
    cout << ans[n+1] << endl;
}

int main(){
    ldout();
    while (true){
        int n; cin >> n;
        if (n == 0) break;
        solve(n);
    }
}
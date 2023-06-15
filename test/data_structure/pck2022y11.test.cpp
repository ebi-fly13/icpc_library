#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0489"

#include"../../template/template.hpp"

#include"../../data_structure/segtree.hpp"
#include"../../tree/LowestCommonAncestor.hpp"

#include"../../template/debug_template.hpp"

using namespace lib;

using P = pair<int,int>;
const int geta = 1'000'000;
const int mx = geta*2+10;

int op(int a, int b){
    return a + b;
}
int e(){
    return 0;
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    vector<vector<int>> querys;
    vector<P> es(n-1);
    rep(i,0,n-1) cin >> es[i].first >> es[i].second;
    {   
        int pre = n+1;
        while (m--){
            int t; cin >> t;
            if (t == 1){
                int u, w; cin >> u >> w;
                es.emplace_back(u,pre++);
                a.emplace_back(w);
            }
            if (t == 2){
                int u, v, k; cin >> u >> v >> k; u--, v--;
                querys.push_back({u,v,k});
            }
        }
        n = es.size()+1;
        m = querys.size();
    }
    vector<vector<int>> g(n);
    for (auto &[u, v] : es){
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    LowestCommonAncestor lca(g);
    vector<int> lcas(m);
    rep(i,0,m) lcas[i] = lca.lca(querys[i][0],querys[i][1]);
    vector<int> les(m,0), ris(m,mx);
    int test = 22;
    while (test--){
        vector<int> mds(m);
        vector<vector<P>> ask(n);
        rep(i,0,m){
            mds[i] = (les[i] + ris[i]) / 2;
            ask[querys[i][0]].emplace_back(i,1);
            ask[querys[i][1]].emplace_back(i,1);
            ask[lcas[i]].emplace_back(i,-2);
        }
        vector<int> cur(m,0);
        segtree<int,op,e> seg(mx);
        auto add = [&](int val, int cnt){
            val += geta;
            seg.set(val,seg.get(val)+cnt);
        };
        auto dfs = [&](auto dfs, int v, int f) -> void {
            add(a[v],1);
            for (auto &[id, type] : ask[v]){
                cur[id] += seg.prod(0,mds[id]) * type;
                if (type == -2 && a[v]+geta < mds[id]) cur[id]++; 
            }
            for (int u : g[v]){
                if (u == f) continue;
                dfs(dfs,u,v);
            }
            add(a[v],-1);
        };
        dfs(dfs,0,-1);
        rep(i,0,m){
            if (cur[i] < querys[i][2]) les[i] = mds[i];
            else ris[i] = mds[i];
        }
    }
    rep(i,0,m) cout << les[i]-geta << endl;
}
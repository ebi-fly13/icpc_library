#define PROBLEM "https://yukicoder.me/problems/no/1976"

#include "../../template/template.hpp"
#include "../../tree/RerootingDP.hpp"

using namespace lib;

using P = pair<int,int>;
P merge(P a, P b){
    return P(max(max(a.first,b.first),a.second+b.second),max(a.second,b.second));
}
P e(){
    return P(0,0);
}
P pute(P v, int id){
    return P(max(v.first,v.second+1),v.second+1);
}
P putv(P e, int id){
    return e;
}

int main(){
    int n; cin >> n;
    RerootingDP<P,P,merge,e,pute,putv> g(n);
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--, v--;
        g.add_edge(u,v,i,i);
    }
    g.build();
    g.reroot();
    int ans = n;
    for (int u = 0; u < n; u++){
        for (auto [v, idx, dxi] : g[u]){
            int x = g.get(u,v).first;
            int y = g.get(v,u).first;
            ans = min(ans,max({x,y,(x+1)/2+(y+1)/2+1}));
        }
    }
    cout << ans << endl;
}
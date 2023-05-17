#define PROBLEM "https://atcoder.jp/contests/abc301/tasks/abc301_g"

#include"../../template/template.hpp"
#include"../../geometry3D/accurate/line.hpp"

using namespace lib;
using rat = rational;
using vec = Vec<rat>;
using line = Line<rat>;

bool same_line(const line &a, const line &b){
    return intersection(a,b) == 3;
}

int popc(ull n){
    return __builtin_popcountll(n);
}

int main(){
    int n; cin >> n;
    vector<vec> a(n);
    rep(i,0,n){
        ll x, y, z; cin >> x >> y >> z;
        a[i] = vec(x,y,z);
    }
    bool (*comp)(vec, vec) = [](vec lhs, vec rhs){
        if (lhs.x == rhs.x){
            if (lhs.y == rhs.y){
                return lhs.z < rhs.z;
            }
            return lhs.y < rhs.y;
        }
        return lhs.x < rhs.x;
    };
    set<vec, bool (*)(vec lhs, vec rhs)> lines(comp);
    vector<line> ls;
    rep(i,0,n-1) rep(j,i+1,n){
        if (a[i].x == a[j].x) continue;
        line cur({a[i],a[j]});
        vec x0 = cur.a + (cur.b - cur.a) * cur.a.x / (cur.a.x - cur.b.x);
        if (lines.find(x0) == lines.end()){
            lines.insert(x0);
            ls.emplace_back(cur);
        }
    }
    int siz = ls.size();
    if (siz == 0){
        cout << n << endl;
        return 0;
    }
    if (siz == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<ull> cnt(siz,0);
    rep(i,0,siz){
        rep(j,0,n){
            if (cross(ls[i].a - a[j], ls[i].b - a[j]) == vec(0,0,0)) cnt[i] |= (1LL<<j);
        }
        rep(j,0,n){
            if (cnt[i] >> j & 1){
                cnt[i] ^= (1LL<<j);
                break;
            }
        }
    }
 
    int ans = n;
    map<vec, ull, bool (*)(vec lhs, vec rhs)> mp(comp);
    rep(i,0,ls.size()){
        rep(j,i+1,ls.size()){
            if (intersection(ls[i],ls[j]) == 0){
                vec p = cross_point(ls[i],ls[j]);
                if (p.x < 0){
                    mp[p] |= (cnt[i] | cnt[j]);
                }
            }
        }
        chmin(ans,n-popc(cnt[i]));
    }
    for (auto vi : mp) chmin(ans,n-popc(vi.second));
    cout << ans << endl;
}
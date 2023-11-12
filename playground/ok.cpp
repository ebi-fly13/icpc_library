#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)
#define all(v) v.begin(), v.end()

using ll = long long;
using ld = long double;
using ull = unsigned long long;

template <typename T> bool chmin(T &a, const T &b) {
    if (a <= b) return false;
    a = b;
    return true;
}
template <typename T> bool chmax(T &a, const T &b) {
    if (a >= b) return false;
    a = b;
    return true;
}

using namespace std;

int main(){
    int n, x; cin >> n >> x;
    int ans = 0;
    rep(i,0,n){
        int s; cin >> s;
        if (s <= x) ans += s; // 以下
    }
    cout << ans << endl;
}
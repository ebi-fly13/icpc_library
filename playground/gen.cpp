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

mt19937_64 mt;
ll rnd(ll l, ll r){
    assert(l <= r);
    return mt() % (r-l+1) + l;
}

int main(int argc, char* argv[]){
    mt.seed(stoi(argv[1]));
    ll n = rnd(4,8);
    ll x = rnd(1,100); // [100,675] のところを [1,100] にすることで、 diff を見つけやすくする
    cout << n << " " << x << endl;
    rep(i,0,n){
        ll s = rnd(1,100); // ここも
        cout << s << " \n"[i == n-1];
    }
}
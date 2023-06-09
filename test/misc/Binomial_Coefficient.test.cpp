#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include"../../template/template.hpp"

#include"../../utility/dynamic_modint.hpp"
#include"../../misc/factorial.hpp"

using namespace lib;

using mint = dynamic_modint<-1>;
const int mx = 10'000'000;

int main(){
    int t, m; cin >> t >> m;
    mint::set_mod(m);
    Binom<mint> bnm(min(m-1,mx));
    while (t--){
        int n, k; cin >> n >> k;
        cout << bnm(n,k).val() << endl;
    }
}
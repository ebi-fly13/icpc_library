#pragma once

#include"../utility/modint.hpp"

namespace lib {

// only for modint998244353
template<typename mint>
struct NTT {
    using uint = unsigned int;
    static constexpr uint mod = mint::mod();
    static constexpr ull mod2 = (ull)mod * mod;
    static constexpr uint pr  = 3; // for modint998244353
    static constexpr int level = 23; // for modint998244353
    array<mint,level+1> wp, wm;
    void set_ws(){
        mint r = mint(pr).pow((mod-1) >> level);
        wp[level] = r, wm[level] = r.inv();
        for (int i = level-1; i >= 0; i--){
            wp[i] = wp[i+1] * wp[i+1];
            wm[i] = wm[i+1] * wm[i+1];
        }
    }
    NTT () { set_ws(); }
    void fft4(vector<mint> &a, int k){
        uint im = wm[2].val();
        uint n = 1<<k;
        uint len = n;
        int d = k;
        while (len > 1){
            if (d == 1){
                for (int i = 0; i < (1<<(k-1)); i++){
                    a[i*2+0] += a[i*2+1];
                    a[i*2+1]  = a[i*2+0] - a[i*2+1] * 2;
                }
                len >>= 1;
                d -= 1;
            }
            else {
                int len4 = len/4;
                int nlen = n/len;
                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;
                for (int i = 0; i < len4; i++){
                    for (int j = 0; j < nlen; j++){
                        uint a0 = a[len4*0+i + len*j].val();
                        uint a1 = a[len4*1+i + len*j].val();
                        uint a2 = a[len4*2+i + len*j].val();
                        uint a3 = a[len4*3+i + len*j].val();
                        uint a0p2 = a0 + a2;
                        uint a1p3 = a1 + a3;
                        ull b0m2 = (a0 + mod - a2) * r1;
                        ull b1m3 = (a1 + mod - a3) * imr1;
                        ull c0m2 = (a0 + mod - a2) * r3;
                        ull c1m3 = (a1 + mod - a3) * imr3;
                        a[len4*0+i + len*j] = a0p2 + a1p3;
                        a[len4*1+i + len*j] = b0m2 + b1m3;
                        a[len4*2+i + len*j] = (a0p2 + mod*2 - a1p3) * r2;
                        a[len4*3+i + len*j] = c0m2 + mod2*2 - c1m3;
                    }
                    r1 = r1 * wm[d].val() % mod;
                    r2 = r1 * r1 % mod;
                    r3 = r1 * r2 % mod;
                    imr1 = im * r1 % mod;
                    imr3 = im * r3 % mod;
                }
                len >>= 2;
                d -= 2;
            }
        }
    }
    void ifft4(vector<mint> &a, int k){
        uint im = wp[2].val();
        uint n = 1<<k;
        uint len = (k & 1 ? 2 : 4);
        int d = (k & 1 ? 1 : 2);
        while (len <= n){
            if (d == 1){
                for (int i = 0; i < (1<<(k-1)); i++){
                    a[i*2+0] += a[i*2+1];
                    a[i*2+1]  = a[i*2+0] - a[i*2+1] * 2;
                }
                len <<= 2;
                d += 2;
            }
            else {
                int len4 = len/4;
                int nlen = n/len;
                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;
                for (int i = 0; i < len4; i++){
                    for (int j = 0; j < nlen; j++){
                        ull a0 = a[len4*0+i + len*j].val();
                        ull a1 = a[len4*1+i + len*j].val() * r1;
                        ull a2 = a[len4*2+i + len*j].val() * r2;
                        ull a3 = a[len4*3+i + len*j].val() * r3;
                        ull b1 = a[len4*1+i + len*j].val() * imr1;
                        ull b3 = a[len4*3+i + len*j].val() * imr3;
                        ull a0p2 = a0 + a2;
                        ull a1p3 = a1 + a3;
                        ull a0m2 = a0 + mod2 - a2;
                        ull b1m3 = b1 + mod2 - b3;
                        a[len4*0+i + len*j] = a0p2 + a1p3;
                        a[len4*1+i + len*j] = a0m2 + b1m3;
                        a[len4*2+i + len*j] = a0p2 + mod2*2 - a1p3;
                        a[len4*3+i + len*j] = a0m2 + mod2*2 - b1m3;
                    }
                    r1 = r1 * wp[d].val() % mod;
                    r2 = r1 * r1 % mod;
                    r3 = r1 * r2 % mod;
                    imr1 = im * r1 % mod;
                    imr3 = im * r3 % mod;
                }
                len <<= 2;
                d += 2;
            }
        }
    }
    vector<mint> multiply(const vector<mint> &a, const vector<mint> &b){
        if (a.empty() || b.empty()) return {};
        int d = a.size() + b.size() - 1;
        if (min<int>(a.size(), b.size()) <= 40){
            vector<mint> s(d);
            rep(i,0,a.size()) rep(j,0,b.size()) s[i+j] += a[i]*b[j];
            return s;
        }
        int k = 2, M = 4;
        while (M < d) M <<= 1, ++k;
        vector<mint> s(M), t(M);
        rep(i,0,a.size()) s[i] = a[i];
        rep(i,0,b.size()) t[i] = b[i];
        fft4(s,k);
        fft4(t,k);
        rep(i,0,M) s[i] *= t[i];
        ifft4(s, k);
        s.resize(d);
        mint invm = mint(M).inv();
        rep(i,0,d) s[i] *= invm;
        return s;
    }
};

} // namespace lib
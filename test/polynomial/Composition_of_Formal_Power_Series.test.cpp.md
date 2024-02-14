---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT convolution
  - icon: ':heavy_check_mark:'
    path: convolution/ntt4.hpp
    title: convolution/ntt4.hpp
  - icon: ':heavy_check_mark:'
    path: fps/composition_of_fps.hpp
    title: $f(g(x))$
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/composition_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/composition_of_formal_power_series
  bundledCode: "#line 1 \"test/polynomial/Composition_of_Formal_Power_Series.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n\n#include <iostream>\n\n#line 2 \"convolution/ntt.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 2 \"\
    utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\n\nnamespace lib {\n\n\
    template <ll m> struct modint {\n    using mint = modint;\n    ll a;\n\n    modint(ll\
    \ x = 0) : a((x % m + m) % m) {}\n    static constexpr ll mod() {\n        return\
    \ m;\n    }\n    ll val() const {\n        return a;\n    }\n    ll& val() {\n\
    \        return a;\n    }\n    mint pow(ll n) const {\n        mint res = 1;\n\
    \        mint x = a;\n        while (n) {\n            if (n & 1) res *= x;\n\
    \            x *= x;\n            n >>= 1;\n        }\n        return res;\n \
    \   }\n    mint inv() const {\n        return pow(m - 2);\n    }\n    mint& operator+=(const\
    \ mint rhs) {\n        a += rhs.a;\n        if (a >= m) a -= m;\n        return\
    \ *this;\n    }\n    mint& operator-=(const mint rhs) {\n        if (a < rhs.a)\
    \ a += m;\n        a -= rhs.a;\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint rhs) {\n        a = a * rhs.a % m;\n        return *this;\n    }\n    mint&\
    \ operator/=(mint rhs) {\n        *this *= rhs.inv();\n        return *this;\n\
    \    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const modint &lhs,\
    \ const modint &rhs) {\n        return lhs.a == rhs.a;\n    }\n    friend bool\
    \ operator!=(const modint &lhs, const modint &rhs) {\n        return !(lhs ==\
    \ rhs);\n    }\n    mint operator+() const {\n        return *this;\n    }\n \
    \   mint operator-() const {\n        return mint() - *this;\n    }\n};\n\nusing\
    \ modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1'000'000'007>;\n\
    \n}  // namespace lib\n#line 5 \"convolution/ntt.hpp\"\n\nnamespace lib {\n\n\
    using mint = modint998244353;\n\nstruct ntt_info {\n    static constexpr int rank2\
    \ = 23;\n    const int g = 3;\n    std::array<std::array<mint, rank2 + 1>, 2>\
    \ root;\n\n    ntt_info() {\n        root[0][rank2] = mint(g).pow((mint::mod()\
    \ - 1) >> rank2);\n        root[1][rank2] = root[0][rank2].inv();\n        rrep(i,\
    \ 0, rank2) {\n            root[0][i] = root[0][i + 1] * root[0][i + 1];\n   \
    \         root[1][i] = root[1][i + 1] * root[1][i + 1];\n        }\n    }\n};\n\
    \nvoid butterfly(std::vector<mint>& a, bool inverse) {\n    static ntt_info info;\n\
    \    int n = a.size();\n    int bit_size = 0;\n    while ((1 << bit_size) < n)\
    \ bit_size++;\n    assert(1 << bit_size == n);\n    for (int i = 0, j = 1; j <\
    \ n - 1; j++) {\n        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n      \
    \  if (j < i) {\n            std::swap(a[i], a[j]);\n        }\n    }\n    rep(bit,\
    \ 0, bit_size) {\n        rep(i, 0, n / (1 << (bit + 1))) {\n            mint\
    \ zeta1 = 1;\n            mint zeta2 = info.root[inverse][1];\n            mint\
    \ w = info.root[inverse][bit + 1];\n            rep(j, 0, 1 << bit) {\n      \
    \          int idx = i * (1 << (bit + 1)) + j;\n                int jdx = idx\
    \ + (1 << bit);\n                mint p1 = a[idx];\n                mint p2 =\
    \ a[jdx];\n                a[idx] = p1 + zeta1 * p2;\n                a[jdx] =\
    \ p1 + zeta2 * p2;\n                zeta1 *= w;\n                zeta2 *= w;\n\
    \            }\n        }\n    }\n    if (inverse) {\n        mint inv_n = mint(n).inv();\n\
    \        rep(i, 0, n) a[i] *= inv_n;\n    }\n}\n\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& f,\n                              const std::vector<mint>&\
    \ g) {\n    int n = 1;\n    while (n < int(f.size() + g.size() - 1)) n <<= 1;\n\
    \    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(), f.end(), a.begin());\n\
    \    std::copy(g.begin(), g.end(), b.begin());\n    butterfly(a, false);\n   \
    \ butterfly(b, false);\n    rep(i, 0, n) {\n        a[i] *= b[i];\n    }\n   \
    \ butterfly(a, true);\n    a.resize(f.size() + g.size() - 1);\n    return a;\n\
    }\n\n}  // namespace lib\n#line 2 \"fps/composition_of_fps.hpp\"\n\n#line 2 \"\
    fps/fps.hpp\"\n\n#line 2 \"convolution/ntt4.hpp\"\n\n#line 4 \"convolution/ntt4.hpp\"\
    \n\nnamespace lib {\n\n// only for modint998244353\ntemplate<typename mint>\n\
    struct NTT {\n    using uint = unsigned int;\n    static constexpr uint mod =\
    \ mint::mod();\n    static constexpr ull mod2 = (ull)mod * mod;\n    static constexpr\
    \ uint pr  = 3; // for modint998244353\n    static constexpr int level = 23; //\
    \ for modint998244353\n    array<mint,level+1> wp, wm;\n    void set_ws(){\n \
    \       mint r = mint(pr).pow((mod-1) >> level);\n        wp[level] = r, wm[level]\
    \ = r.inv();\n        for (int i = level-1; i >= 0; i--){\n            wp[i] =\
    \ wp[i+1] * wp[i+1];\n            wm[i] = wm[i+1] * wm[i+1];\n        }\n    }\n\
    \    NTT () { set_ws(); }\n    void fft4(vector<mint> &a, int k){\n        uint\
    \ im = wm[2].val();\n        uint n = 1<<k;\n        uint len = n;\n        int\
    \ d = k;\n        while (len > 1){\n            if (d == 1){\n               \
    \ for (int i = 0; i < (1<<(k-1)); i++){\n                    a[i*2+0] += a[i*2+1];\n\
    \                    a[i*2+1]  = a[i*2+0] - a[i*2+1] * 2;\n                }\n\
    \                len >>= 1;\n                d -= 1;\n            }\n        \
    \    else {\n                int len4 = len/4;\n                int nlen = n/len;\n\
    \                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;\n         \
    \       for (int i = 0; i < len4; i++){\n                    for (int j = 0; j\
    \ < nlen; j++){\n                        uint a0 = a[len4*0+i + len*j].val();\n\
    \                        uint a1 = a[len4*1+i + len*j].val();\n              \
    \          uint a2 = a[len4*2+i + len*j].val();\n                        uint\
    \ a3 = a[len4*3+i + len*j].val();\n                        uint a0p2 = a0 + a2;\n\
    \                        uint a1p3 = a1 + a3;\n                        ull b0m2\
    \ = (a0 + mod - a2) * r1;\n                        ull b1m3 = (a1 + mod - a3)\
    \ * imr1;\n                        ull c0m2 = (a0 + mod - a2) * r3;\n        \
    \                ull c1m3 = (a1 + mod - a3) * imr3;\n                        a[len4*0+i\
    \ + len*j] = a0p2 + a1p3;\n                        a[len4*1+i + len*j] = b0m2\
    \ + b1m3;\n                        a[len4*2+i + len*j] = (a0p2 + mod*2 - a1p3)\
    \ * r2;\n                        a[len4*3+i + len*j] = c0m2 + mod2*2 - c1m3;\n\
    \                    }\n                    r1 = r1 * wm[d].val() % mod;\n   \
    \                 r2 = r1 * r1 % mod;\n                    r3 = r1 * r2 % mod;\n\
    \                    imr1 = im * r1 % mod;\n                    imr3 = im * r3\
    \ % mod;\n                }\n                len >>= 2;\n                d -=\
    \ 2;\n            }\n        }\n    }\n    void ifft4(vector<mint> &a, int k){\n\
    \        uint im = wp[2].val();\n        uint n = 1<<k;\n        uint len = (k\
    \ & 1 ? 2 : 4);\n        int d = (k & 1 ? 1 : 2);\n        while (len <= n){\n\
    \            if (d == 1){\n                for (int i = 0; i < (1<<(k-1)); i++){\n\
    \                    a[i*2+0] += a[i*2+1];\n                    a[i*2+1]  = a[i*2+0]\
    \ - a[i*2+1] * 2;\n                }\n                len <<= 2;\n           \
    \     d += 2;\n            }\n            else {\n                int len4 = len/4;\n\
    \                int nlen = n/len;\n                ull r1 = 1, r2 = 1, r3 = 1,\
    \ imr1 = im, imr3 = im;\n                for (int i = 0; i < len4; i++){\n   \
    \                 for (int j = 0; j < nlen; j++){\n                        ull\
    \ a0 = a[len4*0+i + len*j].val();\n                        ull a1 = a[len4*1+i\
    \ + len*j].val() * r1;\n                        ull a2 = a[len4*2+i + len*j].val()\
    \ * r2;\n                        ull a3 = a[len4*3+i + len*j].val() * r3;\n  \
    \                      ull b1 = a[len4*1+i + len*j].val() * imr1;\n          \
    \              ull b3 = a[len4*3+i + len*j].val() * imr3;\n                  \
    \      ull a0p2 = a0 + a2;\n                        ull a1p3 = a1 + a3;\n    \
    \                    ull a0m2 = a0 + mod2 - a2;\n                        ull b1m3\
    \ = b1 + mod2 - b3;\n                        a[len4*0+i + len*j] = a0p2 + a1p3;\n\
    \                        a[len4*1+i + len*j] = a0m2 + b1m3;\n                \
    \        a[len4*2+i + len*j] = a0p2 + mod2*2 - a1p3;\n                       \
    \ a[len4*3+i + len*j] = a0m2 + mod2*2 - b1m3;\n                    }\n       \
    \             r1 = r1 * wp[d].val() % mod;\n                    r2 = r1 * r1 %\
    \ mod;\n                    r3 = r1 * r2 % mod;\n                    imr1 = im\
    \ * r1 % mod;\n                    imr3 = im * r3 % mod;\n                }\n\
    \                len <<= 2;\n                d += 2;\n            }\n        }\n\
    \    }\n    vector<mint> multiply(const vector<mint> &a, const vector<mint> &b){\n\
    \        if (a.empty() || b.empty()) return {};\n        int d = a.size() + b.size()\
    \ - 1;\n        if (min<int>(a.size(), b.size()) <= 40){\n            vector<mint>\
    \ s(d);\n            rep(i,0,a.size()) rep(j,0,b.size()) s[i+j] += a[i]*b[j];\n\
    \            return s;\n        }\n        int k = 2, M = 4;\n        while (M\
    \ < d) M <<= 1, ++k;\n        vector<mint> s(M), t(M);\n        rep(i,0,a.size())\
    \ s[i] = a[i];\n        rep(i,0,b.size()) t[i] = b[i];\n        fft4(s,k);\n \
    \       fft4(t,k);\n        rep(i,0,M) s[i] *= t[i];\n        ifft4(s, k);\n \
    \       s.resize(d);\n        mint invm = mint(M).inv();\n        rep(i,0,d) s[i]\
    \ *= invm;\n        return s;\n    }\n};\n\n} // namespace lib\n#line 6 \"fps/fps.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class mint> struct FormalPowerSeries : std::vector<mint>\
    \ {\n  private:\n    using FPS = FormalPowerSeries<mint>;\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::vector::operator=;\n\n    NTT<mint> ntt;\n\n  public:\n\
    \    FormalPowerSeries(const std::vector<mint> &a) {\n        *this = a;\n   \
    \ }\n\n    FPS operator+(const FPS &rhs) const noexcept {\n        return FPS(*this)\
    \ += rhs;\n    }\n    FPS operator-(const FPS &rhs) const noexcept {\n       \
    \ return FPS(*this) -= rhs;\n    }\n    FPS operator*(const FPS &rhs) const noexcept\
    \ {\n        return FPS(*this) *= rhs;\n    }\n    FPS operator/(const FPS &rhs)\
    \ const noexcept {\n        return FPS(*this) /= rhs;\n    }\n    FPS operator%(const\
    \ FPS &rhs) const noexcept {\n        return FPS(*this) %= rhs;\n    }\n\n   \
    \ FPS operator+(const mint &rhs) const noexcept {\n        return FPS(*this) +=\
    \ rhs;\n    }\n    FPS operator-(const mint &rhs) const noexcept {\n        return\
    \ FPS(*this) -= rhs;\n    }\n    FPS operator*(const mint &rhs) const noexcept\
    \ {\n        return FPS(*this) *= rhs;\n    }\n    FPS operator/(const mint &rhs)\
    \ const noexcept {\n        return FPS(*this) /= rhs;\n    }\n\n    FPS &operator+=(const\
    \ FPS &rhs) noexcept {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] +=\
    \ rhs[i];\n        }\n        return *this;\n    }\n\n    FPS &operator-=(const\
    \ FPS &rhs) noexcept {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] -=\
    \ rhs[i];\n        }\n        return *this;\n    }\n\n    FPS &operator*=(const\
    \ FPS &rhs) noexcept {\n        *this = ntt.multiply(*this, rhs);\n        return\
    \ *this;\n    }\n\n    FPS &operator/=(const FPS &rhs) noexcept {\n        int\
    \ n = deg() - 1;\n        int m = rhs.deg() - 1;\n        if (n < m) {\n     \
    \       *this = {};\n            return *this;\n        }\n        *this = (*this).rev()\
    \ * rhs.rev().inv(n - m + 1);\n        (*this).resize(n - m + 1);\n        std::reverse((*this).begin(),\
    \ (*this).end());\n        return *this;\n    }\n\n    FPS &operator%=(const FPS\
    \ &rhs) noexcept {\n        *this -= *this / rhs * rhs;\n        shrink();\n \
    \       return *this;\n    }\n\n    FPS &operator+=(const mint &rhs) noexcept\
    \ {\n        if (this->empty()) this->resize(1);\n        (*this)[0] += rhs;\n\
    \        return *this;\n    }\n\n    FPS &operator-=(const mint &rhs) noexcept\
    \ {\n        if (this->empty()) this->resize(1);\n        (*this)[0] -= rhs;\n\
    \        return *this;\n    }\n\n    FPS &operator*=(const mint &rhs) noexcept\
    \ {\n        for (int i = 0; i < deg(); ++i) {\n            (*this)[i] *= rhs;\n\
    \        }\n        return *this;\n    }\n    FPS &operator/=(const mint &rhs)\
    \ noexcept {\n        mint inv_rhs = rhs.inv();\n        for (int i = 0; i < deg();\
    \ ++i) {\n            (*this)[i] *= inv_rhs;\n        }\n        return *this;\n\
    \    }\n\n    FPS operator>>(int d) const {\n        if (deg() <= d) return {};\n\
    \        FPS f = *this;\n        f.erase(f.begin(), f.begin() + d);\n        return\
    \ f;\n    }\n\n    FPS operator<<(int d) const {\n        FPS f = *this;\n   \
    \     f.insert(f.begin(), d, 0);\n        return f;\n    }\n\n    FPS operator-()\
    \ const {\n        FPS g(this->size());\n        for (int i = 0; i < (int)this->size();\
    \ i++) g[i] = -(*this)[i];\n        return g;\n    }\n\n    FPS pre(int sz) const\
    \ {\n        return FPS(this->begin(), this->begin() + std::min(deg(), sz));\n\
    \    }\n\n    FPS rev() const {\n        auto f = *this;\n        std::reverse(f.begin(),\
    \ f.end());\n        return f;\n    }\n\n    FPS differential() const {\n    \
    \    int n = deg();\n        FPS g(std::max(0, n - 1));\n        for (int i =\
    \ 0; i < n - 1; i++) {\n            g[i] = (*this)[i + 1] * (i + 1);\n       \
    \ }\n        return g;\n    }\n\n    FPS integral() const {\n        int n = deg();\n\
    \        FPS g(n + 1);\n        g[0] = 0;\n        if (n > 0) g[1] = 1;\n    \
    \    auto mod = mint::mod();\n        for (int i = 2; i <= n; i++) g[i] = (-g[mod\
    \ % i]) * (mod / i);\n        for (int i = 0; i < n; i++) g[i + 1] *= (*this)[i];\n\
    \        return g;\n    }\n\n    FPS inv(int d = -1) const {\n        int n =\
    \ 1;\n        if (d < 0) d = deg();\n        FPS g(n);\n        g[0] = (*this)[0].inv();\n\
    \        while (n < d) {\n            n <<= 1;\n            g = (g * 2 - g * g\
    \ * this->pre(n)).pre(n);\n        }\n        g.resize(d);\n        return g;\n\
    \    }\n\n    FPS log(int d = -1) const {\n        assert((*this)[0].val() ==\
    \ 1);\n        if (d < 0) d = deg();\n        return ((*this).differential() *\
    \ (*this).inv(d)).pre(d - 1).integral();\n    }\n\n    FPS exp(int d = -1) const\
    \ {\n        assert((*this)[0].val() == 0);\n        int n = 1;\n        if (d\
    \ < 0) d = deg();\n        FPS g(n);\n        g[0] = 1;\n        while (n < d)\
    \ {\n            n <<= 1;\n            g = (g * (this->pre(n) - g.log(n) + 1)).pre(n);\n\
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS pow(ll k,\
    \ int d = -1) const {\n        const int n = deg();\n        if (d < 0) d = n;\n\
    \        if (k == 0) {\n            FPS f(d);\n            if (d > 0) f[0] = 1;\n\
    \            return f;\n        }\n        for (int i = 0; i < n; i++) {\n   \
    \         if ((*this)[i].val() != 0) {\n                mint rev = (*this)[i].inv();\n\
    \                FPS f = (((*this * rev) >> i).log(d) * k).exp(d);\n         \
    \       f *= (*this)[i].pow(k);\n                f = (f << (i * k)).pre(d);\n\
    \                if (f.deg() < d) f.resize(d);\n                return f;\n  \
    \          }\n            if (i + 1 >= (d + k - 1) / k) break;\n        }\n  \
    \      return FPS(d);\n    }\n\n    int deg() const {\n        return (*this).size();\n\
    \    }\n\n    void shrink() {\n        while ((!this->empty()) && this->back()\
    \ == 0) this->pop_back();\n    }\n\n    int count_terms() const {\n        int\
    \ c = 0;\n        for (int i = 0; i < deg(); i++) {\n            if ((*this)[i]\
    \ != 0) c++;\n        }\n        return c;\n    }\n};\n\n}  // namespace lib\n\
    #line 5 \"fps/composition_of_fps.hpp\"\n\nnamespace lib {\n\ntemplate <class mint>\n\
    FormalPowerSeries<mint> composition_of_fps(const FormalPowerSeries<mint> &f, const\
    \ FormalPowerSeries<mint> &g) {\n    using FPS = FormalPowerSeries<mint>;\n  \
    \  int n = f.deg();\n    int k = 1;\n    while (k * k < n) k++;\n    std::vector<FPS>\
    \ baby(k + 1);\n    baby[0] = FPS{1};\n    baby[1] = g;\n    for (int i = 2; i\
    \ < k + 1; i++) {\n        baby[i] = (baby[i - 1] * g).pre(n);\n    }\n    std::vector<FPS>\
    \ giant(k + 1);\n    giant[0] = FPS{1};\n    giant[1] = baby[k];\n    for (int\
    \ i = 2; i < k + 1; i++) {\n        giant[i] = (giant[i - 1] * giant[1]).pre(n);\n\
    \    }\n    FPS h(n);\n    for (int i = 0; i < k + 1; i++) {\n        FPS a(n);\n\
    \        for (int j = 0; j < k; j++) {\n            if (k * i + j < n) {\n   \
    \             mint coef = f[k * i + j];\n                a += baby[j] * coef;\n\
    \            } else\n                break;\n        }\n        h += (giant[i]\
    \ * a).pre(n);\n    }\n    return h;\n}\n\n}  // namespace lib\n#line 9 \"test/polynomial/Composition_of_Formal_Power_Series.test.cpp\"\
    \n\nusing namespace lib;\nusing mint = modint998244353;\nusing FPS = FormalPowerSeries<mint>;\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    FPS f(n), g(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        std::cin >> f[i].val();\n    }\n    for (int i\
    \ = 0; i < n; i++) {\n        std::cin >> g[i].val();\n    }\n    FPS h = composition_of_fps(f,\
    \ g);\n    for (int i = 0; i < n; i++) {\n        std::cout << h[i].val() << \"\
    \ \\n\"[i == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n\n#include <iostream>\n\n#include \"../../convolution/ntt.hpp\"\n#include \"\
    ../../fps/composition_of_fps.hpp\"\n#include \"../../utility/modint.hpp\"\n\n\
    using namespace lib;\nusing mint = modint998244353;\nusing FPS = FormalPowerSeries<mint>;\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    FPS f(n), g(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        std::cin >> f[i].val();\n    }\n    for (int i\
    \ = 0; i < n; i++) {\n        std::cin >> g[i].val();\n    }\n    FPS h = composition_of_fps(f,\
    \ g);\n    for (int i = 0; i < n; i++) {\n        std::cout << h[i].val() << \"\
    \ \\n\"[i == n - 1];\n    }\n}"
  dependsOn:
  - convolution/ntt.hpp
  - template/template.hpp
  - utility/modint.hpp
  - fps/composition_of_fps.hpp
  - fps/fps.hpp
  - convolution/ntt4.hpp
  isVerificationFile: true
  path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  requiredBy: []
  timestamp: '2024-02-14 16:29:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Composition_of_Formal_Power_Series.test.cpp
- /verify/test/polynomial/Composition_of_Formal_Power_Series.test.cpp.html
title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
---

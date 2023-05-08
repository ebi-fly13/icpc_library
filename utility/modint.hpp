#include "../template/template.hpp"

namespace lib {

template <ll mod>
struct modint {
    ll a;

    modint(ll x = 0) : a((x % mod + mod) % mod) {}
    ll &val() {
        return a;
    }
    modint pow(ll n) {
        modint res = 1;
        modint x = a;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    modint inv() {
        return pow(mod-2);
    }
    constexpr modint &operator+=(const modint rhs) {
        a += rhs.a;
        if (a >= mod) a -= mod;
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) {
        if (a < rhs.a) a += mod;
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) {
        a = a * rhs.a % mod;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) {
        *this *= rhs.inv();
        return *this;
    }
    constexpr modint operator+(const modint rhs) {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) {
        return modint(*this) /= rhs;
    }
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1'000'000'007>;

}
#pragma once

#include "../template/template.hpp"

namespace lib {

template <ll m> struct modint {
    using mint = modint;
    ll a;

    modint(ll x = 0) : a((x % m + m) % m) {}
    static ll mod() {
        return m;
    }
    ll& val() {
        return a;
    }
    mint pow(ll n) {
        mint res = 1;
        mint x = a;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    mint inv() {
        return pow(m - 2);
    }
    mint& operator+=(const mint rhs) {
        a += rhs.a;
        if (a >= m) a -= m;
        return *this;
    }
    mint& operator-=(const mint rhs) {
        if (a < rhs.a) a += m;
        a -= rhs.a;
        return *this;
    }
    mint& operator*=(const mint rhs) {
        a = a * rhs.a % m;
        return *this;
    }
    mint& operator/=(mint rhs) {
        *this *= rhs.inv();
        return *this;
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1'000'000'007>;

}  // namespace lib
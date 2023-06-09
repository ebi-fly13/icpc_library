#pragma once

#include"../template/template.hpp"

namespace lib {

template <int id> struct dynamic_modint {
    using mint = dynamic_modint;
    ll a;
    static ll m;
    dynamic_modint (ll x = 0) : a((x % m + m) % m) {}
    static ll mod() {
        return m;
    }
    static void set_mod(ll mod){
        assert(1 <= mod);
        m = mod;
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

template<int id>
ll dynamic_modint<id>::m = 2;

} // namespace lib
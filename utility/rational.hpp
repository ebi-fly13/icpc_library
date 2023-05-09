#pragma once

#include"../template/template.hpp"

namespace lib{

struct rational{
    rational() : p(0), q(1) {}
    rational(ll n) : p(n), q(1) {}
    rational(ll n, ll m){
        assert(m != 0);
        if (m < 0) n = -n, m = -m;
        ll g = gcd(n,m);
        p = n / g; q = m / g;
    }
    ld val(){
        return ld(p) / ld(q);
    }
    rational& operator+=(const rational& rhs){
        ll g = gcd(q,rhs.q);
        ll np = rhs.q / g * p + q / g * rhs.p;
        ll nq = q / g * rhs.q;
        ll ng = gcd(np,nq);
        p = np/ng, q = nq/ng;
        return *this; 
    }
    rational& operator-=(const rational& rhs){
        (*this) += rational(-rhs.p,rhs.q);
        return *this;
    }
    rational& operator*=(const rational& rhs){
        ll g1 = gcd(q,rhs.p), g2 = gcd(p,rhs.q);
        ll np = p / g2 * rhs.p / g1;
        ll nq = q / g1 * rhs.q / g2;
        p = np, q = nq;
        return *this;
    }
    rational& operator/=(const rational& rhs){
        (*this) *= rational(rhs.q,rhs.p);
        return *this;
    }
    rational operator+() const {return *this;}
    rational operator-() const {return rational() - *this;}
    friend rational operator+(const rational& lhs, const rational& rhs) {
        return rational(lhs) += rhs;
    }
    friend rational operator-(const rational& lhs, const rational& rhs) {
        return rational(lhs) -= rhs;
    }
    friend rational operator*(const rational& lhs, const rational& rhs) {
        return rational(lhs) *= rhs;
    }
    friend rational operator/(const rational& lhs, const rational& rhs) {
        return rational(lhs) /= rhs;
    }
    friend bool operator==(const rational& lhs, const rational& rhs) {
        return lhs.p == rhs.p && lhs.q == rhs.q;
    }
    friend bool operator!=(const rational& lhs, const rational& rhs) {
        return lhs.p != rhs.p || lhs.q != rhs.q;
    }
    friend bool operator< (const rational lhs, const rational rhs) {
        return less_than(lhs,rhs);
    }
    friend bool operator> (const rational lhs, const rational rhs) {
        return less_than(rhs,lhs);
    }
    friend bool operator<= (const rational lhs, const rational rhs) {
        return lhs == rhs || lhs < rhs;
    }
    friend bool operator>= (const rational lhs, const rational rhs) {
        return lhs == rhs || lhs > rhs;
    }
    friend std::ostream &operator<<(std::ostream &os,const rational&r) {
        return os << r.p << " / " << r.q;
    }
  private:
    ll p, q;
    static bool less_than(rational lhs, rational rhs){
        __int128_t lv = __int128_t(lhs.p) * __int128_t(rhs.q);
        __int128_t rv = __int128_t(lhs.q) * __int128_t(rhs.p);
        return lv < rv;
    }
};


} // namespace lib
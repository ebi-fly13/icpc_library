#pragma once

#include"../template/template.hpp"

namespace lib {

template<typename T>
struct Vec {
    T x, y;
    Vec (T _x = T(0), T _y = T(0)) : x(_x), y(_y) {}
    Vec& operator*=(const T& a){
        x *= a;
        y *= a;
        return *this;
    }
    Vec& operator/=(const T& a){
        x /= a;
        y /= a;
        return *this;
    }
    Vec& operator+=(const Vec& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vec& operator-=(const Vec& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    friend Vec operator+(const Vec& lhs, const Vec& rhs) {
        return Vec(lhs) += rhs;
    }
    friend Vec operator-(const Vec& lhs, const Vec& rhs) {
        return Vec(lhs) -= rhs;
    }
    friend Vec operator*(const Vec& lhs, const T& rhs) {
        return Vec(lhs) *= rhs;
    }
    friend Vec operator*(const T& rhs, const Vec& lhs) {
        return Vec(lhs) *= rhs;
    }
    friend Vec operator/(const Vec& lhs, const T& rhs) {
        return Vec(lhs) /= rhs;
    }
    friend Vec operator/(const T& rhs, const Vec& lhs) {
        return Vec(lhs) /= rhs;
    }
    ld norm(){
        return sqrtl(ld(x*x+y*y));
    }
    T norm2(){
        return x*x+y*y;
    }
};

template<typename T>
T dot(const Vec<T> &a, const Vec<T> &b){
    return a.x * b.x + a.y * b.y;
}

// cross > 0 : counter clockwise a -> b
template<typename T>
T cross(const Vec<T> &a, const Vec<T> &b){
    return a.x * b.y - a.y * b.x;
}

// e : vec(OX)
// orthant k : [ pi/2 * k, pi/2 * (k+1) ) rad
// orthant 4 is NOT expected
template<typename T>
int orthant(const Vec<T> &e, const Vec<T> &p){
    T _dot = dot(e,p), _cross = cross(e,p);
    if (_dot >  0 && _cross >= 0) return 0;
    if (_dot <= 0 && _cross >  0) return 1;
    if (_dot <  0 && _cross <= 0) return 2;
    if (_dot >= 0 && _cross <  0) return 3;
    return 4;
}

// usage : 
//   vector<Vec<ll>> vec;
//   sort(vec.begin(),vec.end(),comp_for_argument_sort<ll>);
template<typename T>
bool comp_for_argument_sort(const Vec<T> &lhs, const Vec<T> &rhs){
    int pl = orthant(Vec<T>(1,0),lhs), pr = orthant(Vec<T>(1,0),rhs);
    if (pl == pr){
        return cross(lhs,rhs) > 0;
    }
    return pl < pr;
}

// DISTINCT points are given
// ans[0] --- ans[1] --- ... --- ans[k-1] --- ans[k] --- ans[0]
// upper_hull --- lower_hull
// upper_hull : x is from small to large
// lower hull : x is from large to small
// points rearranged clockwise
template<typename T>
vector<Vec<T>> convex_hull(vector<Vec<T>> a){
    int n = a.size();
    if (n <= 2) return a;
    using vec = Vec<T>;
    auto comp = [&](vec lhs, vec rhs){
        if (lhs.x == rhs.x) return lhs.y < rhs.y;
        return lhs.x < rhs.x;
    };
    sort(all(a),comp);
    stack<int> uid, did;
    uid.push(0);
    vec ri = a[n-1];
    rep(i,1,n-1) {
        vec le = a[uid.top()];
        if (cross(ri-le,a[i]-le) > 0){
            while (uid.size() >= 2){
                int test = uid.top(); uid.pop();
                vec from = a[uid.top()];
                if (cross(a[i]-from,a[test]-from) > 0){
                    uid.push(test);
                    break;
                }
            }
            uid.push(i);
        }
    }
    did.push(0);
    rep(i,1,n-1){
        vec le = a[did.top()];
        if (cross(ri-le,a[i]-le) < 0){
            while (did.size() >= 2){
                int test = did.top(); did.pop();
                vec from = a[did.top()];
                if (cross(a[i]-from,a[test]-from) < 0){
                    did.push(test);
                    break;
                }
            }
            did.push(i);
        }
    }
    vector<int> ids(1,n-1);
    while (!uid.empty()) ids.emplace_back(uid.top()), uid.pop();
    reverse(all(ids));
    while (!did.empty()) ids.emplace_back(did.top()), did.pop();
    vector<vec> ans(ids.size());
    rep(i,0,ids.size()) ans[i] = a[ids[i]];
    return ans;
}

} // namespace lib
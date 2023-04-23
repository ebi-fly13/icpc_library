#pragma once

#include"../template/template.hpp"

namespace lib {

using vec = complex<ll>;

ll dot(const vec &a, const vec &b){
    return (conj(a) * b).real();
}

ll cross(const vec &a, const vec &b){
    return (conj(a) * b).imag();
}

// e : vec(OX)
// orthant k : [ pi/2 * k, pi/2 * (k+1) ) rad
// orthant 4 is NOT expected
int orthant(const vec &p, const vec &e = vec(1,0)){
    ll _dot = dot(e,p), _cross = cross(e,p);
    if (_dot >  0 && _cross >= 0) return 0;
    if (_dot <= 0 && _cross >  0) return 1;
    if (_dot <  0 && _cross <= 0) return 2;
    if (_dot >= 0 && _cross <  0) return 3;
    return 4;
}

// usage : 
//   vector<vec>> a;
//   sort(all(a),comp_for_argument_sort);
bool comp_for_argument_sort(const vec &lhs, const vec &rhs){
    int pl = orthant(lhs), pr = orthant(rhs);
    if (pl == pr){
        return cross(lhs,rhs) > 0;
    }
    return pl < pr;
}

vector<vec> convex_hull(vector<vec> a){
    int n = a.size();
    if (n <= 2) return a;
    auto comp = [&](vec lhs, vec rhs){
        if (lhs.real() == rhs.real()) return lhs.imag() < rhs.imag();
        return lhs.real() < rhs.real();
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

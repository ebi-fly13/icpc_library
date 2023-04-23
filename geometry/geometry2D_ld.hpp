#pragma once

#include"../template/template.hpp"

namespace lib {

void ldout(){
    cout << fixed << setprecision(20);
}

using vec = complex<ld>;
const ld eps = 1e-7;

ld dot(const vec &a, const vec &b){
    return (conj(a) * b).real();
}

ld cross(const vec &a, const vec &b){
    return (conj(a) * b).imag();
}

void rot(vec &a, ld rad){
    a *= vec(cosl(rad),sinl(rad));
}

bool comp_for_argument_sort(const vec &lhs, const vec &rhs){
    //if (abs(arg(lhs)-arg(rhs)) < eps) return false; // need ?
    return arg(lhs) < arg(rhs);
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

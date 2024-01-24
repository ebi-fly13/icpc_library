#pragma once

#include "../geometry/base_ld.hpp"
#include "../template/template.hpp"



vector<vec> convex_hull(vector<vec> a) {
    int n = a.size();
    if (n <= 2) return a;
    auto comp = [&](vec lhs, vec rhs) {
        if (lhs.real() == rhs.real()) return lhs.imag() < rhs.imag();
        return lhs.real() < rhs.real();
    };
    sort(all(a), comp);
    stack<int> uid, did;
    vec ri = a[n - 1];
    auto make_half = [&](bool isupper) {
        auto &id = (isupper ? uid : did);
        id.push(0);
        rep(i, 1, n - 1) {
            vec le = a[id.top()];
            auto cr = cross(ri - le, a[i] - le);
            if ((cr > 0 && isupper) || (cr < 0 && !isupper)) {
                while (id.size() >= 2) {
                    int test = id.top();
                    id.pop();
                    vec from = a[id.top()];
                    auto cr2 = cross(a[i] - from, a[test] - from);
                    if ((cr2 > 0 && isupper) || (cr2 < 0 && !isupper)) {
                        id.push(test);
                        break;
                    }
                }
                id.push(i);
            }
        }
    };
    make_half(true);
    make_half(false);
    vector<int> ids(1, n - 1);
    while (!did.empty()) ids.emplace_back(did.top()), did.pop();
    reverse(all(ids));
    while (!uid.empty()) ids.emplace_back(uid.top()), uid.pop();
    ids.pop_back();
    vector<vec> ans(ids.size());
    rep(i, 0, ids.size()) ans[i] = a[ids[i]];
    return ans;
}


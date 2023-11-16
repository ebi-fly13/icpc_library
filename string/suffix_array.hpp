#pragma once

#include "../template/template.hpp"

namespace lib {

vector<int> suffix_array(const string &s) {
    int n = s.size();
    vector<int> rnk(n, -1), sa(n);
    iota(all(sa), 0);
    rep(i, 0, n) {
        rnk[i] = s[i];
    }
    int k = 1;
    auto compare = [&](int i, int j) -> bool {
        if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
        return (i + k < n ? rnk[i + k] : -1) < (j + k < n ? rnk[j + k] : -1);
    };
    while (k < n) {
        sort(all(sa), compare);
        vector<int> tmp(n, 0);
        rep(i, 1, n) {
            tmp[sa[i]] = tmp[sa[i - 1]] + int(compare(sa[i - 1], sa[i]));
        }
        swap(rnk, tmp);
        k <<= 1;
    }
    return sa;
}

vector<int> lcp_array(const string &s, const vector<int> &sa) {
    int n = s.size();
    vector<int> rnk(n), lcp(n - 1);
    rep(i, 0, n) rnk[sa[i]] = i;
    int h = 0;
    rep(i, 0, n) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
            h++;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

}  // namespace lib
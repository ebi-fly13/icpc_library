#pragma once

#include "../tree/HeavyLightDecomposition.hpp"



using namespace std;

vector<pair<int, int>> HeavyLightDecomposition::lca_based_auxiliary_tree(
    vector<int> vs) {
    if (vs.empty()) return {};
    sort(all(vs), [&](int u, int v) { return in[u] < in[v]; });
    auto s = vs;
    for (int i = 1; i < int(vs.size()); i++) {
        s.emplace_back(lca(vs[i - 1], vs[i]));
    }
    std::sort(all(s), [&](int u, int v) { return in[u] < in[v]; });
    s.erase(unique(all(s)), s.end());
    stack<int> st;
    st.push(s[0]);
    int sz = s.size();
    std::vector<std::pair<int, int>> dfs_order(sz);
    dfs_order[0] = {s[0], -1};
    rep(i, 1, sz) {
        int v = s[i];
        while (!st.empty()) {
            int u = st.top();
            if (in[u] <= in[v] && in[v] < out[u]) {
                break;
            } else {
                st.pop();
            }
        }
        assert(!st.empty());
        int par = st.top();
        dfs_order[i] = {v, par};
        st.push(v);
    }
    return dfs_order;
}


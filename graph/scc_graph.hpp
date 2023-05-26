#pragma once

#include "../template/template.hpp"

namespace lib {

struct scc_graph {
    vector<vector<int>> g, rg;
    int n, k;

    vector<int> vs, cmp;
    vector<int> seen;

    void dfs(int v) {
        seen[v] = 1;
        for (auto &nv : g[v]) {
            if (seen[nv] < 0) dfs(nv);
        }
        vs.emplace_back(v);
    }

    void rdfs(int v) {
        cmp[v] = k;
        for (auto nv : rg[v]) {
            if (cmp[nv] < 0) rdfs(nv);
        }
    }

    scc_graph(int n) : n(n) {
        g.resize(n);
        rg.resize(n);
    }

    void add_edge(int from, int to) {
        g[from].emplace_back(to);
        rg[to].emplace_back(from);
    }

    void scc() {
        seen.assign(n, -1);
        rep(i, 0, n) {
            if (seen[i] < 0) dfs(i);
        }
        reverse(all(vs));
        cmp.assign(n, -1);
        k = 0;
        for (auto &v : vs) {
            if (cmp[v] < 0) {
                rdfs(v);
                k++;
            }
        }
    }

    bool same(int u, int v) {
        return cmp[u] == cmp[v];
    }

    vector<int> scc_id() {
        return cmp;
    }

    vector<vector<int>> create_graph() {
        vector<vector<int>> t(k);
        rep(i, 0, n) {
            int v = cmp[i];
            for (auto to : g[i]) {
                int nv = cmp[to];
                if (v == nv) continue;
                t[v].emplace_back(nv);
            }
        }
        rep(i, 0, k) {
            sort(all(t[i]));
            t[i].erase(unique(all(t[i])), t[i].end());
        }
        return t;
    }
};

}
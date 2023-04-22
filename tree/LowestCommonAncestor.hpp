#pragma once

#include "../template/template.hpp"

namespace lib {

struct LowestCommonAncestor {
    int n;
    std::vector<std::vector<int>> table;
    std::vector<int> depth;
    int log = 25;

    LowestCommonAncestor(const std::vector<std::vector<int>> &gh, int root = 0) : n(gh.size()) {
        table = std::vector(log, std::vector<int>(n, -1));
        depth.assign(n, 0);
        auto dfs = [&](auto &&self, int v) -> void {
            for (auto nv : gh[v]) {
                if (table[0][v] == nv) continue;
                table[0][nv] = v;
                depth[nv] = depth[v] + 1;
                self(self, nv);
            }
        };
        dfs(dfs, root);
        table[0][root] = root;
        rep(i, 0, log - 1) {
            rep(v, 0, n) { table[i + 1][v] = table[i][table[i][v]]; }
        }
    }

    int la(int u, int k) const {
        if(depth[u] < k) return -1;
        rrep(i, 0, log) {
            if ((k >> i) & 1) {
                u = table[i][u];
            }
        }
        return u;
    }

    int lca(int u, int v) const {
        if (depth[u] < depth[v]) std::swap(u, v);
        u = la(u, depth[u] - depth[v]);
        if (u == v) return u;
        rrep(i, 0, log) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int distance(int u, int v) const {
        int l = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[l];
    };
};

}  // namespace lib
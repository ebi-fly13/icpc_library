#pragma once

#include "../template/template.hpp"
#include "../graph/scc_graph.hpp"

namespace lib {

struct two_sat {
    two_sat(int n) : n(n), scc(2 * n), _ans(n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < n);
        assert(0 <= j && j < n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }

    bool satisfiable() {
        scc.scc();
        auto id = scc.scc_id();
        rep(i, 0, n) {
            if (scc.same(2 * i, 2 * i + 1)) return false;
            _ans[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }

    vector<bool> ans() {
        return _ans;
    }
    int n;
    scc_graph scc;
    vector<bool> _ans;
};

}  // namespace lib
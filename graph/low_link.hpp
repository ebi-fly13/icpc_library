#pragma once
#include "../template/template.hpp"



struct low_link {
    low_link(const std::vector<std::vector<int>> &g) : n(g.size()), ord(n, -1), low(n), par(n,-1) {
        int k = 0;
        auto dfs = [&](auto &&self, int v) -> void {
            low[v] = ord[v] = k++;
            int cnt = 0;
            bool is_arti = false, is_second = false;
            for(auto nv: g[v]) {
                if(ord[nv] == -1) {
                    cnt++;
                    par[nv] = v;
                    self(self, nv);
                    chmin(low[v], low[nv]);
                    is_arti |= par[v] != -1 && low[nv] >= ord[v];
                    if(ord[v] < low[nv]) {
                        _bridge.emplace_back(std::minmax(v, nv));
                    }
                }
                else if(nv != par[v] || is_second) {
                    chmin(low[v], ord[nv]);
                }
                else {
                    is_second = true;
                }
            }
            is_arti |= par[v] == -1 && cnt > 1;
            if(is_arti) _articulation.emplace_back(v);
        };
        dfs(dfs, 0);
    }

    bool is_bridge(int u, int v) {
        if(par[v] != u) std::swap(u, v);
        if(par[v] != u) return false;
        return ord[u] < low[v];
    }

    std::vector<std::pair<int,int>> bridge() {
        return _bridge;
    }

    std::vector<int> articulation() {
        return _articulation;
    }
    
    int n;
    std::vector<int> ord, low, par, _articulation;
    std::vector<std::pair<int,int>> _bridge;
};

}
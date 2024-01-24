#pragma once
#include "../template/template.hpp"


using namespace std;

template <typename fa> struct FordFulkerson {
    struct edge {
        int to;
        fa cap;
        int rev;
        bool isrev;
    };

    const fa INF;
    vector<vector<edge>> g;
    vector<int> used;
    int ts;

    explicit FordFulkerson(int v)
        : INF(numeric_limits<fa>::max()), g(v), used(v, -1), ts(0) {}

    void add_edge(int from, int to, fa cap) {
        g[from].push_back((edge){to, cap, (int)g[to].size(), false});
        g[to].push_back((edge){from, 0, (int)g[from].size() - 1, true});
    }
    fa dfs(int v, int t, fa flow) {
        if (v == t) return flow;
        used[v] = ts;
        for (auto &e : g[v]) {
            if (e.cap > 0 && used[e.to] != ts) {
                fa d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    fa flow(int s, int t) {
        fa ret = 0;
        for (fa f; (f = dfs(s, t, INF)) > 0; ts++) ret += f;
        ts++;
        return ret;
    }
};



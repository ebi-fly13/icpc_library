#pragma once
#include "../template/template.hpp"

namespace lib{
using namespace std;

template<typename ft>
struct FordFulkerson {
    struct edge {int to; ft cap; int rev; bool isrev;};

    const ft INF;
    vector<vector<edge>> g;
    vector<int> used;
    int ts;

    explicit FordFulkerson(int V) : INF(numeric_limits<ft>::max()), g(V), used(V,-1), ts(0) {}

    void add_edge(int from, int to, ft cap) {
        g[from].push_back((edge){to, cap, (int)g[to].size(), false});
        g[to].push_back((edge){from, 0, (int)g[from].size()-1, true});
    }

    ft dfs(int v, const int t, ft f) {
        if(v == t) return f;
        used[v] = ts;
        for(auto &e: g[v]) {
            if(e.cap > 0 && used[e.to] != ts) {
                ft d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ft flow(int s, int t) {
        ft ret = 0;
        for(ft f; (f=dfs(s,t,INF))>0; ts++) ret += f;
        ts++;
        return ret;
    }
};

}

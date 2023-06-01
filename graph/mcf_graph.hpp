#pragma once
#include "../template/template.hpp"

namespace lib {
using namespace std;

struct MinCostFlow {
    int n;
    vector<vector<vector<ll>>> g;
    vector<ll> h, dis;
    vector<int> pv, pe;

    MinCostFlow(int v) : n(v), g(v), dis(v), pv(v), pe(v) {}

    void add_edge(int from, int to, ll cap, ll cost) {
        g[from].push_back({to, cap, cost, (int)g[to].size()});
        g[to].push_back({from, 0, -cost, (int)g[from].size()-1});
    }

    ll flow(int s, int t, ll f) {
        ll res = 0;
        h.assign(n, 0);
        using Q = pair<ll, int>;
        while (f > 0) {
            priority_queue<Q, vector<Q>, greater<Q>> que;
            dis.assign(n, LLONG_MAX);
            dis[s] = 0;
            que.push({0, s});
            while (que.size()) {
                Q q = que.top();
                int v = q.second;
                que.pop();
                if (dis[v] < q.first) continue;
				rep(i,0,g[v].size()){
                    auto edge = g[v][i];
                    int to = edge[0];
                    ll cap = edge[1], cost = edge[2];
                    if (cap > 0 and dis[to] > dis[v] + cost + h[v] - h[to]) {
                        dis[to] = dis[v] + cost + h[v] - h[to];
                        pv[to] = v;
                        pe[to] = i;
                        que.push({dis[to], to});
                    }
                }
            }
            if (dis[t] == LLONG_MAX) return -1;
            rep(i,0,n) h[i] += dis[i];
            ll d = f;
            for (int i=t; i!=s; i=pv[i]) d = min(d, g[pv[i]][pe[i]][1]);
            f -= d;
            res += d * h[t];
            for (int i=t; i!=s; i=pv[i]) {
                auto& edge = g[pv[i]][pe[i]];
                edge[1] -= d;
                g[i][edge[3]][1] += d;
            }
        }
        return res;
    }
};

}

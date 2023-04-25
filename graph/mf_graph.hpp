#pragma once
#include "../template/template.hpp"

namespace lib{
using namespace std;

template <class Cap> struct mf_graph {
    struct edge{
        int from, to;
        Cap cap, flow;
    };

    struct nedge{
        int to, rev;
        Cap cap;
    };

    int nn;
    vector<pair<int, int>> pos;
    vector<vector<nedge>> g;

    mf_graph() : nn(0) {}
    explicit mf_graph(int n) : nn(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        int m = pos.size();
        pos.push_back({from, int(g[from].size())});
        int frid = int(g[from].size());
        int toid = int(g[to].size());
        if (from == to) toid++;
        g[from].push_back(nedge{to, toid, cap});
        g[to].push_back(nedge{from, frid, 0});
        return m;
    }

	
    Cap flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }

    Cap flow(int s, int t, Cap flow_limit) {
        vector<int> lv(nn), iter(nn);
        queue<int> q;

        auto bfs = [&]() {
            fill(all(lv), -1);
            lv[s] = 0;
            queue<int>().swap(q);
            q.push(s);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || lv[e.to] >= 0) continue;
                    lv[e.to] = lv[v] + 1;
                    if (e.to == t) return;
                    q.push(e.to);
                }
            }
        };

        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int lvvv = lv[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                nedge& e = g[v][i];
                if (lvvv <= lv[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            lv[v] = nn;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (lv[t] == -1) break;
            fill(all(iter), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

	/*
	
    if you want other functions, take from here
    NOT VERIFIED.

    edge get_edge(int i) {
        int m = int(pos.size());
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    
    vector<edge> edges() {
        int m = int(pos.size());
        vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }

    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    std::vector<bool> min_cut(int s) {
        vector<bool> visited(_n);
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return visited;
    }
	
	*/
};

}

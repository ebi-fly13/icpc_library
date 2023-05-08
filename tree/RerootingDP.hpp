#pragma once

#include "../template/template.hpp"

namespace lib {

template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int),
          V (*put_vertex)(E, int)>
struct Rerooting {
    struct edge {
        int to, idx, xdi;
    };
    Rerooting(int _n = 0) : n(_n) { es.resize(n); }
    void add_edge(int u, int v, int idx1, int idx2) {
        es[u].push_back({v, idx1, idx2});
        es[v].push_back({u, idx2, idx1});
    }
    vector<V> build(int v = 0) {
        root = v;
        outs.resize(n);
        subdp.resize(n);
        in.resize(n), up.resize(n);
        int tnow = 0;
        dfs(root, -1, tnow);
        return subdp;
    }
    vector<V> reroot() {
        reverse_edge.resize(n);
        reverse_edge[root] = e();
        reverse_dp.resize(n);
        answers.resize(n);
        bfs(root);
        return answers;
    }
    V get(int r, int v) {
        if (r == v) return answers[r];
        if (!(in[v] < in[r] && up[r] <= up[v])) return subdp[v];
        int le = 0, ri = outs[v].size();
        while (ri - le > 1) {
            int md = (le + ri) / 2;
            if (in[es[v][md].to] <= in[r])
                le = md;
            else
                ri = md;
        }
        return reverse_dp[es[v][le].to];
    }
    const vector<edge> &operator[](int idx) const { return es[idx]; }

  private:
    int n, root;
    vector<vector<edge>> es;
    vector<vector<E>> outs;
    vector<E> reverse_edge;
    vector<V> subdp, reverse_dp, answers;
    vector<int> in, up;
    void dfs(int v, int p, int &t) {
        E val = e();
        in[v] = t++;
        for (auto &u : es[v]) {
            if (u.to == p && u.to != es[v].back().to) swap(u, es[v].back());
            if (u.to == p) continue;
            dfs(u.to, v, t);
            E nval = put_edge(subdp[u.to], u.idx);
            outs[v].emplace_back(nval);
            val = merge(val, nval);
        }
        subdp[v] = put_vertex(val, v);
        up[v] = t;
    }
    void bfs(int v) {
        int siz = outs[v].size();
        vector<E> lui(siz + 1), rui(siz + 1);
        lui[0] = e(), rui[siz] = e();
        for (int i = 0; i < siz; i++) lui[i + 1] = merge(lui[i], outs[v][i]);
        for (int i = siz - 1; i >= 0; i--)
            rui[i] = merge(outs[v][i], rui[i + 1]);
        for (int i = 0; i < siz; i++) {
            reverse_dp[es[v][i].to] = put_vertex(
                merge(merge(lui[i], rui[i + 1]), reverse_edge[v]), v);
            reverse_edge[es[v][i].to] =
                put_edge(reverse_dp[es[v][i].to], es[v][i].xdi);
            bfs(es[v][i].to);
        }
        answers[v] = put_vertex(merge(lui[siz], reverse_edge[v]), v);
    }
};

}  // namespace lib

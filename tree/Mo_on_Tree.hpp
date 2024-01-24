#pragma once

#include"../template/template.hpp"
#include"../misc/mo_algorithm.hpp"

/*

MoTree_edge is verified with : https://atcoder.jp/contests/pakencamp-2022-day1/submissions/43052952

*/

namespace lib{

template<class T>
struct MoTree_edge {
    int n;
    vector<vector<pair<int,T>>> es;
    MoTree_edge (int _n) : n(_n) {
        es.resize(n);
    }
    void add_edge(int u, int v, T w){
        es[u].emplace_back(v,w);
        es[v].emplace_back(u,w);
    }
    vector<int> in;
    vector<pair<int,T>> vals;
    Mo mo;
    void build(int q){
        int tnow = 0;
        auto dfs = [&](auto dfs, int v, int f) -> void {
            in[v] = tnow++;
            for (auto [u, w] : es[v]){
                if (u == f) continue;
                vals.emplace_back(u,w);
                dfs(dfs,u,v);
                vals.emplace_back(u,w);
                tnow++;
            }
        };
        in.resize(n);
        dfs(dfs,0,-1);
        mo = Mo(2*n-2,q);
    }
    void insert(int u, int v){
        u = in[u], v = in[v];
        if (u > v) swap(u,v);
        mo.insert(u,v);
    }
    template<typename ADD, typename DEL, typename REM>
    void run(const ADD &add, const DEL &del, const REM &rem){
        vector<bool> contain(n,false);
        auto change = [&](int i){
            int id = vals[i].first;
            if (contain[id]){
                del(vals[i].second);
                contain[id] = false;
            }
            else {
                add(vals[i].second);
                contain[id] = true;
            }
        };
        mo.run(change,change,change,change,rem);
    }
};


template<class T>
struct MoTree_vertex {
    int n;
    vector<vector<int>> es;
    vector<T> b;
    MoTree_vertex (int _n, vector<T> _b) : n(_n), b(_b) {
        es.resize(n);
    }
    void add_edge(int u, int v){
        es[u].emplace_back(v);
        es[v].emplace_back(u);
    }
    vector<int> in;
    vector<pair<int,T>> vals;
    vector<int> lcas;
    Mo mo;
    void build(int q){
        vals.reserve(2*n-2);
        lcas.reserve(q);
        int tnow = 0;
        auto dfs = [&](auto dfs, int v, int f) -> void {
            in[v] = tnow++;
            for (auto u : es[v]){
                if (u == f) continue;
                vals.emplace_back(u,b[u]);
                dfs(dfs,u,v);
                vals.emplace_back(u,b[u]);
                tnow++;
            }
        };
        in.resize(n);
        dfs(dfs,0,-1);
        mo = Mo(2*n-2,q);
    }
    
    void insert(int u, int v, int lca){
        u = in[u], v = in[v];
        if (u > v) swap(u,v);
        mo.insert(u,v);
        lcas.push_back(lca);
    }
    template<typename ADD, typename DEL, typename REM>
    void run(const ADD &add, const DEL &del, const REM &rem){
        vector<bool> contain(n,false);
        auto change = [&](int i){
            int id = vals[i].first;
            if (contain[id]){
                del(vals[i].second);
                contain[id] = false;
            }
            else {
                add(vals[i].second);
                contain[id] = true;
            }
        };
        auto rem_add_lca = [&](int i){
            add(b[lcas[i]]);
            rem(i);
            del(b[lcas[i]]);
        };
        mo.run(change,change,change,change,rem_add_lca);
    }
};


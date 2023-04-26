---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/RerootingDP.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib{\n\nusing namespace std;\n\n} // namespace\
    \ lib;\n\n//using namespace lib;\n#line 4 \"tree/RerootingDP.hpp\"\n\nnamespace\
    \ lib {\n\ntemplate<class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V,\
    \ int), V (*put_vertex)(E, int)>\nstruct Rerooting {\n    struct edge{\n     \
    \   int to, idx, xdi;\n    };\n    Rerooting (int _n = 0) : n(_n) { es.resize(n);}\n\
    \    void add_edge(int u, int v, int idx1, int idx2){\n        es[u].push_back({v,idx1,idx2});\n\
    \        es[v].push_back({u,idx2,idx1});\n    }\n    vector<V> build(int v = 0){\n\
    \        root = v;\n        outs.resize(n);\n        subdp.resize(n);\n      \
    \  in.resize(n), up.resize(n);\n        int tnow = 0;\n        dfs(root,-1,tnow);\n\
    \        return subdp;\n    }\n    vector<V> reroot(){\n        reverse_edge.resize(n);\n\
    \        reverse_edge[root] = e();\n        reverse_dp.resize(n);\n        answers.resize(n);\n\
    \        bfs(root);\n        return answers;\n    }\n    V get(int r, int v){\n\
    \        if (r == v) return answers[r];\n        if (!(in[v] < in[r] && up[r]\
    \ <= up[v])) return subdp[v];\n        int le = 0, ri = outs[v].size();\n    \
    \    while (ri - le > 1){\n            int md = (le + ri) / 2;\n            if\
    \ (in[es[v][md].to] <= in[r]) le = md;\n            else ri = md;\n        }\n\
    \        return reverse_dp[es[v][le].to];\n    }\n    const vector<edge>& operator[](int\
    \ idx) const { return es[idx]; }\n  private:\n    int n, root;\n    vector<vector<edge>>\
    \ es;\n    vector<vector<E>> outs;\n    vector<E> reverse_edge;\n    vector<V>\
    \ subdp, reverse_dp, answers;\n    vector<int> in, up;\n    void dfs(int v, int\
    \ p, int &t){\n        E val = e();\n        in[v] = t++;\n        for (auto &u\
    \ : es[v]){\n            if (u.to == p && u.to != es[v].back().to) swap(u,es[v].back());\n\
    \            if (u.to == p) continue;\n            dfs(u.to,v,t);\n          \
    \  E nval = put_edge(subdp[u.to],u.idx);\n            outs[v].emplace_back(nval);\n\
    \            val = merge(val,nval);\n        }\n        subdp[v] = put_vertex(val,v);\n\
    \        up[v] = t;\n    }\n    void bfs(int v){\n        int siz = outs[v].size();\n\
    \        vector<E> lui(siz+1), rui(siz+1);\n        lui[0] = e(), rui[siz] = e();\n\
    \        for (int i = 0; i < siz; i++) lui[i+1] = merge(lui[i],outs[v][i]);\n\
    \        for (int i = siz-1; i >= 0; i--) rui[i] = merge(outs[v][i],rui[i+1]);\n\
    \        for (int i = 0; i < siz; i++){\n            reverse_dp[es[v][i].to] =\
    \ put_vertex(merge(merge(lui[i],rui[i+1]),reverse_edge[v]),v);\n            reverse_edge[es[v][i].to]\
    \ = put_edge(reverse_dp[es[v][i].to],es[v][i].xdi);\n            bfs(es[v][i].to);\n\
    \        }\n        answers[v] = put_vertex(merge(lui[siz],reverse_edge[v]), v);\n\
    \    }\n};\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate<class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int),\
    \ V (*put_vertex)(E, int)>\nstruct Rerooting {\n    struct edge{\n        int\
    \ to, idx, xdi;\n    };\n    Rerooting (int _n = 0) : n(_n) { es.resize(n);}\n\
    \    void add_edge(int u, int v, int idx1, int idx2){\n        es[u].push_back({v,idx1,idx2});\n\
    \        es[v].push_back({u,idx2,idx1});\n    }\n    vector<V> build(int v = 0){\n\
    \        root = v;\n        outs.resize(n);\n        subdp.resize(n);\n      \
    \  in.resize(n), up.resize(n);\n        int tnow = 0;\n        dfs(root,-1,tnow);\n\
    \        return subdp;\n    }\n    vector<V> reroot(){\n        reverse_edge.resize(n);\n\
    \        reverse_edge[root] = e();\n        reverse_dp.resize(n);\n        answers.resize(n);\n\
    \        bfs(root);\n        return answers;\n    }\n    V get(int r, int v){\n\
    \        if (r == v) return answers[r];\n        if (!(in[v] < in[r] && up[r]\
    \ <= up[v])) return subdp[v];\n        int le = 0, ri = outs[v].size();\n    \
    \    while (ri - le > 1){\n            int md = (le + ri) / 2;\n            if\
    \ (in[es[v][md].to] <= in[r]) le = md;\n            else ri = md;\n        }\n\
    \        return reverse_dp[es[v][le].to];\n    }\n    const vector<edge>& operator[](int\
    \ idx) const { return es[idx]; }\n  private:\n    int n, root;\n    vector<vector<edge>>\
    \ es;\n    vector<vector<E>> outs;\n    vector<E> reverse_edge;\n    vector<V>\
    \ subdp, reverse_dp, answers;\n    vector<int> in, up;\n    void dfs(int v, int\
    \ p, int &t){\n        E val = e();\n        in[v] = t++;\n        for (auto &u\
    \ : es[v]){\n            if (u.to == p && u.to != es[v].back().to) swap(u,es[v].back());\n\
    \            if (u.to == p) continue;\n            dfs(u.to,v,t);\n          \
    \  E nval = put_edge(subdp[u.to],u.idx);\n            outs[v].emplace_back(nval);\n\
    \            val = merge(val,nval);\n        }\n        subdp[v] = put_vertex(val,v);\n\
    \        up[v] = t;\n    }\n    void bfs(int v){\n        int siz = outs[v].size();\n\
    \        vector<E> lui(siz+1), rui(siz+1);\n        lui[0] = e(), rui[siz] = e();\n\
    \        for (int i = 0; i < siz; i++) lui[i+1] = merge(lui[i],outs[v][i]);\n\
    \        for (int i = siz-1; i >= 0; i--) rui[i] = merge(outs[v][i],rui[i+1]);\n\
    \        for (int i = 0; i < siz; i++){\n            reverse_dp[es[v][i].to] =\
    \ put_vertex(merge(merge(lui[i],rui[i+1]),reverse_edge[v]),v);\n            reverse_edge[es[v][i].to]\
    \ = put_edge(reverse_dp[es[v][i].to],es[v][i].xdi);\n            bfs(es[v][i].to);\n\
    \        }\n        answers[v] = put_vertex(merge(lui[siz],reverse_edge[v]), v);\n\
    \    }\n};\n\n} // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: tree/RerootingDP.hpp
  requiredBy: []
  timestamp: '2023-04-26 12:09:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/RerootingDP.hpp
layout: document
redirect_from:
- /library/tree/RerootingDP.hpp
- /library/tree/RerootingDP.hpp.html
title: tree/RerootingDP.hpp
---

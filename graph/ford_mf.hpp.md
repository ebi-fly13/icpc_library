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
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define\
    \ rep(i,s,n) for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template<typename T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T &a, const\
    \ T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\nnamespace\
    \ lib{\n\nusing namespace std;\n\n} // namespace lib;\n\n//using namespace lib;\n\
    #line 3 \"graph/ford_mf.hpp\"\n\nnamespace lib{\nusing namespace std;\n\nstruct\
    \ ford_mf{\n\tstruct edge{int to, cap, rev;};\n\tint n;\n\tvector<int> a;\n\t\
    vector<vector<edge>> g;\n\tvector<bool> used;\n\n\tford_mf(int ni){\n\t\tn = ni;\n\
    \t\ta.resize(ni);\n\t\tg.resize(ni);\n\t\tused.resize(ni);\n\t}\n\n\tvoid add_edge(int\
    \ from, int to, int cap){\n\t\tg[from].push_back((edge){to,cap,(int)g[to].size()});\n\
    \t\tg[to].push_back((edge){from,0,(int)g[from].size()-1});\n\t}\n\n\tint dfs(int\
    \ v,int t,int f){\n\t\tif (v==t) return f;\n\t\tused[v] = true;\n\t\tfor(edge\
    \ &e: g[v]){\n\t\t\tif (!used[e.to] && e.cap>0){\n\t\t\t\tint d = dfs(e.to, t,\
    \ min(f,e.cap));\n\t\t\t\tif (d > 0){\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tg[e.to][e.rev].cap\
    \ += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\
    \tint max_flow(int s, int t){\n\t\tint flow = 0;\n\t\tfor(;;){\n\t\t\tfill(all(used),false);\n\
    \t\t\tint f = dfs(s, t, 1e9);\n\t\t\tif (f==0) return flow;\n\t\t\tflow += f;\n\
    \t\t}\n\t}\n};\n\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib{\nusing\
    \ namespace std;\n\nstruct ford_mf{\n\tstruct edge{int to, cap, rev;};\n\tint\
    \ n;\n\tvector<int> a;\n\tvector<vector<edge>> g;\n\tvector<bool> used;\n\n\t\
    ford_mf(int ni){\n\t\tn = ni;\n\t\ta.resize(ni);\n\t\tg.resize(ni);\n\t\tused.resize(ni);\n\
    \t}\n\n\tvoid add_edge(int from, int to, int cap){\n\t\tg[from].push_back((edge){to,cap,(int)g[to].size()});\n\
    \t\tg[to].push_back((edge){from,0,(int)g[from].size()-1});\n\t}\n\n\tint dfs(int\
    \ v,int t,int f){\n\t\tif (v==t) return f;\n\t\tused[v] = true;\n\t\tfor(edge\
    \ &e: g[v]){\n\t\t\tif (!used[e.to] && e.cap>0){\n\t\t\t\tint d = dfs(e.to, t,\
    \ min(f,e.cap));\n\t\t\t\tif (d > 0){\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tg[e.to][e.rev].cap\
    \ += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\
    \tint max_flow(int s, int t){\n\t\tint flow = 0;\n\t\tfor(;;){\n\t\t\tfill(all(used),false);\n\
    \t\t\tint f = dfs(s, t, 1e9);\n\t\t\tif (f==0) return flow;\n\t\t\tflow += f;\n\
    \t\t}\n\t}\n};\n\n}\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: graph/ford_mf.hpp
  requiredBy: []
  timestamp: '2023-04-25 23:17:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ford_mf.hpp
layout: document
redirect_from:
- /library/graph/ford_mf.hpp
- /library/graph/ford_mf.hpp.html
title: graph/ford_mf.hpp
---

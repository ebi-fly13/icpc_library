---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/shobon_mcf.hpp
    title: shobon min cost flow
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"test/graph/Shobon_Minimum_Flow.test.cpp\"\n#define PROBLEM\
    \ \\\n\t\"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\n\
    \n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 3 \"graph/shobon_mcf.hpp\"\n\nnamespace lib {\nusing namespace std;\n\
    \ntemplate<class Cap, class Cost> struct shobon_mcf {\n  struct E{\n    int from;\n\
    \    int to;\n    int rev;\n    Cap cap;\n    Cost cost;\n  };\n  \n  int n;\n\
    \  vector<E> e;\n  vector<Cost> p;\n  vector<vector<int>> ikeru;\n  const Cost\
    \ inf = numeric_limits<Cost>::max() / 4;\n\n  shobon_mcf(int n): n(n) {\n    ikeru.resize(n);\n\
    \    p.resize(n);\n  }  \n\n  void add_edge(int from, int to, Cap cap, Cost cost){\n\
    \    int x = e.size();\n    e.push_back({from, to, x + 1, cap, cost});\n    e.push_back({to,\
    \ from, x, 0, -cost});\n    ikeru[from].push_back(x);\n    ikeru[to].push_back(x+1);\n\
    \  }\n\n  pair<Cap, Cost> flow(int from, int to, Cap f){\n    Cap cap = 0;\n \
    \   Cost cost = 0;\n    \n    while(f > 0){\n      vector<Cost> d(n, inf);\n \
    \     vector<int> cf(n, -1);\n      priority_queue<pair<Cost,int>> pq;\n     \
    \ pq.push(pair(0, from));\n      d[from] = 0;\n      while(!pq.empty()){\n   \
    \     auto [tmp, i] = pq.top();\n        pq.pop();\n        tmp = -tmp;\n    \
    \    if (tmp > d[i]) continue;\n        for (int x: ikeru[i]){\n          int\
    \ j = e[x].to;\n          if (e[x].cap == 0) continue;\n          if (chmin(d[j],\
    \ e[x].cost + tmp + p[i] - p[j])){\n            cf[j] = x;\n            pq.push(pair(-d[j],\
    \ j));\n          }\n        }\n      }\n\n      if (d[to] == inf) break;\n  \
    \    rep(i,0,n) p[i] += d[i];\n\n      Cap z = f;\n      int nw = to;\n      while\
    \ (nw != from){\n        chmin(z, e[cf[nw]].cap);\n        nw = e[cf[nw]].from;\n\
    \      }\n\n      f -= z;\n      cap += z;\n      cost += z * p[to];\n\n     \
    \ nw = to;\n      while (nw != from){\n        e[cf[nw]].cap -= z;\n        e[e[cf[nw]].rev].cap\
    \ += z;\n        nw = e[cf[nw]].from;\n      }\n    }\n\n    return pair(cap,\
    \ cost);\n  }\n\n  pair<Cap, Cost> flow(int from, int to){\n    return flow(from,\
    \ to, numeric_limits<Cap>::max());\n  }\n\n  // Type the following code if you\
    \ need\n  // Return the edges\n\n  vector<E> edges(){\n    vector<E> ret((int)e.size()\
    \ / 2);\n    rep(i,0,(int)e.size() / 2) ret[i] = e[2*i];\n    return ret;\n  }\n\
    \n  // Init the potential with Bellman-Ford\n\n  void potential_bellman_ford(int\
    \ from){\n    int m = (int)e.size() / 2;\n    fill(all(p), inf);\n    p[from]\
    \ = 0;\n    rep(num,0,n){\n      rep(x,0,m){\n        int i = e[2*x].from;\n \
    \       int j = e[2*x].to;\n        chmin(p[j], p[i] + e[2*x].cost);\n      }\n\
    \    }\n  }\n\n  // Init the potential with DP on DAG\n\n  void potential_dag(int\
    \ from){\n    vector<int> deg(n);\n    rep(x,0,(int)e.size()){\n      if (e[x].cap\
    \ > 0){\n        deg[e[x].to]++;\n      }\n    }\n    \n    assert(deg[from] ==\
    \ 0);\n\n    fill(all(p), inf);\n    p[from] = 0;\n    vector<int> mada;\n   \
    \ rep(i,0,n){\n      if (deg[i] == 0) mada.push_back(i);\n    }\n\n    int cnt\
    \ = 0;\n    while(!mada.empty()){\n      int i = mada.back();\n      mada.pop_back();\n\
    \      cnt++;\n      for (int x: ikeru[i]){\n        if (e[x].cap == 0) continue;\n\
    \        int j = e[x].to;\n        chmin(p[j], p[i] + e[x].cost);\n        deg[j]--;\n\
    \        if (deg[j] == 0){\n          mada.push_back(j);\n        }\n      }\n\
    \    }\n    \n    assert(cnt == n);\n  }\n\n};\n\n}\n#line 6 \"test/graph/Shobon_Minimum_Flow.test.cpp\"\
    \n\nint main(){\n\tint v,e,f; std::cin>>v>>e>>f;\n\tlib::shobon_mcf<int,int> mcf(v);\n\
    \tfor (int i=0;i<e;i++){\n\t\tint a,b,c,d; std::cin >> a >> b >> c >> d;\n\t\t\
    mcf.add_edge(a,b,c,d);\n\t}\n\tauto [flow, cost] = mcf.flow(0,v-1,f);\n\tif (flow\
    \ != f) std::cout << \"-1\\n\";\n\telse std::cout << cost << '\\n';\n}\n"
  code: "#define PROBLEM \\\n\t\"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include \"../../graph/shobon_mcf.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nint main(){\n\tint v,e,f; std::cin>>v>>e>>f;\n\tlib::shobon_mcf<int,int> mcf(v);\n\
    \tfor (int i=0;i<e;i++){\n\t\tint a,b,c,d; std::cin >> a >> b >> c >> d;\n\t\t\
    mcf.add_edge(a,b,c,d);\n\t}\n\tauto [flow, cost] = mcf.flow(0,v-1,f);\n\tif (flow\
    \ != f) std::cout << \"-1\\n\";\n\telse std::cout << cost << '\\n';\n}"
  dependsOn:
  - graph/shobon_mcf.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/graph/Shobon_Minimum_Flow.test.cpp
  requiredBy: []
  timestamp: '2023-11-16 03:45:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Shobon_Minimum_Flow.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Shobon_Minimum_Flow.test.cpp
- /verify/test/graph/Shobon_Minimum_Flow.test.cpp.html
title: test/graph/Shobon_Minimum_Flow.test.cpp
---

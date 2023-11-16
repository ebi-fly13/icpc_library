---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: Suffix Array
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/string/Number_of_Substrings.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 2 \"\
    string/suffix_array.hpp\"\n\n#line 4 \"string/suffix_array.hpp\"\n\nnamespace\
    \ lib {\n\nvector<int> suffix_array(const string &s) {\n    int n = s.size();\n\
    \    vector<int> rnk(n, -1), sa(n);\n    iota(all(sa), 0);\n    rep(i, 0, n) {\n\
    \        rnk[i] = s[i];\n    }\n    int k = 1;\n    auto compare = [&](int i,\
    \ int j) -> bool {\n        if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];\n  \
    \      return (i + k < n ? rnk[i + k] : -1) < (j + k < n ? rnk[j + k] : -1);\n\
    \    };\n    while (k < n) {\n        sort(all(sa), compare);\n        vector<int>\
    \ tmp(n, 0);\n        rep(i, 1, n) {\n            tmp[sa[i]] = tmp[sa[i - 1]]\
    \ + int(compare(sa[i - 1], sa[i]));\n        }\n        swap(rnk, tmp);\n    \
    \    k <<= 1;\n    }\n    return sa;\n}\n\nvector<int> lcp_array(const string\
    \ &s, const vector<int> &sa) {\n    int n = s.size();\n    vector<int> rnk(n),\
    \ lcp(n - 1);\n    rep(i, 0, n) rnk[sa[i]] = i;\n    int h = 0;\n    rep(i, 0,\
    \ n) {\n        if (h > 0) h--;\n        if (rnk[i] == 0) continue;\n        int\
    \ j = sa[rnk[i] - 1];\n        while (i + h < n && j + h < n && s[i + h] == s[j\
    \ + h]) {\n            h++;\n        }\n        lcp[rnk[i] - 1] = h;\n    }\n\
    \    return lcp;\n}\n\n}  // namespace lib\n#line 5 \"test/string/Number_of_Substrings.test.cpp\"\
    \n\nnamespace lib {\n\nvoid main_() {\n    string s;\n    cin >> s;\n    auto\
    \ sa = suffix_array(s);\n    auto lcp = lcp_array(s, sa);\n    ll n = s.size();\n\
    \    ll ans = n * (n + 1) / 2;\n    rep(i,0,n-1) {\n        ans -= lcp[i];\n \
    \   }\n    cout << ans << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n \
    \   int t = 1;\n    // cin >> t;\n    while (t--) {\n        lib::main_();\n \
    \   }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../string/suffix_array.hpp\"\
    \n\nnamespace lib {\n\nvoid main_() {\n    string s;\n    cin >> s;\n    auto\
    \ sa = suffix_array(s);\n    auto lcp = lcp_array(s, sa);\n    ll n = s.size();\n\
    \    ll ans = n * (n + 1) / 2;\n    rep(i,0,n-1) {\n        ans -= lcp[i];\n \
    \   }\n    cout << ans << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n \
    \   int t = 1;\n    // cin >> t;\n    while (t--) {\n        lib::main_();\n \
    \   }\n    return 0;\n}"
  dependsOn:
  - template/template.hpp
  - string/suffix_array.hpp
  isVerificationFile: true
  path: test/string/Number_of_Substrings.test.cpp
  requiredBy: []
  timestamp: '2023-11-17 01:51:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/Number_of_Substrings.test.cpp
layout: document
redirect_from:
- /verify/test/string/Number_of_Substrings.test.cpp
- /verify/test/string/Number_of_Substrings.test.cpp.html
title: test/string/Number_of_Substrings.test.cpp
---

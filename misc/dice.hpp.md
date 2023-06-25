---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/aoj_1197.test.cpp
    title: test/misc/aoj_1197.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    #define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i,\
    \ s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),\
    \ v.end()\n\nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned\
    \ long long;\n\ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a\
    \ <= b) return false;\n    a = b;\n    return true;\n}\ntemplate <typename T>\
    \ bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n}  // namespace\
    \ lib\n\n// using namespace lib;\n#line 2 \"misc/dice.hpp\"\n\nnamespace lib {\n\
    \nstruct Dice {\n    int up = 0, front = 1, right = 2, left = 3, back = 4, down\
    \ = 5;\n\n    Dice() = default;\n\n    void set_val(const std::vector<int> &_val)\
    \ {\n        assert(int(_val.size()) == 6);\n        val = _val;\n    }\n\n  \
    \  // y++\n    void rollN() {\n        int buff = down;\n        down = back;\n\
    \        back = up;\n        up = front;\n        front = buff;\n    }\n\n   \
    \ // y--\n    void rollS() {\n        int buff = down;\n        down = front;\n\
    \        front = up;\n        up = back;\n        back = buff;\n    }\n\n    //\
    \ x++\n    void rollE() {\n        int buff = down;\n        down = right;\n \
    \       right = up;\n        up = left;\n        left = buff;\n    }\n\n    //\
    \ x--\n    void rollW() {\n        int buff = down;\n        down = left;\n  \
    \      left = up;\n        up = right;\n        right = buff;\n    }\n\n    //\
    \ \u53F3\u56DE\u8EE2(\u6642\u8A08\u56DE\u308A)\n    void rollR() {\n        int\
    \ buff = right;\n        right = back;\n        back = left;\n        left = front;\n\
    \        front = buff;\n    }\n\n    // \u5DE6\u56DE\u8EE2(\u53CD\u6642\u8A08\u56DE\
    \u308A)\n    void rollL() {\n        int buff = left;\n        left = back;\n\
    \        back = right;\n        right = front;\n        front = buff;\n    }\n\
    \n    void roll(char c) {\n        if (c == 'N')\n            rollN();\n     \
    \   else if (c == 'S')\n            rollS();\n        else if (c == 'E')\n   \
    \         rollE();\n        else if (c == 'W')\n            rollW();\n       \
    \ else if (c == 'R')\n            rollR();\n        else if (c == 'L')\n     \
    \       rollL();\n        else\n            assert(0);\n    }\n\n    int top_val()\
    \ const {\n        return val[up];\n    }\n\n    int right_val() const {\n   \
    \     return val[right];\n    }\n\n    int left_val() const {\n        return\
    \ val[left];\n    }\n\n    int front_val() const {\n        return val[front];\n\
    \    }\n\n    int back_val() const {\n        return val[back];\n    }\n\n   \
    \ int down_val() const {\n        return val[down];\n    }\n\n    std::vector<int>\
    \ now() const {\n        std::vector<int> ret(6);\n        ret[0] = top_val();\n\
    \        ret[1] = front_val();\n        ret[2] = right_val();\n        ret[3]\
    \ = left_val();\n        ret[4] = back_val();\n        ret[5] = down_val();\n\
    \        return ret;\n    }\n\n    std::vector<Dice> makeDice() const {\n    \
    \    std::vector<Dice> ret;\n        for (int i = 0; i < 6; i++) {\n         \
    \   Dice d(*this);\n            if (i == 1) d.rollN();\n            if (i == 2)\
    \ d.rollS();\n            if (i == 3) {\n                d.rollS();\n        \
    \        d.rollS();\n            }\n            if (i == 4) d.rollL();\n     \
    \       if (i == 5) d.rollR();\n            for (int j = 0; j < 4; j++) {\n  \
    \              ret.emplace_back(d);\n                d.rollE();\n            }\n\
    \        }\n        return ret;\n    }\n\n    std::vector<int> val = {0, 1, 2,\
    \ 3, 4, 5};\n};\n\n}\n"
  code: "#include \"../template/template.hpp\"\n\nnamespace lib {\n\nstruct Dice {\n\
    \    int up = 0, front = 1, right = 2, left = 3, back = 4, down = 5;\n\n    Dice()\
    \ = default;\n\n    void set_val(const std::vector<int> &_val) {\n        assert(int(_val.size())\
    \ == 6);\n        val = _val;\n    }\n\n    // y++\n    void rollN() {\n     \
    \   int buff = down;\n        down = back;\n        back = up;\n        up = front;\n\
    \        front = buff;\n    }\n\n    // y--\n    void rollS() {\n        int buff\
    \ = down;\n        down = front;\n        front = up;\n        up = back;\n  \
    \      back = buff;\n    }\n\n    // x++\n    void rollE() {\n        int buff\
    \ = down;\n        down = right;\n        right = up;\n        up = left;\n  \
    \      left = buff;\n    }\n\n    // x--\n    void rollW() {\n        int buff\
    \ = down;\n        down = left;\n        left = up;\n        up = right;\n   \
    \     right = buff;\n    }\n\n    // \u53F3\u56DE\u8EE2(\u6642\u8A08\u56DE\u308A\
    )\n    void rollR() {\n        int buff = right;\n        right = back;\n    \
    \    back = left;\n        left = front;\n        front = buff;\n    }\n\n   \
    \ // \u5DE6\u56DE\u8EE2(\u53CD\u6642\u8A08\u56DE\u308A)\n    void rollL() {\n\
    \        int buff = left;\n        left = back;\n        back = right;\n     \
    \   right = front;\n        front = buff;\n    }\n\n    void roll(char c) {\n\
    \        if (c == 'N')\n            rollN();\n        else if (c == 'S')\n   \
    \         rollS();\n        else if (c == 'E')\n            rollE();\n       \
    \ else if (c == 'W')\n            rollW();\n        else if (c == 'R')\n     \
    \       rollR();\n        else if (c == 'L')\n            rollL();\n        else\n\
    \            assert(0);\n    }\n\n    int top_val() const {\n        return val[up];\n\
    \    }\n\n    int right_val() const {\n        return val[right];\n    }\n\n \
    \   int left_val() const {\n        return val[left];\n    }\n\n    int front_val()\
    \ const {\n        return val[front];\n    }\n\n    int back_val() const {\n \
    \       return val[back];\n    }\n\n    int down_val() const {\n        return\
    \ val[down];\n    }\n\n    std::vector<int> now() const {\n        std::vector<int>\
    \ ret(6);\n        ret[0] = top_val();\n        ret[1] = front_val();\n      \
    \  ret[2] = right_val();\n        ret[3] = left_val();\n        ret[4] = back_val();\n\
    \        ret[5] = down_val();\n        return ret;\n    }\n\n    std::vector<Dice>\
    \ makeDice() const {\n        std::vector<Dice> ret;\n        for (int i = 0;\
    \ i < 6; i++) {\n            Dice d(*this);\n            if (i == 1) d.rollN();\n\
    \            if (i == 2) d.rollS();\n            if (i == 3) {\n             \
    \   d.rollS();\n                d.rollS();\n            }\n            if (i ==\
    \ 4) d.rollL();\n            if (i == 5) d.rollR();\n            for (int j =\
    \ 0; j < 4; j++) {\n                ret.emplace_back(d);\n                d.rollE();\n\
    \            }\n        }\n        return ret;\n    }\n\n    std::vector<int>\
    \ val = {0, 1, 2, 3, 4, 5};\n};\n\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: misc/dice.hpp
  requiredBy: []
  timestamp: '2023-06-23 21:58:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/aoj_1197.test.cpp
documentation_of: misc/dice.hpp
layout: document
title: "\u30B5\u30A4\u30B3\u30ED\u30E9\u30A4\u30D6\u30E9\u30EA"
---

## 説明

サイコロを転がします。ころころ

### set_val(std::vector<int> _val)

`val`を`_val`に更新

### roll(c)

`c` の方向に回転する。`rollc()`と同じ動作 (`c`には`NSFWRL`のいずれかが入る)

### ~_val()

`~`のvalを返す。`~`にはtop, right, left, front, back, downが入る。

### makeDice()

サイコロを全通り (24通り)列挙する。
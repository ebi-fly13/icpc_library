---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/BinaryTrie.hpp
    title: BinaryTrie
  - icon: ':warning:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':warning:'
    path: geometry/base_ll.hpp
    title: geometry/base_ll.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: circle
  - icon: ':warning:'
    path: geometry/convex_hull.hpp
    title: geometry/convex_hull.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: line
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: segment
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: eratosthenes sieve
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.hpp
    title: RollingHash
  - icon: ':warning:'
    path: string/parsing_template.hpp
    title: string/parsing_template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/HeavyLightDecomposition.hpp
    title: HeavyLightDecomposition
  - icon: ':heavy_check_mark:'
    path: tree/LowestCommonAncestor.hpp
    title: LowestCommonAncestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Range_Sum.test.cpp
    title: test/data_structure/Point_Add_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Set_Xor_Min.test.cpp
    title: test/data_structure/Set_Xor_Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Circumscribed_Circle_of_Triangle.test.cpp
    title: test/geometry/Circumscribed_Circle_of_Triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Counter_Clockwise.test.cpp
    title: test/geometry/Counter_Clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Cross_Point.test.cpp
    title: test/geometry/Cross_Point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Cross_Points_of_Circle_and_Line.test.cpp
    title: test/geometry/Cross_Points_of_Circle_and_Line.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Cross_Points_of_Circles.test.cpp
    title: test/geometry/Cross_Points_of_Circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Distance.test.cpp
    title: test/geometry/Distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Incircle_of_Triangle.test.cpp
    title: test/geometry/Incircle_of_Triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Intersection.test.cpp
    title: test/geometry/Intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Intersection_Circle.test.cpp
    title: test/geometry/Intersection_Circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Parallel_Orthogonal.test.cpp
    title: test/geometry/Parallel_Orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Projection.test.cpp
    title: test/geometry/Projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Reflection.test.cpp
    title: test/geometry/Reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_primes.test.cpp
    title: test/math/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/aoj_2444.test.cpp
    title: test/string/aoj_2444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Lowest_Common_Ancestor.test.cpp
    title: test/tree/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define\
    \ rep(i,s,n) for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template<typename T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T &a, const\
    \ T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\nnamespace\
    \ lib{\n\nusing namespace std;\n\n} // namespace lib;\n\n//using namespace lib;\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i\
    \ = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T\
    \ &a, const T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n\
    }\ntemplate<typename T> bool chmax(T &a, const T &b){\n    if (a >= b) return\
    \ false;\n    a = b;\n    return true;\n}\n\nnamespace lib{\n\nusing namespace\
    \ std;\n\n} // namespace lib;\n\n//using namespace lib;"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - string/parsing_template.hpp
  - string/RollingHash.hpp
  - tree/HeavyLightDecomposition.hpp
  - tree/LowestCommonAncestor.hpp
  - geometry/line.hpp
  - geometry/circle.hpp
  - geometry/segment.hpp
  - geometry/base_ll.hpp
  - geometry/convex_hull.hpp
  - geometry/base_ld.hpp
  - math/eratosthenes_sieve.hpp
  - data_structure/segtree.hpp
  - data_structure/BinaryTrie.hpp
  - data_structure/dsu.hpp
  timestamp: '2023-04-23 15:49:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aoj_2444.test.cpp
  - test/tree/Lowest_Common_Ancestor.test.cpp
  - test/geometry/Cross_Points_of_Circle_and_Line.test.cpp
  - test/geometry/Circumscribed_Circle_of_Triangle.test.cpp
  - test/geometry/Cross_Point.test.cpp
  - test/geometry/Parallel_Orthogonal.test.cpp
  - test/geometry/Counter_Clockwise.test.cpp
  - test/geometry/Distance.test.cpp
  - test/geometry/Incircle_of_Triangle.test.cpp
  - test/geometry/Intersection_Circle.test.cpp
  - test/geometry/Projection.test.cpp
  - test/geometry/Cross_Points_of_Circles.test.cpp
  - test/geometry/Reflection.test.cpp
  - test/geometry/Intersection.test.cpp
  - test/math/enumerate_primes.test.cpp
  - test/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/data_structure/Set_Xor_Min.test.cpp
  - test/data_structure/Point_Add_Range_Sum.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---

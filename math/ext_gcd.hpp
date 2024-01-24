#pragma once

#include "../template/template.hpp"

// https://github.com/maspypy/library/blob/main/nt/extgcd.hpp



tuple<ll, ll, ll, ll> Farey_lr(ll a, ll b) {
    assert(a > 0 && b > 0);
    /*
    Farey 数列で、a/b が最初に現れるときの、左右を求める。
    a/b = 19/12 → (x1/y1, x2/y2) = (11/7, 8/5) → (11,7,8,5) を返す。
    */
    if (a == b) return {0, 1, 1, 0};
    ll q = (a - 1) / b;
    auto [x1, y1, x2, y2] = Farey_lr(b, a - q * b);
    return {q * x2 + y2, x2, q * x1 + y1, x1};
}

tuple<ll, ll, ll> extgcd(ll a, ll b) {
    // ax + by = d の最小解 (x, y, d) を返す。
    // (|x|+|y|, x) に関する辞書順最小とする。
    auto [x1, y1, x2, y2] = Farey_lr(a, b);
    tie(x1, y1) = make_pair(y1, -x1);
    tie(x2, y2) = make_pair(-y2, x2);
    ll g = a * x1 + b * y1;
    pair<ll,ll> key1 = make_pair(abs(x1) + abs(y1), x1);
    pair<ll,ll> key2 = make_pair(abs(x2) + abs(y2), x2);
    return (key1 < key2 ? make_tuple(x1, y1, g) : make_tuple(x2, y2, g));
}


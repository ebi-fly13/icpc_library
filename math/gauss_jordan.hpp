#pragma once
#include "../template/template.hpp"

namespace lib {
using namespace std;

template <typename T> vector<vector<T>> gauss_jordan(vector<vector<T>> &a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<T>> b = a;
    int piv = 0;
    rep(j, 0, m) rep(i, piv, n) {
        if (b[i][j] != T(0)) {
            swap(b[i], b[piv]);
            T ip = T(1) / b[piv][j];
            rep(l, 0, n) {
                if (l != piv) {
                    T tmp = ip * b[l][j];
                    rep(k, j, m) b[l][k] -= tmp * b[piv][k];
                }
            }
            rep(k, j, m) b[piv][k] *= ip;
            piv++;
            break;
        }
    }
    return b;
}

}  // namespace lib
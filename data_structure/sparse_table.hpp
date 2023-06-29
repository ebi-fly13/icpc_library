#pragma once

#include"../template/template.hpp"

namespace lib{

template<class S, S (*op)(S, S)>
struct SparseTable{
    vector<vector<S>> table;
    vector<int> clz;
    SparseTable (const vector<S> &vec){
        int n = vec.size(), n2 = 0;
        while ((1<<n2) < n) n2++;
        table.resize(n2+1);
        rep(i,0,n2+1){
            table[i].resize(n);
            if (i == 0){
                rep(j,0,n) table[i][j] = vec[j];
            }
            else {
                rep(j,0,n){
                    if (j + (1<<(i-1)) < n) table[i][j] = op(table[i-1][j],table[i-1][j + (1<<(i-1))]);
                    else table[i][j] = table[i-1][j];
                }
            }
        }
        clz.resize(n+1);
        rep(i,0,n2+1){
            for (int j = (1<<i); j < (2<<i) && j <= n; j++){
                clz[j] = i;
            }
        }
    }
    // 単位元を要求しないので if (l >= r) return e() みたいなことをしていない、注意すること！！
    S get(int l, int r){
        assert(r - l > 0);
        //int lgs = 31 - __builtin_clz((unsigned int)(r-l));
        int lgs = clz[r-l];
        return op(table[lgs][l], table[lgs][r - (1 << lgs)]);
    }
};

} // namespace lib
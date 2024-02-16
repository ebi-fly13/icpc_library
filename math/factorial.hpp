#pragma once

#include"../template/template.hpp"

namespace lib {

template<typename T>
struct Binom{
    Binom(int lim = 300000){
        if (kaijo.empty()){
            kaijo = {1,1};
            kainv = {1,1};
        }
        extend(lim);
    }
    static T fact(int x) {
        if (x < 0) return T(0);
        return kaijo[x];
    }
    static T ifact(int x){
        if (x < 0) return T(0);
        return kainv[x];
    }
    static T C(int n, int r){
        if (n < 0 || n < r || r < 0) return T(0);
        return kaijo[n] * kainv[r] * kainv[n-r];
    }
    static T P(int n, int r){
        if (n < 0 || n < r || r < 0) return T(0);
        return kaijo[n] * kainv[n-r];
    }
    static T Inv(int n){
        assert(0 < n);
        return ifact(n) * fact(n-1);
    }
    T operator()(int n, int r){ return C(n,r); }
  private:
    static vector<T> kaijo, kainv;
    static void extend(int lim){
        if ((int)kaijo.size() > lim) return ;
        int pre = kaijo.size();
        kaijo.resize(lim+1);
        kainv.resize(lim+1);
        for (int i = pre; i <= lim; i++) kaijo[i] = kaijo[i-1] * T(i);
        kainv[lim] = kaijo[lim].inv();
        for (int i = lim-1; i >= pre; i--) kainv[i] = kainv[i+1] * T(i+1);
    }
};
template<typename T>
vector<T>Binom<T>::kaijo = vector<T>(2,T(1));
template<typename T>
vector<T>Binom<T>::kainv = vector<T>(2,T(1));

} // namespace lib
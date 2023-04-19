#pragma once

#include<bits/stdc++.h>
#include<iostream>
#define rep(i,s,n) for (int i = s; i < (int)(n); i++)
#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)
#define all(v) v.begin(),v.end()

using ll = long long;
using ull = unsigned long long;

template<typename T> bool chmin(T &a, const T &b){
    if (a <= b) return false;
    a = b;
    return true;
}
template<typename T> bool chmax(T &a, const T &b){
    if (a >= b) return false;
    a = b;
    return true;
}

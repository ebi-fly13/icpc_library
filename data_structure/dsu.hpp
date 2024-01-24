#pragma once

#include "../template/template.hpp"



struct dsu {
  public:
    dsu(int n = 0) : _n(n), data(n, -1) {}

    int leader(int a) {
        if (data[a] < 0) return a;
        return data[a] = leader(data[a]);
    }

    int merge(int a, int b) {
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-data[x] < -data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return x;
    }

    bool same(int a, int b) {
        return leader(a) == leader(b);
    }

    int size(int a) {
        return -data[leader(a)];
    }

  private:
    int _n;
    vector<int> data;
};



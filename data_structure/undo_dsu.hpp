#pragma once

#include "../template/template.hpp"

namespace lib {

struct undo_dsu {
  public:
    undo_dsu(int n) : n(n), data(n, -1) {}

    int leader(int a) const {
        if (data[a] < 0) return a;
        return leader(data[a]);
    }

    int size(int a) const {
        int x = leader(a);
        return -data[x];
    }

    int merge(int a, int b) {
        int x = leader(a);
        int y = leader(b);
        stack.push({x, data[x]});
        stack.push({y, data[y]});
        if (x == y) return x;
        if (size(x) < size(y)) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return x;
    }

    void undo() {
        assert(stack.size() >= 2);
        auto [x, xval] = stack.top();
        data[x] = xval;
        stack.pop();
        auto [y, yval] = stack.top();
        data[y] = yval;
        stack.pop();
    }

  private:
    int n;
    std::vector<int> data;
    std::stack<std::pair<int, int>> stack;
};

}  // namespace lib
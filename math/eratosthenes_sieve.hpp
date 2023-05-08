#pragma once

#include <cassert>
#include <vector>

#include "../template/template.hpp"

namespace lib {

using namespace std;

struct eratosthenes_sieve {
  private:
    int n;
    vector<bool> table;

  public:
    eratosthenes_sieve(int n) : n(n), table(vector<bool>(n + 1, true)) {
        table[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (!table[i]) continue;
            for (int j = i; i * j <= n; j++) {
                table[i * j] = false;
            }
        }
    }

    bool is_prime(int p) { return table[p]; }

    vector<int> prime_table(int m = -1) {
        if (m < 0) m = n;
        std::vector<int> prime;
        rep(i, 2, m + 1) {
            if (table[i]) prime.emplace_back(i);
        }
        return prime;
    }
};

}  // namespace lib
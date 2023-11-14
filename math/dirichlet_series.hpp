#pragma once

#include "../template/template.hpp"

namespace lib {

template <class T>
std::vector<T> dirichlet_convolution(const std::vector<T> &a,
                                     const std::vector<T> &b) {
    assert(a.size() == b.size());
    int n = a.size() - 1;
    std::vector<T> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            c[i * j] += a[i] * b[j];
        }
    }
    return c;
}

template <class T, int id> struct DirichletSeries {
  private:
    using Self = DirichletSeries<T, id>;

    void set(std::function<T(ll)> f, std::function<T(ll)> F) {
        for (int i = 1; i <= K; i++) {
            a[i] = f(i);
        }
        for (int i = 1; i <= L; i++) {
            A[i] = F(N / i);
        }
    }

  public:
    DirichletSeries() : a(K + 1), A(L + 1) {}

    DirichletSeries(std::function<T(ll)> f, std::function<T(ll)> F)
        : a(K + 1), A(L + 1) {
        set(f, F);
    }

    Self operator+(const Self &rhs) const noexcept {
        return Self(*this) += rhs;
    }
    Self operator-(const Self &rhs) const noexcept {
        return Self(*this) -= rhs;
    }
    Self operator*(const Self &rhs) const noexcept {
        return Self(*this) *= rhs;
    }
    Self operator/(const Self &rhs) const noexcept {
        return Self(*this) /= rhs;
    }

    Self operator+=(const Self &rhs) noexcept {
        for (int i = 1; i <= K; i++) {
            a[i] += rhs.a[i];
        }
        for (int i = 1; i <= L; i++) {
            A[i] += rhs.A[i];
        }
        return *this;
    }

    Self operator-=(const Self &rhs) noexcept {
        for (int i = 1; i <= K; i++) {
            a[i] -= rhs.a[i];
        }
        for (int i = 1; i <= L; i++) {
            A[i] -= rhs.A[i];
        }
        return *this;
    }

    Self operator*=(const Self &rhs) noexcept {
        Self ret;
        ret.a = dirichlet_convolution(a, rhs.a);
        std::vector<T> sum_a = a, sum_b = rhs.a;
        for (int i = 1; i < K; i++) {
            sum_a[i + 1] += sum_a[i];
            sum_b[i + 1] += sum_b[i];
        }
        auto get_A = [&](ll x) -> T {
            if (x <= K) {
                return sum_a[x];
            } else {
                return A[N / x];
            }
        };
        auto get_B = [&](ll x) -> T {
            if (x <= K) {
                return sum_b[x];
            } else {
                return rhs.A[N / x];
            }
        };
        for (ll l = L, m = 1; l >= 1; l--) {
            ll n = N / l;
            while (m * m <= n) m++;
            m--;
            for (int i = 1; i <= m; i++) {
                ret.A[l] +=
                    a[i] * get_B(n / i) + (get_A(n / i) - get_A(m)) * rhs.a[i];
            }
        }
        return ret;
    }

    // c = a / b
    Self operator/=(const Self &b) noexcept {
        Self c = *this;
        T inv_a = b.a[1].inv();
        for (int i = 1; i <= K; i++) {
            c.a[i] *= inv_a;
            for (int j = 2; i * j <= K; j++) {
                c.a[i * j] -= c.a[i] * b.a[j];
            }
        }
        std::vector<T> sum_b = b.a, sum_c = c.a;
        for (int i = 1; i < K; ++i) {
            sum_b[i + 1] += sum_b[i];
            sum_c[i + 1] += sum_c[i];
        }
        auto get_B = [&](ll x) -> T {
            if (x <= K) {
                return sum_b[x];
            } else {
                return b.A[N / x];
            }
        };
        auto get_C = [&](ll x) -> T {
            if (x <= K) {
                return sum_c[x];
            } else {
                return c.A[N / x];
            }
        };
        for (ll l = L, m = 1; l >= 1; l--) {
            ll n = N / l;
            while (m * m <= n) m++;
            m--;
            for (int i = 2; i <= m; i++) {
                c.A[l] -= b.a[i] * get_C(n / i);
            }

            for (int i = 1; i <= m; i++) {
                c.A[l] -= c.a[i] * (get_B(n / i) - get_B(m));
            }
            c.A[l] *= inv_a;
        }
        return *this = c;
    }

    Self pow(ll n) const {
        Self res;
        res.a[1] = 1;
        std::fill(res.A.begin(), res.A.end(), 1);
        Self x = *this;
        while (n > 0) {
            if (n & 1) res = res * x;
            x = x * x;
            n >>= 1;
        }
        return res;
    }

    T get_sum() {
        return A[1];
    }

    static Self zeta() {
        Self ret;
        std::fill(ret.a.begin(), ret.a.end(), 1);
        for (int i = 1; i <= L; i++) {
            ret.A[i] = N / i;
        }
        return ret;
    }

    static Self zeta1() {
        Self ret;
        std::iota(ret.a.begin(), ret.a.end(), 0);
        T inv2 = T(2).inv();
        for (int i = 1; i <= L; i++) {
            ll n = N / i;
            ret.A[i] = T(n) * T(n + 1) * inv2;
        }
        return ret;
    }

    static Self zeta2() {
        Self ret;
        for (int i = 1; i <= K; i++) {
            ret.a[i] = i * i;
        }
        T inv6 = T(6).inv();
        for (int i = 1; i <= L; i++) {
            ll n = N / i;
            ret.A[i] = T(n) * T(n + 1) * T(2 * n + 1) * inv6;
        }
    }

    static void set_size(ll n) {
        N = n;
        if (N <= 10) {
            K = N;
            L = 1;
        } else if (N <= 5000) {
            K = 1;
            while (K * K < N) K++;
            L = (N + K - 1) / K;
        } else {
            L = 1;
            while (L * L * L / 50 < N) L++;
            K = (N + L - 1) / L;
        }
    }

    static void set_size_multiplicative(ll n) {
        N = n;
        L = 1;
        while (L * L * L < N) L++;
        K = L * L;
    }

  private:
    static ll N, K, L;
    static std::vector<std::pair<int, int>> prime_pow_table;
    std::vector<T> a, A;
};

template <class T, int id> ll DirichletSeries<T, id>::N = 1000000;
template <class T, int id> ll DirichletSeries<T, id>::K = 10000;
template <class T, int id> ll DirichletSeries<T, id>::L = 100;
template <class T, int id>
std::vector<std::pair<int, int>> DirichletSeries<T, id>::prime_pow_table = {};

}  // namespace lib
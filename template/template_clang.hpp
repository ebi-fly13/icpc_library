#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)
#define all(v) v.begin(), v.end()

using ll = long long;
using ld = long double;
using ull = unsigned long long;

template <typename T> bool chmin(T &a, const T &b) {
    if (a <= b) return false;
    a = b;
    return true;
}
template <typename T> bool chmax(T &a, const T &b) {
    if (a >= b) return false;
    a = b;
    return true;
}

using namespace std;

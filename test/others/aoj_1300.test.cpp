#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300"

#include "../../math/gauss_jordan.hpp"
#include "../../template/parsing_template.hpp"
#include "../../template/template.hpp"
#include "../../utility/rational.hpp"

std::vector<std::vector<rational>> chemical_equation(State &);
std::vector<std::map<std::string, ll>> molecule_sequence(State &);
std::map<std::string, ll> molecule(State &);
std::map<std::string, ll> group(State &);
std::map<std::string, ll> unit_group(State &);
std::pair<std::string, ll> chemical_element(State &);
ll number(State &);

std::vector<std::vector<rational>> chemical_equation(State &begin) {
    auto lhs = molecule_sequence(begin);
    consume(begin, '-');
    consume(begin, '>');
    auto rhs = molecule_sequence(begin);
    std::set<std::string> set;
    for (auto &map : lhs) {
        for (auto &p : map) set.insert(p.first);
    }
    int h = set.size();
    std::vector a(h, std::vector<rational>());
    rep(i, 0, lhs.size()) {
        int j = 0;
        for (auto &s : set) {
            a[j].emplace_back(lhs[i][s]);
            j++;
        }
    }
    rep(i, 0, rhs.size()) {
        int j = 0;
        for (auto &s : set) {
            a[j].emplace_back(-rhs[i][s]);
            j++;
        }
    }
    assert(a[0].size() == lhs.size() + rhs.size());
    return a;
}

std::vector<std::map<std::string, ll>> molecule_sequence(State &begin) {
    std::vector<std::map<std::string, ll>> mole;
    mole.emplace_back(molecule(begin));
    while (expect(begin, '+')) {
        consume(begin, '+');
        mole.emplace_back(molecule(begin));
    }
    return mole;
}

std::map<std::string, ll> molecule(State &begin) {
    auto ret = group(begin);
    while (isAlpha(*begin) || expect(begin, '(')) {
        for (auto [s, c] : group(begin)) {
            ret[s] += c;
        }
    }
    return ret;
}

std::map<std::string, ll> group(State &begin) {
    auto ret = unit_group(begin);
    if (isdigit(*begin)) {
        ll num = number(begin);
        for (auto &p : ret) {
            p.second *= num;
        }
    }
    return ret;
}

std::map<std::string, ll> unit_group(State &begin) {
    if (isAlpha(*begin)) {
        std::string ret = "";
        ret += *begin;
        consume(begin, *begin);
        if (isalpha(*begin)) {
            ret += *begin;
            consume(begin, *begin);
        }
        std::map<std::string, ll> map;
        map[ret] = 1;
        return map;
    } else {
        consume(begin, '(');
        auto ret = molecule(begin);
        consume(begin, ')');
        return ret;
    }
}

ll number(State &begin) {
    ll ret = 0;
    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        consume(begin, *begin);
    }
    return ret;
}

int main() {
    std::string s;
    while (std::cin >> s, !(s == ".")) {
        State begin = s.begin();
        auto a = chemical_equation(begin);
        consume(begin, '.');
        a = gauss_jordan<rational>(a);
        int n = a.size();
        int m = a[0].size();
        int x = -1;
        {
            bool is_break = false;
            rrep(i, 0, n) {
                if (is_break) break;
                rep(j, 0, m) {
                    if (a[i][j] != 0) {
                        x = j + 1;
                        is_break = true;
                        break;
                    }
                }
            }
        }
        std::vector<ll> ans(m, 1);
        rep(j, x, m) {
            rep(i, 0, n) {
                if (a[i][j] != 0) {
                    ans[j] = std::lcm(ans[j], a[i][j].val().second);
                }
            }
        }
        rep(i, 0, x) {
            ans[i] = 0;
            rep(j, x, m) {
                ans[i] -= (a[i][j] * ans[j]).val().first;
            }
        }
        rep(i, 0, m) {
            std::cout << ans[i] << " \n"[i == m - 1];
        }
    }
}
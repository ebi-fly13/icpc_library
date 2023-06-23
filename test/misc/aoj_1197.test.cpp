#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1197&lang=en"

#include "../../misc/dice.hpp"
#include "../../template/template.hpp"

bool input(std::vector<int> &t) {
    int zero = 0;
    rep(i, 0, 6) {
        std::cin >> t[i];
        if (t[i] == 0) zero++;
    }
    if (zero == 6) return false;
    return true;
}

using namespace lib;

int main() {
    std::vector<int> t(6);
    while (input(t)) {
        int sum = 0;
        rep(i, 0, 6) sum += t[i];
        int p, q;
        std::cin >> p >> q;
        p--;
        std::vector<int> idxs(6);
        std::iota(all(idxs), 0);
        std::string ans = "";
        do {
            std::vector<int> val(6);
            rep(i, 0, 6) val[i] = t[idxs[i]];
            Dice dice;
            dice.set_val(val);
            auto check = [&]() -> bool {
                int na = dice.top_val() + dice.down_val();
                int nb = dice.left_val() + dice.right_val();
                int nc = dice.front_val() + dice.back_val();
                return dice.top_val() >= 0 && na <= nb + nc &&
                       nb <= 1 + nc + na && nc <= 1 + na + nb;
            };
            if (!check()) {
                continue;
            }
            std::string s = "";
            rep(_, 0, sum) {
                {
                    dice.rollE();
                    dice.val[dice.up]--;
                    if (check()) {
                        s += 'E';
                        continue;
                    }
                    dice.val[dice.up]++;
                    dice.rollW();
                }
                {
                    dice.rollN();
                    dice.val[dice.up]--;
                    if (check()) {
                        s += 'N';
                        continue;
                    }
                    dice.val[dice.up]++;
                    dice.rollS();
                }
                {
                    dice.rollS();
                    dice.val[dice.up]--;
                    if (check()) {
                        s += 'S';
                        continue;
                    }
                    dice.val[dice.up]++;
                    dice.rollN();
                }
                {
                    dice.rollW();
                    dice.val[dice.up]--;
                    if (check()) {
                        s += 'W';
                        continue;
                    }
                    dice.val[dice.up]++;
                    dice.rollE();
                }
                assert(0);
            }
            if (ans.empty())
                ans = s;
            else
                chmin(ans, s);
        } while (std::next_permutation(all(idxs)));
        if (ans.empty()) {
            std::cout << "impossible\n";
            continue;
        }
        std::cout << ans.substr(p, q - p) << '\n';
    }
}
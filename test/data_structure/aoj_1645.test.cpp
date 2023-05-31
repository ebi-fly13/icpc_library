#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1645"

#include "../../data_structure/undo_dsu.hpp"
#include "../../template/template.hpp"

struct Edge {
    int u, v, s;
};

using namespace lib;

int main() {
    int n, m;
    while (std::cin >> n >> m, !(n == 0 && m == 0)) {
        std::vector<Edge> edges(m);
        int max = -1;
        for (auto &[u, v, s] : edges) {
            std::cin >> u >> v >> s;
            u--;
            v--;
            chmax(max, s);
        }
        std::sort(all(edges), [](auto l, auto r) -> bool { return l.s > r.s; });
        std::vector g(n, std::vector<int>());
        undo_dsu uf(n);
        for (auto &[u, v, s] : edges) {
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            uf.merge(u, v);
        }
        std::reverse(all(edges));
        std::vector<int> seen(n, -1);
        int now = 0;
        std::set<std::pair<int, int>> set;
        set.insert({uf.size(0), uf.leader(0)});
        rep(i, 1, max + 1) {
            std::queue<int> que;
            std::vector<int> vs;
            while (now < m) {
                auto [u, v, s] = edges[now];
                if (s != i) break;
                /*
                std::cout << i << '\n';
                std::cout << "debug: " << u << " " << v << " " << s << '\n';
                */
                std::pair<int, int> p = {uf.size(u), uf.leader(u)};
                if (set.find(p) != set.end()) set.erase(p);
                uf.undo();
                g[u].pop_back();
                g[v].pop_back();
                if (seen[u] < 0) {
                    vs.emplace_back(u);
                    set.insert({uf.size(u), uf.leader(u)});
                }
                if (seen[v] < 0) {
                    vs.emplace_back(v);
                    set.insert({uf.size(v), uf.leader(v)});
                }
                now++;
            }
            int smax = set.rbegin()->first;
            for (auto v : vs) {
                if (smax > uf.size(v)) {
                    std::pair<int, int> p = {uf.size(v), uf.leader(v)};
                    if (set.find(p) != set.end()) set.erase(p);
                    que.push(v);
                    seen[v] = 1;
                }
            }
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto nv : g[v]) {
                    if (seen[nv] < 0) {
                        seen[nv] = 1;
                        que.push(nv);
                    }
                }
            }
        }
        std::vector<int> ans;
        rep(i, 0, n) {
            if (seen[i] > 0) continue;
            ans.emplace_back(i + 1);
        }
        rep(i, 0, ans.size()) {
            std::cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        }
    }
}
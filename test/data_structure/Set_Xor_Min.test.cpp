#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../data_structure/BinaryTrie.hpp"
#include "../../template/template.hpp"

int main() {
    BinaryTrie<int, 30> trie;
    int q;
    std::cin >> q;
    while (q--) {
        int t, x;
        std::cin >> t >> x;
        if (t == 0) {
            if (trie.count(x) > 0) continue;
            trie.insert(x);
        } else if (t == 1) {
            if (trie.count(x) == 0) continue;
            trie.erase(x);
        } else {
            trie.xor_all(x);
            std::cout << trie.get(0) << '\n';
            trie.xor_all(x);
        }
    }
}
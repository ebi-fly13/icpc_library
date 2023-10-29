#pragma once

#include "../template/template.hpp"

namespace lib {

template <class T> struct section_set {
  private:
    std::set<std::pair<T, T>> st;

  public:
    section_set() {
        st.insert(
            {std::numeric_limits<T>::min(), std::numeric_limits<T>::min()});
        st.insert(
            {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()});
    }

    std::set<std::pair<T, T>> sections() const {
        return st;
    }

    // [l, r)を追加
    void insert(T l, T r) {
        auto itr =
            std::prev(st.lower_bound({l, std::numeric_limits<T>::min()}));
        if (l <= itr->second) {
            assert(itr->first <= l);
            l = itr->first;
            r = std::max(r, itr->second);
            st.erase(itr);
        }
        itr = st.lower_bound({l, std::numeric_limits<T>::min()});
        while (itr->first <= r) {
            assert(l <= itr->first);
            r = std::max(r, itr->second);
            itr = st.erase(itr);
        }
        st.insert({l, r});
        return;
    }

    // 集合内の[l, r)に含まれている要素を削除
    void erase(T l, T r) {
        auto itr =
            std::prev(st.lower_bound({l, std::numeric_limits<T>::min()}));
        if (l < itr->second) {
            assert(itr->first < l);
            st.insert({itr->first, l});
            if (r < itr->second) {
                st.insert({r, itr->second});
            }
            st.erase(itr);
        }
        itr = st.lower_bound({l, std::numeric_limits<T>::min()});
        while (itr->first < r) {
            if (itr->second <= r) {
                itr = st.erase(itr);
            } else {
                st.insert({r, itr->second});
                st.erase(itr);
                break;
            }
        }
        return;
    }

    bool find(T x) const {
        auto itr =
            std::prev(st.upper_bound({x, std::numeric_limits<T>::max()}));
        if (x < itr->second) {
            assert(itr->first <= x);
            return true;
        } else {
            return false;
        }
    }

    bool find(T l, T r) const {
        auto itr =
            std::prev(st.upper_bound({l, std::numeric_limits<T>::max()}));
        if (r <= itr->second) {
            assert(itr->first <= l);
            return true;
        } else {
            return false;
        }
    }

    std::pair<T, T> belong(T x) const {
        auto itr =
            std::prev(st.upper_bound({x, std::numeric_limits<T>::max()}));
        if (x <= itr->second) {
            assert(itr->first <= x);
            return *itr;
        } else {
            return {0, 0};
        }
    }

    std::pair<T, T> lower_bound(T l) const {
        return *st.lower_bound({l, -1});
    }
};

}  // namespace lib
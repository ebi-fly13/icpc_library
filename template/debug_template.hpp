#pragma once

#include "../template/template.hpp"

#define debug(...)                                                     \
    std::cerr << "LINE: " << __LINE__ << " [" << #__VA_ARGS__ << "]:", \
        debug_out(__VA_ARGS__)

void debug_out() {
    std::cerr << std::endl;
}

template <typename Head, typename... Tail> void debug_out(Head h, Tail... t) {
    std::cerr << " " << h;
    if (sizeof...(t) > 0) std::cerr << ",";
    debug_out(t...);
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa) {
    return os << pa.first << " " << pa.second;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    for (std::size_t i = 0; i < vec.size(); i++)
        os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    return os;
}
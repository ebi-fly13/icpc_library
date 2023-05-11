#pragma once

#include"../template/template.hpp"

namespace lib {

template<typename T>
struct Vec {
    T x, y;
    Vec (T _x = T(0), T _y = T(0)) : x(_x), y(_y) {}
    Vec& operator*=(const T& a){
        x *= a;
        y *= a;
        return *this;
    }
    Vec& operator/=(const T& a){
        x /= a;
        y /= a;
        return *this;
    }
    Vec& operator+=(const Vec& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vec& operator-=(const Vec& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    friend bool operator==(const Vec& lhs, const Vec& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
    friend bool operator!=(const Vec& lhs, const Vec& rhs) {
        return lhs.x != rhs.x || lhs.y != rhs.y;
    }
    friend Vec operator+(const Vec& lhs, const Vec& rhs) {
        return Vec(lhs) += rhs;
    }
    friend Vec operator-(const Vec& lhs, const Vec& rhs) {
        return Vec(lhs) -= rhs;
    }
    friend Vec operator*(const Vec& lhs, const T& rhs) {
        return Vec(lhs) *= rhs;
    }
    friend Vec operator*(const T& rhs, const Vec& lhs) {
        return Vec(lhs) *= rhs;
    }
    friend Vec operator/(const Vec& lhs, const T& rhs) {
        return Vec(lhs) /= rhs;
    }
    friend Vec operator/(const T& rhs, const Vec& lhs) {
        return Vec(lhs) /= rhs;
    }
};

template<typename T>
T dot(const Vec<T> &a, const Vec<T> &b){
    return a.x * b.x + a.y * b.y;
}

// cross > 0 : counter clockwise a -> b
template<typename T>
T cross(const Vec<T> &a, const Vec<T> &b){
    return a.x * b.y - a.y * b.x;
}

template<typename T>
ld abs(const Vec<T> &a){
    return sqrtl(a.x*a.x+a.y*a.y);
}

template<typename T>
T norm(const Vec<T> &a){
    return a.x*a.x+a.y*a.y;
}

template<typename T>
struct Line {
    Vec<T> p, q;
};

template<typename T>
int intersection(const Line<T> &a, const Line<T> &b){
    if (cross(a.p-a.q,b.p-b.q) == 0){
        if (cross(a.p-b.p,a.q-b.p) == 0) return 2;
        return 0;
    }
    return 1;
}

// intersection == 1 (cross(a.p-a.q,b.p-b.q) != 0)
template<typename T>
Vec<T> cross_point(const Line<T> &a, const Line<T> &b){
    Vec<T> va = a.p-a.q, vb = b.p-b.q;
    Vec<T> ba = b.p-a.q;
    T alpha = cross(ba,vb) / cross(va,vb);
    return alpha * a.p + (1 - alpha) * a.q;
}


} // namespace lib
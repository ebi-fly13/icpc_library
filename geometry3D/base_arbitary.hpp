#pragma once

#include"../template/template.hpp"

namespace lib {

template<typename T>
struct Vec {
    T x, y, z;
    Vec (T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y), z(_z) {}
    Vec& operator*=(const T& a){
        x *= a;
        y *= a;
        z *= a;
        return *this;
    }
    Vec& operator/=(const T& a){
        x /= a;
        y /= a;
        z /= a;
        return *this;
    }
    Vec& operator+=(const Vec& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    Vec& operator-=(const Vec& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
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
    friend std::ostream &operator<<(std::ostream &os,const Vec&r) {
        return os << "(" << r.x << "," << r.y << "," << r.z << ")"; 
    }
};

};
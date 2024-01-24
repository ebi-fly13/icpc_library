#pragma once

#include "../../template/template.hpp"
#include "../base_arbitary.hpp"



template<typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

template<typename T>
T dot(const Vec<T> &a, const Vec<T> &b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

template<typename T>
Vec<T> cross(const Vec<T> &a, const Vec<T> &b){
    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

template<typename T>
T norm(const Vec<T> &a){
    return a.x*a.x+a.y*a.y+a.z*a.z;
}


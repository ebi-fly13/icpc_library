#pragma once

#include"../template/template.hpp"

namespace lib{

using namespace std;

template<typename T, int MAX_LOG> // T = int/ll, 0 <= x < 2 ^ MAX_LOG
struct BinaryTrie{ // set(NOT multiset) of integer
    struct node{
        node *p;
        array<node*,2> ch;
        int exist; // number of item
        int sz; // number of integers exist in the subtree of this node
        node () : p(nullptr), ch({nullptr,nullptr}), exist(0), sz(0) {}
    };
    BinaryTrie () : lazy(T(0)){}
    int size(node *v){
        if (v == nullptr){return 0;}
        return v->sz;
    }
    int count(T x = -1) {
        node *v = root;
        if(x < 0) return v->sz;
        x ^= lazy;
        rrep(i,0,MAX_LOG) {
            int j = x >> i & 1;
            if(v->ch[j] == nullptr) {
                return 0;
            }
            v = v->ch[j];
        }
        return v->sz;
    }
    void insert(T x){
        x ^= lazy;
        node *v = root;
        rrep(i,0,MAX_LOG){
            int j = x >> i & 1;
            if (v->ch[j] == nullptr){
                v->ch[j] = new node();
                v->ch[j]->p = v;
            }
            v = v->ch[j];
        }
        v->exist++;
        update(v);
        rep(i,0,MAX_LOG){
            v = v->p;
            update(v);
        }
    }
    void erase(T x){
        x ^= lazy;
        node *v = root;
        rrep(i,0,MAX_LOG){
            int j = x >> i & 1;
            if (v->ch[j] == nullptr){
                return ;
            }
            v = v->ch[j];
        }
        if (v->exist == 0) return ;
        v->exist--;
        update(v);
        rrep(i,0,MAX_LOG){
            node *p = v->p;
            if (size(v) == 0){
                if (v == p->ch[0]) p->ch[0] = nullptr;
                else p->ch[1] = nullptr;
                delete v;
            }
            v = p;
            update(v);
        }
    }
    int order(T x){ // number of element which is less than x
        node *v = root;
        int res = 0;
        rrep(i,0,MAX_LOG){
            int j = lazy >> i & 1;
            if ((x >> i & 1) == 0){
                v = v->ch[j];
            }
            else {
                res += size(v->ch[j]);
                v = v->ch[j^1];
            }
            if (v == nullptr){
                break;
            }
        }
        return res;
    }
    T get(int k){ // value of kth(0_indexed) element, order(get(k)) = k
        node *v = root;
        T ans = T(0);
        rrep(i,0,MAX_LOG){
            int j = lazy >> i & 1;
            if (k < size(v->ch[j])){
                v = v->ch[j];
            }
            else {
                k -= size(v->ch[j]);
                v = v->ch[j^1];
                ans |= T(1) << i;
            }
        }
        return ans;
    }
    void xor_all(T x){lazy ^= x;}
  private:
    T lazy;
    node *root = new node();
    void update(node *v){
        v->sz = v->exist + size(v->ch[0]) + size(v->ch[1]);
    }
};

} // namespace lib
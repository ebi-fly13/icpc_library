#pragma once

#include"../template/template.hpp"
#include"base_ld.hpp"
#include"../data_structure/dsu.hpp"

namespace lib{

struct circle {
    vec c;
    ld r;
};

// c1 != c2
vector<ld> cross_point_x(const circle &c1, const circle &c2){
    assert(sgn(abs(c1.r - c2.r)) != 0 || sgn(abs(c1.c - c2.c)) != 0);
    ld d = abs(c1.c - c2.c);
    // 円が離れすぎている
    if (sgn(d - c1.r - c2.r) > 0) return {};
    // 円が近すぎる
    if (sgn(abs(c1.r - c2.r) - d) > 0) return {};
    // 外接している
    if (sgn(d - c1.r - c2.r) == 0){
        return {(c1.r*c2.c.real() + c2.r*c1.c.real()) / (c1.r + c2.r)};
    }
    // 内接している
    if (sgn(abs(c1.r - c2.r) - d) == 0){
        return {(c1.r * c2.c.real() - c2.r * c1.c.real()) / (c1.r - c2.r)};
    }
    // 2 点を共有する
    ld e = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
    vec p = c1.c + (c2.c - c1.c) * e / d;
    vec v((c1.c - c2.c).imag(),(c2.c - c1.c).real());
    v *= sqrtl(max(c1.r * c1.r - e * e, ld(0))) / abs(v);
    return {(p+v).real(),(p-v).real()};
}

vector<ld> cross_point_y(const circle &c, const ld &x){
    int cond = sgn(abs(c.c.real() - x) - c.r); 
    if (cond > 0) return {};
    if (cond == 0) return {c.c.imag()};
    ld ydiff = sqrtl(max(c.r*c.r - (x - c.c.real()) * (x - c.c.real()),ld(0)));
    return {c.c.imag()+ydiff,c.c.imag()-ydiff};
}

struct Partition_by_Circles {
    vector<circle> a;
    // 同じ円は与えられない
    void add_circle(circle c){
        // x 座標で区切る場所が重ならないように 1 rad 回転しておく
        c.c = rot(c.c,1);
        a.emplace_back(c);
    }
    ld coordinate_width(){
        ld res = 0.0;
        for (auto &c : a){
            chmax(res,abs(c.c)+c.r);
        }
        return res;
    }
    vector<ld> x_coordinates(){
        vector<ld> xs;
        for (auto &c : a){
            xs.emplace_back(c.c.real()-c.r);
            xs.emplace_back(c.c.real()+c.r);
        }
        int siza = a.size();
        for (int i = 0; i < siza-1; i++) for (int j = i+1; j < siza; j++){
            for (auto x : cross_point_x(a[i],a[j])){
                bool yet = true;
                for (auto testx : xs){
                    if (sgn(abs(x - testx)) == 0){
                        yet = false;
                        break;
                    }
                }
                if (yet) xs.emplace_back(x);
            }
        }
        sort(all(xs));
        return xs;
    }
    using ylr = tuple<ld,int,int>;
    vector<ylr> y_coordinates(ld x){
        vector<ylr> ys;
        auto add = [&](ld y, int l, int r){
            bool yet = true;
            for (auto &[testy, testl, testr] : ys){
                if (sgn(abs(y - testy)) == 0){
                    yet = false;
                    testl += l;
                    testr += r;
                    break;
                }
            }
            if (yet) ys.push_back({y,l,r});
        };
        for (auto &c : a){
            auto vecy = cross_point_y(c,x);
            if (vecy.empty()) continue;
            if ((int)(vecy.size()) == 2){
                for (auto y : vecy) add(y,1,1);
            }
            else {
                if (c.c.real() < x){
                    add(vecy[0],2,0);
                }
                else {
                    add(vecy[0],0,2);
                }
            }
        }
        sort(all(ys),[&](ylr lhs, ylr rhs){
            return get<0>(lhs) < get<0>(rhs);
        });
        return ys;
    }
    dsu d;
    vector<ld> xs;
    vector<int> lower_idx;
    map<int,int> mp;
    vector<vector<int>> build_graph(ld max_width = 0){
        // 大きな円で全体を囲ってしまう
        if (sgn(max_width) == 0) max_width = coordinate_width()*2;
        a.push_back({vec(0,0),max_width});
        // x 座標の列挙
        xs = x_coordinates();
        // 各 x について y 座標の列挙
        vector<vector<ylr>> yss; yss.reserve(xs.size());
        for (auto &x : xs) yss.push_back(y_coordinates(x));
        // x で切って領域を舐める
        int idx = 0;
        vector<pair<int,int>> es, merge;
        vector<int> cur;
        for (int itr = 0; itr < (int)(xs.size())-1; itr++){
            lower_idx.emplace_back(idx);
            vector<int> lid, rid;
            for (int l = 0; l < (int)(yss[itr].size()); l++){
                for (int t = 0; t < get<2>(yss[itr][l]); t++){
                    lid.emplace_back(l);
                }
            }
            for (int r = 0; r < (int)(yss[itr+1].size()); r++){
                for (int t = 0; t < get<1>(yss[itr+1][r]); t++){
                    rid.emplace_back(r);
                }
            }
            assert(lid.size() == rid.size());
            int pre = 0;
            vector<int> nxt;
            for (int i = 0; i < (int)(lid.size())-1; i++){
                for (int t = 0; t < rid[i+1]-rid[i]; t++){
                    nxt.emplace_back(idx);
                }
                if (i != 0){
                    es.emplace_back(idx-1,idx);
                }
                if (lid[i+1] - lid[i] != 0){
                    merge.emplace_back(cur[pre++],idx);
                }
                if (lid[i+1] - lid[i] == 2){
                    merge.emplace_back(cur[pre++],idx);
                }
                idx++;
            }
            swap(cur,nxt);
        }
        // グラフを構築
        d = dsu(idx);
        for (auto &[u, v] : merge) d.merge(u,v);
        set<int> st;
        for (int i = 0; i < idx; i++) st.insert(d.leader(i));
        int vid = 0;
        for (auto v : st) mp[v] = vid++;
        vector<vector<int>> graph(vid);
        for (auto [u, v] : es){
            u = mp[d.leader(u)];
            v = mp[d.leader(v)];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        return graph;
    }
    int get_area_idx(vec p){
        p = rot(p,1);
        int xid = int(lower_bound(all(xs),p.real()) - xs.begin()) - 1;
        vector<ld> ys;
        for (auto &[y, l, r] : y_coordinates(p.real())) ys.emplace_back(y);
        int yid = int(lower_bound(all(ys),p.imag()) - ys.begin()) - 1;
        return mp[d.leader(lower_idx[xid] + yid)];
    }
};

} //namespace lib
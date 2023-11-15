#pragma once
#include "../template/template.hpp"

namespace lib {
using namespace std;

template<class Cap, class Cost> struct shobon_mcf {
  struct E{
    int from;
    int to;
    int rev;
    Cap cap;
    Cost cost;
  };
  
  int n;
  vector<E> e;
  vector<Cost> p;
  vector<vector<int>> ikeru;
  const Cost inf = numeric_limits<Cost>::max() / 4;

  shobon_mcf(int n): n(n) {
    ikeru.resize(n);
    p.resize(n);
  }  

  void add_edge(int from, int to, Cap cap, Cost cost){
    int x = e.size();
    e.push_back({from, to, x + 1, cap, cost});
    e.push_back({to, from, x, 0, -cost});
    ikeru[from].push_back(x);
    ikeru[to].push_back(x+1);
  }

  pair<Cap, Cost> flow(int from, int to, Cap f){
    Cap cap = 0;
    Cost cost = 0;
    
    while(f > 0){
      vector<Cost> d(n, inf);
      vector<int> cf(n, -1);
      priority_queue<pair<Cost,int>> pq;
      pq.push(pair(0, from));
      d[from] = 0;
      while(!pq.empty()){
        auto [tmp, i] = pq.top();
        pq.pop();
        tmp = -tmp;
        if (tmp > d[i]) continue;
        for (int x: ikeru[i]){
          int j = e[x].to;
          if (e[x].cap == 0) continue;
          if (chmin(d[j], e[x].cost + tmp + p[i] - p[j])){
            cf[j] = x;
            pq.push(pair(-d[j], j));
          }
        }
      }

      if (d[to] == inf) break;
      rep(i,0,n) p[i] += d[i];

      Cap z = f;
      int nw = to;
      while (nw != from){
        chmin(z, e[cf[nw]].cap);
        nw = e[cf[nw]].from;
      }

      f -= z;
      cap += z;
      cost += z * p[to];

      nw = to;
      while (nw != from){
        e[cf[nw]].cap -= z;
        e[e[cf[nw]].rev].cap += z;
        nw = e[cf[nw]].from;
      }
    }

    return pair(cap, cost);
  }

  pair<Cap, Cost> flow(int from, int to){
    return flow(from, to, numeric_limits<Cap>::max());
  }

  // Type the following code if you need
  // Return the edges

  vector<E> edges(){
    vector<E> ret((int)e.size() / 2);
    rep(i,0,(int)e.size() / 2) ret[i] = e[2*i];
    return ret;
  }

  // Init the potential with Bellman-Ford

  void potential_bellman_ford(int from){
    int m = (int)e.size() / 2;
    fill(all(p), inf);
    p[from] = 0;
    rep(num,0,n){
      rep(x,0,m){
        int i = e[2*x].from;
        int j = e[2*x].to;
        chmin(p[j], p[i] + e[2*x].cost);
      }
    }
  }

  // Init the potential with DP on DAG

  void potential_dag(int from){
    vector<int> deg(n);
    rep(x,0,(int)e.size()){
      if (e[x].cap > 0){
        deg[e[x].to]++;
      }
    }
    
    assert(deg[from] == 0);

    fill(all(p), inf);
    p[from] = 0;
    vector<int> mada;
    rep(i,0,n){
      if (deg[i] == 0) mada.push_back(i);
    }

    int cnt = 0;
    while(!mada.empty()){
      int i = mada.back();
      mada.pop_back();
      cnt++;
      for (int x: ikeru[i]){
        if (e[x].cap == 0) continue;
        int j = e[x].to;
        chmin(p[j], p[i] + e[x].cost);
        deg[j]--;
        if (deg[j] == 0){
          mada.push_back(j);
        }
      }
    }
    
    assert(cnt == n);
  }

};

}

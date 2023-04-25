#pragma once
#include "../template/template.hpp"

namespace lib{
using namespace std;

struct ford_mf{
	struct edge{int to, cap, rev;};
	int n;
	vector<int> a;
	vector<vector<edge>> g;
	vector<bool> used;

	ford_mf(int ni){
		n = ni;
		a.resize(ni);
		g.resize(ni);
		used.resize(ni);
	}

	void add_edge(int from, int to, int cap){
		g[from].push_back((edge){to,cap,(int)g[to].size()});
		g[to].push_back((edge){from,0,(int)g[from].size()-1});
	}

	int dfs(int v,int t,int f){
		if (v==t) return f;
		used[v] = true;
		for(edge &e: g[v]){
			if (!used[e.to] && e.cap>0){
				int d = dfs(e.to, t, min(f,e.cap));
				if (d > 0){
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t){
		int flow = 0;
		for(;;){
			fill(all(used),false);
			int f = dfs(s, t, 1e9);
			if (f==0) return flow;
			flow += f;
		}
	}
};

}

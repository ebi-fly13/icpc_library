#define PROBLEM \
	"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "../../graph/shobon_mcf.hpp"
#include "../../template/template.hpp"

int main(){
	int v,e,f; std::cin>>v>>e>>f;
	lib::shobon_mcf<int,int> mcf(v);
	for (int i=0;i<e;i++){
		int a,b,c,d; std::cin >> a >> b >> c >> d;
		mcf.add_edge(a,b,c,d);
	}
	auto [flow, cost] = mcf.flow(0,v-1,f);
	if (flow != f) std::cout << "-1\n";
	else std::cout << cost << '\n';
}
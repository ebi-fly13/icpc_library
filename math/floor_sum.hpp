#pragma once
#include "../template/template.hpp"


using namespace std;

ll floor_sum(ll n, ll m, ll a, ll b){
	if (n == 0) return 0;
	ll ret = 0;
	
	/* if [a >= 0 and b >= 0] is guaranteed, ignore from here */
	if (a < 0){
		ll a2 = a % m;
		if (a2 < 0) a2 += m;
		ret -= (ll)n * (n-1) / 2 * ((a2 - a) / m);
		a = a2;
	}
	if (b < 0){
		ll b2 = b % m;
		if (b2 < 0) b2 += m;
		ret -= (ll)n * ((b2 - b) / m);
		b = b2;
	}
	/* till here */

	if (a >= m){
		ret += n * (n-1) / 2 * (a / m);
		a %= m;
	}
	if (b >= m){
		ret += n * (b / m);
		b %= m;
	}
	ll y = (a * n + b) / m;
	ll z = (a * n + b) % m;
	return ret + floor_sum(y, a, m, z);
}


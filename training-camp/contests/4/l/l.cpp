//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define elif else if
#define ll long long int
#define ld long double
#define vec vector
#define forn(a) for(ll a=0; a<n; a++)
#define fore(a, v, n) for(ll a=v; a<n; a++)
#define all(x) x.begin(), x.end()
#define presicion(x) cout<<fixed<<setprecision(x)
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define PI 3.14159265358979323
#define sen(ang) sin((ang)*PI/180)
//cout<<flush;

using namespace std;

ll next_b(ll b, ll w, ll x) {
	return w - (x - (b % x));
}


vector<ll> first_bs(ll b, ll w, ll x, ll& repeated_index) {
	vector<ll> bs;
	vector<ll> module_pos(1000, -1);
	bs.push_back(b);
	ll next = next_b(b, w, x);
	do {
		bs.push_back(next);
		ll resto = next % x;
		if (module_pos[resto] != -1) {
			repeated_index = module_pos[resto];
			break;
		} else {
			module_pos[resto] = bs.size();
		}
		next = next_b(next, w, x);
	} while (true);
	return bs;
}

ll time_for_b(ll b, ll x) {
	return b / x + 1;
}

ll time_for_cycle(ll first_cycle_time, ll cycle_time, ll cycle_number) {
	ll time = 0;
	if (cycle_number > 0) {
		time = first_cycle_time + (cycle_number - 1) * cycle_time;
	}
	return time;
}

ll restado_for_cycle(ll restado_first_cycle, ll restado_cycle, ll cycle_number) {
	ll restado = 0;
	if (cycle_number > 0) {
		restado = restado_first_cycle + (cycle_number - 1) * restado_cycle;
	}
	return restado;
}


int main() {
	IOS;

	ll a, b, w, x, c;
	cin >> a >> b >> w >> x >> c;


	if (c <= a) {
		cout << 0 << endl;
		return 0;
	}

	ll repeated_index;
	vector<ll> bs = first_bs(b, w, x, repeated_index);
	// assert(bs.size() <= 1001);

	ll first_cycle_time = 0;
	ll cycle_time = 0;
	fore (i, 0, bs.size()) {
		ll time = time_for_b(bs[i], x);
		if (i >= repeated_index) {
			cycle_time += time;
		}
		first_cycle_time += time;
	}


	ll first_cycle_restado = bs.size();
	ll restado_per_cycle = bs.size() - repeated_index;


	ll from = 1;
	if (c - first_cycle_time > a - first_cycle_restado) {
		from = (c - a + first_cycle_restado - first_cycle_time) /
			(cycle_time - restado_per_cycle) + 1;
	}


	// // Encontramos cuantas veces tiene que ciclar como máximo
	// // para que a siga siendo menor a c.
	// ll from = 1;
	// ll to = (a - c) * 1000'000'000'000;
	// while (from < to) {
	// 	ll middle = (from + to) / 2;
	// 	// ciclamos middle veces
	// 	ll time = time_for_cycle(first_cycle_time, cycle_time, middle);

	// 	// cada ciclo hay que ver cuánto resta de a.
	// 	ll restado = restado_for_cycle(first_cycle_restado, restado_per_cycle, middle);
	// 	ll a_after_cycling = a - restado;
	// 	if (c - time <= a_after_cycling) {
	// 		// tenemos que disminuir cuanto ciclamos
	// 		to = middle;
	// 	} else {
	// 		from = middle + 1;
	// 	}
	// }

	from--;

	// from es cuanto tenemos que ciclar como mínimo.
	ll from_time = time_for_cycle(first_cycle_time, cycle_time, from);
	// avanzamos en el tiempo de a uno hasta que c <= a
	c = c - from_time;
	ll restado = restado_for_cycle(first_cycle_restado, restado_per_cycle, from);
	a -= restado;
	if (from > 0) {
		b = bs[repeated_index];
	}

	while (c > a) {
		from_time++;
		c--;
		if (b >= x) {
			b = b - x;
		} else {
			a--;
			b = w - (x - b);
		}
	}

	cout << from_time << endl;






	return 0;
}

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

map<ll, ll> factorizar(ll n) {
	map<ll,ll> rta;
	for (int i = 2; i <= n; i++)
		while (n % i == 0) {
			rta[i]++;
			n /= i;
		}
	if(n!=1) rta[n]++;
	return rta;
}

ll divisores(const map<ll, ll>& fact) {
	ll rta = 1;
	for (auto e : fact) {
		rta *= (e.second + 1);
	}
	return rta;
}

int main() {
	IOS;
	ll t, n, rta, _max, _min;
	bool error;
	vec<ll> ds;
	ds.reserve(300);

	cin >> t;
	while(t--) {
		error = false;
		_max = 0;
		_min = 10000000;
		ds.clear();
		cin >> n;

		for (int i = 0; i < n; i++) {
			ll d;
			cin >> d;
			ds.push_back(d);
			_max = max(_max, d);
			_min = min(_min, d);
		}

		rta = _max * _min;

		for (ll d : ds)
			if (rta % d != 0) {
				rta = -1;
				break;
			}

		if (rta == -1) {
			cout << -1 << endl;
			continue;
		}

		if (divisores(factorizar(rta)) - 2 != n) {
			cout << -1 << endl;
			continue;
		}

		cout << rta << endl;
	}

	return 0;
}

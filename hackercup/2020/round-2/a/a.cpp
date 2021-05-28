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

void solve() {
	ll n, k;
	cin >> n >> k;
	vec<ll> customers(n);
	fore (i, 0, k) cin >> customers[i];

	ll a ,b,c,d;
	cin >> a >> b >> c >> d;

	fore (i, k, n) {
		customers[i] = (a * customers[i-2] + b*customers[i-1] + c) % d;
	}

	vec<ll> mins(n);
	fore (i, 0, k) cin >> mins[i];
	cin >> a >> b >> c >> d;

	fore (i, k, n) {
		mins[i] = (a * mins[i-2] + b*mins[i-1] + c) % d;
	}

	vec<ll> maxs(n);
	fore (i, 0, k) cin >> maxs[i];
	cin >> a >> b >> c >> d;

	fore (i, k, n) {
		maxs[i] = (a * maxs[i-2] + b*maxs[i-1] + c) % d;
	}

	ll moves = 0;
	ll to_remove = 0;
	fore (i, 0, n) {
		to_remove += max(0ll, customers[i] - (maxs[i] + mins[i]));
	}
	ll i = 0;
	moves = to_remove;
	for (; i< n; i++) {
		if (customers[i] < mins[i]) {
			ll added = min(mins[i] - customers[i], to_remove);
			customers[i] += added;
			to_remove -= added;
			if (customers[i] < mins[i]) {
				break;
			}
		}
	}
	if (i < n) {
		// i es el primero al que todavía le falta
		ll sobra = 0;
		fore (j, 0, n) {
			customers[j] = min(mins[j] + maxs[j], customers[j]);
			sobra += max(0ll, customers[j] - mins[j]);
		}

		for (; i<n; i++) {
			if (customers[i] < mins[i]) {
				ll added = min(sobra, mins[i] - customers[i]);
				moves += added;
				customers[i] += added;
				sobra -= added;
				if (customers[i] < mins[i]) {
					cout << -1 << endl;
					return;
				}
			}
		}
	} else {
		// todavía nos sobra de algún lado
		for (ll j = 0; j < n && to_remove > 0; j++) {
			if (customers[j] < mins[j] + maxs[j]) {
				ll added = min(mins[j] + maxs[j] - customers[j], to_remove);
				to_remove -= added;
				customers[j] += added;
			}
		}
		if (to_remove > 0) {
			cout << -1 << endl;
			return;
		}
	}

	cout << moves << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}

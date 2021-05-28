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

ll solve_type_1(vec<ll>& factorials, vec<ll>& acum, ll moves, ll l, ll r) {
	ll n = acum.size() - 1;
	ll last = min(16LL, n);
	ll res = 0;
	// pueden cambiar solo los ultimos 16
	ll right_acum = min(r, n - last);
	if (right_acum >= l) res += acum[right_acum] - acum[l-1];
	vec<ll> ultimos;
	vec<bool> usados(last, false);
	for (ll i = n - last+1; i <= n; i++) {
		ultimos.push_back(i);
	}
	for (ll i = last-1; i >= 0; i--) {
		ll avanza = moves / factorials[i];
		ll comidos = 0;
		ll pos_ultimo = 0;
		do {
			while (usados[pos_ultimo]) pos_ultimo++;
			comidos++;
		} while (comidos <= avanza);
		usados[pos_ultimo] = true;

		ll pos = n - i;
		if (pos >= l && pos <= r) res += ultimos[pos_ultimo];
		moves = moves % factorials[i];
	}

	return res;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	ll q;
	cin >> q;

	vec<ll> factorials;
	ll curr = 1;
	for (ll i = 1; i <= 16; i++) {
		factorials.push_back(curr);
		curr *= i;
	}

	vec<ll> acum(n+1);
	curr = 0;
	for (ll i = 0; i <= n; i++) {
		acum[i] = curr;
		curr += i;
	}

	ll moves = 0;
	while (q--) {
		ll type;
		cin >> type;
		if (type == 1) {
			ll l, r;
			cin >> l >> r;

			cout << solve_type_1(factorials, acum, moves, l, r) << endl;
		} else {
			ll x;
			cin >> x;
			moves += x;
		}
	}

	return 0;
}

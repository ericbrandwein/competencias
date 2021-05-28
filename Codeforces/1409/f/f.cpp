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

ll max_combi(string& s, string& t, ll moves, vec<ll> border_removed) {
	moves -= border_removed[0] + border_removed[1];
	if (moves < 0) {
		return 0;
	}

	string new_s = s;
	for (ll i = 0; i < s.size() && border_removed[1] > 0; i++) {
		if (s[i] == t[1]) {
			new_s[i] = t[0];
			border_removed[1]--;
		}
	}

	for (ll i = s.size() - 1; i >= 0 && border_removed[0] > 0; i--) {
		if (s[i] == t[0]) {
			new_s[i] = t[1];
			border_removed[0]--;
		}
	}

	ll n = s.size();
	vec<ll> bests(2);
	vec<ll> amounts(2, 0);
	bests[0] = 0;
	for (ll i = 0; i < n; i++) {
		if (new_s[i] != t[0] && new_s[i] != t[1]) {
			break;
		}
		bests[0]++;
	}
	bests[1] = n - 1;
	for (;bests[1] >= 0 && (new_s[bests[1]] == t[0] || new_s[bests[1]] == t[1]); bests[1]--);

	for (ll i = 0; i < bests[1]; i++) {
		if (new_s[i] == t[0]) amounts[1]++;
	}

	for (ll i = n - 1; i > bests[0]; i--) {
		if (new_s[i] == t[1]) amounts[0]++;
	}

	while (moves > 0 && bests[0] <= bests[1]) {
		ll pos = 0;
		if (amounts[0] < amounts[1]) {
			// cambiamos el de la derecha
			pos = 1;
		}
		new_s[bests[pos]] = t[pos];
		amounts[(pos + 1) % 2]++;
		ll dir = -(pos *2 - 1);
		for (;
			bests[pos] >= 0 && bests[pos] < n &&
				(new_s[bests[pos]] == t[0] || new_s[bests[pos]] == t[1]);
			bests[pos] += dir
		) {
			if (new_s[bests[pos]] == t[(pos + 1) % 2]) {
				amounts[pos]--;
			}
		}
		moves--;
	}

	ll total = 0;
	ll acum = 0;
	for (ll i = 0; i < n; i++) {
		if (new_s[i] == t[0]) acum++;
		if (new_s[i] == t[1]) total += acum;
	}

	return total;
}

int main() {
	IOS;


	ll n, moves;
	cin >> n >> moves;
	string s;
	cin >> s;
	string t;
	cin >> t;
	ll combi = 0;
	if (t[0] != t[1]) {
		vec<ll> left(n + 1, 0);
		vec<ll> right(n + 1, 0);
		for (ll i = 1; i <= s.size(); i++) {
			left[i] = left[i - 1];
			if (s[i - 1] == t[0]) left[i]++;
		}

		for (ll i = s.size() - 1; i >= 0; i--) {
			right[i] = right[i + 1];
			if (s[i] == t[1]) right[i]++;
		}

		for (ll first = 0; first <= left[n]; first++) {
			for (ll second = 0; second <= right[0]; second++) {
				ll curr = max_combi(s, t, moves, {first, second});
				combi = max(combi, curr);
			}
		}
	} else {
		ll amount = 0;
		fore (i, 0, n) {
			if (s[i] == t[0]) amount++;
		}
		amount += min(n - amount, moves);
		combi = amount * (amount-1) / 2;
	}

	cout << combi << endl;

	return 0;
}

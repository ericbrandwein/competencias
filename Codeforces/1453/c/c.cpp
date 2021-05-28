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
	ll n;
	cin >> n;
	vec<string> rows(n);
	forn (i) cin >> rows[i];

	vec<ll> max_tris(10, 0);
	vec<vec<ll>> firsts(n, vec<ll>(10, LONG_LONG_MAX));
	vec<vec<ll>> lasts(n, vec<ll>(10, LONG_LONG_MAX));
	vec<ll> lowest(10, LONG_LONG_MAX);
	vec<ll> uppest(10, -1);
	for (ll row = 0; row < n; row++) {
		for (ll col = 0; col < n; col++) {
			ll curr_num = rows[row][col] - '0';
			if (firsts[row][curr_num] == LONG_LONG_MAX) {
				firsts[row][curr_num] = col;
			}
			lasts[row][curr_num] = col;
			lowest[curr_num] = min(lowest[curr_num], row);
			uppest[curr_num] = max(uppest[curr_num], row);
		}
	}

	for (ll row = 0; row < n; row++)
	for (char c = 0; c < 10; c++) {
		ll altura_add_alto = max(n - row - 1, row);
		ll ancho_add_alto = lasts[row][c] - firsts[row][c];
		ll adding_alto = altura_add_alto*ancho_add_alto;
		ll adding_bajo = 0;
		if (lasts[row][c] != LONG_LONG_MAX) {
			ll altura_add_bajo = max(abs(row - lowest[c]), abs(row - uppest[c]));
			ll ancho_add_bajo = max(lasts[row][c], n - 1 - firsts[row][c]);
			adding_bajo = altura_add_bajo*ancho_add_bajo;
		}
		max_tris[c] = max({max_tris[c], adding_alto, adding_bajo});
	}

	firsts = vec<vec<ll>>(n, vec<ll>(10, LONG_LONG_MAX));
	lasts = vec<vec<ll>>(n, vec<ll>(10, LONG_LONG_MAX));
	vec<ll> leftest(10, LONG_LONG_MAX);
	vec<ll> rightest(10, -1);
	for (ll col = 0; col < n; col++) {
		for (ll row = 0; row < n; row++) {
			ll curr_num = rows[row][col] - '0';
			if (firsts[col][rows[row][col] - '0'] == LONG_LONG_MAX) {
				firsts[col][rows[row][col] - '0'] = row;
			}
			lasts[col][rows[row][col] - '0'] = row;

			leftest[curr_num] = min(leftest[curr_num], col);
			rightest[curr_num] = max(rightest[curr_num], col);
		}
	}

	for (ll col = 0; col < n; col++) {
		for (char c = 0; c < 10; c++) {
			ll altura_add_alto = max(n - col - 1, col);
			ll ancho_add_alto = lasts[col][c] - firsts[col][c];
			ll adding_alto = altura_add_alto*ancho_add_alto;

			ll adding_bajo = 0;
			if (lasts[col][c] != LONG_LONG_MAX) {
				ll altura_add_bajo = max(abs(col - leftest[c]), abs(col - rightest[c]));
				ll ancho_add_bajo = max(lasts[col][c], n - 1 - firsts[col][c]);
				adding_bajo = altura_add_bajo*ancho_add_bajo;
			}
			max_tris[c] = max({max_tris[c], adding_alto, adding_bajo});
		}
	}

	for (ll num : max_tris) {
		cout << num << " ";
	}

	cout << endl;




}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}

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

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<ll> a(n);
	forn (i) cin >> a[i];

	vector<ll> sums(n + 1, 0);
	sums[0] = 0;
	fore (i, 1, n + 1) {
		sums[i] = sums[i - 1] + a[i - 1];
	}

	// cuanto mejoro si muevo para adelante
	vector<ll> cuanto_mejoro(n, 0);
	map<ll, ll> pos_anterior;
	ll max_mejora = 0;

	for (ll i = n - 1; i >= 0; i--) {
		ll num = a[i];
		ll prox;
		if (pos_anterior.count(num) == 0) {
			prox = n - 1;
		} else {
			prox = pos_anterior[num];
		}
		cuanto_mejoro[i] = cuanto_mejoro[prox] - (sums[prox + 1] - sums[i + 1]) +
			num * (prox - i);
		max_mejora = max(max_mejora, cuanto_mejoro[i]);
		pos_anterior[num] = i;
	}

	// cuanto mejoro si muevo para atras
	cuanto_mejoro = vector<ll>(n, 0);
	pos_anterior = map<ll, ll>();

	for (ll i = 0; i < n; i++) {
		ll num = a[i];
		ll prox;
		if (pos_anterior.count(num) == 0) {
			prox = 0;
		} else {
			prox = pos_anterior[num];
		}
		cuanto_mejoro[i] = cuanto_mejoro[prox] + (sums[i] - sums[prox]) -
			num * (i - prox);
		max_mejora = max(max_mejora, cuanto_mejoro[i]);
		pos_anterior[num] = i;
	}

	ll valor_original = 0;
	forn (i) {
		valor_original += a[i] * (i + 1);
	}

	cout << valor_original + max_mejora << endl;



	return 0;
}

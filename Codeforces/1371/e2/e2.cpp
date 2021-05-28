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

ll f(ll x, vector<ll>& a, ll p) {
	ll res = 1;
	ll curr_mult = 0;
	ll pos = 0;
	fore (i, 0, a.size()) {
		while (a[i] > x + pos) {
			res *= curr_mult;
			res %= p;
			curr_mult--;
			if (curr_mult < 0) curr_mult += p;
			pos++;
			if (pos >= a.size()) {
				goto end;
			}
		}
		curr_mult++;
		curr_mult %= p;
	}

	// Tenemos que ir multiplicando curr_mult por los x que queden
	for (; pos < a.size(); pos++) {
		res *= curr_mult;
		res %= p;
		curr_mult--;
		if (curr_mult < 0) curr_mult += p;
	}
end:
	return res;
}

int main() {
	IOS;

	ll p, n;
	cin >> n >> p;

	vector<ll> a(n);
	ll max_a = 0;
	forn (i) {
		cin >> a[i];
		max_a = max(max_a, a[i]);
	}

	sort(a.begin(), a.end());

	ll candies_necessary = 0;
	fore (i, 0, a.size()) {
		candies_necessary = max(
			candies_necessary,
			a[i] - i
		);
	}

	// Busqueda binaria por el primer x' cuya f sea divisible por p.
	// Se que todos los x > x' tienen f divisible por p.
	ll from = candies_necessary;
	ll to = max_a + 1;
	while (from < to) {
		ll middle = (from + to) / 2;
		if (f(middle, a, p) % p == 0) {
			to = middle;
		} else {
			from = middle + 1;
		}
	}

	vector<ll> good;
	fore (x, candies_necessary, from) {
		good.push_back(x);
	}

	cout << good.size() << endl;
	for (ll x : good) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

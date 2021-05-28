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

const ll MOD = 998244353;

struct modll {
	ll value;

	void adjust() {
		value %= MOD;
		if (value < 0) value += MOD;
	}

	modll(ll value) : value(value) {
		adjust();
	}

	modll operator*(ll other) const {
		return modll(value * other);
	}
	modll operator*(modll other) const {
		return modll(value * other.value);
	}
	void operator*=(ll other) {
		__int128 num = __int128(value) * other;
		value = num % MOD;
	}
	void operator*=(modll other) {
		__int128 num = __int128(value) * other.value;
		value = num % MOD;
	}


	modll operator+(ll other) const {
		return modll(value + other);
	}
	modll operator+(modll other) const {
		return modll(value + other.value);
	}
	void operator+=(ll other) {
		value += other;
		adjust();
	}
	void operator+=(modll other) {
		value += other.value;
		adjust();
	}
};



ll powmod(ll base, ll exp, ll mod) {
	ll res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

/**
 * El mod tiene que ser primo.
 * Se basa en fermatito.
 */
ll inverso_mod(ll num, ll mod) {
	return powmod(num, mod - 2ll, mod);
}


int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	vec<ll> d(n);
	forn (i) cin >> d[i];

	vec<ll> a(m), b(m);
	fore (i, 0, m) {
		cin >> a[i] >> b[i];
	}

	sort(all(d));
	vec<ll> acum(n + 1, 0);
	ll suma = 0;
	for (ll i = 0; i < n; i++) {
		suma += d[i];
		acum[i + 1] = acum[i] + d[i];
	}

	vec<ll> fact(n + 1);
	vec<ll> inv(n+1);
	fact[0] = 1;
	inv[0] = inverso_mod(fact[0], MOD);
	for (ll i = 1; i < n + 1; i++) {
		fact[i] = fact[i-1] * i;
		fact[i] %= MOD;
		inv[i] = inverso_mod(fact[i], MOD);
	}

	for (ll i = 0; i < m; i++) {
		auto it = lower_bound(d.begin(), d.end(), b[i]);
		ll cant_chicos = it - d.begin();
		ll suma_chicos = acum[cant_chicos];
		ll c = n - cant_chicos;

		if (c < a[i]) {
			cout << 0 << endl;
		} else {
			modll A{0};

			if (c > a[i]) {
				A += fact[c - 1];
				A *= inv[c - a[i] - 1];
				A *= inv[c - 1 - (c - a[i] - 1)];
				A *= suma - suma_chicos;
				A *= c + 1;
			}
			modll B{c - a[i] + 1};
			B *= suma_chicos;
			B *= fact[c];
			B *= inv[c - a[i]];
			B *= inv[c - (c - a[i])];

			modll G = B + A;
			G *= fact[c - a[i]];
			G *= fact[c - (c - a[i])];
			G *= inv[c];
			G *= inverso_mod(c + 1, MOD);

			cout << G.value << endl;
		}

	}



	return 0;
}

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


ll powmod(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res*base) % MOD;
		}
		base = (base*base) % MOD;
		exp >>= 1;
	}
	return res;
}

/**
 * El mod tiene que ser primo.
 * Se basa en fermatito.
 */
ll inverso_mod(ll num) {
	return powmod(num, MOD - 2ll);
}

void reduce(pair<ll,ll>& fraction) {
	ll g = gcd(fraction.first, fraction.second);
	fraction.first /= g;
	fraction.second /= g;
	fraction.first %= MOD;
	fraction.second %= MOD;
}

pair<ll,ll> add(pair<ll,ll> some, pair<ll,ll> other) {
	ll denominator = some.second * other.second;
	ll numerator = some.first*other.second + other.first * some.second;
	pair<ll,ll> res = {numerator, denominator};
	reduce(res);
	return res;
}

int main() {
	IOS;

	ll n;
	cin >> n;

	vec<pair<ll,ll>> probs(n + 1);
	probs[0] = {0, 1};
	probs[1] = {1, 2};
	for (ll i = 2; i < n + 1; i++) {
		pair<ll,ll> prev = probs[i - 2];
		prev.second *= 4;
		prev.second %= MOD;

		pair<ll,ll> ant = probs[i-1];
		ant.second *= 2;
		ant.second %= MOD;
		probs[i] = add(prev, ant);
	}

	// cout << probs[n].first << "/" << probs[n].second << endl;
	cout << (probs[n].first * inverso_mod(probs[n].second)) % MOD << endl;

	return 0;
}

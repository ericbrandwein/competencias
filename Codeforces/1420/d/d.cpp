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
			res = res * base % MOD;
		}
		base = base * base % MOD;
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


vec<ll> get_factorials(ll n) {
	vec<ll> factorials;
	ll curr = 1;
	for (ll i = 1; i <= n+1; i++) {
		factorials.push_back(curr);
		curr *= i;
		curr %= MOD;
	}
	return factorials;
}

struct Border {
	bool start;
	ll pos;
	bool operator<(const Border& other) const {
		return pos < other.pos || (pos == other.pos && start && !other.start);
	}
};

int main() {
	IOS;

	ll n;
	cin >> n;
	ll k;
	cin >> k;

	vec<pair<ll,ll>> intervals(n);
	vec<Border> borders;
	forn (i) {
		cin >> intervals[i].first >> intervals[i].second;
		borders.push_back({true, intervals[i].first});
		borders.push_back({false, intervals[i].second});
	}

	ll total = 0;
	sort(all(borders));

	vec<ll> fact = get_factorials(n);
	vec<ll> inv;
	for (ll i = 0; i < fact.size(); i++) {
		inv.push_back(inverso_mod(fact[i]));
	}

	ll starts = 0;

	for (ll i = 0; i < borders.size() - 1; i++) {
		if (borders[i].start){
			if (starts >= k-1) {
				total += ((fact[starts] * inv[starts-(k-1)])%MOD) * inv[k-1];
				total %= MOD;
			}
			starts++;
		} else starts--;
	}

cout << total << endl;






	return 0;
}

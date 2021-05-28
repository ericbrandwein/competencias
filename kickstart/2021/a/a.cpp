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

const ll MOD = 1e9 + 7;

void solve() {
	ll n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vec<ll> pals(n + 1);
	pals[0] = 1;
	for (ll i = 1; i < pals.size(); i++) {
		if (i % 2 == 0) {
			pals[i] = pals[i-1];
		} else {
			pals[i] = pals[i - 1] * k;
			pals[i] %= MOD;
		}
	}

	ll res = 0;
	for (ll i = 0; 2 * (i+1) <= n; i++) {
		ll lower = s[i] - 'a';
		ll internal = s.size() - 2 * (i+1);
		ll combi = (lower * pals[internal]) %MOD;
		res += combi;
		res %= MOD;
	}

	if (n % 2 == 1) {
		res += s[s.size() / 2] - 'a';
		res %= MOD;
	}

	string prefix = s.substr(0, s.size() / 2);
	string last = prefix;
	if (s.size() % 2 == 1) {
		last.push_back(s[s.size() / 2]);
	}
	reverse(all(prefix));
	last += prefix;
	if (last < s) {
		res++;
		res %= MOD;
	}

	cout << res;



}


int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i+1 << ": ";
		solve();
		cout << endl;
	}

}

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

ll max_without(vec<ll>& a, ll pos) {
	if (a.size() == 1 && pos == 0) {
		return -1;
	}
	ll maxi = 0;
	if (maxi == pos) maxi++;
	for (ll i = 0; i < a.size(); i++) {
		if (i == pos) continue;
		if (a[i] > a[maxi]) maxi = i;
	}

	return maxi;
}

void solve() {
	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<string> players = {"T", "HL"};
	ll curr_player = 0;
	ll maxi = max_without(a, -1);
	while (maxi != -1 && a[maxi] != 0) {
		a[maxi]--;
		curr_player++;
		curr_player %= 2;
		maxi = max_without(a, maxi);
	}

	cout << players[((curr_player + 1) % 2)] << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

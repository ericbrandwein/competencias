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
	vec<ll> candies(n);
	forn (i) cin >> candies[i];

	ll last = 0;
	ll moves = 0;
	vec<ll> eaten(2, 0);
	vec<ll> pos = {-1, n};
	ll player = 0;
	while (pos[0] < pos[1] - 1) {
		ll curr = 0;
		ll dir = -(player * 2 - 1);
		while (curr <= last && pos[0] < pos[1] - 1) {
			pos[player] += dir;
			curr += candies[pos[player]];
		}
		last = curr;
		eaten[player] += curr;
		player++;
		player %= 2;
		moves++;
	}

	cout << moves << " " << eaten[0] << " " << eaten[1] << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

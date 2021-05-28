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

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		vector<ll> prox(n, -1);
		vector<ll> pos(n, -1);
		vector<ll> nums(n);
		forn (i) {
			cin >> nums[i];
			nums[i]--;
			ll posicion_ant = pos[nums[i]];
			if (posicion_ant != -1) {
				prox[posicion_ant] = i;
			}
			pos[nums[i]] = i;
		}

		ll min_dist = LONG_LONG_MAX;
		forn (i) {
			if (prox[i] != -1) {
				min_dist = min(min_dist, prox[i] - i + 1);
			}
		}

		if (min_dist != LONG_LONG_MAX) {
			cout << min_dist << endl;
		} else {
			cout << -1 << endl;
		}

	}


	return 0;
}

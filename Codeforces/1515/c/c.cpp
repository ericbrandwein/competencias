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
	ll n, m, x;
	cin >> n >> m >> x;

	map<ll, vec<ll>> towers;
	vec<ll> pos(n);
	fore (i, 0, m) {
		towers[0].push_back(i);
	}
	forn (i) {
		ll num;
		cin >> num;

		auto it = towers.begin();
		ll new_num = it->first + num;
		ll tower = it->second.back();
		pos[i] = tower;
		it->second.pop_back();
		if (it->second.empty()) {
			towers.erase(it);
		}
		towers[new_num].push_back(tower);
	}


	cout << "YES" << endl;
	for (auto num : pos) {
		cout << num + 1<< " ";
	}
	cout << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}

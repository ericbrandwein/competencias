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
	string s;
	cin >> s;
	pair<ll,ll> pos = {0,0};
	vec<pair<ll,ll>> dirs(s.size());
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == 'U') {
			dirs[i] = {0, 1};
		} else if (s[i] == 'D') {
			dirs[i] = {0, -1};
		} else if (s[i] == 'L') {
			dirs[i] = {-1, 0};
		} else {
			dirs[i] = {1, 0};
		}
	}

	for (ll i = 0; i < s.size(); i++) {
		pair<ll,ll> curr_pos = {0,0};
		pair<ll,ll> obstacle = {LONG_LONG_MAX,LONG_LONG_MAX};
		for (ll step = 0; step < s.size(); step++) {
			curr_pos = {curr_pos.first + dirs[step].first, curr_pos.second + dirs[step].second};
			if (step == i) {
				obstacle = curr_pos;
				break;
			}
		}
		curr_pos = pair<ll,ll>{0,0};
		for (ll step = 0; step < s.size(); step++) {
			pair<ll,ll> new_pos = {curr_pos.first + dirs[step].first, curr_pos.second + dirs[step].second};
			if (obstacle != new_pos) {
				curr_pos = new_pos;
			}
		}
		if (curr_pos == pair<ll,ll>{0,0} && obstacle != pair<ll,ll>{0,0}) {
			pos = obstacle;
		}
	}
	cout << pos.first << " " << pos.second << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


}

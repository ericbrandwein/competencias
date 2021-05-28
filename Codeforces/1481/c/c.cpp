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
	ll n, m;
	cin >> n >> m;
	vec<ll> a(n), b(n);
	vec<ll> painters(m);
	map<ll, vec<ll>> to_paint;
	map<ll, vec<ll>> painted;
	forn (i) cin >> a[i];
	forn (i) {
		cin >> b[i];
		if (a[i] != b[i]) {
			to_paint[b[i]].push_back(i);
		} else {
			painted[b[i]].push_back(i);
		}
	}
	fore (i, 0, m) cin >> painters[i];

	vec<ll> res;

	ll first_painted = -1;
	for (ll i = m - 1; i >= 0; i--) {
		ll curr_painted = -1;
		if (to_paint[painters[i]].empty()) {
			if (painted[painters[i]].empty()) {
				if (first_painted == -1) {
					cout << "NO" << endl;
					return;
				} else {
					curr_painted = first_painted;
				}
			} else {
				curr_painted = painted[painters[i]][0];
			}
		} else {
			curr_painted = to_paint[painters[i]].back();
			to_paint[painters[i]].pop_back();
		}
		if (first_painted == -1) {
			first_painted = curr_painted;
		}
		res.push_back(curr_painted);
	}

	for (const pair<ll,vec<ll>>& entry : to_paint) {
		if (!entry.second.empty()) {
			cout << "NO" << endl;
			return;
		}
	}

	reverse(all(res));
	cout << "YES" << endl;
	for (ll num : res) {
		cout << num +1 << " ";
	}
	cout << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}

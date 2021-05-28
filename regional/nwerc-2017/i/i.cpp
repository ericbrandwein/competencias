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

bool better(pair<ll,ll>& first, pair<ll,ll>& second) {
	return first.second < second.second || (
		first.second == second.second && first.first > second.first
	);
}

int main() {
	IOS;

	ll n, space;
	cin >> n >> space;
	vec<pair<ll,ll>> sizes(n);
	forn (i) {
		cin >> sizes[i].first >> sizes[i].second;
	}

	vec<bool> used(n, false);
	vec<ll> apps;
	ll min_app = 0;
	while (space > 0 && min_app != -1) {
		min_app = -1;
		for (ll i = 0; i < n; i++) {
			if (
				!used[i] && max(sizes[i].first, sizes[i].second) <= space &&
				(min_app == -1 || better(sizes[i], sizes[min_app]))
			) {
				min_app = i;
			}
		}
		if (min_app != -1) {
			apps.push_back(min_app + 1);
			used[min_app] = true;
		}
	}

	cout << apps.size() << endl;
	if (!apps.empty()) {
		for (ll app : apps) {
			cout << app << " ";
		}
		cout << endl;
	}


}

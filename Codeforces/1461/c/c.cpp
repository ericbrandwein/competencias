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
	vec<ll> nums(n);
	forn (i) cin >> nums[i];

	vec<pair<ll,ld>> experiments(m);
	fore (i, 0, m) cin >> experiments[i].first >> experiments[i].second;
	ll last_not_sorted;
	for (
		last_not_sorted = n - 1;
		last_not_sorted >= 0 && nums[last_not_sorted] == last_not_sorted + 1;
		last_not_sorted--
	);
	ld result = 1;
	if (last_not_sorted != -1) {
		ld not_happening = 1;
		for (const pair<ll,ld>& experiment: experiments) {
			if (experiment.first > last_not_sorted) {
				not_happening *= (ld)1 - experiment.second;
			}
		}
		result -= not_happening;
	}

	presicion(6);
	cout << result << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


}

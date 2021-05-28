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

bool interseca(pair<ll,ll>& intervalo, pair<ll,ll>& call) {
	return intervalo.second > call.first && intervalo.first < call.second;
}

int main() {
	IOS;

	ll n;
	ll m;
	cin >> n >>m;
	while(n!=0 || m!= 0) {

		vec<pair<ll,ll>> calls(n);
		forn (i) {
			ll ignored;
			cin >> ignored >> ignored >>calls[i].first >> calls[i].second;
			calls[i].second += calls[i].first;
		}
		vec<pair<ll,ll>> intervals(m);
		fore(i, 0, m) {
			cin >> intervals[i].first >> intervals[i].second;
			intervals[i].second = intervals[i].first + intervals[i].second;
			ll cant = 0;
			forn (j) {
				if (interseca(intervals[i], calls[j])) cant++;
			}
			cout << cant << endl;
		}
		cin >> n >>m;
	}




	return 0;
}

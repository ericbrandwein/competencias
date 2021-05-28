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

	ll n, t;
	ld p;
	cin >> n >> p >> t;
	vec<vec<ld>> probs(t+1, vec<ld>(n+1, 0.0));
	probs[0][0] = 1;
	for (ll time = 1; time <= t; time++) {
		for (ll people = 0; people <= n; people++) {
			if (people > 0) {
				probs[time][people] = probs[time-1][people-1] * p;
			}
			if (people < n) {
				probs[time][people] += probs[time-1][people] * (1 - p);
			} else {
				probs[time][people] += probs[time-1][people];
			}
		}
	}

	presicion(6);
	ld res = 0;
	for (ll people = 0; people <= n; people++) {
		res += probs[t][people] * people;
	}
	cout << res << endl;

}

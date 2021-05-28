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

	ll n;
	cin >> n;
	vec<ll> heights(n);
	forn (i) cin >> heights[i];

	vec<ll> jumps(n, LONG_LONG_MAX);
	vec<ll> dec;
	vec<ll> inc;
	dec.push_back(0);
	inc.push_back(0);
	jumps[0] = 0;
	fore (i, 1, n) {
		while (!dec.empty() && heights[dec.back()] < heights[i]) {
			jumps[i] = min(jumps[i], jumps[dec.back()] + 1);
			dec.pop_back();
		}
		while (!inc.empty() && heights[inc.back()] > heights[i]) {
			jumps[i] = min(jumps[i], jumps[inc.back()] + 1);
			inc.pop_back();
		}
		if (!inc.empty()) {
			jumps[i] = min(jumps[i], jumps[inc.back()] + 1);
			if (heights[inc.back()] == heights[i]) {
				inc.pop_back();
			}
		}
		if (!dec.empty()) {
			jumps[i] = min(jumps[i], jumps[dec.back()] + 1);
			if (heights[dec.back()] == heights[i]) {
				dec.pop_back();
			}
		}
		dec.push_back(i);
		inc.push_back(i);
	}

	cout << jumps[n - 1] << endl;

	return 0;
}

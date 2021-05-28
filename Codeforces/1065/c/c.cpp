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

	ll n, max_slice;
	cin >> n>> max_slice;

	vec<ll> heights(n);
	forn (i) cin >> heights[i];

	sort(all(heights));
	ll minh = heights[0];

	ll cuts = 0;
	ll sobra = 0;
	ll level = heights[heights.size() - 1];
	for (ll i = heights.size() - 1; i > 0; i--) {
		while (level > heights[i - 1]) {
			ll aca = n - i;
			if (sobra + aca > max_slice) {
				sobra = 0;
				cuts++;
			}
			sobra += aca;
			level--;
		}
	}

	if (sobra > 0) cuts++;
	cout << cuts << endl;

	return 0;
}

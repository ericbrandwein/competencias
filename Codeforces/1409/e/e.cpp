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
	ll n, length;
	cin >> n >> length;

	vec<ll> xs(n);
	forn (i) cin >> xs[i];
	ll p;
	forn (i) cin >> p;

	sort(all(xs));

	vec<ll> biggest_out(n);
	ll right = 0;
	forn (i) {
		while (right < n && xs[right] - xs[i] <= length) {
			right++;
		}
		biggest_out[i] = right;
	}


	vec<ll> largest_right(n + 1);
	ll largest = n - 1;
	largest_right[n] = 0;
	largest_right[n - 1] = 0;
	for (ll i = n - 2; i >= 0; i--) {
		largest_right[i] = biggest_out[largest] - largest;
		if (biggest_out[largest] - largest < biggest_out[i] - i) {
			largest = i;
		}
	}

	ll max_res = 0;
	forn (i) {
		max_res = max(
			max_res,
			biggest_out[i] - i + largest_right[biggest_out[i] - 1]
		);
	}

	cout << max_res << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

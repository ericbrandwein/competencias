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

void solve () {
	ll n, s;
	cin >> n >> s;

	vec<ll> digits;
	ll num = n;
	ll sum = 0;
	while (num > 0) {
		digits.push_back(num % 10);
		sum += digits.back();
		num/=10;
	}

	vec<ll> res = digits;
	if (sum > s) {
		ll pos = 0;
		while (sum > s-1) {
			ll restado = digits[pos];
			res[pos] = 0;
			sum -= digits[pos];
			pos++;
		}
		while (pos < digits.size() && digits[pos] == 9) {
			sum -= 9;
			res[pos] = 0;
			pos++;
		}
		if (pos >= digits.size()) {
			res.push_back(1);
		} else {
			res[pos]++;
		}
		sum++;
	}

	ll num_res = 0;
	ll mult = 1;
	for (ll i = 0; i < res.size(); i++) {
		num_res += res[i]*mult;
		mult *= 10;
	}

	cout << num_res - n << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

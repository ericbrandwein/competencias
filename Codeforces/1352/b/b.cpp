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
	ll n, k;
	cin >> n >> k;

	vec<ll> nums(k, 1);
	nums[k-1] += n - k;
	if (k > n || (k % 2 == 0 && n % 2 == 1)) {
		cout << "NO" << endl;
		return;
	} else if (k % 2 == 1 && n % 2 == 0) {
		// hay que poner todos pares
		if (k*2 > n) {
			cout << "NO" << endl;
			return;
		} else {
			nums = vec<ll>(k, 2);
			nums[k-1] += n - 2*k;
		}
	}

	cout << "YES" << endl;
	fore (i, 0, k) {
		cout << nums[i] << " ";
	}
	cout << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

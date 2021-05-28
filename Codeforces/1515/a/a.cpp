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
	ll n, x;
	cin >> n >> x;
	vec<ll> nums(n);
	ll suma = 0;
	forn (i) {
		cin >> nums[i];
		suma += nums[i];
	}

	if (suma == x) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		ll curr_sum = 0;
		for (ll i = 0; i < n; i++) {
			curr_sum += nums[i];
			if (curr_sum == x) {
				swap(nums[i], nums[i+1]);
				break;
			}
		}
		forn (i) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}


}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}

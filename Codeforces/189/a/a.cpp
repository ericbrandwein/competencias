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
	vector<ll> nums(3);
	cin >> n ;
	for (ll i = 0; i < 3; i++) {
		cin >> nums[i];
	}

	vector<ll> pieces(n + 1, -1);
	for (ll i = 0; i < 3; i++) {
		if (nums[i] < pieces.size()) {
			pieces[nums[i]] = 1;
		}
	}
	for (ll i = 2; i < pieces.size(); i++) {
		for (ll j = 0; j < 3; j++) {
			ll prev = i - nums[j];
			if (prev >= 0 && pieces[prev] > -1) {
				pieces[i] = max(pieces[i], pieces[prev] + 1);
			}
		}
	}

	cout << pieces[n] << endl;


	return 0;
}

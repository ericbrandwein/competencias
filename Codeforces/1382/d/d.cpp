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
	ll n;
	cin >> n;

	vector<ll> p(2*n);
	fore (i, 0, 2*n) {
		cin >> p[i];
	}



	ll curr_max = p[0];
	vector<ll> lengths;
	ll curr_len = 1;
	fore (i, 1, 2*n) {
		if (p[i] > curr_max) {
			lengths.push_back(curr_len);
			curr_len = 0;
			curr_max = p[i];
		}
		curr_len++;
	}
	lengths.push_back(curr_len);



	set<ll> sums;
	sums.insert(0);
	for (ll i = 0; i < lengths.size(); i++) {
		vector<ll> added;
		for (ll sum : sums) {
			added.push_back(sum + lengths[i]);
		}
		for (ll add : added) {
			sums.insert(add);
		}
	}

	if (sums.count(n)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


	return 0;
}

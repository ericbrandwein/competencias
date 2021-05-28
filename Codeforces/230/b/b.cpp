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

set<ll> cuadrados() {
	set<ll> cuads;
	vector<bool> criba(1000001, true);
	criba[0] = false;
	criba[1] = false;
	for (ll num = 2; num < criba.size(); num++) {
		if (criba[num]) {
			for (ll salto = num * 2; salto < criba.size(); salto += num) {
				criba[salto] = false;
			}
			cuads.insert(num * num);
		}
	}

	return cuads;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<ll> nums(n);
	forn (i) {
		cin >> nums[i];
	}

	set<ll> cuads = cuadrados();
	for (ll& num : nums) {
		if (cuads.count(num) != 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}


	return 0;
}

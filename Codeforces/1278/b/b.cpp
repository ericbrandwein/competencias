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

ll max_dif(ll n) {
	return n*(n+1) / 2;
}

ll search_operations_q(ll searched) {
	ll right = 50000;
	ll left = 0;
	while (left != right) {
		ll middle = (right + left) / 2;

		if (max_dif(middle) < searched) {
			left = middle + 1;
		} else {
			right = middle;
		}
	}

	return left;
}

ll operations_for(ll searched) {
	ll min_operations = search_operations_q(searched);
	while (max_dif(min_operations) % 2 != searched % 2) {
		min_operations++;
	}
	return min_operations;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		cout << operations_for(abs(a - b)) << endl;
	}

	return 0;
}

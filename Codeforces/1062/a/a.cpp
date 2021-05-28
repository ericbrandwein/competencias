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
	vec<ll> a;
	a.push_back(0);
	forn (i) {
		ll num;
		cin >> num;
		a.push_back(num);
	}
	a.push_back(1001);

	ll longest_consec = 1;
	ll curr = 1;
	fore (i, 1, a.size()) {
		if (a[i] == a[i-1] + 1) {
			curr++;
		} else {
			curr = 1;
		}
		longest_consec = max(curr, longest_consec);
	}

	cout << max(0ll, longest_consec - 2) << endl;

	return 0;
}

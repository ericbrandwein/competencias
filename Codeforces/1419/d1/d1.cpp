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
	vec<pair<ll,ll>> a(n);
	forn (i) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(all(a));
	vec<ll> chicos;
	vec<ll> grandes;
	ll i = 0;
	for (; i*2 < n-2; i++) {
		chicos.push_back(a[i].first);
	}
	for (; i < n; i++) {
		grandes.push_back(a[i].first);
	}

	cout << chicos.size() << endl;
	ll j = 0;
	for (; j < chicos.size(); j++) {
		cout << grandes[j] << " " << chicos[j] << " ";
	}
	for (; j < grandes.size();j++) {
		cout << grandes[j] << " ";
	}
	cout << endl;




	return 0;
}

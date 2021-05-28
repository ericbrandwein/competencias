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
	vec<ll> a(n);
	map<ll,ll> amounts;

	ll biggest = -1;
	forn (i) {
		cin >> a[i];
		amounts[a[i]]++;
		if (amounts[a[i]] >= n / 2) biggest = a[i];
	}

	sort(all(a));
	vec<ll> chicos;
	vec<ll> grandes;
	ll i = 0;
	for (; i*2 < n-2; i++) {
		chicos.push_back(a[i]);
	}
	bool used = false;
	for (; i < n; i++) {
		if (a[i] == biggest && n % 2 == 0 && !used) {
			used = true;
			continue;
		}
		grandes.push_back(a[i]);
	}
	if (used) grandes.push_back(biggest);

	vec<ll> res;
	ll j = 0;
	for (; j < chicos.size(); j++) {
		res.push_back(grandes[j]);
		res.push_back(chicos[j]);
	}
	for (; j < grandes.size();j++) {
		res.push_back(grandes[j]);
	}

	ll amount = 0;
	for (ll k = 1; k < res.size() - 1; k++) {
		if (res[k] < res[k-1] && res[k] < res[k+1]) amount++;
	}

	cout << amount << endl;
	for (ll elem : res) {
		cout << elem << " ";
	}
	cout << endl;
}

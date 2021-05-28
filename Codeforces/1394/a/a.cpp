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

	ll n, d, mood;
	cin >> n >> d >> mood;
	vec<ll> a(n);
	forn (i) cin >> a[i];
	sort(all(a));

	vector<ll> chicos;
	vector<ll> grandes;
	ll total = 0;
	ll i = 0;
	for (; i< n && a[i] <= mood; i++) {
		total += a[i];
		chicos.push_back(a[i]);
	}

	reverse(all(chicos));

	for (ll j = n - 1; j >= i; j--) {
		grandes.push_back(a[j]);
	}

	ll restantes = n - i;
	ll mayores = restantes / (d + 1);
	if (restantes % (d + 1) != 0) mayores++;

	ll tirados = ((restantes - 1) + (d+1)) % (d+1);
	for (ll k = 0;k < mayores; k++) {
		total += grandes[k];
	}

	ll curr = total;
	while (i + tirados >= d+1 && mayores < grandes.size()) {
		mayores++;
		curr += grandes[mayores - 1];
		for (;tirados < d + 1; tirados++) {
			i--;
			curr -= chicos[i];
		}
		tirados = 0;

		total = max(total, curr);
	}


	cout << total << endl;


	return 0;
}

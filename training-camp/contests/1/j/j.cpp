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
	ll d;
	cin >> n >> d;
	ll a, b;
	cin >> a >> b;
	vector<pair<ll, ll>> sizes(n);

	vector<pair<ll, ll>> pesos(n);
	forn (i) {
		cin >> sizes[i].first;
		pesos[i].first = sizes[i].first * a;
		cin >> sizes[i].second;
		pesos[i].first += sizes[i].second * b;
		pesos[i].second = i;
	}

	sort(all(pesos));

	ll remaining = d;
	ll total = 0;
	vector<ll> chosen;
	forn (i) {
		pair<ll ,ll> curr = pesos[i];
		if (curr.first > remaining) {
			break;
		} else {
			remaining -= curr.first;
			chosen.push_back(curr.second);
			total++;
		}
	}


	cout << total << endl;
	for (ll num:chosen) {
		cout << num + 1 << " ";
	}
	cout << endl;


	return 0;
}

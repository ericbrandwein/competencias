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

	ll n, q;
	cin >> n >> q;
	vector<ll> elements(n);
	forn (i) {
		cin >> elements[i];
	}

	vector<ll> to_sum(n + 1, 0);

	vector<pair<ll, ll>> queries(q);
	fore (i, 0, q) {
		cin >> queries[i].first >> queries[i].second;
		queries[i].first--;
		queries[i].second--;
		to_sum[queries[i].first]++;
		to_sum[queries[i].second + 1]--;
	}

	vector<ll> quants(n);
	ll curr_quant = 0;
	forn (i) {
		curr_quant += to_sum[i];
		quants[i] = curr_quant;
	}

	sort(elements.rbegin(), elements.rend());
	sort(quants.rbegin(), quants.rend());

	ll total = 0;
	forn (i) {
		total += quants[i] * elements[i];
	}
	cout << total << endl;


	return 0;
}

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

bool is_there_subsequence_with_max_less_or_equal_than(
	vector<ll>& a, ll less_than, ll subsequence_length
) {
	fore (paridad, 0, 2) {
		ll curr_length = 0;
		bool winning_group = paridad;
		for (ll i = 0; curr_length < subsequence_length && i < a.size(); i++) {
			if (!winning_group || a[i] <= less_than) {
				curr_length++;
				winning_group = !winning_group;
			}
		}
		if (curr_length == subsequence_length) {
			return true;
		}
	}
	return false;
}


int main() {
	IOS;

	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	forn (i) cin >> a[i];

	// Busqueda binaria para encontrar el mínimo máximo
	ll from = 0;
	ll to = 1e9 + 1;
	while (from < to) {
		ll middle = (from + to) / 2;
		if (is_there_subsequence_with_max_less_or_equal_than(a, middle, k)) {
			to = middle;
		} else {
			from = middle + 1;
		}
	}

	cout << to << endl;

	return 0;
}

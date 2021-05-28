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

void calc_incr(vec<vec<ll>>& increase, ll index, vec<ll>& lens, vec<ll> &prices) {
	fore (i, 0, 3) {
		increase[index][i] = LONG_LONG_MAX;
		fore (j, 0, 3) {
			if (lens[index] + i != lens[index - 1] + j) {
				increase[index][i] = min(increase[index][i], increase[index - 1][j]);
			}
		}
		increase[index][i] += prices[index] * i;
	}
}

int main() {
	IOS;

	ll q;
	cin >> q;

	fore (i, 0, q) {
		ll n;
		cin >> n;

		vec<ll> lens(n), prices(n);
		fore (j, 0, n) {
			cin >> lens[j] >> prices[j];
		}

		vec<vec<ll>> increase(n, vec<ll>(3, 0));
		increase[0][1] = prices[0];
		increase[0][2] = 2 * prices[0];

		fore (j, 1, n) {
			calc_incr(increase, j, lens, prices);
		}

		cout << min(min(increase[increase.size() - 1][0], increase[increase.size() - 1][1]), increase[increase.size() - 1][2]) << endl;
	}

	return 0;
}

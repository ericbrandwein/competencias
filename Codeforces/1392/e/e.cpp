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

void solve(vec<vec<ll>>& grid, ll sum, ll n) {
	ll diag_amount = n + n - 1;
	vec<ll> bits;
	for (ll i = 1; i < diag_amount; i++) {
		bits.push_back((sum % 2) << (i - 1));
		sum >>= 1;
	}

	vec<pair<ll,ll>> pos;
	pos.push_back({0,0});

	for (ll i = 0; i < bits.size(); i++) {
		pair<ll,ll> pos_actual = pos.back();
		if (pos_actual.first == n - 1) {
			pos_actual.second++;
		} else if (pos_actual.second == n - 1) {
			pos_actual.first++;
		} else if (grid[pos_actual.first + 1][pos_actual.second] == bits[i]) {
			pos_actual.first++;
		} else {
			pos_actual.second++;
		}
		pos.push_back(pos_actual);
	}

	for (ll i = 0; i < pos.size(); i++) {
		cout << pos[i].first + 1 << " " << pos[i].second + 1 << endl;
	}
	cout << flush;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	vec<vec<ll>> grid(n, vec<ll>(n, 0));
	ll pot = 1;
	for (ll diag = 1; diag < n + n - 1; diag++) {
		bool cero = false;
		for (ll col = 0; col < n; col++) {
			ll row = diag - col;
			if (row < n && row >= 0) {
				if (!cero) {
					grid[row][col] = pot;
				}
				cero = !cero;
			}
		}
		pot *= 2;
	}

	forn (i) {
		forn (j) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	cout << flush;

	ll q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		solve(grid, k, n);
	}


	return 0;
}

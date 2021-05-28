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

const ll MOD = 1e9 + 7;

void solve() {
	ll n;
	cin >> n;
	ll k;
	cin >> k;
	ll width;
	cin >> width;

	vector<ll> starts(n);
	fore (i, 0, k) cin >> starts[i];

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	fore (i, k, n) {
		starts[i] = ((a * starts[i - 2] + b * starts[i - 1] + c) % d) + 1;
	}

	vector<ll> heights(n);
	fore (i, 0, k) cin >> heights[i];

	cin >> a >> b >> c >> d;

	fore (i, k, n) {
		heights[i] = ((a * heights[i - 2] + b * heights[i - 1] + c) % d) + 1;
	}

	vector<ll> perimeters(n);
	perimeters[0] = 2*width + 2*heights[0];
	perimeters[0] %= MOD;
	vector<ll> current;
	current.push_back(0);
	fore (i, 1, n) {
		ll first_choque = 0;
		for (; first_choque < current.size() &&
			starts[current[first_choque]] + width < starts[i];
			first_choque++);

		vector<ll> to_keep;
		if (first_choque == current.size()) {
			perimeters[i] = perimeters[i - 1] + 2*width + 2*heights[i];
			perimeters[i] %= MOD;
		} else {
			ll min_mayor = -1;
			for (ll j = first_choque; j < current.size(); j++) {
				if (heights[current[j]] > heights[i]) {
					to_keep.push_back(current[j]);
					if (min_mayor == -1 || heights[min_mayor] >= heights[current[j]]) {
						min_mayor = j;
					}
				}
			}

			if (min_mayor == -1) {
				// first_choque es de menor altura
				ll anterior = current[first_choque];
				perimeters[i] = perimeters[anterior];
				perimeters[i] += 2*(starts[i] - starts[anterior]) + 2*(heights[i] - heights[anterior]);
			} else {
				ll anterior = current[min_mayor];
				perimeters[i] = perimeters[anterior];
				perimeters[i] += 2*(starts[i] - starts[anterior]);
			}
			perimeters[i] %= MOD;
		}

		current = to_keep;
		current.push_back(i);
	}

	ll total = 1;
	for (ll i = 0; i < perimeters.size(); i++) {
		total *= perimeters[i];
		total %= MOD;
	}

	cout << total << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}

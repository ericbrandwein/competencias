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

ll n;

struct Jar {
	ll dif;
	ll pos;

	bool operator<(const Jar& other) const {
		return dif < other.dif || (dif == other.dif && abs(pos - n) < abs(other.pos - n));
	}
};

int main() {
	IOS;

	ll t;
	cin >> t;

	while (t--) {
		cin >> n;

		vector<ll> colors(2*n);
		vector<Jar> jars(2*n + 1);
		jars[0].dif = 0;
		jars[0].pos = 0;
		ll last_dif = 0;
		fore (i, 0, 2*n) {
			cin >> colors[i];
			jars[i + 1].pos = i + 1;
			if (colors[i] == 1) {
				jars[i + 1].dif = last_dif - 1;
			} else {
				jars[i + 1].dif = last_dif + 1;
			}
			last_dif = jars[i + 1].dif;
		}


		ll total_dif = jars[2 * n].dif;
		if (total_dif == 0) {
			cout << 0 << endl;
		} else {
			vector<Jar> left, right;

			for (ll i = 0; i <= n; i++) {
				left.push_back(jars[i]);
			}

			for (ll i = n; i <= 2*n; i++) {
				right.push_back(jars[i]);
			}

			sort(all(left));
			sort(all(right));

			ll min_len = LONG_LONG_MAX;

			for (ll i = 0; i < left.size(); i++) {

				ll searched_dif = left[i].dif + total_dif;
				auto it = lower_bound(all(right), Jar{searched_dif, n});
				if (it != right.end() && it->dif == searched_dif) {
					min_len = min(min_len, it->pos - left[i].pos);
				}
			}


			cout << min_len<< endl;

		}











	}

	return 0;
}

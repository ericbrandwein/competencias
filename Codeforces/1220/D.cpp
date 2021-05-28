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

	vec<vec<ll>> pots(64, vec<ll>(0));

	vec<ll> exps(64, 1);
	fore (i, 1, exps.size()) {
		exps[i] = exps[i - 1] * 2LL;
	}

	ll max_amount = 0;
	ll max_index = 0;
	fore (i, 0, n) {
		ll num;
		cin >> num;
		for (ll j = pots.size() - 1; j >= 0; j--) {
			if (num % exps[j] == 0) {
				pots[j].push_back(num);
				if (pots[j].size() > max_amount) {
					max_amount = pots[j].size();
					max_index = j;
				}
				break;
			}
		}
	}

	vec<ll> sacados;
	fore (i, 0, pots.size()) {
		if (i != max_index) {
			for (auto& elem : pots[i]) {
				sacados.push_back(elem);
			}
		}
	}
	
	cout << sacados.size() << endl;
	fore (i, 0, sacados.size()) {
		cout << sacados[i] << " ";
	}

	if (sacados.size() > 0) {
		cout << endl;
	}


	return 0;
}

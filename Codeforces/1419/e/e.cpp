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

vec<pair<ll, ll>> get_primos(ll n) {
	vec<pair<ll,ll>> primos;
	ll curr_primo = 2;
	while (curr_primo * curr_primo <= n) {
		pair<ll,ll> curr = {curr_primo, 0};
		while (n % curr_primo == 0) {
			curr.second++;
			n /= curr_primo;
		}
		if (curr.second > 0) {
			primos.push_back(curr);
		}
		curr_primo++;
	}
	if (n != 1) {
		primos.push_back({n, 1});
	}
	return primos;
}

vec<ll> multiples_from(vec<pair<ll,ll>>& primos, ll pos) {
	if (pos == primos.size()) {
		return {1};
	} else {
		vec<ll> res;
		vec<ll> next = multiples_from(primos, pos + 1);
		ll curr = 1;
		for (ll cant = 0;cant <= primos[pos].second; cant++) {
			for (ll elem : next) {
				res.push_back(curr * elem);
			}
			curr *= primos[pos].first;
		}
		return res;
	}
}

void add_segment(
	vec<pair<ll,ll>>& primos, ll pos_actual, ll anterior, ll siguiente, vec<ll>& res
) {

	if (anterior != -1) {
		res.push_back(anterior * primos[pos_actual].first);
	}

	vec<ll> multiplos = multiples_from(primos, pos_actual + 1);
	ll curr = primos[pos_actual].first;
	for (ll cant= 1; cant <= primos[pos_actual].second; cant++) {
		for (ll elem : multiplos) {
			ll added = elem * curr;
			if (
				added != primos[pos_actual].first * anterior &&
				added != primos[pos_actual].first * siguiente
			) {
				res.push_back(added);
			}
		}
		curr *= primos[pos_actual].first;
	}
}


void solve() {
	ll n;
	cin >> n;

	vec<pair<ll,ll>> primos = get_primos(n);

	vec<ll> res;
	ll ops = 0;
	if (primos.size() == 2) {
		if (primos[0].second == 1 && primos[1].second == 1) {
			ops = 1;
			res.push_back(primos[0].first);
			res.push_back(primos[1].first);
			res.push_back(primos[1].first*primos[0].first);
		} else {
			if (primos[0].second > primos[1].second) {
				swap(primos[0], primos[1]);
			}

			res.push_back(primos[0].first*primos[1].first);
			ll curr_0 = primos[0].first;
			for (ll i = 1; i <= primos[0].second; i++) {
				ll curr_1 = 1;
				for (ll j = 0; j <= primos[1].second; j++, curr_1*=primos[1].first) {
					if (i == 1 && j > 0 && j < 3) continue;
					res.push_back(curr_0*curr_1);
				}
				curr_0 *= primos[0].first;
			}
			res.push_back(primos[0].first*primos[1].first*primos[1].first);
			ll curr = primos[1].first;
			for (ll i = 1; i <=primos[1].second; i++) {
				res.push_back(curr);
				curr *= primos[1].first;
			}
		}
	} else if (primos.size() == 1) {
		add_segment(primos, 0, -1, -1, res);
	} else {
		for (ll i = 0; i < primos.size(); i++) {
			ll anterior = primos.back().first;
			if (i > 0) {
				anterior = primos[i-1].first;
			}
			ll siguiente = primos[0].first;
			if (i < primos.size() - 1) {
				siguiente = primos[i+1].first;
			}
			add_segment(primos, i, anterior, siguiente, res);
		}
	}

	for (ll elem : res) {
		cout << elem << " ";
	}
	cout << endl;
	cout << ops << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

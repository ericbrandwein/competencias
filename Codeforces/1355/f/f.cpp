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

const ll MAX_NUM = 1e8;

void max_divisores() {
	ll max_divisores = 0;
	vec<ll> divisores(MAX_NUM + 1, 0);
	for (ll i = 1; i <= MAX_NUM; i++) {
		for (ll j = i; j <= MAX_NUM; j+=i) {
			divisores[j]++;
			if (divisores[j] > max_divisores) {
				max_divisores = divisores[j];
				cout << max_divisores << endl << flush;
			}
		}
	}
}

ll query(ll num) {
	cout << "? " << num << endl << flush;
	ll res;
	cin >> res;
	return res;
}

map<ll,ll> factorize(ll num) {
	map<ll,ll> res;
	for (ll p = 2; p *p<= num; p++) {
		while (num%p == 0) {
			res[p]++;
			num/=p;
		}
	}
	if (num > 1) {
		res[num]++;
	}
	return res;
}

vec<ll> get_asked() {
	vec<ll> asked;
	ll p = 2;
	while (asked.size() < 22) {
		asked.push_back(1);
		for (; asked.back() < 100'000'000; p++) {
			map<ll,ll> factors = factorize(p);
			if (factors.size() == 1) {
				if (asked.back() * p > 100'000'000) {
					break;
				} else {
					asked[asked.size() - 1] *= p;
				}
			}
		}
		cout << asked.back() << " " << endl;
	}
	return asked;
}

void solve(uniform_int_distribution<unsigned long long>& distr, mt19937_64& eng) {

	map<ll,ll> known;
	for (ll i = 0; i < 22; i++) {
		ll res = query(abs((long long)distr(eng)));
		map<ll,ll> factors = factorize(res);
		for (pair<ll,ll> entry : factors) {
			known[entry.first] = max(known[entry.first], entry.second);
		}
	}

	ll total = 1;
	for (pair<ll,ll> entry : known) {
		total *= entry.second + 1;
	}

	cout << "! " << max(8ll,2*total) <<endl;
}

int main() {
	IOS;

	random_device rd;
	mt19937_64 eng(rd());
	uniform_int_distribution<unsigned long long> distr;

	ll t;
	cin >> t;
	while (t--) solve(distr, eng);
	// max_divisores();



}

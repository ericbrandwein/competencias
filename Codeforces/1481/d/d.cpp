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

void solve() {
	ll n, m;
	cin >> n >> m;
	vec<string> aristas(n);
	forn (i) {
		cin >> aristas[i];
	}
	vec<ll> res;
	if (m % 2 == 1) {
		res.push_back(0);
		res.push_back(1);
		m--;
		while (m > 0) {
			res.push_back(0);
			res.push_back(1);
			m -= 2;
		}
	} else {
		fore (i, 0, n) {
			ll otro = -1;
			fore (j, 0, n) {
				if (j != i && aristas[i][j] == aristas[j][i]) {
					otro = j;
					break;
				}
			}
			if (otro != -1) {
				res.push_back(i);
				while (m > 0) {
					res.push_back(otro);
					res.push_back(i);
					m -= 2;
				}
				break;
			}
		}
		for (ll i = 0; i < n && res.empty(); i++) {
			ll otro = -1;
			char entrada = '0';
			ll entrada_a = -1;
			ll entrada_b = -1;
			fore (j, 0, n) {
				if (j != i) {
					if (aristas[j][i] == 'a') {
						entrada_a = j;
					} else {
						entrada_b = j;
					}
					if (entrada == '0') {
						entrada = aristas[j][i];
					} else if (entrada != aristas[j][i]) {
						entrada = '*';
						break;
					}
				}
			}
			fore (j, 0, n) {
				if (j != i && (entrada == '*' || entrada == aristas[i][j])) {
					otro = j;
					break;
				}
			}

			if (otro != -1) {
				ll anterior;
				if (aristas[i][otro] == 'a') {
					anterior = entrada_a;
				} else {
					anterior = entrada_b;
				}
				if (m == 2) {
					res.push_back(anterior);
					res.push_back(i);
					res.push_back(otro);
				} else if (m % 4 == 2) {
					res.push_back(otro);
					res.push_back(i);
					res.push_back(anterior);
					m -=2;
					while (m > 0) {
						res.push_back(i);
						res.push_back(otro);
						res.push_back(i);
						res.push_back(anterior);
						m -= 4;
					}
				} else {
					res.push_back(i);
					res.push_back(anterior);
					res.push_back(i);
					res.push_back(otro);
					m-= 3;
					while (m > 1) {
						res.push_back(i);
						res.push_back(anterior);
						res.push_back(i);
						res.push_back(otro);
						m-= 4;
					}
					res.push_back(i);
				}
			}
		}
	}
	if (res.empty()) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (ll num : res) {
			cout << num + 1 << " ";
		}
		cout << endl;
	}

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}

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

struct Constraint {
	ll from, to, result;
};

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;

	vector<Constraint> constraints(m);
	vector<vector<ll>> added(n + 1, vector<ll>(30, 0));
	fore (i, 0, m) {
		cin >> constraints[i].from >> constraints[i].to >> constraints[i].result;
		constraints[i].from--;
		constraints[i].to--;
		bitset<30> binary(constraints[i].result);
		for (ll bit = 0; bit < 30; bit++) {
			added[constraints[i].from][bit] += binary[bit];
			added[constraints[i].to + 1][bit] -= binary[bit];
		}
	}

	vector<bitset<30>> array(n, bitset<30>(0));
	vector<vector<ll>> ones_before(n, vector<ll>(30, 0));
	vector<ll> acum(30, 0);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 30; j++) {
			acum[j] += added[i][j];
			if (acum[j] > 0) {
				array[i][j] = 1;
				if (i > 0) {
					ones_before[i][j] = ones_before[i - 1][j] + 1;
				} else {
					ones_before[i][j] = 1;
				}
			}
		}
	}

	for (Constraint& constraint : constraints) {
		bitset<30> binary(constraint.result);
		ll length = constraint.to - constraint.from + 1;
		for (ll bit = 0; bit < 30; bit++) {
			if ((ones_before[constraint.to][bit] >= length) != (binary[bit])) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	for (ll i = 0; i < n; i++) {
		cout << array[i].to_ullong() << " ";
	}
	cout << endl;



	return 0;
}

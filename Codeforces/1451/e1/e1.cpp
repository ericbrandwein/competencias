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

ll query(string name, ll i, ll j) {
	cout << name << " " << i << " " << j << endl << flush;
	ll res;
	cin >> res;
	return res;
}

void print(vec<ll>& values) {
	cout << "! ";
	for (ll i = 1; i < values.size(); i++) {
		cout << values[i] << " ";
	}
	cout << endl;
}



void solve_repeated(vec<ll>& xors, ll i, ll j, ll n) {
	ll repeated = query("AND", i, j);
	vec<ll> values(n + 1,  -1);
	values[i] = repeated;
	values[j] = repeated;
	if (values[1] == -1) {
		values[1] = xors[i] ^ repeated;
	}
	for (ll i = 2; i <= n; i++) {
		if (values[i] == -1) {
			values[i] = xors[i]^values[1];
		}
	}
	print(values);
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> xors(n+1);
	vec<ll> sorted_xors;
	for (ll j = 2; j <= n; j++) {
		xors[j] = query("XOR", 1, j);
		sorted_xors.push_back(xors[j]);
	}
	sort(all(sorted_xors));

	for (ll i = 2; i <= n; i++) {
		if (xors[i] == 0) {
			solve_repeated(xors, 1, i, n);
			return 0;
		}
	}

	ll repeated = -1;
	for (ll i = 0; i < sorted_xors.size() - 1; i++) {
		if (sorted_xors[i] == sorted_xors[i+1]) {
			repeated = sorted_xors[i];
			break;
		}
	}

	if (repeated != -1) {
		vec<ll> equal;
		for (ll i = 2; i <= n; i++) {
			if (xors[i] == repeated) {
				equal.push_back(i);
			}
		}
		solve_repeated(xors, equal[0], equal[1], n);
	} else {
		// son todos diferentes
		vec<ll> biggest(3, -1);
		for (ll i = 2; i <= n; i++) {
			if (biggest[0] == -1 || xors[i] > xors[biggest[0]]) {
				biggest[2] = biggest[1];
				biggest[1] = biggest[0];
				biggest[0] = i;
			} else if (biggest[1] == -1 || xors[i] > xors[biggest[1]]) {
				biggest[2] = biggest[1];
				biggest[1] = i;
			} else if (biggest[2] == -1 || xors[i] > xors[biggest[2]]) {
				biggest[2] = i;
			}
		}
		ll repeated = query("AND", biggest[0], biggest[1]);
		ll last = query("AND", biggest[0], biggest[2]) % 2;
		vec<ll> values(n + 1,  -1);
		values[biggest[0]] = repeated + last;
		if (values[1] == -1) {
			values[1] = xors[biggest[0]] ^ values[biggest[0]];
		}
		for (ll i = 2; i <= n; i++) {
			if (values[i] == -1) {
				values[i] = xors[i]^values[1];
			}
		}
		print(values);
	}




}

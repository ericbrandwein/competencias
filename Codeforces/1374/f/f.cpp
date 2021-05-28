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

ll index_of_max(vector<ll>& a, ll until) {
	ll max_i = 0;
	fore (i, 0, until) {
		if (a[i] >= a[max_i]) {
			max_i = i;
		}
	}
	return max_i;
}

void rotate(vector<ll>& a, ll from) {
	ll temp = a[from];
	a[from] = a[from + 2];
	a[from + 2] = a[from + 1];
	a[from + 1] = temp;
}

ll find_repeated(vector<ll>& a) {
	fore (i, 1, a.size()) {
		if (a[i] == a[i - 1]) {
			return i - 1;
		}
	}
	return -1 ;
}


void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	forn (i) {
		cin >> a[i];
	}

	vector<ll> ops;

	while (n > 2) {
		ll max_i = index_of_max(a, n);

		while (max_i < n - 1) {
			ll from = max_i - 1;
			if (max_i == 0) {
				from = max_i;
			}
			rotate(a, from);
			ops.push_back(from);
			max_i++;
		}
		n--;
	}

	if (a[0] > a[1]) {
		ll repeated = find_repeated(a);
		if (repeated == -1) {
			if (a[0] == a[2]) {
				ops.push_back(0);
				ops.push_back(0);
			} else {
				cout << -1 << endl;
				return;
			}
		} else {
			rotate(a, repeated - 1);
			ops.push_back(repeated - 1);

			n = repeated + 1;
			while (n > 2) {
				ll max_i = index_of_max(a, n);

				while (max_i < n - 1) {
					ll from = max_i - 1;
					if (max_i == 0) {
						from = max_i;
					}
					rotate(a, from);
					ops.push_back(from);
					max_i++;
				}
				n--;
			}
		}
	}




	cout << ops.size() << endl;
	fore (i, 0, ops.size()) {
		cout << ops[i] + 1 << " ";
	}
	cout << endl;







}

int main() {
	IOS;

	ll t;
	cin >> t;
	 while (t--) solve();

	return 0;
}

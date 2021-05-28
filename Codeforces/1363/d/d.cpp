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

ll ask_for(vector<ll>& indices) {
	cout << "? " << indices.size();
	for (ll i : indices) {
		cout << " " << i;
	}
	cout << endl;
	cout << flush;
	ll res;
	cin >> res;
	return res;
}


void answer(vector<ll>& password) {
	cout<<"!";

	for (ll num : password) {
		cout << " " << num;
	}

	cout << endl;
	cout << flush;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		ll n, subsets_q;
		cin >> n >> subsets_q;

		vector<vector<ll>> subsets(subsets_q);

		fore (i, 0, subsets_q) {
			ll size;
			cin >> size;
			fore (j, 0, size) {
				ll num;
				cin >> num;

				subsets[i].push_back(num);
			}
		}


		// ask for all
		vector<ll> all_indices;
		forn (i) {
			all_indices.push_back(i + 1);
		}
		ll total_max = ask_for(all_indices);

		vector<ll> password(subsets_q);

		ll from = 0;
		ll to = subsets_q;
		while (from + 1 < to) {
			ll middle = (to - from) / 2 + from;
			vector<ll> indices;
			fore (i, from, middle) {
				fore (j, 0, subsets[i].size()) {
					indices.push_back(subsets[i][j]);
				}
			}
			ll part_max = ask_for(indices);
			if (part_max == total_max) {
				to = middle;
			} else {
				from = middle;
			}
		}

		// si está en algún grupo, está en el grupo from
		// lo que importa ahora es si está en otro lado.
		// si está en otro lado, toda la password es el max.
		// sino, es todo el max excepto la posicion from, que es el max de lo de afuera de from.

		vector<bool> in_from(n + 1, false);
		fore (i, 0, subsets[from].size()) {
			in_from[subsets[from][i]] = true;
		}


		vector<ll> outside_from;
		fore (i, 1, n + 1) {
			if (!in_from[i]) {
				outside_from.push_back(i);
			}
		}
		ll max_outside_from = ask_for(outside_from);

		fore (i, 0, subsets_q) {
			password[i] = total_max;
		}
		password[from] = max_outside_from;


		answer(password);

		string correct;
		cin >> correct;
		if (correct != "Correct") {
			return 0;
		}

	}

	return 0;
}

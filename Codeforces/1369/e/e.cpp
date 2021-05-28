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

	ll types, friends;
	cin >> types >> friends;
	vector<ll> platos(types);
	fore (i, 0, types) {
		cin >> platos[i];
	}
	vector<vector<ll>> favourites(friends, vector<ll>(2));

	// Which friends prefer food type [i]?
	vector<set<ll>> friends_per_type(types);
	fore (i, 0, friends) {
		fore (j, 0, 2) {
			cin >> favourites[i][j];
			favourites[i][j]--;
			friends_per_type[favourites[i][j]].insert(i);
		}
	}

	queue<ll> surplus_types;
	fore (i, 0, types) {
		if (friends_per_type[i].size() <= platos[i]) {
			surplus_types.push(i);
		}
	}

	vector<ll> order;
	while (!surplus_types.empty()) {
		ll current_type = surplus_types.front();
		surplus_types.pop();
		for (ll amigo : friends_per_type[current_type]) {
			// Lo sacamos de su otro lado
			order.push_back(amigo);
			ll other_type = favourites[amigo][0];
			if (other_type == current_type) other_type = favourites[amigo][1];
			friends_per_type[other_type].erase(amigo);
			if (
				friends_per_type[other_type].size() > 0 &&
				friends_per_type[other_type].size() == platos[other_type]
			) {
				surplus_types.push(other_type);
			}
		}
		friends_per_type[current_type].clear();
	}

	if (order.size() < friends) {
		cout << "DEAD" << endl;
	} else {
		cout << "ALIVE" << endl;
		for (ll i = order.size() - 1; i >= 0; i--) {
			cout << order[i] + 1 << " ";
		}
		cout << endl;
	}




	return 0;
}

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

	ll trees_q, people_q;
	cin >> trees_q >> people_q;

	vector<ll> trees(trees_q);
	for (ll i = 0; i < trees_q; i++) {
		cin >> trees[i];
	}

	sort(all(trees));

	ll INF = 2000000001;
	set<pair<ll, ll>> boundaries;
	ll previous = trees[0];
	boundaries.insert({-INF, previous});
	for (ll i = 1; i < trees_q; i++) {
		if (trees[i] > previous + 1) {
			boundaries.insert({previous, trees[i]});
		}
		previous = trees[i];
	}

	boundaries.insert({trees[trees.size() - 1], INF});

	vector<ll> people(people_q);
	ll total = 0;
	ll dist = 1;
	bool left = false;
	auto boundary_it = boundaries.begin();
	for (ll i = 0; i < people_q; i++) {
		if (left && boundary_it->first == -INF) {
			left = false;
		}
		if (!left && boundary_it->second == INF) {
			dist++;
			boundary_it = boundaries.begin();
		}
		pair<ll, ll> new_boundary = *boundary_it;
		if (left) {
			people[i] = boundary_it->first + 1;
			new_boundary.first += 1;
		} else {
			people[i] = boundary_it->second - 1;
			new_boundary.second -= 1;
		}
		total += dist;
		boundaries.erase(boundary_it);
		if (new_boundary.first + 1 != new_boundary.second) {
			boundary_it = boundaries.insert(new_boundary).first;
			if (!left) {
				boundary_it++;
			}
			left = !left;
		} else {
			boundary_it = boundaries.upper_bound(new_boundary);
			left = true;
		}
	}

	cout << total << endl;
	for (ll i = 0; i < people_q; i++) {
		cout << people[i] << " ";
	}
	cout << endl;


	return 0;
}

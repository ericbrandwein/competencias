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

void fill_component(
	ll from, vec<pair<ll,ll>>& points, vec<vec<vec<int>>>& ady, ll time, int comp_num,
	vec<int>& components
){

	stack<int> next;
	next.push(from);
	components[from] = comp_num;
	while (!next.empty()) {
		int curr = next.top();
		next.pop();
		for (ll coord = 0; coord < 2; coord++) {
			for (ll side = 0; side < 2; side++) {
				ll other = ady[curr][coord][side];
				if (
					other != -1 &&
					components[other] == 0 &&
					abs(points[other].first - points[curr].first) <= time &&
					abs(points[other].second - points[curr].second) <= time
				) {
					components[other] = comp_num;
					next.push(other);
				}
			}
		}

	}
}


bool can_connect(vec<pair<ll,ll>>& points, vec<vec<vec<int>>>& ady, ll time) {
	vec<int> components(points.size(), 0);
	int component_quantity = 0;
	for (ll i = 0; i < points.size(); i++) {
		if (components[i] == 0) {
			component_quantity++;
			fill_component(i, points, ady, time, component_quantity, components);
		}
	}

	if (component_quantity > 4) return false;
	if (component_quantity == 1) return true;
	for (ll from = 0; from < points.size(); from++) {
		for (ll to = from + 1; to < points.size(); to++) {
			pair<ll,ll> first = points[from], second = points[to];
			if (
				first.first != second.first && first.second != second.second &&
				abs(first.first - second.first) <= time &&
				abs(first.second - second.second) <= time
			) {
				ll from_posta = from, to_posta = to;
				if (first.first > second.first) {
					swap(from_posta, to_posta);
					swap(first, second);
				}

				// Están ordenados por x
				for (ll coord_first = 0; coord_first < 2; coord_first++) {
					set<int> curr_components = {components[to], components[from]};
					ll coord_second = 1-coord_first;
					ll next_first = coord_first;
					ll next_second = coord_first;
					if (first.second < second.second) {
						// Es un anterior y un siguiente
						next_first = 1;
						next_second = 0;
					}
					pair<ll,ll> intersection;
					if (coord_first == 0) {
						intersection = {first.first, second.second};
					} else {
						intersection = {second.first, first.second};
					}
					int next_point_first = ady[from_posta][coord_first][next_first];
					if (
						next_point_first != -1 &&
						abs(intersection.first - points[next_point_first].first) <= time &&
						abs(intersection.second - points[next_point_first].second) <= time
					) {
						curr_components.insert(components[next_point_first]);
					}

					int next_point_second = ady[to_posta][coord_second][next_second];
					if (
						next_point_second != -1 &&
						abs(intersection.first - points[next_point_second].first) <= time &&
						abs(intersection.second - points[next_point_second].second) <= time
					) {
						curr_components.insert(components[next_point_second]);
					}
					if (curr_components.size() == component_quantity) {
						return true;
					}
				}
			}
		}
	}

	if (component_quantity == 2) {
		for (ll from = 0; from < points.size(); from++) {
			for (ll to = from + 1; to < points.size(); to++) {
				if (
					(points[from].first == points[to].first &&
					abs(points[from].second - points[to].second) <= time*2) ||
					(points[from].second == points[to].second &&
					abs(points[from].first - points[to].first) <= time*2)
				) {
					return true;
				}
			}
		}
	}
	return false;

}


int main() {
	IOS;

	ll n;
	cin >> n;
	vec<map<ll, set<pair<ll,ll>>>> ordered(2); // (x, (y, i)
	vec<pair<ll,ll>> points(n);
	forn (i) {
		cin >> points[i].first >> points[i].second;
		ordered[0][points[i].first].insert({points[i].second, i});
		ordered[1][points[i].second].insert({points[i].first, i});
	}

	// (point, {same_x, same_y}, {lower, bigger})
	vec<vec<vec<int>>> ady(n,vec<vec<int>>(2, vec<int>(2, -1)));
	for (ll i = 0; i < 2; i++) {
		for (const pair<ll, set<pair<ll,ll>>>& entry : ordered[i]) {
			const set<pair<ll,ll>>& points_in_x = entry.second;
			auto it = points_in_x.begin();
			ll prev = it->second;
			it++;
			while (it != points_in_x.end()) {
				ll next = it->second;
				ady[prev][i][1] = next;
				ady[next][i][0] = prev;
				prev = next;
				it++;
			}
		}
	}

	ll inf = 2*1e9 + 1;
	ll from = 1;
	ll to = inf;
	while (from < to) {
		ll mid = (from + to) / 2;
		if (can_connect(points, ady, mid)) {
			to = mid;
		} else {
			from = mid + 1;
		}
	}

	if (from == inf) {
		cout << -1 << endl;
	} else {
		cout << from << endl;
	}


	return 0;
}

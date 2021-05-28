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

void compress(vec<ll>& nums) {
	vec<ll> tmp = nums;
	map<ll,ll> position;
	sort(all(tmp));
	for(ll i = 0; i < tmp.size(); i++) {
		position[tmp[i]] = i;
	}
	for (ll i = 0; i < nums.size(); i++) {
		nums[i] = position[nums[i]];
	}
}

void inverso(vec<ll>& nums) {
	reverse(all(nums));
	for (ll i = nums.size() - 1; i >= 0; i--) {
		nums[i] = nums.size() - i - 1;
	}
}

void compress(vec<pair<ll,ll>>& poly) {
	map<ll,vec<ll>> points_x, points_y;
	for (ll i = 0; i < poly.size(); i++) {
		pair<ll,ll>& point = poly[i];
		points_x[point.first].push_back(i);
		points_y[point.second].push_back(i);
	}
	vec<ll> xs, ys;
	for (auto& entry : points_x) {
		xs.push_back(entry.first);
	}
	for (auto& entry : points_y) {
		ys.push_back(entry.first);
	}

	ll pos = 0;
	for (ll x : xs) {
		for (ll i : points_x[x]) {
			poly[i].first = pos;
		}
		pos++;
	}
	pos = 0;
	for (ll y : ys) {
		for (ll i : points_y[y]) {
			poly[i].second = pos;
		}
		pos++;
	}
}

void rotate(vec<pair<ll,ll>>& poly) {
	// x = max_y - prev_y
	// y = prev_x
	ll max_y = 0;
	for (const pair<ll,ll>& point: poly) {
		max_y = max(max_y, point.second);
	}

	for (ll i = 0; i < poly.size(); i++) {
		ll prev_x = poly[i].first;
		poly[i].first = max_y - poly[i].second;
		poly[i].second = prev_x;
	}
}

int main() {
	IOS;

	ll cant;
	cin >> cant;
	vec<pair<ll,ll>> a(cant);
	fore (i, 0, cant) {
		ll x, y;
		cin >> x >> y;
		a[i] = {x,y};
	}

	cin >> cant;
	vec<pair<ll,ll>> b(cant);


	fore (i, 0, cant) {
		ll x, y;
		cin >> x>> y;
		b[i] = {x, y};
	}

	compress(a);
	compress(b);
	set<pair<ll,ll>> a_set(all(a));
	for (ll i = 0; i < 4; i++) {
		set<pair<ll,ll>> b_set(all(b));
		if (a_set == b_set) {
			cout << "yes" << endl;
			return 0;
		}
		rotate(b);
	}
	cout << "no" << endl;

}

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

ll dist(pair<ll,ll>& from, pair<ll,ll>& to) {
	ll dist_x = abs(from.first - to.first);
	ll dist_y = abs(from.second - to.second);
	return dist_x*dist_x + dist_y*dist_y;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<pair<ll,ll>> points(n);
	forn (i) {
		cin >> points[i].first >> points[i].second;
	}

	vec<ll> p;
	ll curr_num = 0;
	vec<bool> used(n, false);
	used[curr_num] = true;
	p.push_back(curr_num);
	fore (i, 1, n) {
		ll max_dist = 0;
		ll max_dist_num = -1;
		forn (j) {
			if (j != curr_num && !used[j]) {
				ll curr_dist =  dist(points[curr_num], points[j]);
				if (curr_dist > max_dist) {
					max_dist = curr_dist;
					max_dist_num = j;
				}
			}
		}
		curr_num = max_dist_num;
		used[curr_num] = true;
		p.push_back(curr_num);
	}

	forn (i) {
		cout << p[i] + 1 << " ";
	}
	cout << endl;



}

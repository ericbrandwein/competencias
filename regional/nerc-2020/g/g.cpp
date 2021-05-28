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

int point_above(pair<ll,ll>& to, pair<ll,ll>& from, pair<ll,ll>& point) {
	ll dif_x = to.first - from.first;
	ll pendiente = to.second - from.second;
	ll ordenada = dif_x*from.second - pendiente*from.first;
	ll left = dif_x*point.second;
	ll right = point.first*pendiente + ordenada;
	if (left == right) {
		return 0;
	} else if ((dif_x >= 0 && left > right) || (dif_x < 0 && left < right)) {
		return 1;
	} else {
		return -1;
	}
}

ld dist(pair<ld,ld> from, pair<ld,ld> to) {
	ld dist_x = to.first - from.first;
	ld dist_y = to.second - from.second;
	return sqrt(dist_x*dist_x + dist_y*dist_y);
}

ld distance_added(pair<ll,ll>& sauron, pair<ll,ll>& prev_biggest, pair<ll,ll>& from, pair<ll,ll>& to) {
	ld pendiente_sauron = (sauron.second - prev_biggest.second) / (ld)(sauron.first - prev_biggest.first);
	ld ordenada_sauron = sauron.second - sauron.first*pendiente_sauron;
	ld pendiente = (to.second - from.second) / (ld)(to.first - from.first);
	ld ordenada = to.second - to.first*pendiente;
	ld x_to = (ordenada - ordenada_sauron) / (pendiente_sauron-pendiente);
	ld y_to = x_to*pendiente + ordenada;
	return dist(from, {x_to, y_to});
}


int main() {
	IOS;

	ll n, h;
	cin >> n >> h;
	vec<pair<ll,ll>> pos(n);
	forn (i) {
		cin >> pos[i].first >> pos[i].second;
	}
	pair<ll,ll> sauron = {pos[n - 1].first, pos[n-1].second + h};
	pair<ll,ll> prev_biggest = pos[n-2];
	ld res = dist(pos[n-2], pos[n-1]);
	for (ll i = n-3; i >= 0; i--) {
		int above = point_above(sauron, prev_biggest, pos[i]);
		if (above == 1) {
			res += distance_added(sauron, prev_biggest, pos[i], pos[i+1]);
			prev_biggest = pos[i];
		} else if (above == 0 && point_above(sauron, prev_biggest, pos[i+1]) == 0) {
			res += dist(pos[i], pos[i+1]);
		}
	}
	presicion(10);

	cout << res << endl;


}

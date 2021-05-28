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

struct Ghost {
	ll a, x, vx, vy, order;

	ll get_order() const {
		return vx*a - vy;
	}

	ll operator<(const Ghost& other) const {
		return order < other.order || (order == other.order && vx < other.vx);
	}
};

int main() {
	IOS;

	ll n, a ,b;
	cin >> n >> a >> b;
	vec<Ghost> ghosts(n);
	forn (i) {
		cin >> ghosts[i].x >> ghosts[i].vx >> ghosts[i].vy;
		ghosts[i].a = a;
		ghosts[i].order = ghosts[i].get_order();
	}

	sort(all(ghosts));
	ll total = 0;
	ll curr_order = LONG_LONG_MAX;
	ll curr_vx = LONG_LONG_MAX;
	ll curr_order_ghosts = 0;
	ll curr_vx_ghosts = 0;
	for (ll i = 0; i < n; i++) {
		if (ghosts[i].vx != curr_vx) {
			curr_order_ghosts += curr_vx_ghosts;
			curr_vx_ghosts = 0;
			curr_vx = ghosts[i].vx;
		}
		if (ghosts[i].order == curr_order) {
			total += 2* curr_order_ghosts;
		} else {
			curr_order_ghosts = 0;
			curr_vx_ghosts = 0;
			curr_order = ghosts[i].order;
		}
		curr_vx_ghosts++;
	}

	cout << total << endl;

}

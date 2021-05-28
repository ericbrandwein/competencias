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

	ll n, m, page_length;
	cin >> n >> m >> page_length;
	vec<ll> pos(m);
	fore (i, 0, m) {
		cin >> pos[i];
		pos[i]--;
	}

	ll curr_page = -1;
	ll restado = 0;
	ll curr_restado = 0;
	ll moves = 0;
	for (ll i = 0; i < m; i++) {
		ll true_pos = pos[i] - restado;
		ll true_page = true_pos / page_length;
		if (curr_page == -1) {
			curr_page = true_page;
		}
		if (curr_page == true_page) {
			curr_restado++;
		} else {
			restado += curr_restado;
			curr_restado = 0;
			moves++;
			curr_page = -1;
			i--;
		}
	}
	moves++;

	cout << moves << endl;

	return 0;
}

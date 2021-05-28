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

void solve(ll number) {
	cout << "Case #"<<number<<": ";

	ll n;
	cin >> n;
	vector<pair<ll,ll>> trees(n);
	forn (i) {
		cin >> trees[i].first >> trees[i].second;
	}
	sort(all(trees));

	ll max_largo = 0;
	// fin, largo último
	map<ll, ll> largos;
	fore (i, 0, trees.size()) {
		pair<ll, ll>& tree = trees[i];
		ll pos = tree.first;
		ll alto = tree.second;

		ll pos_adelante = pos + alto;
		ll largo_adelante = alto;
		if (largos.count(pos) != 0) {
			largo_adelante += largos[pos];
		}
		largos[pos_adelante] = max(largos[pos_adelante], largo_adelante);

		max_largo = max(max_largo, largos[pos_adelante]);

		ll pos_atras = pos - alto;
		ll largo_atras = alto;
		if (largos.count(pos_atras) != 0) {
			largo_atras += largos[pos_atras];
		}
		largos[pos] = max(largos[pos], largo_atras);

		max_largo = max(max_largo, largos[pos]);
	}

	cout << max_largo << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) solve(i + 1);


	return 0;
}

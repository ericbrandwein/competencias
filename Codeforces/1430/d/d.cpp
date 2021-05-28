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

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;

	vec<ll> bloque_length;
	char curr = s[0];
	ll length = 1;
	for (ll i = 1; i < n; i++) {
		if (s[i] == curr) length++;
		else {
			bloque_length.push_back(length);
			curr = s[i];
			length = 1;
		}
	}
	bloque_length.push_back(length);

	ll bloque_mas_de_uno = 0;
	ll bloque = 0;
	ll moves = 0;
	for (;bloque < bloque_length.size(); bloque++) {
		while (
			bloque_mas_de_uno < bloque || (
				bloque_mas_de_uno < bloque_length.size() &&
				bloque_length[bloque_mas_de_uno] == 1
			)
		) {
			bloque_mas_de_uno++;
		}
		if (bloque_mas_de_uno == bloque_length.size()) {
			break;
		}
		bloque_length[bloque_mas_de_uno]--;
		moves++;
	}
	if (bloque < bloque_length.size()) {
		moves += (bloque_length.size()-bloque+1)/2;
	}

	cout << moves << endl;


}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

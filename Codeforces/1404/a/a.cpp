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
	ll n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	for (ll i = 0; i < n - k; i++) {
		if (s[i] == '?') {
			if (s[i + k] != '?') {
				s[i] = s[i + k];
			}
		} else if (s[i + k] == '?') {
			s[i + k] = s[i];
		} else if (s[i] != s[i+k]) {
			cout << "NO" << endl;
			return;
		}
	}

	for (ll i = n - 1; i - k >= 0; i--) {
		if (s[i] == '?') {
			if (s[i - k] != '?') {
				s[i] = s[i - k];
			}
		} else if (s[i - k] == '?') {
			s[i - k] = s[i];
		} else if (s[i] != s[i-k]) {
			cout << "NO" << endl;
			return;
		}
	}

	ll faltan = 0;
	ll preguntas = 0;
	for (ll i = 0; i < k; i++) {
		if (s[i] == '?') preguntas++;
		else faltan += (s[i] - '0') * 2 - 1;
	}

	if (abs(faltan) <= preguntas) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}


int main() {
	IOS;


	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

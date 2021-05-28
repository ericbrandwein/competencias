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


	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll letras = 'z' - 'a' + 1;
	ll total = 0;
	string r = s;
	reverse(all(r));
	for (char actual = 'a'; actual <= 'z'; actual++) {
		vec<ll> pos_real;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] == actual) pos_real.push_back(i);
			// else new_s.push_back(s[i]);
		}
		vec<ll> pos_reversed;
		for (ll i = 0; i < r.size(); i++) {
			if (r[i] == actual) pos_reversed.push_back(i);
		}

		for (ll i = 0; i < pos_real.size(); i++) {
			total += abs(pos_real[i] - pos_reversed[i]);
		}

		string new_s = "";
		ll indice = 0;
		ll indice_reversed = 0;
		ll adelantado = 0;
		for (ll indice_reversed = 0; indice_reversed < pos_reversed.size(); indice_reversed++) {
			while (indice + adelantado < pos_reversed[indice_reversed]) {
				if (s[indice] == actual) {
					adelantado--;
				} else {
					new_s.push_back(s[indice]);
				}
				indice++;
			}
			new_s.push_back(actual);
			adelantado++;
		}
		for(; indice< s.size(); indice++) {
			if (s[indice] != actual) new_s.push_back(s[indice]);
		}


		s = new_s;
	}

	cout << total << endl;
	return 0;
}

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

	ll current, l, r, time, sacado, added;
	cin >> current >> l >> r >> time >> sacado >> added;
	ll dias = 0;
	if (sacado > added) {
		if (current + added > r) {
			current -= sacado;
			if (current >= l) {
				dias++;
			}
		}
		if (current >= l) {
			ll dif = sacado - added;
			dias += (current - l) / dif;
		}
	} else {
		ll i;
		for (i = 0; i < sacado; i++) {
			ll dias_actuales = (current - l) / sacado;
			ll resto = current - dias_actuales*sacado - l;
			dias += dias_actuales;
			if (l + resto + added > r) {
				break;
			} else {
				current = l+resto + added;
			}
		}
		if (i == sacado) {
			dias = time;
		}
	}

	if (dias >= time) {
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}

}

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

	ll litres;
	cin >> litres;
	vector<ll> costs(10);
	ll min_cost_digit = 1;
	fore (i, 1, 10) {
		cin >> costs[i];
		if (costs[i] <= costs[min_cost_digit]) {
			min_cost_digit = i;
		}
	}

	// Primero hay que poner todos los dígitos posibles,
	// y después tratar de subir al máximo los de la izquierda.
	// O sea, primero poner en todos el número más chico,
	// y después empezar por el primero y poner el más grande
	// que se pueda.
	vector<ll> result;
	while (litres >= costs[min_cost_digit]) {
		result.push_back(min_cost_digit);
		litres -= costs[min_cost_digit];
	}

	if (result.empty()) {
		cout << -1 << endl;
		return 0;
	}

	bool incremente = true;
	for (ll i = 0; i < result.size() && incremente; i++) {
		litres += costs[min_cost_digit];
		ll digit = 9;
		for (; digit > min_cost_digit && litres < costs[digit]; digit--);
		if (digit > min_cost_digit) {
			litres -= costs[digit];
			result[i] = digit;
		} else {
			incremente = false;
		}
	}

	for (ll digito : result) {
		cout << digito;
	}
	cout << endl;


	return 0;
}

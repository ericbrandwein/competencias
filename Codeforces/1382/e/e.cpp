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
	ll iguales, compartidos;
	cin >> iguales >> compartidos;

	vector<ll> b(n);
	// numero, indices
	map<ll, vec<ll>> ocurr;

	forn (i) {
		cin >> b[i];
		ocurr[b[i]].push_back(i);
	}

	// ocurrencias, numero
	set<pair<ll, ll>> mas_ocurr;
	for (const pair<ll, vec<ll>>& curr : ocurr) {
		mas_ocurr.insert({curr.second.size(), curr.first});
	}

	vector<ll> res(n, 0);

	while (iguales > 0) {
		// if (mas_ocurr.empty()) {
		// 	cout << "MAL" << endl;
		// 	return;
		// }
		auto max_it = mas_ocurr.end();
		max_it--;

		ll num_mayor = max_it->second;
		ll indice = ocurr[num_mayor].back();
		res[indice] = num_mayor;
		ocurr[num_mayor].pop_back();
		mas_ocurr.erase(max_it);
		if (ocurr[num_mayor].size() > 0) {
			mas_ocurr.insert({ocurr[num_mayor].size(), num_mayor});
		}

		compartidos--;
		iguales--;
	}

	if (mas_ocurr.empty()) {
		cout << "YES" << endl;
		for (ll i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
		return;
	}
	auto curr = mas_ocurr.end();
	curr--;
	ll rotar = curr->first;
	vector<ll> indices;
	vector<ll> rotado;
	for (const pair<ll, ll>& curr : mas_ocurr) {
		ll numero = curr.second;
		vector<ll>& indices_agregados = ocurr[numero];
		indices.insert(indices.end(), all(indices_agregados));
		for (ll i = 0; i < curr.first; i++) {
			rotado.push_back(numero);
		}
	}

	rotate(rotado.begin(), rotado.begin() + rotar, rotado.end());

	vector<bool> aparece(n + 2, false);
	ll no_aparece = 0;
	for (ll i = 0; i < n; i++) {
		aparece[b[i]] = true;
	}
	for (ll i = 1; i <= n+1; i++) {
		if (!aparece[i]) {
			no_aparece = i;
			break;
		}
	}

	ll ultimo_compartido = 0;
	for (; ultimo_compartido < rotado.size() && compartidos > 0; ultimo_compartido++) {
		if (b[indices[ultimo_compartido]] == rotado[ultimo_compartido]) {
			rotado[ultimo_compartido] = no_aparece;
		} else {
			compartidos--;
		}
	}

	if (compartidos > 0) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (; ultimo_compartido < rotado.size(); ultimo_compartido++) {
			rotado[ultimo_compartido] = no_aparece;
		}

		for (ll i = 0; i < rotado.size(); i++) {
			res[indices[i]] = rotado[i];
		}

		for (ll i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}

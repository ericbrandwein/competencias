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

const ll MOD = 1e9 + 7;


ll powmod(ll base, ll exp, ll mod) {
	ll res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

/**
 * El mod tiene que ser primo.
 * Se basa en fermatito.
 */
ll inverso_mod(ll num, ll mod) {
	return powmod(num, mod - 2ll, mod);
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<vector<ll>> graph(n);
	fore(i, 0, n -1 ) {
		ll to;
		cin >> to;
		graph[i + 1].push_back(to);
		graph[to].push_back(i + 1);
	}

	vector<bool> blacks(n, false);
	forn (i) {
		ll num = 0;
		cin >> num;
		if (num) blacks[i] = true;
	}

	vector<ll> combi_blanco(n, 0);
	vector<ll> combi_negro(n,0);
	vector<bool> visited(n, false);
	vector<ll> parents(n, -1);
	stack<ll> next;
	next.push(0);
	while (!next.empty()) {
		ll curr = next.top();
		if (visited[curr]) {
			// Ya calculamos todos los hijos
			ll children_product = 1;
			for (ll child : graph[curr]) {
				if (child != parents[curr]) {
					children_product *= (combi_blanco[child] + combi_negro[child]) % MOD;
					children_product %= MOD;
				}
			}

			if (blacks[curr]) {
				combi_negro[curr] = children_product;
			} else {
				combi_blanco[curr] = children_product;
				for (ll black_child : graph[curr]) {
					if (black_child != parents[curr]) {
						ll inverso = inverso_mod(
							combi_blanco[black_child] + combi_negro[black_child],
							MOD
						);
						ll others_product = (children_product * inverso) % MOD;
						combi_negro[curr] += (others_product * combi_negro[black_child]) % MOD;
						combi_negro[curr] %= MOD;
					}
				}
			}

			next.pop();
		} else {
			for (ll child : graph[curr]) {
				if (child != parents[curr]) {
					next.push(child);
					parents[child] = curr;
				}
			}
		}
		visited[curr] = true;
	}


	cout << combi_negro[0] << endl;

	return 0;
}

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

vec<ll> get_divisores(ll x) {
	vec<ll> res;
	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			res.push_back(i);
			if (i *i != x) {
				res.push_back(x / i);
			}
		}
	}
	return res;
}

const int N = 30'000'000;
int lp[N+1];
vector<int> pr;

void criba() {
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

ll cant_de_primos(ll num) {
	if (num == 1) {
		return 0;
	}
	if (lp[num] == 0) {
		return 1;
	}
	ll min_primo = lp[num];
	while (num % min_primo == 0) num /= min_primo;
	return 1 + cant_de_primos(num);
}


void solve() {
	ll c,d,x;
	cin >> c >> d >> x;

	ll res = 0;
	vec<ll> divisores = get_divisores(x);
	for (ll divisor : divisores) {
		ll nuevo_d = d + (x / divisor);
		// c*lcm = nuevo_d*gcd
		// lcm = nuevo_d*gcd/c
		// a*b/gcd/gcd = nuevo_d/c
		if (nuevo_d % c == 0) {
			ll sobra = nuevo_d / c;
			ll repartidos = cant_de_primos(sobra);
			ll sumados = 1 << repartidos;
			res += sumados;
		}
	}
	cout << res << endl;
}

int main() {
	IOS;

	criba();
	ll t;
	cin >> t;
	while (t--) solve();
}

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

ll calcular(ll l, ll o, ll s, ll t) {
	ll total = 0;
	total += o / 4;
	o -= o / 4;
	
	total += t / 4;
	t = 0;

	s = s / 2 * 2;
	l = l / 2 * 2;
	ll gastar = min(s, l);
	s = 0;
	l -= gastar;
	total += gastar / 2;

	total += l / 4;
	return total;
}

int main() {
	IOS;

	ll l, o, s, t;
	cin >> l >> o >> s >> t;

	ll maxi = 0;
	o = o / 2 * 2;
	t = t / 2 * 2;
	s = min(l, s);

	// Usando LTTS y LLOO
	if (l > 0 && s > 0 && t >= 2) {
		ll nl = l, no = o, ns = s, nt = t, nmax = 0;
		nt = t - 2;
		nl = l - 1;
		ns = s - 1;
		nmax = 1;
		if (nl >= 2 && no >= 2) {
			nl -= 2;
			no -= 2;
			nmax++;
			nmax += calcular(nl, no, ns, nt);
			maxi = nmax;
		}
	}

	// Usando LLOO y LTTS
	if (l >= 2 && o >= 2) {
		ll nl = l, no = o, ns = s, nt = t, nmax = 0;
		nl -= 2;
		no -= 2;
		nmax++;
		if (nl > 0 && ns > 0 && nt >= 2) {
			nt -= 2;
			nl--;
			ns--;
			nmax++;
			nmax += calcular(nl, no, ns, nt);
			maxi = max(nmax, maxi);
		}
	}

	// Usando solo LLOO
	if (l >= 2 && o >= 2) {
		ll nl = l, no = o, ns = s, nt = t, nmax = 0;
		nl -= 2;
		no -= 2;
		nmax++;
		nmax += calcular(nl, no, ns, nt);
		maxi = max(nmax, maxi);
	}

	// Usando solo LTTS
	if (l > 0 && s > 0 && t >= 2) {
		ll nl = l, no = o, ns = s, nt = t, nmax = 0;
		nt -= 2;
		nl--;
		ns--;
		nmax++;
		nmax += calcular(nl, no, ns, nt);
		maxi = max(nmax, maxi);
	}

	// Usando ninguno
	maxi = max(calcular(l, o, s, t), maxi);
	
	cout << maxi << endl;

	return 0;
}

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

vec<ll> with_biggest(ll pos, vec<ll>& a, ll& sum) {
	vec<ll> heights(a.size(), 0);
	heights[pos] = a[pos];
	sum += a[pos];
	for (ll i = pos - 1; i >= 0; i--) {
		heights[i] = min(heights[i+1], a[i]);
		sum += heights[i];
	}
	for (ll i = pos + 1; i < a.size(); i++) {
		heights[i] = min(heights[i-1], a[i]);
		sum += heights[i];
	}
	return heights;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<ll> sumas_izq(n, 0), sumas_der(n, 0);
	stack<ll> creciente;
	for (ll i = 0; i < n; i++) {
		while (!creciente.empty() && a[creciente.top()] >= a[i]) {
			creciente.pop();
		}
		ll ult_menor = -1;
		if (!creciente.empty()) {
			ult_menor = creciente.top();
			sumas_izq[i] += sumas_izq[ult_menor];
			sumas_izq[i] += a[ult_menor];
		}
		sumas_izq[i] += (i - ult_menor - 1) * a[i];
		creciente.push(i);
	}
	stack<ll> decreciente;
	for (ll i = n - 1; i >= 0; i--) {
		while (!decreciente.empty() && a[decreciente.top()] >= a[i]) {
			decreciente.pop();
		}
		ll ult_menor = n;
		if (!decreciente.empty()) {
			ult_menor = decreciente.top();
			sumas_der[i] += sumas_der[ult_menor];
			sumas_der[i] += a[ult_menor];
		}
		sumas_der[i] += (ult_menor - i - 1) * a[i];
		decreciente.push(i);
	}

	ll suma_max = 0;
	ll maxi = 0;
	for (ll i = 0; i < n; i++) {
		ll suma = a[i] + sumas_izq[i] + sumas_der[i];
		if (suma > suma_max) {
			suma_max = suma;
			maxi = i;
		}
	}

	ll sum = 0;
	vec<ll> res = with_biggest(maxi, a, sum);
	assert(suma_max == sum);

	// ll maxi = 0;
	// vec<ll> res;
	// for (ll i = 0; i < n; i++) {
	// 	ll sum = 0;
	// 	vec<ll> new_vec = with_biggest(i, a, sum);
	// 	if (sum > maxi) {
	// 		maxi = sum;
	// 		res = new_vec;
	// 	}
	// }

	for (ll i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}

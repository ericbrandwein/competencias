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

vector<ll> calculate_next(vector<ll>& a) {
	ll n = a.size();
	vector<ll> next(n, 0);

	fore (i, 0, n) {
		if (a[i] != 0) {
			ll next_pos = (i + 1) % n;
			if (a[next_pos] == 0) {
				next_pos++;
				next_pos %= n;
			}
			next[a[i]] = a[next_pos];
		}
	}
	return next;
}


int main() {
	IOS;

	ll n;
	cin >> n;

	vector<ll> a(n);
	vector<ll> b(n);
	forn (i) {
		cin >> a[i];
	}
	forn (i) {
		cin >> b[i];
	}
	vector<ll> next_a = calculate_next(a);
	vector<ll> next_b = calculate_next(b);
	cout << (next_a == next_b ? "YES" : "NO") << endl;


	return 0;
}

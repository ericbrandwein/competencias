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
	vector<vector<ll>> a(n, vector<ll>(2));
	forn (i) {
		cin >> a[i][0];
	}
	forn (i) {
		cin >> a[i][1];
	}

	// la mejor suma par e impar para la posicion i
	vector<vector<ll>> sumas(n, vector<ll>(2));
	sumas[0][0] = a[0][0];
	sumas[0][1] = a[0][1];
	fore (i, 1, n) {
		sumas[i][0] = max(sumas[i - 1][0], sumas[i - 1][1] + a[i][0]);
		sumas[i][1] = max(sumas[i - 1][1], sumas[i - 1][0] + a[i][1]);
	}

	cout << max(sumas[n-1][0], sumas[n-1][1]) << endl;

	return 0;
}

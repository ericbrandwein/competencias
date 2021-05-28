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
	int n;
	cin >> n;

	vector<int> vector_denso(n);
	for (int i = 0; i < n; i++) {
		cin >> vector_denso[i];
	}

	int agregados = 0;
	for (int i = 1; i < n; i++) {
		// Voy a agarrar el par
		// (vector_denso[i - 1], vector_denso[i])
		int mini = min(vector_denso[i - 1], vector_denso[i]);
		int maxi = max(vector_denso[i - 1], vector_denso[i]);

		while (mini*2 < maxi) {
			agregados++;
			mini *= 2;
		}
	}

	cout << agregados << endl;
}


int main() {
	IOS;

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}

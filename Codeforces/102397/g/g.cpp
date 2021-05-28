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

	ll n, k;
	cin >> n >> k;

	vector<ll> conteoa(100001, 0);
	ll canta = 0;
	vector<ll> conteob(100001, 0);
	ll cantb = 0;

	vector<ll> as(n);
	forn (i) {
		cin >> as[i];
		if (k > as[i]) {
			canta += conteoa[k - as[i]];
		}
		conteoa[as[i]]++;
	}

	vector<ll> bs(n);
	forn (i) {
		cin >> bs[i];
		if (k > bs[i]) {
			cantb += conteob[k - bs[i]];
		}
		conteob[bs[i]]++;
	}

	if (canta > cantb) {
		cout << "MAHMOUD" << endl;
	} else if (cantb > canta) {
		cout << "BASHAR" << endl;
	} else {
		cout << "DRAW" << endl;
	}



	return 0;
}

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


	ll a1,b1,c1,d1,a2,b2,c2,d2;
	cin >> a1 >> b1 >> c1 >> d1>> a2>>b2>> c2 >> d2;
	while ( a1 != 0 || b1 != 0 || c1 != 0 || d1 != 0 || a2 != 0 || b2 != 0 ||c2 != 0 ||d2 != 0) {
		pair<ll,ll> t = {-1,-1};
		pair<ll,ll> first_case_t = {0,0};
		// a1*t + b1 = a2*t + b2
		// (b1 - b2)/(a2-a1) = t <---- a2 != a1
		if (a2 == a1) {
			if (b1 == b2) {
				// C1*t + d1 === c2*t + d2 (mod 360)
				// t === (d2 - d1)*(c1-c2)^-1 (mod 360) <------ (c1-c2) es coprimo con 360
				// (c1-c2)*t === (d2 - d1) (mod 360) <------ sino
				// c * t = 360 * k + d
				// p * c' * t = p * s * k + d
				// c' * t = s*k  + d/p
				ll c = (((c1-c2) % 360) + 360) % 360;
				ll d = (((d2 - d1) % 360) + 360) % 360;
				ll i;
				for (i = 0; i < 360; i++) {
					if (((c*i) % 360) == (d % 360)) {
						break;
					}
				}
				if (i != 360) {
					first_case_t = {}
				}
			}
		}
		if (b1 == 0 && b2 == 0) {
			t = {0,1};
		} else {

		}

		cin >> a1 >> b1 >> c1 >> d1>> a2>>b2>> c2 >> d2;
	}


}

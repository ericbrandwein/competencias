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

	ll q;
	cin >> q;
	while (q--) {
		ll h, n;
		cin >> h >> n;

        vector<ll> platforms(n);
        forn (i) {
            cin >> platforms[i];
        }

        ll next_plat = 1;
        ll total = 0;
        while (next_plat < n) {
            if ((next_plat == n -1 && platforms[next_plat] != 1) 
                || next_plat < n - 1 && platforms[next_plat + 1] != platforms[next_plat] - 1) {
                total++;
            } else {
                next_plat++;
            }
            next_plat++;
        }

        cout << total << endl;



	}

	return 0;
}

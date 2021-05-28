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

    ll n, v;
    cin >> n;
    ll pos = 0, neg = 0, ceros = 0, costo = 0;

    forn (i) {
        cin >> v;
        if (v < 0) {
            neg++;
            costo += abs(v) - 1;
        } else if (v > 0) {
            pos++;
            costo += v - 1;
        } else {
            ceros++;
            costo++;
        }
    }

    if (neg % 2 && !ceros)
        costo += 2;

    cout << costo << endl;

	return 0;
}

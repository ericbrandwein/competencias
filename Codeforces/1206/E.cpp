//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
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
    ll n;
    cin >> n;

    bool t[n][n];
    bool es_igual;
    t[0][0] = true;
    t[n-1][n-1] = false;

    forn(i) {
        if (i != 0) {
            cout << "? " << 1 << " " << i << " " << 1 << " " << i + 1 << endl << flush;
            cin >> es_igual;
            t[i][0] = es_igual ? t[i-1][0] : !t[i-1][0];
        }
        for(ll j = 1; j < n; j++) {
            cout << "? " << j << " " << i + 1 << " " << j + 1 << " " << i + 1 << endl << flush;
            cin >> es_igual;
            t[i][j] = es_igual ? t[i][j-1] : !t[i][j-1];
        }
    }

    cout << "!" << endl;
    forn(i) {
        forn(j)
            cout << t[i][j];
        cout << endl;
    }
}

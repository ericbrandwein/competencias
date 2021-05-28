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

    vector<ll> diferencias;
    ll anterior;
    cin >> anterior;
    ll total = 0;
    ll primero = anterior;

    fore (i, 1, n) {
        ll num;
        cin >> num;

        diferencias.push_back(num - anterior);
        anterior = num;
        if (i == n - 1) {
            total = num - primero;
        }
    }

    sort(all(diferencias));

    fore (i, 0, k - 1) {
        total -= diferencias[diferencias.size() - i - 1];
    }

    cout << total << endl;
	return 0;
}

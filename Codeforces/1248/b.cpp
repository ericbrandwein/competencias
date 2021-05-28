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
    vector<ll> sticks(n);
    forn (i) {
        cin >> sticks[i];
    }
    
    sort(all(sticks));

    ll base = 0;
    ll height = 0;
    for (ll i = 0; i < n - i - 1; i++ ) {
        base += sticks[i];
        height += sticks[n - i - 1];
    }

    if (n % 2 == 1) {
        height += sticks[n / 2];
    }

    cout << height * height + base * base << endl;
}

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
	ll n;
	cin >> n;

    vector<ll> a(n);
    forn (i) {
        cin >> a[i];
    }

    vector<ll> b(n);
    forn (i) {
        cin >> b[i];
    }

    // trato de poner todo en i - 1
    vector<ll> filled(n, 0);
    vector<ll> used_in_right(n, 0);
    fore (i, 0, n-1) {
        ll previous = i - 1;
        if (previous < 0) {
            previous += n;
        }
        ll put_in_previous = min(b[previous] - filled[previous], a[i]);
        filled[previous] += put_in_previous;
        ll remaining = a[i] - put_in_previous;
        filled[i] += remaining;
        used_in_right[i] = remaining;
        if (filled[i] > b[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    // pongo lo de a[n - 1] en i -1 y veo lo que me queda
    ll previous = n - 2;
    ll put_in_previous = min(b[previous] - filled[previous], a[n - 1]);
    filled[previous] += put_in_previous;
    ll remaining = a[n - 1] - put_in_previous;

    // trato de poner el remaining del anterior en el siguiente, si llego
    // de nuevo al n - 1 quiere decir que no se puede
    for (ll i = 0; i < n - 1 && remaining > 0; i++) {
        previous = i - 1;
        if (previous < 0) {
            previous += n;
        }
        used_in_right[previous] += remaining;
        if (used_in_right[previous] > b[previous]) {
            cout << "NO" << endl;
            return;
        }

        ll used_in_left = a[i] - used_in_right[i];
        ll available_in_previous = b[previous] - used_in_right[previous];
        remaining = used_in_left - available_in_previous;
    }

    if (remaining > 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}



int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}

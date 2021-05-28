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

struct Event {
    ll type, first, second;
};

int main() {
	IOS;

    ll n;
    cin >> n;

    vec<ll> orig(n);
    forn (i) {
        cin >> orig[i];
    }

    ll q;
    cin >> q;

    vector<Event> events;
    fore (i, 0, q) {
        Event e;
        cin >> e.type;
        cin >> e.first;
        if (e.type == 1) {
            cin >> e.second;
        }
        events.push_back(e);
    }

    map<ll, ll> finales;
    ll max_cambio = 0;
    for (ll i = q - 1; i >= 0; i--) {
        Event& actual = events[i];
        if (actual.type == 2) {
            max_cambio = max(actual.first, max_cambio);
        } else if (finales.find(actual.first) == finales.end()) {
            finales[actual.first] = max(actual.second, max_cambio);
        }
    }

    forn (i) {
        auto final = finales.find(i + 1);
        if (final != finales.end()) {
            orig[i] = final->second;
        } else {
            orig[i] = max(orig[i], max_cambio);
        }
    }

    forn (i) {
        if (i != 0) {
            cout << " ";
        }
        cout << orig[i];
    }
    cout << endl;

}

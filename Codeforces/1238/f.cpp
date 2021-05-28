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

pair<ll, ll> mejor_camino(ll padre, ll desde, vector<vector<ll>>& graph) {
    vector<ll>& hijos = graph[desde];
    ll mejor_rama = 0;
    ll segunda_mejor_rama = 0;
    ll mejor_camino_hijo = 0;
    for (ll i = 0; i < hijos.size(); i++) {
        if (graph[hijos[i]].size() > 1 && hijos[i] != padre) {
            pair<ll, ll> camino_hijo = mejor_camino(desde, hijos[i], graph);
            if (camino_hijo.first > mejor_camino_hijo) {
                mejor_camino_hijo = camino_hijo.first;
            }
            if (camino_hijo.second > mejor_rama) {
                segunda_mejor_rama = mejor_rama;
                mejor_rama = camino_hijo.second;
            } else if (camino_hijo.second > segunda_mejor_rama) {
                segunda_mejor_rama = camino_hijo.second;
            }
        }
    }

    // La mejor rama no cuenta al padre.
    ll rama_mia = hijos.size() + 1;
    if (mejor_rama > 0) {
        rama_mia += mejor_rama - 1;
    }
    ll camino_mio = rama_mia;
    if (segunda_mejor_rama > 0) {
        camino_mio += segunda_mejor_rama - 1;
    }
    if (padre != -1) {
        rama_mia--;
    }

    camino_mio = max(camino_mio, mejor_camino_hijo);

    return make_pair(camino_mio, rama_mia);
}

int main() {
	IOS;

	ll q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;

        vector<vector<ll>> graph(n);
        fore (i, 0, n - 1) {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        ll i = 0;
        for (; i < n && graph[i].size() == 1; i++);
        if (i == n) {
            cout << n << endl;
        } else {
            pair<ll, ll> best = mejor_camino(-1, i, graph);
            cout << best.first << endl;
        }
	}

	return 0;
}

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

    string grande, chico;
    cin >> grande >> chico;

    vector<ll> last_possible(chico.size(), 0);
    ll indice_chico = chico.size() - 1;
    for (ll i = grande.size() - 1; i >= 0 && indice_chico >= 0; i--) {
        if (grande[i] == chico[indice_chico]) {
            last_possible[indice_chico] = i;
            indice_chico--;
        }
    }

    vector<ll> first_possible(chico.size(), 0);
    indice_chico = 0;
    for (ll i = 0; i < grande.size() && indice_chico < chico.size(); i++) {
        if (grande[i] == chico[indice_chico]) {
            first_possible[indice_chico] = i;
            indice_chico++;
        }
    }

    ll max_len = 0;
    ll anterior = -1;
    fore (i, 0, chico.size()) {
        max_len = max(last_possible[i] - anterior - 1, max_len);
        anterior = first_possible[i];
    }
    max_len = max((ll) grande.size() - 1 - anterior, max_len);

    cout << max_len << endl;


	return 0;
}

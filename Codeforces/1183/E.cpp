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

ll cant_sacando(
    ll a_sacar, vector<pair<ll, char>>& conjuntos, ll indice, ll sacados_indice,
    char ultimo_disp) {
    if (a_sacar == 0) {
        return 1;
    }
    if (indice >= conjuntos.size()) {
        return 0;
    }

    ll cant = 0;
    if (sacados_indice < conjuntos[indice].first && conjuntos[indice].second != ultimo_disp) {
        cant += cant_sacando(a_sacar - 1, conjuntos, indice, sacados_indice + 1, ultimo_disp);
    }
    if (sacados_indice < conjuntos[indice].first) {
        cant += cant_sacando(a_sacar, conjuntos, indice + 1, 0, conjuntos[indice].second);
    } else {
        cant += cant_sacando(a_sacar, conjuntos, indice + 1, 0, ultimo_disp);        
    }

    return cant;
}

int main() {
	IOS;

    ll n, k;
    cin >> n >> k;

    string letters;
    cin >> letters;
    vec<pair<ll, char>> conjuntos;
    conjuntos.push_back(make_pair(1, letters[0]));
    fore (i, 1, letters.size()) {
        if (conjuntos[conjuntos.size() - 1].second == letters[i]) {
            conjuntos[conjuntos.size() - 1].first++;
        } else {
            conjuntos.push_back(make_pair(1, letters[i]));
        }
    }

    ll gasto = 0;
    ll a_sacar = 0;
    while (k > 0) {
        ll cant = cant_sacando(a_sacar, conjuntos, 0, 0, 0);
        ll usados = min(cant, k);
        gasto += usados * a_sacar;
        k -= usados;
        a_sacar++;
        if (k > 0 && a_sacar > letters.size()) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << gasto << endl;

    
	return 0;
}

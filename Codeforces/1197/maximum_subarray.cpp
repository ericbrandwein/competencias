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

/* 
Entrada:
    n - cantidad de elementos
    n números separados por espacios - elementos 
Salida:
    s - suma máxima
    Intervalo: [l, r] - índices de un subarray de suma máxima
*/

int main() {
	IOS;

    ll n;
    cin >> n;

    vector<ll> nums(n);
    forn (i) {
        cin >> nums[i];
    }

    vector<ll> acumuladas;
    ll suma = 0;
    forn (i) {
        suma += nums[i];
        acumuladas.push_back(suma);
    }

    vector<ll> indices_minimos;
    vector<ll> minimos;
    ll minimo = 0;
    ll indice_minimo = -1;
    forn (i) {
        if (acumuladas[i] < minimo) {
            minimo = acumuladas[i];
            indice_minimo = i;
        }
        indices_minimos.push_back(indice_minimo);
        minimos.push_back(minimo);
    }

    ll mayor_resta = 0;
    ll l = -1;
    ll r = -1;
    forn (i) {
        ll resta_actual = acumuladas[i] - minimos[i];
        if (resta_actual > mayor_resta) {
            l = indices_minimos[i] + 1;
            r = i;
            mayor_resta = resta_actual;
        }
    }

    cout << mayor_resta << endl;
    cout << "Intervalo: [" << l << ", " << r << "]" << endl;

	return 0;
}

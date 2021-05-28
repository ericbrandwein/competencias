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
struct Intervalo {
    ll l, r, suma;
};

int main() {
	IOS;

    ll n;
    cin >> n;

    vector<ll> nums(n);
    forn (i) {
        cin >> nums[i];
    }

    // Hacemos que sea una lista de intervalos alternados positivos con negativos
    vector<Intervalo> intervalos;
    ll suma_actual = nums[0];
    bool positivo = suma_actual > 0;
    Intervalo intervalo_actual = {0, 0, suma_actual};
    fore (i, 1, n) {
        if ((positivo && nums[i] < 0) ||
            (!positivo && nums[i] > 0)) {
            positivo = !positivo;
            intervalo_actual.r = i - 1;
            intervalo_actual.suma = suma_actual;
            intervalos.push_back(intervalo_actual);
            intervalo_actual.l = i;
            suma_actual = 0;
        }
        suma_actual += nums[i];
    }
    intervalo_actual.r = n - 1;
    intervalo_actual.suma = suma_actual;
    intervalos.push_back(intervalo_actual);
    
    ll primer_positivo;
    for (primer_positivo = 0; 
        intervalos[primer_positivo].suma < 0; 
        primer_positivo++);

    Intervalo mejor_anterior;
    Intervalo mejor_total = {-1, -1, 0};
    for (ll i = primer_positivo; i < intervalos.size(); i += 2) {
        Intervalo mejor = intervalos[i];
        // ¿Cuánto sumaría si extendiese el array hasta el anterior positivo?
        ll sumado_con_mejor_anterior = intervalos[i - 1].suma + mejor_anterior.suma;
        if (i - 2 >= 0 && sumado_con_mejor_anterior > 0) {
            mejor.suma += sumado_con_mejor_anterior;
            mejor.l = mejor_anterior.l;
        }
        if (mejor.suma > mejor_total.suma) {
            mejor_total = mejor;
        }
        mejor_anterior = mejor;
    }

    cout << mejor_total.suma << endl;
    cout << "Intervalo: [" << mejor_total.l << ", " << mejor_total.r << "]" << endl;

	return 0;
}

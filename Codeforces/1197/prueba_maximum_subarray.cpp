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

int main(int argc, char* argv[]) {
	IOS;

    ll cantidad = strtol(argv[1], NULL, 10);

    cout << cantidad << endl;

    fore (i, 0, cantidad) {
        cout << rand() << " ";
    }

	return 0;
}

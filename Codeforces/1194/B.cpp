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
    
    int q;
    cin >> q;

    fore (i, 0, q) {
        ll rows, cols;
        cin >> rows >> cols;

        vector<vector<bool>> pintados(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            string fila;
            cin >> fila;
            for (int j = 0; j < cols; j++) {
                pintados[i][j] = fila[j] == '*';
            }
        }

        vector<ll> cant_vacios_filas(rows, cols);
        vector<ll> cant_vacios_cols(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pintados[i][j]) {
                    cant_vacios_filas[i]--;
                    cant_vacios_cols[j]--;
                }
            }
        }

        ll mini = rows * cols;
        for (ll i = 0; i < rows; i++) {
            for (ll j = 0; j < cols; j++) {
                ll suma = cant_vacios_filas[i] + cant_vacios_cols[j];
                if (!pintados[i][j]) {
                    suma--;
                } 
                mini = min(suma, mini); 
            }
        }

        cout << mini << endl;
    }
    
	return 0;
}

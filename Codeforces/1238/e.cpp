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

ll sumar(ll mask, ll tecla, vector<vector<ll>>& conexiones, vector<ll>& prendidos) {
    ll conexiones_mask = conexiones[mask][tecla];
    ll no_mask = mask ^ ((1 << conexiones[mask].size()) - 1);
    ll conexiones_no_mask = conexiones[no_mask][tecla];

    return prendidos[mask] * (conexiones_mask - conexiones_no_mask);
}

void actualizar_sumas(ll mask, vector<ll>& sumas, vector<vector<ll>>& conexiones_mask,
    vector<ll>& prendidos) {
    ll divided_mask = mask;
    ll i = 0;
    while (divided_mask != 0) {
        if (divided_mask & 1) {
            ll mask_without_i = mask ^ (1 << i);
            sumas[mask] = min(
                sumas[mask], 
                sumas[mask_without_i] + sumar(mask_without_i, i, conexiones_mask, prendidos)
            );
        }
        divided_mask >>= 1;
        i++;
    }
}

ll calcular_prendidos(ll mask) {
    ll prendidos = 0;
    while (mask !=0) {
        if (mask & 1) {
            prendidos++;
        }
        mask >>= 1;
    }
    return prendidos;
}

ll last(ll mask) {
    ll i = 0;
    while ((mask & 1) == 0) {
        mask >>= 1;
        i++;
    }
    return i;
}

int main() {
	IOS;

    ll n, m;
    cin >> n >> m;
    string pass;
    cin >> pass;

    vector<vector<ll>> conexiones(m, vector<ll>(m, 0));
    fore (i, 1, n) {
        conexiones[pass[i] - 'a'][pass[i - 1] - 'a']++;
        conexiones[pass[i - 1] - 'a'][pass[i] - 'a']++;
    }

    ll cant_mascaras = 1 << m;
    vector<ll> prendidos(cant_mascaras, 0);
    for (ll i = 1; i < cant_mascaras; i++) {
        prendidos[i] = calcular_prendidos(i);
    }

    vector<vector<ll>> conexiones_mask(cant_mascaras, vector<ll>(m, 0));
    for (ll mask = 1; mask < cant_mascaras; mask++) {
        ll ult_prendido = last(mask);
        ll mask_sin_ulti = mask ^ (1 << ult_prendido);

        for (ll tecla = 0; tecla < m; tecla++) {
            conexiones_mask[mask][tecla] = conexiones_mask[mask_sin_ulti][tecla];
            if (ult_prendido != tecla) {
                conexiones_mask[mask][tecla] += conexiones[ult_prendido][tecla];
            }
        }
    }

    vector<ll> sumas(cant_mascaras, LONG_LONG_MAX);
    sumas[0] = 0;
    for (ll i = 1; i < cant_mascaras; i++) {
        actualizar_sumas(i, sumas, conexiones_mask, prendidos);
    }

    cout << sumas[cant_mascaras - 1] << endl;
}

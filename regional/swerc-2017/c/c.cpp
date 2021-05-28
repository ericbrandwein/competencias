#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK: 20000000")
#define _CRT_SECURE_NO_WARNINGS
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

const ll MOD = 1e9;

vec<int> to_bits(ll n) {
	vec<int> res;
	while (n > 0) {
		res.push_back(n% 2);
		n/=2;
	}
	return res;
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;


	// ancho pot de 2, entra_izq, sale_der
	ll max_pot = 64;
	vec<vec<vec<ll>>> combinaciones(max_pot, vec<vec<ll>>(1<<n, vec<ll>(1<<n, 0)));
	for (ll izq = 0; izq < 1 << n; izq++) {
		for (ll der = 0; der < 1 << n; der++) {
			vec<ll> combis_col(n + 1, 0);
			combis_col[0] = 1;
			for (ll bit = 1; bit <= n; bit++) {
				combis_col[bit] = combis_col[bit-1];
				int bit_der = (der >> (bit-1)) % 2;
				int bit_izq = (izq >> (bit-1)) % 2;
				if (bit_der == 1 && bit_izq == 1) {
					combis_col[bit] = 0;
				} else if (bit_izq == 0 && bit_der == 0 && bit > 1) {
					int bit_der_ant = (der >> (bit-2)) % 2;
					int bit_izq_ant = (izq >> (bit-2)) % 2;
					if (bit_izq_ant == 0 && bit_der_ant == 0) {
						combis_col[bit] += combis_col[bit-2];
					}
				}
				combis_col[bit] %= MOD;
			}
			combinaciones[0][izq][der] = combis_col[n];
		}
	}


	for (ll pot = 1; pot < max_pot; pot++) {
		for (ll izq = 0; izq < 1<<n; izq++) {
			for (ll der = 0; der < 1<<n; der++) {
				for (ll mid = 0; mid < 1<<n; mid++) {
					combinaciones[pot][izq][der] +=
						(combinaciones[pot-1][izq][mid] * combinaciones[pot-1][mid][der]) % MOD;
					combinaciones[pot][izq][der] %= MOD;
				}
			}
		}
	}

	vec<int> bits = to_bits(m); // el primero es el menos significativo
	ll primer_uno = 0;
	for (primer_uno = 0; bits[primer_uno] == 0; primer_uno++);

	vec<ll> combis = combinaciones[primer_uno][0]; // derecha
	for (ll i = primer_uno + 1; i < bits.size(); i++) {
		if (bits[i] == 1) {
			vec<ll> nuevas_combis(1<<n, 0);
			for (ll der = 0; der < 1<<n; der++) {
				for (ll izq = 0; izq < 1<<n; izq++) {
					nuevas_combis[der] +=
						(combis[izq] * combinaciones[i][izq][der]) % MOD;
					nuevas_combis[der] %= MOD;
				}
			}
			combis = nuevas_combis;
		}
	}

	cout << combis[0] << endl;




}

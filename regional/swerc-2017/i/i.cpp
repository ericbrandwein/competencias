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

pair<ll,ll> interseccion(pair<ll,ll>& prim, pair<ll,ll>& seg) {
	return {max(prim.first, seg.first), min(prim.second, seg.second)};
}

bool contenido(pair<ll,ll>& intervalo, ll punto) {
	return intervalo.first <= punto && punto <= intervalo.second;
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	vec<vec<ll>> stairs(n);
	vec<vec<ll>> jars(n, vec<ll>(m, 0));
	forn (fila) {
		string nums;
		cin >> nums;
		for (ll col = 0; col < nums.size(); col++) {
			ll numero;
			if (nums[col] == '-') {
				numero = 0;
			} else {
				numero = nums[col] - '0';
			}
			jars[fila][col] = numero;
		}
		string pipes;
		cin >> pipes;
		for (ll col = 0; col < pipes.size(); col++) {
			if (pipes[col] == '|') {
				stairs[fila].push_back(col);
			}
		}
	}

	vec<vec<ll>> acums(n, vec<ll>(m+1, 0)); // exclusivo [0, i)
	for (ll fila = 0; fila < n; fila++) {
		acums[fila][0] = 0;
		for (ll col = 1; col <= m; col++) {
			acums[fila][col] = acums[fila][col-1] + jars[fila][col-1];
		}
	}

	vec<vec<ll>> jar_before(n), jar_after(n); // fila, stair
	vec<vec<ll>> jar_before_abj(n), jar_after_abj(n); // fila, stair
	for (ll fila = 0; fila < n; fila++) {
		ll jar = -1;
		for (ll stair : stairs[fila]) {
			for (ll nuevo_jar = jar + 1; nuevo_jar <= stair; nuevo_jar++) {
				if (jars[fila][nuevo_jar] > 0) {
					jar = nuevo_jar;
				}
			}
			if (jar == stair) {
				jar_before[fila].push_back(-1);
			} else {
				jar_before[fila].push_back(jar);
			}
		}

		jar = m;
		jar_after[fila] = vec<ll>(stairs[fila].size(), -1);
		for (ll stair_i = stairs[fila].size() - 1; stair_i >= 0; stair_i--) {
			ll stair = stairs[fila][stair_i];
			for (ll nuevo_jar = jar - 1; nuevo_jar >= stair; nuevo_jar--) {
				if (jars[fila][nuevo_jar] > 0) {
					jar = nuevo_jar;
				}
			}
			if (jar != stair && jar != m) {
				jar_after[fila][stair_i] = jar;
			}
		}

		jar = -1;
		for (ll stair : stairs[fila]) {
			if (fila == n - 1) {
				jar_before_abj[fila].push_back(-1);
			} else {
				for (ll nuevo_jar = jar + 1; nuevo_jar <= stair; nuevo_jar++) {
					if (jars[fila+1][nuevo_jar] > 0) {
						jar = nuevo_jar;
					}
				}
				if (jar == stair) {
					jar_before_abj[fila].push_back(-1);
				} else {
					jar_before_abj[fila].push_back(jar);
				}
			}
		}

		jar = m;
		jar_after_abj[fila] = vec<ll>(stairs[fila].size(), -1);
		for (ll stair_i = stairs[fila].size() - 1; stair_i >= 0; stair_i--) {
			ll stair = stairs[fila][stair_i];
			if (fila == n - 1) {
				jar_after_abj[fila].push_back(-1);
			} else {
				for (ll nuevo_jar = jar - 1; nuevo_jar >= stair; nuevo_jar--) {
					if (jars[fila+1][nuevo_jar] > 0) {
						jar = nuevo_jar;
					}
				}
				if (jar != stair && jar != m) {
					jar_after_abj[fila][stair_i] = jar;
				}
			}
		}

	}


	// fila, bajando, subiendo
	vec<vec<vec<ll>>> max_candies(n, vec<vec<ll>>(10, vec<ll>(10, -1)));
	for (ll bajando = 0; bajando < stairs[n-1].size(); bajando++) {
		for (ll subiendo = bajando; subiendo < stairs[n-1].size(); subiendo++) {
			max_candies[n-1][bajando][subiendo] = 0;
		}
	}

	for (ll fila = n - 2; fila >= 0; fila--) {
		for (ll bajando = 0; bajando < stairs[fila].size(); bajando++)
		for (ll subiendo = bajando; subiendo < stairs[fila].size(); subiendo++) {
			ll stairs_izq = stairs[fila][bajando];
			ll stairs_der = stairs[fila][subiendo];
			// Si no bajamos de la fila + 1
			max_candies[fila][bajando][subiendo] =
				acums[fila+1][stairs_der + 1] - acums[fila+1][stairs_izq];
			if (jar_before_abj[fila][bajando] != -1) {
				max_candies[fila][bajando][subiendo] +=
					jars[fila+1][jar_before_abj[fila][bajando]];
			}
			if (jar_after_abj[fila][subiendo] != -1) {
				max_candies[fila][bajando][subiendo] +=
					jars[fila+1][jar_after_abj[fila][subiendo]];
			}

			// if (bajando == subiendo && jars[fila+1][stairs_izq] > 0) {
			// 	// Hay un jar justo abajo de esta escalera, no podemos bajar más
			// 	continue;
			// }
			// Si bajamos a la fila + 2
			for (ll abajo_baj = 0; abajo_baj < stairs[fila+1].size(); abajo_baj++)
			for (ll abajo_sub = abajo_baj; abajo_sub < stairs[fila+1].size(); abajo_sub++) {
				if (abajo_baj == abajo_sub && jars[fila+1][stairs[fila+1][abajo_baj]] > 0) {
					// Si son iguales y hay un jar arriba, no se puede
					continue;
				}
				ll stairs_izq_abj = stairs[fila+1][abajo_baj];
				ll stairs_der_abj = stairs[fila+1][abajo_sub];
				pair<ll,ll> intervalo_izq = {
					min(stairs_izq, stairs_izq_abj),
					max(stairs_izq, stairs_izq_abj)
				};
				pair<ll,ll> intervalo_der = {
					min(stairs_der, stairs_der_abj),
					max(stairs_der, stairs_der_abj)
				};
				pair<ll,ll> compartidos = interseccion(intervalo_izq, intervalo_der);
				if (
					compartidos.first <= compartidos.second &&
					acums[fila+1][compartidos.second + 1] - acums[fila+1][compartidos.first] > 0
				) {
					// Se pisan algunos jars
					continue;
				}
				pair<ll,ll> usados = intervalo_izq;
				// del bajando voy al abajo_baj
				ll curr_candies =
					acums[fila+1][max(stairs_izq, stairs_izq_abj) + 1] -
					acums[fila+1][min(stairs_izq, stairs_izq_abj)];
				if (stairs_izq <= stairs_izq_abj) {
					ll jar_agregado = jar_before_abj[fila][bajando];
					if (jar_agregado != -1) {
						curr_candies += jars[fila+1][jar_agregado];
						usados.first = jar_agregado;
					}
					jar_agregado = jar_after[fila+1][abajo_baj];
					if (jar_agregado != -1 && jar_agregado < min(stairs_der, stairs_der_abj)) {
						curr_candies += jars[fila+1][jar_agregado];
						usados.second = jar_agregado;
					}
				} else {
					ll jar_agregado = jar_after_abj[fila][bajando];
					if (jar_agregado != -1 && jar_agregado < min(stairs_der, stairs_der_abj)) {
						curr_candies += jars[fila+1][jar_agregado];
						usados.second = jar_agregado;
					}
					jar_agregado = jar_before[fila+1][abajo_baj];
					if (jar_agregado != -1) {
						curr_candies += jars[fila+1][jar_agregado];
						usados.first = jar_agregado;
					}
				}

				// del subiendo voy al abajo_sub
				curr_candies +=
					acums[fila+1][intervalo_der.second + 1] -
					acums[fila+1][intervalo_der.first];
				if (stairs_der <= stairs_der_abj) {
					ll jar_agregado = jar_before_abj[fila][subiendo];
					if (jar_agregado != -1 && !contenido(usados, jar_agregado)) {
						curr_candies += jars[fila+1][jar_agregado];
					}
					jar_agregado = jar_after[fila+1][abajo_sub];
					if (jar_agregado != -1) {
						curr_candies += jars[fila+1][jar_agregado];

					}
				} else {
					ll jar_agregado = jar_after_abj[fila][subiendo];
					if (jar_agregado != -1) {
						curr_candies += jars[fila+1][jar_agregado];

					}
					jar_agregado = jar_before[fila+1][abajo_sub];
					if (jar_agregado != -1 && !contenido(usados, jar_agregado)) {
						curr_candies += jars[fila+1][jar_agregado];

					}
				}

				curr_candies += max_candies[fila+1][abajo_baj][abajo_sub];
				max_candies[fila][bajando][subiendo] = max(
					max_candies[fila][bajando][subiendo],
					curr_candies
				);
			}
		}
	}


	ll res = 0;
	for (ll bajando = 0; bajando < stairs[0].size(); bajando++) {
		for (ll subiendo = bajando; subiendo < stairs[0].size(); subiendo++) {
			res = max(res, max_candies[0][bajando][subiendo]);
		}
	}

	cout<< res << endl;







}

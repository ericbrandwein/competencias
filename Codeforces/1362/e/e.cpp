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

const ll MOD = 1e9 + 7;

ll mulmod(ll a, ll b, ll mod) {
	ll res = 0;
	while (b) {
		if (b & 1) {
			res = (res + a) % mod;
		}
		a = a * 2 % mod;
		b >>= 1;
	}
	return res;
}

ll powmod(ll base, ll exp, ll mod) {
	ll res = 1;
	while (exp) {
		if (exp & 1) {
			// res = mulmod(res, base, mod);
			res = (res * base) % mod;
		}
		// base = mulmod(base, base, mod);
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

ll llenar_diferencia_desde(
	const map<ll, ll>::reverse_iterator& end_it, map<ll, ll>::reverse_iterator& it, ll ultima_potencia, ll cantidad_en_dif,
	ll p
) {
	ll lado1 = mulmod(powmod(p, ultima_potencia, MOD), cantidad_en_dif, MOD);
	ll lado2 = 0;
	for (; it != end_it; it++) {
		ll potencia = it->first;
		ll cantidad = it->second;
		lado2 += mulmod(powmod(p, potencia, MOD), cantidad, MOD);
		lado2 %= MOD;
	}
	ll diferencia = lado1 - lado2;
	if (diferencia < 0) {
		diferencia += MOD;
	}
	return diferencia;
}

void solve() {
	ll n, p;
	cin >> n >> p;

	map<ll, ll> potencias;
	ll cantidad_total = 0;
	forn (i) {
		ll num;
		cin >> num;
		potencias[num]++;
		cantidad_total++;
	}

	if (p == 1) {
		cout << cantidad_total % 2 << endl;
		return;
	}


	// Como guardo la diferencia entre haber puesto la potencia
	// k y la k - 1? La diferencia absoluta puede ser muy grande.
	// Imaginemos que la potencia k es 10^6, y la potencia k - 1 es 1.
	// No podemos representar la diferencia en cantidad de p^1, porque entonces
	// tendríamos que guardar el número p^(10^6 - 1) como diferencia, obviamente
	// imposible. Tenemos que encontrar otra representación.
	// Podríamos guardar las potencias que hay en cada lado, pero después cómo
	// sé cuánto tengo que agregar para que la diferencia sea 0?
	// Guardar el módulo de la diferencia hace que no sepamos si llegar a cero diferencia
	// significa que ya no queda diferencia o si todavía queda diferencia que
	// no vemos porque le hicimos módulo. Supongo que se podría arreglar sabiendo
	// cuántas veces hicimos módulo, pero p^(10^6 - 1) es un número muuuuuy grande,
	// o sea que esa cuenta podría irse muy al carajo, además de que no sé cómo hacerla.

	// Si necesito más que 10^6 de la próxima potencia menor para llenar la diferencia, ya sé
	// que no voy a poder. Por lo tanto puedo poner todas las potencias restantes del otro lado.
	// Cómo sé si necesito más que 10^6 de la próxima potencia? Tendría que encontrar
	// el mínimo i tal que p^i > 10^6. Entonces divido todo lo que puedo a n por p hasta que
	// llegue a 0. Si llega a 0, quiere decir que en total lo dividí por algo que era más
	// grande que n. Hay que tomar en cuenta el caso especial p = 1, pero en ese caso
	// la mínima diferencia va a ser n % 2.
	// Teniendo este i, yo sé que si una diferencia está en potencia r y la próxima potencia es
	// r - j con j >= i, necesitaría un m >= n para que m*p^(r-j) = p^r.
	// Como ya hay una diferencia, quiere decir que ya usé por lo menos un número de los n,
	// y por lo tanto no tengo m potencias r - j, y por lo tanto no lo puedo hacer.
	// Entonces:
	// - Guardo la diferencia en términos de la última potencia que agregué.
	// - Si la diferencia entre la última potencia y la actual es mayor o igual a i,
	//   pongo todo en la otra bolsa, termino.
	// - Si la diferencia es menor a i, tengo que guardar la diferencia en términos de la
	//   última potencia a la que llegué. Pero esto no puede volverse muy grande al final?
	//   Ponele que tenemos una diferencia de 10^6 * p^5. Pero acá está el truco: Cómo llegamos
	//   a tener 10^6 cosas? Si entre potencias tenemos una diferencia de n, sabemos que
	//   tenemos que rellenar con todo lo que nos queda. Por lo tanto solo podemos ir sumando
	//   de a cosas menores que n en la variable de cantidad de elementos que nos
	//   faltan para rellenar la diferencia. Y entonces es fácil saber cuándo nos pasamos
	//   de n en esa variable, y si nos pasamos de n en esa variable tenemos que rellenar con
	//   todo lo que nos queda y listo. Por lo tanto esa variable siempre va a ser menor a 10^6,
	//   o sea, algo manejable por un ll tranquilamente.

	// Calculamos la mínima potencia de p que llega a n.
	ll n_dividido = n;
	ll potencia_para_n = 0;
	while (n_dividido > 0) {
		n_dividido /= p;
		potencia_para_n++;
	}

	// Reeeesumiendo:
	// - Dos variables:
	ll ultima_potencia = 0;
	ll cantidad_en_dif = 0;
	// - Si la diferencia entre la última potencia y la actual es mayor o igual a
	//   i, pongo todo lo que me queda en la otra bolsa para después calcular la diferencia
	//   total.
	// - Si la diferencia j es menor a i, ultima_potencia = nueva_potencia, y la
	//   nueva cantidad_en_dif = cantidad_en_dif * p^j - potencias[nueva_potencia].
	//   Si cantidad_en_dif > n, meto todo lo que me queda en la otra bolsa, devuelvo.
	//   Sino, sigo con la próxima potencia.
	auto it = potencias.rbegin();
	ll diferencia = -1;
	for (; it != potencias.rend(); it++) {
		ll potencia = it->first;
		ll cantidad = it->second;
		ll dif_de_potencias = ultima_potencia - potencia;

		if (cantidad_en_dif == 0) {
			cantidad_en_dif = cantidad % 2;
		} else if (dif_de_potencias >= potencia_para_n) {
			diferencia = llenar_diferencia_desde(potencias.rend(), it, ultima_potencia, cantidad_en_dif, p);
			break;
		} else {
			ll nueva_cantidad_en_dif = cantidad_en_dif * pow(p, dif_de_potencias) - cantidad;
			if (nueva_cantidad_en_dif > n) {
				diferencia = llenar_diferencia_desde(potencias.rend(), it, ultima_potencia, cantidad_en_dif, p);
				break;
			}
			cantidad_en_dif = nueva_cantidad_en_dif;

			if (cantidad_en_dif < 0) {
				cantidad_en_dif = cantidad_en_dif % 2;
				cantidad_en_dif = abs(cantidad_en_dif);
			}
		}
		ultima_potencia = potencia;
	}

	if (diferencia == -1) {
		// La diferencia es p^ultima_potencia * cantidad_en_dif
		diferencia = mulmod(powmod(p, ultima_potencia, MOD), cantidad_en_dif, MOD);
	}

	cout << diferencia << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

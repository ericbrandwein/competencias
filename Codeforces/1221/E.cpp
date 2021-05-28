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
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define PI 3.14159265358979323
#define sen(ang) sin((ang)*PI/180)
//cout<<flush;

using namespace std;

int main() {
	IOS;


	ll q;
	cin >> q;
	fore (i, 0, q) {
		ll a, b;
		cin >> a >> b;

		string chars;
		cin >> chars;
		vec<ll> nums;
		ll actual = 0;
		fore (j, 0, chars.size()) {
			if (chars[j] == '.') {
				actual++;
			} else if (actual != 0) {
				nums.push_back(actual);
				actual = 0;
			}
		}
		if (actual != 0) {
			nums.push_back(actual);
		}


		bool termine = false;
		ll dobles = 0;
		ll pos_dobles = -1;
		ll entro = 0;
		fore (j, 0, nums.size()) {
			bool entra_b_no_a = nums[j] < a && nums[j] >= b;
			if (entra_b_no_a || 4 * b - 1 + a <= nums[j]) {
				termine = true;
				break;
			}
			if (2 * b <= nums[j]) {
				dobles++;
				pos_dobles = j;
			}
			if (nums[j] >= a) {
				entro++;
			}
		}
		if (termine || dobles > 1) {
			cout << "NO" << endl;
			continue;
		}

		ll opciones = 0;
		if (dobles == 1) {
			if (nums[pos_dobles] >= 2 * a) {
				// Ultimo caso: 2*a <= nums[j] < 4 * b - 1 + a,
				// y hay uno solo en el que entro dos veces.
				// a < 4 * b - 1 <= 4 * a - 5.
				// En cada uno de los otros entramos una vez cada uno
				// y no sobra lugar para ninguno más.

				// Este es el único en el que entro dos veces.
				// Si puedo decidir entre entrar una vez o dos o tres,
				// gané. Sino, sumo la cantidad correspondiente a entro.
				
				// Si dejar lugar para que entre yo hace que deje 2 * b,
				// tengo que no dejar lugar.
				
				// Puedo dejar 0, 1, o 2 lugares. En cada uno de estos
				// lugares tenemos que entrar los dos.

				// Me fijo si puedo no dejar lugar para ninguno de los dos.
				vec<bool> lugares(3, false);

				lugares[0] = b - 1 + a + b - 1 >= nums[pos_dobles];
				bool dejar_para_mi_deja_2b = a >= 2 * b;
				bool tengo_que_dejar_dos = nums[pos_dobles] - a - (b - 1) >= 2 * b;
				lugares[1] = !dejar_para_mi_deja_2b && !tengo_que_dejar_dos;
				lugares[2] = nums[pos_dobles] >= 3 * a;
				
				ll sumar = 0;
				fore (k, 0, 3) {
					if (lugares[k]) {
						opciones++;
						sumar = k;
					}
				}

				if (opciones == 0) {
					cout << "NO" << endl;
					continue;
				}
				entro += sumar;
			} else if (2 * b - 1 <= nums[pos_dobles] - a) {
				cout << "NO" << endl;
				continue;
			}
		}

		// Tengo las veces que entramos los dos.
		// Si es impar gané.
		// Sino perdí.
		if (opciones >= 2 || entro % 2 != 0) {
			cout << "YES" << endl;
		}  else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

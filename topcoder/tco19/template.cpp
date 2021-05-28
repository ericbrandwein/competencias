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

class  EllysIncrements {
public:

	vector<ll> primos;

	void sacar_primos() {
		vector<bool> criba(10000001, false);

		for (ll i = 2; i < 10000000; i++) {
			if (!criba[i]) {
				primos.push_back(i);
				for (ll j = i; j < criba.size(); j+=i) {
					criba[j] = true;
				}
			}
		}
	}

	int pasos(vector<int>& A, vector<ll>& diferencias, ll start_A, ll end_A, ll start_dif, ll end_dif) {
		if (start >= end) {
			return 0;
		}

		ll valor_actual = A[start];

		if (valor_actual == 0) {
			return pasos(A, diferencias, start + 1, end, start_dif + 1, end_dif);
		}
		if (A[end - 1] == 0) {
			return pasos(A, diferencias, start, end - 1, start_dif, end_dif - 1);
		}



		bool todos_mayores = true;
		for (ll i = start; i < end; i++) {
			ll pasos_actuales = min(A[i], A[start]);
			pasos()
		}

		for (ll i = start; i < end; i++) {
			ll pasos_actuales = min(A[i], A[start]);
			pasos()
		}
	}

	int getMin(vector <int> A) {

		vector<ll> prox_primos;
		vector<ll> diferencias;
		sacar_primos();
		for (ll i = 0; i < A.size(); i++) {
			auto it_mayor_o_igual = lower_bound(all(primos), A[i]);
			ll indice_primo = it_mayor_o_igual - primos.begin();
			prox_primos.push_back(indice_primo);
			diferencias.push_back(primos[indice_primo] - A[i]);
		}

		ll start = 0;
		ll end = A.size();

		for (ll i = start; i < end; i++) {

		}


		return A.size();
	}
};


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

const ld EPSILON = 1e-9;

struct Fraction {
	ll num, den;

	Fraction(ll num, ll den) : num{num}, den{den} {
		reduce();
	}

	bool operator==(const Fraction& other) const {
		return num == other.num && den == other.den;
	}
	bool operator<(const Fraction& other) const {
		return other.den * num < other.num * den;
	}

	Fraction inverse() const {
		return {den, num};
	}

    Fraction negated() const {
		return {-num, den};
	}

	Fraction operator+(const Fraction& other) const {
		Fraction res = {num*other.den + other.num*den, den*other.den};
		res.reduce();
		return res;
	}

	Fraction operator-(const Fraction& other) const {
		return *this + other.negated();
	}

	Fraction operator*(const Fraction& other) const {
		Fraction res = {num * other.num, den * other.den};
		res.reduce();
		return res;
	}

	Fraction operator/(const Fraction& other) const {
		return *this * other.inverse();
	}

	ld to_long_double() {
		return (ld)num/(ld)den;
	}

	void reduce() {
        ll g = __gcd(num, den);
        num /= g;
        den /= g;
		if (den < 0) {
			den *= -1;
			num *= -1;
		}
	}
};

struct Recta {
	ll a, b;

	Fraction interseccion(Recta& otra) {
		if (a == otra.a) {
			return Fraction(-1, 1);
		}
		return Fraction{otra.b - b, a - otra.a};
	}
};

bool close(ld first, ld second) {
	return abs(first - second) <= EPSILON;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	ll arriba = 0;
	ll iguales = 0;
	vec<Recta> rectas(n);
	forn (i) {
		ll x1, x2;
		cin >> x1 >> x2;
		rectas[i].a = x2 - x1;
		rectas[i].b = x1;
		if (x1 > rectas[0].b) {
			arriba++;
		}
		if (x1 == rectas[0].b && i != 0) {
			iguales++;
		}
	}
	ll best_pos = arriba + 1;
	ll worst_pos = arriba + iguales + 1;


	set<pair<Fraction, ll>> intersecciones;
	for (ll i = 1; i < n;i++) {
		Fraction interseccion = rectas[i].interseccion(rectas[0]);
		if (interseccion.num >= 0 && interseccion.num <= interseccion.den) {
			intersecciones.insert({interseccion, i});
		}
	}

	auto it = intersecciones.begin();
	while (it != intersecciones.end()) {
		vec<ll> curr;
		Fraction interseccion{-1, 1};
		while (it != intersecciones.end() &&
			(interseccion.num == -1 || interseccion == it->first)
		) {
			interseccion = it->first;
			curr.push_back(it->second);
			it++;
		}
		if (interseccion.num > 0) {
			for (ll i : curr) {
				if (rectas[0].a > rectas[i].a) {
					// la pasamos para arriba
					arriba--;
				}
			}
			iguales += curr.size();
		}

		best_pos = min(best_pos, arriba + 1);
		worst_pos = max(worst_pos, arriba + iguales + 1);

		iguales -= curr.size();
		for (ll i : curr) {
			if (rectas[0].a < rectas[i].a) {
				// la pasamos para abajo
				arriba++;
			}
		}
	}

	cout << best_pos << " " << worst_pos << endl;

}

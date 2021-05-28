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

struct Intervalo {
	ll start, end;
	ll height;
	ll added_left = 0, added_right = 0;

	const bool operator<(const Intervalo& other) const {
		return start < other.start;
	}

	ll width() {
		return end - start;
	}

	bool intersects(const Intervalo& other) const {
		return start <= other.end && end >= other.start;
	}

	void join(const Intervalo& other) {
		start = min(start, other.start);
		end = max(end, other.end);
	}

	ll intersection_width(const Intervalo& other) const {
		return max(0ll, min(end, other.end) - max(start, other.start));
	}
};

ll agregar_casa(set<Intervalo>& intervalos, Intervalo& casa, ll perimeter) {
	// cada intervalo toca con el siguiente
	Intervalo actual = casa;
	actual.added_left = casa.height;
	actual.added_right = casa.height;
	vec<Intervalo> erased;
	vec<Intervalo> added;
	// lower_bound: el primero que empiece después o al mismo tiempo que la casa
	auto it = intervalos.lower_bound(casa);
	if (it != intervalos.begin()) {
		it--;
		// Ahora it es el primero cuyo end toca con la casa
		Intervalo nuevo = *it;
		nuevo.end = casa.start;
		nuevo.added_right = 0;
		added.push_back(nuevo);
		actual.added_left -= nuevo.height;
	}
	// Ahora it es el primero que empieza después o al mismo tiempo que la casa.

	while (it != intervalos.end() && it->end <= actual.end) {
		erased.push_back(*it);
		it++;
	}

	if (it != intervalos.end()) {
		// it empieza tocando con la casa pero termina después.
		erased.push_back(*it);
		Intervalo nuevo = *it;
		nuevo.start = actual.end;
		nuevo.added_left = 0;
		added.push_back(nuevo);
		actual.added_right -= nuevo.height;
	}

	added.push_back(actual);

	for (Intervalo& intervalo : erased) {
		if (intervalos.erase(intervalo)) {
			perimeter -= intervalo.added_left;
			perimeter -= intervalo.added_right;
			if (intervalo.height != 0) {
				perimeter -= 2*intervalo.width();
			}
			perimeter %= MOD;
		}
	}
	for (Intervalo& intervalo : added) {
		perimeter += intervalo.added_left;
		perimeter += intervalo.added_right;
		if (intervalo.height != 0) {
			perimeter += 2*intervalo.width();
		}
		perimeter %= MOD;
		intervalos.insert(intervalo);
	}

	if (perimeter < 0) perimeter += MOD;
	return perimeter;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> starts(n);
	fore (i, 0, k) cin >> starts[i];

	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	fore (i, k, n) {
		starts[i] = ((a*starts[i-2] + b*starts[i-1] + c) % d) + 1;
	}

	vector<ll> widths(n);
	fore (i, 0, k) cin >> widths[i];

	cin >> a >> b >> c >> d;
	fore (i, k, n) {
		widths[i] = ((a*widths[i-2] + b*widths[i-1] + c) % d) + 1;
	}

	vector<ll> heights(n);
	fore (i, 0, k) cin >> heights[i];

	cin >> a >> b >> c >> d;
	fore (i, k, n) {
		heights[i] = ((a*heights[i-2] + b*heights[i-1] + c) % d) + 1;
	}

	vector<Intervalo> casas(n);
	ll max_end = 0;
	forn (i) {
		casas[i].start = starts[i];
		casas[i].end = starts[i] + widths[i];
		max_end = max(max_end, casas[i].end);
		casas[i].height = heights[i];
	}

	set<Intervalo> intervalos;
	intervalos.insert({1, max_end, 0});

	ll perimeter = 0;
	ll total = 1;
	for (ll i = 0; i < n; i++) {
		Intervalo& casa = casas[i];
		perimeter = agregar_casa(intervalos, casa, perimeter);
		total *= perimeter;
		total %= MOD;
	}
	cout << total << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}

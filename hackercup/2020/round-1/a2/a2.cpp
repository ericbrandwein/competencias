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
	Intervalo actual = casa;
	ll ancho_sumado = actual.width();
	vec<Intervalo> erased;
	// upper_bound: el primero que empiece después que la casa
	auto it = intervalos.upper_bound(casa);
	if (it != intervalos.begin()) {
		it--;
		if (it->intersects(casa)) {
			ancho_sumado -= it->intersection_width(casa);
			actual.join(*it);
			erased.push_back(*it);
			perimeter -= casa.height;
			perimeter %= MOD;
		} else {
			perimeter += casa.height;
			perimeter %= MOD;
		}
		it++;
	} else {
		// no hay ninguno antes
		perimeter += casa.height;
		perimeter %= MOD;
	}

	// it empieza después de la casa
	while (it != intervalos.end() && it->end <= actual.end) {
		ancho_sumado -= it->intersection_width(actual);
		perimeter -= casa.height * 2;
		perimeter %= MOD;
		actual.join(*it);
		erased.push_back(*it);
		it++;
	}

	if (it == intervalos.end() || it->start > actual.end) {
		perimeter += casa.height;
		perimeter %= MOD;
	} else {
		ancho_sumado -= it->intersection_width(actual);
		perimeter -= casa.height;
		perimeter %= MOD;
		actual.join(*it);
		erased.push_back(*it);
	}

	if (ancho_sumado > 0) {
		perimeter += ancho_sumado * 2;
		for (ll i = 0; i < erased.size(); i++) {
			intervalos.erase(erased[i]);
		}
		intervalos.insert(actual);
	}
	perimeter %= MOD;
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
	forn (i) {
		casas[i].start = starts[i];
		casas[i].end = starts[i] + widths[i];
		casas[i].height = heights[i];
	}

	set<Intervalo> intervalos;
	intervalos.insert(casas[0]);
	ll perimeter = 2*widths[0] + 2*heights[0];
	perimeter %= MOD;
	ll total = perimeter;
	for (ll i = 1; i < n; i++) {
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

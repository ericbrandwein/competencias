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


struct Trolley {
	ll time, velocity, index;

	bool operator<(const Trolley& other) const {
		return time < other.time;
	}
};

ld tiempo_de_llegar(Trolley& trolley, ld distance, ld acc) {
	ld tiempo = sqrt(2*distance / acc);
	if (tiempo * acc <= trolley.velocity) {
		return tiempo;
	} else {
		return (ld)trolley.velocity / acc +
			(ld)distance/(ld)trolley.velocity -
			(ld)trolley.velocity/(2*acc);
	}
}

int main() {
	IOS;

	ll n;
	cin >> n;
	ll a, d;
	cin >> a >> d;

	vector<Trolley> trolleys(n);
	forn (i) {
		cin >> trolleys[i].time >> trolleys[i].velocity;
		trolleys[i].index = i;
	}

	sort(all(trolleys));

	vector<ld> tiempos(n);
	ld tiempo_anterior = 0;
	for (ll i = 0; i < trolleys.size(); i++) {
		ld tiempo = tiempo_de_llegar(trolleys[i], d, a);
		tiempo += trolleys[i].time;
		tiempo = max(tiempo, tiempo_anterior);
		tiempos[trolleys[i].index] = tiempo;
		tiempo_anterior = tiempo;
	}

	for (ll i = 0; i < tiempos.size(); i++) {
		presicion(6);
		cout << tiempos[i] << endl;
	}







	return 0;
}

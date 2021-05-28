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

// -1 si hay poco, 0 si es correcto, 1 si hay mucho
ll ask(ll n, ll num, vec<ll>& combis, vec<ll>& droppers) {

	ll index = num;
	vec<ll> used(n, 0);
	while (index > 0) {
		ll dropper = combis[index];
		used[dropper]++;
		ll restado = droppers[dropper];
		index -= restado;
	}


	cout << 1 << endl;
	for (ll cant : used) {
		cout << cant << " ";
	}
	cout << endl << flush;
	string res;
	cin >> res;
	if (res == "green") return -1;
	else if (res == "yellow") return 0;
	else return 1;
}

ll answer(ll num) {
	cout << 2 << endl << num << endl;
	exit(0);
}

const ll MAX_N = 1'000'000;

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> droppers(n);
	forn (i) cin >> droppers[i];

	set<ll> disponibles;
	vec<ll> combis(MAX_N+1, -1); // dropper usado, -1 si no se usó.
	combis[0] = n;
	disponibles.insert(0);
	for (ll i = 1; i <= MAX_N; i++) {
		for (ll j = 0; j < droppers.size(); j++) {
			ll dropper = droppers[j];
			ll anterior = i - dropper;
			if (anterior >= 0 && combis[anterior] != -1) {
				combis[i] = j;
				disponibles.insert(i);
				break;
			}
		}
	}

	ll from = 1;
	ll to = MAX_N;
	ll asked = 0;
	while (from < to && asked < 30) {
		ll mid = (from + to) / 2;
		auto closest = disponibles.lower_bound(mid); // primero mayor o igual

		ll res = ask(n, *closest, combis, droppers);
		if (res == 0) {
			answer(*closest);
		} else if (res == -1) {
			// hay que subir
			from = *closest + 1;
		} else {
			to = *closest - 1;
		}

		asked++;
	}

	if (from >= to) {
		answer(from);
	} else {
		answer(-1);
	}






	return 0;
}

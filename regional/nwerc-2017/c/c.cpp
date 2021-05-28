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


pair<ll,ll> get_direction(pair<ll,ll>& from, pair<ll,ll>& to) {
	ll x = to.first - from.first;
	ll y = to.second - from.second;
	if (x == 0) {
		return {x, y/abs(y)};
	} else if (y == 0) {
		return {x/abs(x), y};
	} else {
		ll g= abs(__gcd(x, y));
		return {x / g, y/g};
	}
}

bool is_left(const pair<ll,ll>& from, const pair<ll,ll>& to, const pair<ll,ll>& other){
     return (
		(to.first - from.first)*(other.second - from.second) -
		(to.second - from.second)*(other.first - from.first)
	) > 0;
}

bool paralelos(const pair<ll,ll>& first, const pair<ll,ll>& second) {
	return first == second || first == pair<ll,ll>{-second.first, -second.second};
}

ll movimientos_de(
	pair<ll,ll>& direction,
	const pair<ll,ll>& dir_from, const pair<ll,ll>& dir_to
) {
	ll moves;
	if (direction == dir_from && direction == dir_to) {
		moves = 0;
	} else if (direction == dir_from || direction == dir_to) {
		moves = 1;
	} else if (
		paralelos(dir_from, direction) ||
		paralelos(dir_to, direction) ||
		paralelos(dir_from, dir_to) ||
		(is_left({0,0}, dir_from, direction) != is_left({0,0}, dir_from, dir_to)) ||
		(is_left({0,0}, direction, dir_from) == is_left({0,0}, direction, dir_to))
	) {
		// son paralelas, o cambian de lado
		moves = 2;
	} else {
		moves = 1;
	}

	return moves;
}

void llenar_movimientos(
	vec<map<pair<ll,ll>, ll>>& movimientos, ll num, vec<pair<ll,ll>>& positions,
	set<pair<ll,ll>>& dirs
) {
	pair<ll,ll> curr_pos = positions[num];
	pair<ll,ll> prev_pos = positions[num-1];
	for (const pair<ll,ll>& dir_to : dirs) {
		movimientos[num][dir_to] = 10000;
		for (const pair<ll,ll>& dir_from : dirs) {
			pair<ll,ll> direction = get_direction(prev_pos, curr_pos);
			ll nuevos = movimientos[num-1][dir_from] +
					movimientos_de(direction, dir_from, dir_to);
			movimientos[num][dir_to] = min(movimientos[num][dir_to], nuevos);
		}
	}
}

int main() {
	IOS;

	const ll posiciones = 16;
	vec<pair<ll,ll>> positions(posiciones);
	for (ll row = 0; row < 4; row++) {
		for (ll col = 0;col < 4; col++) {
			ll num;
			cin >> num;
			num--;
			positions[num] = {col, row};
		}
	}

	set<pair<ll,ll>> dirs;
	for (ll x = -4; x <= 4; x++) {
		for (ll y = -4; y <= 4; y++) {
			if (x == 0 && y == 0) continue;
			if (x == 0) {
				dirs.insert({x, y/abs(y)});
			} else if (y == 0) {
				dirs.insert({x/abs(x), y});
			} else {
				ll g = abs(__gcd(x, y));
				dirs.insert({x/g, y/g});
			}
		}
	}


	vec<map<pair<ll,ll>, ll>> movimientos(posiciones); // costo de salir con una direccion para cada num
	for (pair<ll,ll> dir : dirs) {
		movimientos[0][dir] = 1;
	}

	for (ll i = 1; i < posiciones; i++) {
		llenar_movimientos(movimientos, i, positions, dirs);
	}

	ll min_mov = 10000;
	for (pair<ll,ll> dir : dirs) {
		min_mov = min(min_mov, movimientos[posiciones-1][dir]);
	}

	cout << min_mov << endl;


}

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


ll dist_between(ll x_from, ll y_from, ll x_to, ll y_to) {
	ll dist_y = abs(y_from - y_to);
	ll dist_x = abs(x_from - x_to);
	return dist_x*dist_x + dist_y*dist_y;

}

struct Sensor{
	ll x, y, dist;

	bool touches(Sensor& other) {
		ll dist_sum = dist + other.dist;
		return dist_sum*dist_sum >= dist_between(x, y, other.x, other.y);
	}
};


vec<bool> adyacentes(vec<vec<ll>>& graph, ll from) {
	ll n = graph.size();
	stack<ll> next;
	next.push(from);
	vec<bool> ady(n, false);
	ady[from] = true;
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();
		for (ll child : graph[curr]) {
			if (!ady[child]) {
				ady[child] = true;
				next.push(child);
			}
		}
	}
	return ady;
}


int main() {
	IOS;

	ll m, n, sensors_q;
	cin >> m >> n >> sensors_q;
	vec<Sensor> sensors(sensors_q);
	fore (i, 0, sensors_q) {
		cin >> sensors[i].x >> sensors[i].y >> sensors[i].dist;
	}

	vec<vec<ll>> graph(sensors_q + 4);
	fore (from, 0, sensors_q) {
		fore (to, from + 1, sensors_q) {
			if (sensors[from].touches(sensors[to])) {
				graph[from].push_back(to);
				graph[to].push_back(from);
			}
		}

		// izq, der, arriba, abajo
		Sensor& sensor = sensors[from];
		if (sensor.x - sensor.dist <= 0) {
			graph[sensors_q].push_back(from);
			graph[from].push_back(sensors_q);
		}
		if (sensor.x + sensor.dist >= m) {
			graph[sensors_q+1].push_back(from);
			graph[from].push_back(sensors_q+1);
		}
		if (sensor.y - sensor.dist <= 0) {
			graph[sensors_q+2].push_back(from);
			graph[from].push_back(sensors_q+2);
		}
		if (sensor.y + sensor.dist >= n) {
			graph[sensors_q+3].push_back(from);
			graph[from].push_back(sensors_q+3);
		}
	}

	vec<bool> ady_arriba = adyacentes(graph, sensors_q + 2);
	vec<bool> ady_derecha = adyacentes(graph, sensors_q + 1);
	if (ady_arriba[sensors_q] || ady_arriba[sensors_q+3] || ady_derecha[sensors_q+3] ||
		ady_derecha[sensors_q]) {
			cout << "N" << endl;
		} else {
			cout << "S" << endl;
		}



	return 0;
}

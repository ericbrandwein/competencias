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

struct Event {
	ll edge;
	ll weight;

	bool operator<(const Event& other) const {
		return edge < other.edge;
	}
};

struct order_weight {
	bool operator()(const Event& first, const Event& second) const {
		return first.weight < second.weight || first.weight == second.weight && first.edge < second.edge;
	}
};


ll calculate_benefit(
	set<Event, order_weight>& edges_inside, set<Event, order_weight>& edges_outside,
	ll edges_inside_amount, ll nodes_per_circle
) {
	ll biggest_inside = 1;
	if (!edges_inside.empty()) {
		biggest_inside = (--edges_inside.end())->weight;
		if (biggest_inside == 0 && edges_inside_amount > edges_inside.size()) {
			biggest_inside = 1;
		}
	}

	ll biggest_outside = 1;
	ll edges_outside_amount = nodes_per_circle - edges_inside_amount;
	if (!edges_outside.empty()) {
		biggest_outside = (--edges_outside.end())->weight;
		if (biggest_outside == 0 && edges_outside_amount > edges_outside.size()) {
			biggest_outside = 1;
		}
	}

	return min(biggest_inside, biggest_outside);
}

const ll MOD = 1e9 + 7;

void solve() {
	ll circles_q, nodes_per_circle, events_q, k;
	cin >> circles_q>> nodes_per_circle>> events_q>> k;
	ll nodes = circles_q * nodes_per_circle;
	vec<ll> from(circles_q);
	fore (i, 0, k) cin >> from[i];
	ll a, b, c;
	cin >> a >> b >> c;
	fore (i, k, circles_q) {
		from[i] = (a*from[i-2] +b*from[i-1] + c) % nodes_per_circle;
	}

	vec<ll> to(circles_q);
	fore (i, 0, k) cin >> to[i];
	cin >> a >> b >> c;
	fore (i, k, circles_q) {
		to[i] = (a*to[i-2] +b*to[i-1] + c) % nodes_per_circle;
	}

	for (ll i = 0; i < circles_q; i++) {
		if (from[i] > to[i]) {
			swap(from[i], to[i]);
		}
		from[i] += i*nodes_per_circle;
		to[i] += i*nodes_per_circle;
	}

	vec<Event> events(events_q);
	fore (i, 0, k) {
		cin >> events[i].edge;
	}

	cin >> a >> b >> c;

	fore (i, k, events_q) {
		events[i].edge = (a*events[i-2].edge +b*events[i-1].edge + c) % (nodes + circles_q);
	}
	fore (i, 0, k) {
		cin >> events[i].weight;
	}
	cin >> a >> b >> c;

	fore (i, k, events_q) {
		events[i].weight = (a*events[i-2].weight +b*events[i-1].weight + c) % 1'000'000'000;
	}

	// vec<ll> sums(circles_q, nodes_per_circle);
	// ll sum_big_circle = circles_q;
	vec<set<Event>> circles_edges(circles_q);
	vec<set<Event, order_weight>> edges_inside(circles_q);
	vec<set<Event, order_weight>> edges_outside(circles_q);
	set<Event> big_circle_edges;
	vec<set<Event, order_weight>> biggest_edges(circles_q);
	set<Event, order_weight> big_circle_biggest_edges;
	set<ll> benefits;
	for (ll i = 0; i < circles_q;i++) {
		if (to[i] - from[i] > 0) {
			benefits.insert(1);
		}
	}
	// for (ll i = 0; i < circles_q; i++) {
	// 	biggest_edges[i].edge = i * circles_q;
	// 	biggest_edges[i].weight = 1;
	// }

	ll total = 1;
	ll sum = (circles_q * (nodes_per_circle - 1) + circles_q - 1) % MOD;
	for (Event& event : events) {
		ll circle = event.edge / nodes_per_circle;
		ll prev_weight = 1;
		if (circle >= circles_q) {
			// es el grande
			// Agregamos el más grande al arbol
			if (!big_circle_biggest_edges.empty()) {
				auto biggest = --big_circle_biggest_edges.end();
				if (biggest->weight == 0 && big_circle_biggest_edges.size() < circles_q) {
					sum += 1;
				} else {
					sum += biggest->weight;
				}
			} else {
				sum += 1;
			}
			sum %= MOD;

			auto it = big_circle_edges.find(event);
			if (it != big_circle_edges.end()) {
				prev_weight = it->weight;
				big_circle_biggest_edges.erase(*it);
				big_circle_edges.erase(it);
			}
			big_circle_biggest_edges.insert(event);
			big_circle_edges.insert(event);

			sum -= prev_weight;
			sum += event.weight;
			sum %= MOD;

			// Sacamos el nuevo más grande
			auto biggest = --big_circle_biggest_edges.end();
			if (biggest->weight == 0 && big_circle_biggest_edges.size() < circles_q) {
				sum -= 1;
			} else {
				sum -= biggest->weight;
			}
		} else {
			// es uno chiquito
			// Agregamos el más grande al arbol
			ll edges_inside_amount = to[circle] - from[circle];
			if (edges_inside_amount > 0) {
				ll prev_benefit = calculate_benefit(
					edges_inside[circle], edges_outside[circle], edges_inside_amount,
					nodes_per_circle
				);
				benefits.erase(prev_benefit);
			}

			if (!biggest_edges[circle].empty()) {
				auto biggest = --biggest_edges[circle].end();
				if (biggest->weight == 0 && biggest_edges[circle].size() < nodes_per_circle) {
					sum += 1;
				} else {
					sum += biggest->weight;
				}
			} else {
				sum += 1;
			}
			sum %= MOD;

			bool inside = event.edge < to[circle] && event.edge >= from[circle];
			auto it = circles_edges[circle].find(event);
			if (it != circles_edges[circle].end()) {
				prev_weight = it->weight;
				biggest_edges[circle].erase(*it);
				if (inside) {
					edges_inside[circle].erase(*it);
				} else {
					edges_outside[circle].erase(*it);
				}
				circles_edges[circle].erase(it);
			}
			biggest_edges[circle].insert(event);
			circles_edges[circle].insert(event);
			if (inside) {
				edges_inside[circle].insert(event);
			} else {
				edges_outside[circle].insert(event);
			}

			sum -= prev_weight;
			sum += event.weight;
			sum %= MOD;

			// Sacamos el nuevo más grande
			auto biggest = --biggest_edges[circle].end();
			if (biggest->weight == 0 && biggest_edges[circle].size() < nodes_per_circle) {
				sum -= 1;
			} else {
				sum -= biggest->weight;
			}

			if (edges_inside_amount > 0) {
				ll curr_benefit = calculate_benefit(
					edges_inside[circle], edges_outside[circle], edges_inside_amount,
					nodes_per_circle
				);
				benefits.insert(curr_benefit);
			}
		}
		sum %= MOD;
		sum += MOD;
		sum %= MOD;

		ll true_sum = sum;
		if (!benefits.empty()) {
			ll biggest_weight_big = 1;
			if (!big_circle_biggest_edges.empty()) {
				biggest_weight_big = (--big_circle_biggest_edges.end())->weight;
			}

			ll biggest_benefit = *(--benefits.end());
			if (biggest_benefit > biggest_weight_big) {
				true_sum += biggest_weight_big;
				true_sum -= biggest_benefit;
			}
		}
		true_sum %= MOD;
		if (true_sum < 0) true_sum += MOD;

		total *= true_sum;
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

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

namespace milanesasChiquititas {

using TYPE = ll;
#define OP(a,b) max(a, b)
const TYPE NEUT = -1'000'000;
#define LAZY_OP(a,b) (a + b)
const TYPE NEUT_LAZY = 0;


/**
 * Un Segment Tree al que se le pueden hacer operaciones en rango.
 * No las aplica inmediatamente, sino que guarda en los nodos padres de los segmentos
 * la operación, y cuando querés consultar algo de ese segmento recién la aplica.
 *
 * Uso y Complejidad:
 *   LazyST st;
 *   st.init(vector); | O(n)
 *   st.upd_lazy(from, to, value_to_add); | O(log(n))
 *   st.query(q_left, q_right); // [q_left, q_right] | O(log(n))
 */
struct LazyST {
	vec<TYPE> elems;
	vec<TYPE> lazy;
	void init(vec<TYPE> &a){
		int size = 1;
		while(size<a.size()) size*=2;
		elems.assign(size*2,NEUT);
		lazy.assign(size*2,NEUT_LAZY);
		_init(0,0,size-1,a);
	}
	void _init(int node, int i_from, int i_to, vec<TYPE>& a){
		if(i_from>=a.size())return;
		if(i_from==i_to) {elems[node]=a[i_from]; return;}
		int mid = (i_from+i_to)/2;
		_init(node*2+1,i_from,mid,a);
		_init(node*2+2,mid+1,i_to,a);
		elems[node] = OP(elems[node*2+1], elems[node*2+2]);
	}
	void upd_lazy(int q_left, int q_right, TYPE value) {
		_upd_lazy(0, 0, elems.size()/2 - 1, q_left, q_right, value);
	}
	// Probablemente vas a tener que cambiar esta función
	// dependiendo de las operaciones que hayas elegido.
	void _upd_lazy(int node, int i_from, int i_to, int q_left, int q_right, TYPE value) {
		if(q_left>i_to || q_right<i_from) return;
		if(q_left<=i_from && i_to<=q_right) {
			lazy[node] = LAZY_OP(lazy[node], value);
			elems[node] = LAZY_OP(elems[node], value);
		} else {
			int mid = (i_from+i_to)/2;
			_upd_lazy(node*2+1,i_from,mid,q_left,q_right, value);
			_upd_lazy(node*2+2,mid+1,i_to,q_left,q_right, value);
			elems[node] = OP(elems[node*2+1], elems[node*2+2]);
			elems[node] = LAZY_OP(elems[node], lazy[node]);
		}
	}
	void _move_lazy_down(int node) {
		_upd_lazy(node*2+1,0,0,0,0,lazy[node]);
		_upd_lazy(node*2+2,0,0,0,0,lazy[node]);
		lazy[node] = NEUT_LAZY;
	}

	TYPE query(int q_left, int q_right){
		return _query(0,0,elems.size()/2-1,q_left,q_right);
	}
	TYPE _query(int node, int from, int to, int q_left, int q_right){
		if(q_left<=from && to<=q_right) return elems[node];
		if(q_left>to || q_right<from) return NEUT;
		_move_lazy_down(node);
		int mid = (from+to)/2;
		return OP(_query(node*2+1,from,mid,q_left,q_right),
				_query(node*2+2,mid+1,to,q_left,q_right));
	}
};

};

pair<ll,ll> read_point() {
	ll y;
	cin >> y;
	string xs;
	cin >> xs;
	string new_x = "";
	for (char c : xs) {
		if (c != '.') new_x.push_back(c);
	}
	return {stoi(new_x), y};
}


struct Event {
	bool start; // o end
	pair<ll,ll> punto;
	const bool operator<(const Event& other) const {
		return punto.first < other.punto.first || (
			other.punto.first == punto.first && !start && other.start
		);
	}
};

int main() {
	IOS;

	ll n;
	cin >> n;
	ll ancho, altura;
	tie(ancho, altura) = read_point();
	vec<pair<ll,ll>> puntos(n);
	forn (i) {
		puntos[i] = read_point();
	}
	vec<Event> eventos;
	for (const auto punto : puntos) {
		pair<ll,ll> punto_start = punto;
		pair<ll,ll> punto_end = punto;
		punto_start.first -= ancho;
		punto_end.first++;
		eventos.push_back({true, punto_start});
		eventos.push_back({false, punto_end});
		pair<ll,ll> punto_start_repe = punto_start;
		pair<ll,ll> punto_end_repe = punto_end;
		punto_start_repe.first += 36'000;
		punto_end_repe.first += 36'000;
		eventos.push_back({true, punto_start_repe});
		eventos.push_back({false, punto_end_repe});
	}

	sort(all(eventos));

	milanesasChiquititas::LazyST st;
	ll total = 100'010 + altura;
	vec<ll> a(total, 0);
	st.init(a);
	ll res = 0;
	for (Event event : eventos) {
		ll comienzo = event.punto.second;
		ll fin = event.punto.second + altura;
		st.upd_lazy(comienzo, fin, event.start ? 1 : -1);
		res = max(res, st.query(0, total-1));
	}

	cout << res << endl;





	return 0;
}

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


// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B

//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/STACK: 20000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector
#define all(x) x.begin(), x.end()
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


struct ST_Nodo{
	ll altura, indice;
};

ST_Nodo min_nodo(ST_Nodo first, ST_Nodo second) {
	if (first.altura > second.altura) {
		return first;
	} else {
		return second;
	}
}

#define OP(a,b) min_nodo(a, b)
using TYPE = ST_Nodo;
const TYPE NEUT = ST_Nodo{-1, -1};
const ll MAX_RANGO = 100000;

struct ST {
	vec<TYPE> elems;
	void init(vec<TYPE> &a){ // O(n)
		int size = 1;
		while(size<a.size()) size*=2;
		elems.assign(size*2,NEUT);
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
	void set(int i, TYPE value){ // O(log n)
		_set(0,0,elems.size()/2-1,i,value);
	}
	void _set(int node, int i_from, int i_to, int i, TYPE value){
		if(i_from==i_to){ elems[node]=value; return; }
		int mid = (i_from+i_to)/2;
		if(i<=mid) _set(node*2+1,i_from,mid,i,value);
		else _set(node*2+2,mid+1,i_to,i,value);
		elems[node] = OP(elems[node*2+1], elems[node*2+2]);
	}
	TYPE query(int q_left, int q_right){ // O(log n)
		return _query(0,0,elems.size()/2-1,q_left,q_right);
	}
	TYPE _query(int node, int i_from, int i_to, int q_left, int q_right){
		if(q_left<=i_from && i_to<=q_right) return elems[node];
		if(q_left>i_to || q_right<i_from) return NEUT;
		int mid = (i_from+i_to)/2;
		return OP(_query(node*2+1,i_from,mid,q_left,q_right),
				_query(node*2+2,mid+1,i_to,q_left,q_right));
	}
};// usage: ST st(a); st.set(i,v); st.query(q_l,q_r); []

struct Nodo {
	ll padre, rango, costo, tiempo_total = 0, altura = 0, padre_mayor = -1;
	vec<ll> hijos;
};

void set_altura(vec<Nodo>& nodos, ll i) {
	if (nodos[i].padre != -1) {
		nodos[i].altura = nodos[nodos[i].padre].altura + 1;
	}
	for (ll child : nodos[i].hijos) {
		set_altura(nodos, child);
	}
}

void set_padre_mayor(vec<Nodo>& nodos, ll i, ST& st_padres) {
	ST_Nodo padre_mayor = st_padres.query(nodos[i].rango + 1, MAX_RANGO);
	nodos[i].padre_mayor = padre_mayor.indice;
	ST_Nodo ant = st_padres.elems[nodos[i].rango];
	st_padres.set(nodos[i].rango, {nodos[i].altura, i});
	for (ll child : nodos[i].hijos) {
		set_padre_mayor(nodos, child, st_padres);
	}
	st_padres.set(nodos[i].rango, ant);

	if (padre_mayor.indice >= 0) {
		nodos[padre_mayor.indice].tiempo_total += nodos[i].costo;
		nodos[padre_mayor.indice].tiempo_total += nodos[i].tiempo_total;
	}
}


int main() {
	IOS;

	ll n;
	cin >> n;

	vec<Nodo> nodos(n);
	ll raiz = -1;
	forn (i) {
		cin >> nodos[i].padre >> nodos[i].rango >> nodos[i].costo;
		if (nodos[i].padre == -1) {
			raiz = i;
		} else {
			nodos[i].padre--;
			nodos[nodos[i].padre].hijos.push_back(i);
		}
	}

	set_altura(nodos, raiz);
	ST st_padres;
	vec<ST_Nodo> a(MAX_RANGO + 1, NEUT);
	st_padres.init(a);
	set_padre_mayor(nodos, raiz, st_padres);

	for (Nodo& nodo : nodos) {
		cout << nodo.tiempo_total << endl;
	}
}

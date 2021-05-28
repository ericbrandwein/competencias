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


#define OP(a,b) (a + b)
using TYPE = ll;

struct ST {
	const TYPE NEUT = 0;
	vec<TYPE> elems;
	vec<bool> swapped;
	vec<ll> levels;
	void init(vec<ll> &a){ // O(n)
		int size = 1;
		ll height = 1;
		while(size<a.size()) {
			size*=2;
			height++;
		}
		elems.assign(size*2,NEUT);
		levels.assign(size*2, 0);
		init_levels();
		swapped.assign(height, false);
		_init(0,0,size-1,a);
	}

	void init_levels() {
		ll level = -1;
		ll mult = 1;
		for (ll i = 0; i < levels.size(); i++) {
			if (mult <= i + 1) {
				mult *= 2;
				level++;
			}
			levels[i] = level;
		}
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
		ll node_left = node*2 + 1;
		ll node_right = node*2 + 2;
		if (swapped[levels[node]]) {
			std::swap(node_left, node_right);
		}
		if(i<=mid) _set(node_left,i_from,mid,i,value);
		else _set(node_right,mid+1,i_to,i,value);
		elems[node] = OP(elems[node*2+1], elems[node*2+2]);
	}
	ll query(int q_left, int q_right){ // O(log n)
		return _query(0,0,elems.size()/2-1,q_left,q_right);
	}
	ll _query(int node, int from, int to, int q_left, int q_right){
		if(q_left<=from && to<=q_right) return elems[node];
		if(q_left>to || q_right<from) return NEUT;
		int mid = (from+to)/2;
		ll node_left = node*2 + 1;
		ll node_right = node* 2 + 2;
		if (swapped[levels[node]]) {
			std::swap(node_left, node_right);
		}
		return OP(_query(node_left,from,mid,q_left,q_right),
				_query(node_right,mid+1,to,q_left,q_right));
	}

	void swap(ll k) {
		ll height = swapped.size();
		ll level = height - k - 1;
		level--;
		if (level >= 0) {
			swapped[level] = !swapped[level];
		}
	}

	void reverse(ll k) {
		for (ll i = 0; i < k; i++) {
			swap(i);
		}
	}

};// usage: ST st(a); st.set(i,v); st.query(q_l,q_r); []


int main() {
	IOS;

	ll n, q;
	cin >> n >> q;
	ll cant = 1;
	for (ll i = 0; i < n; i++) {
		cant *= 2;
	}
	vec<ll> a(cant);
	for (ll i = 0; i < cant; i++) cin >> a[i];

	ST st;
	st.init(a);

	fore (i, 0, q) {
		ll type;
		cin >> type;
		if (type == 1) {
			ll x, k;
			cin >> x >> k;
			x--;
			st.set(x, k);
		} else if (type == 2) {
			ll k;
			cin >> k;
			st.reverse(k);
		} else if (type == 3) {
			ll k;
			cin >> k;
			st.swap(k);
		} else {
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << st.query(l, r) << endl;
		}
	}


	return 0;
}

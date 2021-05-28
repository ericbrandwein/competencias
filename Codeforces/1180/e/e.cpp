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

const ll MAX_N = 1e6 + 1;


using TYPE = ll;
#define OP(a,b) max(a, b)
const TYPE NEUT = -1'000'000;
#define LAZY_OP(a,b) (a + b)
const TYPE NEUT_LAZY = 0;

struct STLazy {
	vec<TYPE> elems;
	vec<TYPE> lazy;
	void init(vec<TYPE> &a){ // O(n)
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
	void upd_lazy(int q_left, int q_right, TYPE value) {
		_upd_lazy(0, 0, elems.size()/2 - 1, q_left, q_right, value);
	}
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

	TYPE query(int q_left, int q_right){ // O(log n)
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

	int most_right_positive() {
		return _most_right_positive(0);
	}
	int _most_right_positive(int node) {
		int res = -1;
		if (elems[node] > 0) {
			if (node >= elems.size()/2 - 1) {
				res = node - (elems.size()/2 - 1);
			} else {
				_move_lazy_down(node);
				res = _most_right_positive(node*2+2);
				if (res < 0) {
					res = _most_right_positive(node*2+1);
				}
			}
		}
		return res;
	}

};// usage: ST st(a); st.set(i,v); st.query(q_l,q_r); []


int main() {
	IOS;

	ll n, m;
	cin >> n >> m;

	vec<ll> acum(MAX_N, 0);
	vec<ll> dishes(n);
	forn (i) {
		cin >> dishes[i];
		acum[dishes[i]]++;
	}
	vec<ll> people(m);
	fore (i, 0, m) {
		cin >> people[i];
		acum[people[i]]--;
	}

	for (ll i = MAX_N - 2; i >= 0; i--) {
		acum[i] += acum[i+1];
	}

	ll q;
	cin >> q;
	STLazy st;
	st.init(acum);
	while (q--) {
		ll type;
		cin >> type;
		ll index, price;
		cin >> index >> price;
		index--;
		ll added = 1;
		ll prev = 0;
		if (type == 1) {
			prev = dishes[index];
			dishes[index] = price;
		} else {
			prev = people[index];
			people[index] = price;
			added = -1;
		}
		if (price < prev) {
			added *= -1;
			swap(price, prev);
		}
		st.upd_lazy(prev + 1, price, added);
		cout << st.most_right_positive() << endl;
	}


	return 0;
}

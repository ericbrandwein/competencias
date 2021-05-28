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


struct Solution {
	ll suma_suma, resta_suma, suma_resta, resta_resta;
};

Solution join(const Solution& first, const Solution& second) {
	Solution joined;
	joined.suma_suma = max(
		first.suma_suma + second.resta_suma,
		first.suma_resta + second.suma_suma
	);

	joined.suma_resta = max(
		first.suma_suma + second.resta_resta,
		first.suma_resta + second.suma_resta
	);
	joined.resta_suma = max(
		first.resta_suma + second.resta_suma,
		first.resta_resta + second.suma_suma
	);
	joined.resta_resta = max(
		first.resta_suma + second.resta_resta,
		first.resta_resta + second.suma_resta
	);
	return joined;
}


const ll INF = 1'000'000'000;

#define OP(a,b) join(a, b)
using TYPE = Solution;
const TYPE NEUT = {-INF,0,0,-INF};

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




void solve() {
	ll n, q;
	cin >> n >> q;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<ll> best_sumando(n, 0), best_restando(n, 0);
	best_sumando[0] = a[0];
	best_restando[0] = 0;
	fore (i, 1, n) {
		best_sumando[i] = max(
			best_sumando[i-1], best_restando[i-1] + a[i]
		);
		best_restando[i] = max(
			best_sumando[i-1] - a[i], best_restando[i-1]
		);
	}

	cout << best_sumando[n - 1] << endl;

	vec<Solution> intervalos;
	forn (i) {
		intervalos.push_back({a[i], 0, 0, -a[i]});
	}
	ST st;
	st.init(intervalos);

	while (q--) {
		ll l, r;
		cin >> l >> r;
		l--; r--;
		swap(a[l], a[r]);
		st.set(l, {a[l], 0, 0, -a[l]});
		st.set(r, {a[r], 0, 0, -a[r]});
		Solution sol = st.query(0, n - 1);
		cout << sol.suma_suma << endl;


	}

}

int main() {
	IOS;

	ll t;
	cin>>t;
	while (t--) solve();

	return 0;
}

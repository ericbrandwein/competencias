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

struct MinYCant {
	ll min, cant;
};

MinYCant unir(MinYCant& first, MinYCant& second) {
	MinYCant nuevo;
	nuevo.min = min(first.min, second.min);
	if (first.min < second.min) {
		nuevo.cant = first.cant;
	} else if (first.min > second.min) {
		nuevo.cant = second.cant;
	} else {
		nuevo.cant = second.cant + first.cant;
	}
	return nuevo;
}


#define OP(a,b) unir(a, b)
using TYPE = MinYCant;
const TYPE NEUT = {1e9, 1};

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



int main() {
	IOS;

	ll n;
	cin >> n;

	vec<MinYCant> nums(n);
	vec<vec<ll>> posiciones(1000001);
	forn (i) {
		cin >> nums[i].min;
		nums[i].cant = 1;
		posiciones[nums[i].min].push_back(i);
	}


	ST st;
	st.init(nums);





	return 0;
}

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


#define OP(a,b) a + b
using TYPE = int;

struct ST {
	const TYPE NEUT = 0;
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
	ll query(int q_left, int q_right){ // O(log n)
		return _query(0,0,elems.size()/2-1,q_left,q_right);
	}
	ll _query(int node, int from, int to, int q_left, int q_right){
		if(q_left<=from && to<=q_right) return elems[node];
		if(q_left>to || q_right<from) return NEUT;
		int mid = (from+to)/2;
		return OP(_query(node*2+1,from,mid,q_left,q_right),
				_query(node*2+2,mid+1,to,q_left,q_right));
	}
};// usage: ST st(a); st.set(i,v); st.query(q_l,q_r); []



struct HorizontalSegment {
	ll y, from, to;
};

const bool sort_by_to(const HorizontalSegment& first, const HorizontalSegment& second) {
	return first.to < second.to;
}

const bool sort_by_from(const HorizontalSegment& first, const HorizontalSegment& second) {
	return first.from < second.from;
}

struct VerticalSegment {
	ll x, from, to;

	const bool operator<(const VerticalSegment& other) const {
		return x < other.x;
	}
};

const ll MAX_C = 1000000;

int main() {
	IOS;

	ll hor_q, ver_q;
	cin >> hor_q >> ver_q;

	vec<HorizontalSegment> hor_segments(hor_q);
	vec<HorizontalSegment> hor_segments_left;
	vec<HorizontalSegment> hor_segments_right;
	ll total = 1;
	fore (i, 0, hor_q) {
		cin >> hor_segments[i].y >> hor_segments[i].from >> hor_segments[i].to;
		if (hor_segments[i].from == 0) {
			hor_segments_left.push_back(hor_segments[i]);
			if (hor_segments[i].to == MAX_C) {
				total++;
			}
		} else {
			hor_segments_right.push_back(hor_segments[i]);
		}
	}

	vec<VerticalSegment> ver_segments(ver_q);
	fore (i, 0, ver_q) {
		cin >> ver_segments[i].x >> ver_segments[i].from >> ver_segments[i].to;
		if (ver_segments[i].from == 0 && ver_segments[i].to == MAX_C) {
			total++;
		}
	}

	// De mayor x a menor x
	sort(ver_segments.rbegin(), ver_segments.rend());

	// De mayor to a menor to
	sort(hor_segments_left.rbegin(), hor_segments_left.rend(), sort_by_to);

	vec<int> a(MAX_C + 1, 0);
	ST st;
	st.init(a);

	ll curr_hor = 0;
	for (ll curr_ver = 0; curr_ver < ver_q; curr_ver++) {
		auto& ver_seg = ver_segments[curr_ver];
		while(
			curr_hor < hor_segments_left.size() &&
			hor_segments_left[curr_hor].to >= ver_seg.x
		) {
			st.set(hor_segments_left[curr_hor].y, 1);
			curr_hor++;
		}

		total += st.query(ver_seg.from, ver_seg.to);
 	}

	// De menor from a mayor from
	sort(hor_segments_right.begin(), hor_segments_right.end(), sort_by_from);

	// De menor x a mayor x
	reverse(all(ver_segments));

	st.init(a);
	curr_hor = 0;
	for (ll curr_ver = 0; curr_ver < ver_q; curr_ver++) {
		auto& ver_seg = ver_segments[curr_ver];
		while(
			curr_hor < hor_segments_right.size() &&
			hor_segments_right[curr_hor].from <= ver_seg.x
		) {
			st.set(hor_segments_right[curr_hor].y, 1);
			curr_hor++;
		}

		total += st.query(ver_seg.from, ver_seg.to);
 	}

	cout << total << endl;



	return 0;
}

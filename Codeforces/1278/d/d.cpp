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

struct Segment {
	ll start, end;

	bool operator<(const Segment& other) const {
		return start < other.start;
	}
};

vector<Segment> segments;

int max_end(int first, int second) {
	if (segments[first].end > segments[second].end) {
		return first;
	} else {
		return second;
	}
}

#define oper(a,b) (max_end(a, b))
#define NEUT (0)
struct STree {
    vector<int> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void init(int k, int s, int e, vec<int>& a){
        if(s+1==e){st[k]=a[s];return;}
        int m=(s+e)/2;
        init(2*k,s,m,a);init(2*k+1,m,e,a);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    void upd(int k, int s, int e, int p, int v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    int query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void dump(int n){
        fore(i,0,n){
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }

    void init(vec<int> &a){init(1,0,n,a);}
    void upd(int p, int v){upd(1,0,n,p,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(posicion,nuevo_valor);rmq.query(desde, hasta); [desde, hasta)

int main() {
	IOS;

	ll n;
	cin >> n;

	forn (i) {
		ll start, end;
		cin >> start >> end;
		segments.push_back({start, end});
	}

	segments.push_back(Segment{LONG_LONG_MIN, LONG_LONG_MIN});
	sort(all(segments));

	vector<vector<ll>> edges(n + 1);

	STree stree(n + 1);

	vector<int> pos;
	for (ll i = 0; i < segments.size(); i++) {
		pos.push_back(i);
	}
	stree.init(pos);

	ll edges_q = 0;
	for (ll i =1; i < segments.size() - 1; i++){

		// El primero cuyo start no sea menor que mi end
		auto it_end = lower_bound(all(segments), Segment{segments[i].end, -1});
		// Yo no soy el último
		ll pos_start = i + 1;
		ll pos_end = it_end - segments.begin();

		// Voy sacando los que tengan mayor end para atrás
		// hasta encontrar uno que tenga menor end que yo.
		vector<ll> removed;
		ll last_seg_i = stree.query(pos_start, pos_end);
		while (segments[last_seg_i].end > segments[i].end) {
			edges[i].push_back(last_seg_i);
			edges[last_seg_i].push_back(i);
			edges_q++;

			if (edges_q > n - 1) {
				cout << "NO" << endl;
				return 0;
			}

			stree.upd(last_seg_i, NEUT);
			removed.push_back(last_seg_i);

			last_seg_i = stree.query(pos_start, pos_end);
		}

		for (ll seg_i : removed) {
			stree.upd(seg_i, seg_i);
		}
	}

	vector<bool> visited(n + 1, false);
	stack<ll> next;
	next.push(1);
	visited[1] = true;
	while (!next.empty()){
		ll actual = next.top(); next.pop();
		for (auto child : edges[actual]) {
			if (!visited[child]) {
				next.push(child);
				visited[child] = true;
			}
		}
	}


	for (ll i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;



	return 0;
}

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


#define oper(a,b) (max(a, b))
#define NEUT -1
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
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(desde,hasta);rmq.query(i,elem); [desde, hasta)

struct Hero {
	ll power;
	ll endur;

	bool operator<(const Hero& other) const {
		return power < other.power;
	}
};

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> mons(n);
		forn (i) {
			cin >> mons[i];
		}

		ll m;
		cin >> m;

		vector<Hero> heroes(m);
		fore (i ,0 ,m) {
			cin >> heroes[i].power;
			cin >> heroes[i].endur;
		}

		sort(all(heroes));

		vec<int> endurs;
		fore (i, 0, m) {
			endurs.push_back(heroes[i].endur);
		}

		STree segments(m);
		segments.init(endurs);

		ll days = 1;
		ll curr_endur = 0;
		ll max_mons = 0;
		forn (i) {
			// Por cada monstruo
			curr_endur++;
			max_mons = max(max_mons, mons[i]);
			auto it_heroes = lower_bound(all(heroes), Hero{max_mons, 0});
			if (it_heroes != heroes.end()) {
				ll pos_heroes = it_heroes - heroes.begin();
				int max_endur = segments.query(pos_heroes, m);
				if (max_endur < curr_endur) {
					days++;
					i--;
					curr_endur = 0;
					max_mons = 0;
				}
			} else {
				days = -1;
				break;
			}
		}

		cout << days << endl;

	}


	return 0;
}

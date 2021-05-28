/*    AUTHOR: julianferres   */
#include <bits/stdc++.h>
using namespace std;

// DEBUGGER
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
        sim > struct rge { c b, e; };
        sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
        sim > auto dud(c* x) -> decltype(cerr << *x, 0);
        sim > char dud(...);
        struct debug {
#ifdef LOCAL
            ~debug() { cerr << endl; }
            eni(!=) cerr << boolalpha << i; ris; }
        eni(==) ris << range(begin(i), end(i)); }
        sim, class b dor(pair < b, c > d) {
            ris << "(" << d.first << ", " << d.second << ")";
        }
sim dor(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//END DEBUGGER

typedef int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 1e5+5;
const int M = 320;

ll par[M][MAXN];
char s[MAXN];
int find(int x, int k){
	if(par[x][k]==k) return k;
	return par[x][k]=find(x,par[x][k]);
}
int idx[MAXN], a[MAXN], k[MAXN];
char c[MAXN];

int main(){
    FIN;

    cin >> s;
    ll n = (ll) strlen(s);
    ll m = (ll) sqrt(n);
    forr(i, 1, m+1){ forn(j, n+1){ par[i][j] = j; } }


    int tc; cin >> tc;

    forr(i, 1, tc+1){
        cin >> idx[i] >> a[i] >> k[i] >> c[i];
        idx[i]--;
    }

    vi last(n);
    //debug() << imie("LLEGO");

    for(ll i = tc; i >= 1; i--){
        if(a[i] > m){
            ll j = idx[i];
            while(j <= idx[i] + k[i] * a[i]){
                last[j] = max(last[j], i);
                j += a[i];
            }
        } else {
            for(int j=idx[i];j<=idx[i]+k[i]*a[i]; j=find(a[i],j)){
                last[j]=max(last[j],i);
                par[a[i]][j]=find(a[i],min(j+a[i],n));
            }
        }
    }

    forn(j, n) if(last[j]) s[j] = c[last[j]];

    cout << s << "\n";

    return 0;
}
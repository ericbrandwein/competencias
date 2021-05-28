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
#define MOD 1000000007

vec< vec<ll> > dp(105, vec<ll>(105, -1));
void solve(ll n, ll k){
    if( dp[n][k] != -1 ) return;
    if( k==0 ){
        dp[n][k]=1;
        return;
    }
    if( n==0 ){
        dp[n][k]=0;
        return;
    }
    solve(n-1, k-1);
    solve(n-1, k);
    dp[n][k] = dp[n-1][k-1] + dp[n-1][k];
    dp[n][k] %= MOD;
}

ll contar(vec<vec<ll>>& formas, ll rondas, ll m, ll puntos) {
    if (rondas == 0) {
        if (puntos == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (puntos == 0) {
        return 0;
    }
    if (rondas == 1) {
        if (puntos <= m) {
            return 1;
        } else {
            return 0;
        }
    }

    if (formas[rondas][puntos] != -1) {
        return formas[rondas][puntos];
    }

    ll total = 0;
    for (ll i = 1; i <= m && i <= puntos; i++) {
        total += contar(formas, rondas - 1, m, puntos - i);
        total %= MOD;
    }

    formas[rondas][puntos] = total;
    return total;
}

int main() {
	IOS;
	ll rondas, m, p1, p2;
	cin >> rondas >> m >> p1 >> p2;

    solve(102, 102);

    vec<vec<ll>> formas(rondas + 1, vec<ll>(1001, -1));

    ll total_posta = 0;
    fore (i, 0, rondas + 1) {
        fore (j, i, rondas + 1) {
            ll rondas_0 = rondas - j;
            ll formas_p1 = contar(formas, i, m, p1);
            ll formas_p2 = contar(formas, j - i, m, p2);
            ll total = (formas_p1 * formas_p2) % MOD;
            solve(j, i);
            total *= dp[j][i];
            total %= MOD;
            solve(rondas, rondas_0);
            total *= dp[rondas][rondas_0];
            total %= MOD;
            total_posta += total;
            total_posta %= MOD;
        }
    }

    cout << total_posta << endl;

	return 0;
}

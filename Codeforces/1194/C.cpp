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

int main() {
	IOS;
    
    int n;
    cin >> n;

    forn (i) {
        string s, t, p;
        cin >> s >> t >> p;

        int indice_s = 0;
        int indice_t = 0;
        bool encontrado = true;

        while (encontrado && s.size() <= t.size()) {
            if (indice_s >= s.size() || s[indice_s] != t[indice_t]) {
                encontrado = false;
                for (int indice_p = 0; indice_p < p.size() && !encontrado; indice_p++) {
                    if (p[indice_p] == t[indice_t]) {
                        s.insert(indice_s, 1, p[indice_p]);
                        p.erase(indice_p, 1);
                        indice_s++;
                        indice_t++;
                        encontrado = true;
                    }
                }
            } else {
                indice_s++;
                indice_t++;
            }
        }

        if (s.compare(t) == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
	return 0;
}

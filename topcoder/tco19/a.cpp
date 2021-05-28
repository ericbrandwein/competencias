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

class  EllysBalancedStrings {
public:

	int getMin(string s) {
		vec<char> vowels = {'A', 'E', 'I', 'O', 'U'};
        vec<bool> is_vowel(s.size(), false);
        ll cantv = 0;
        ll cantc  = 0;
        for (ll i = 0; i < s.size(); i++) {
            bool vowel = false;
        	for (ll j = 0; j < vowels.size(); j++) {
            	if (vowels[j] == s[i]){
                	is_vowel[i] = true;
                    break;
                }
            }
            if (!is_vowel[i]) cantc++;
            else cantv++;
        }


        if (cantv > cantc) {
            return cantv - (s.size() / 2);
        } else {
            multiset<ll> cambios;
            for (ll i = 0; i < s.size(); i++) {
                if (!is_vowel[i]) {
                    ll dist = 'Z' - 'A';
                    for (ll j = 0; j < vowels.size(); j++) {
                        dist = min(dist, (ll)abs(s[i] - vowels[j]));
                    }
                    cambios.insert(dist);
                }
            }

            ll res = 0;
            auto it = cambios.begin();
            for (ll i = 0; i < (cantc - (s.size() / 2)); i++) {
                res += *it;
                it++;
            }
            return res;
        }


	}
};


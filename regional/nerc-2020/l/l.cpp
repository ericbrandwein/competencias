// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/STACK: 20000000")
// #define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {int operator()(int x) const { return x ^ RANDOM; }};//avoid hacks

#define endl '\n'

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
    return static_cast<__int128>(a) * b % m;
}
ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}


bool is_prime_prob(ll n, int a){
	// if (primes.count(n) != 0) return true;
	if(n==a)return true;
	ll s=0,d=n-1;
	s = __builtin_ctz(n);
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(_,0,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13};
	fore(i,0,6)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}
map<ll,ll> _rho;
ll rho(ll n){
  if(_rho.count(n)) return _rho[n];
	if(!(n&1))return 2;
	ll x=2,y=2,d=1;
	ll c=rand()%n+1;
	while(d==1){
		x=(mulmod(x,x,n)+c)%n;
		y=(mulmod(y,y,n)+c)%n;
		y=(mulmod(y,y,n)+c)%n;
		if(x>=y)d=gcd(x-y,n);
		else d=gcd(y-x,n);
	}
	return _rho[n]=d==n?rho(n):d;
}
void fact(ll n, vec<ll>& f){ //O (lg n)^3 gp_hash_table<ll, int, chash>& f
	stack<ll> next;
	next.push(n);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();
		if (n == 1) continue;
		if(rabin(curr)){
			f.push_back(curr);
			// f[n]++;
			continue;
		}
		ll q=rho(curr);
		next.push(q);
		next.push(curr/q);
	}
}


int main() {
	IOS;

	int n,k;
	cin >> n >> k;
	vec<ll> nums(n);
	vec<gp_hash_table<ll, int, chash>> factores(n);
	gp_hash_table<ll, vec<int>, chash> potencias;
	forn (i) {
		cin >> nums[i];
	}
	random_shuffle(all(nums));
	forn (i) {
		vec<ll> fac_vec;
		fact(nums[i], fac_vec);
		for (ll num : fac_vec) {
			factores[i][num]++;
		}
		if (factores[i].size() == 1) {
			auto factor = factores[i].begin();
			potencias[factor->first].push_back(i);
		}
	}

	vec<bool> usable(n, true);
	forn (i) {
		for (auto& factor: factores[i]) {
			auto it = potencias.find(factor.first);
			if (
				it == potencias.end() || it->second.size() < 2
			) {
				usable[i] = false;
				break;
			}
		}
	}

	ll potencias_usables = 0;
	for (auto& potencia : potencias) {
		if (potencia.second.size() >= 2) {
			potencias_usables++;
		}
	}
	vec<int> res;
	for (auto& potencia : potencias) {
		if (potencia.second.size() >= 2) {
			res.push_back(potencia.second[0]);
			res.push_back(potencia.second[1]);
		}
		if (res.size() == k || res.size() == k - 1) break;
	}
	if (res.size() != k) {
		int potencias_usadas = res.size() / 2;
		if (potencias_usadas == potencias_usables) {
			// Hay que agregar algunos nums que usen todas las potencias
			for (int i = 0; i < n && res.size() < k; i++) {
				if (usable[i]) {
					if (factores[i].size() == 1) {
						ll potencia = factores[i].begin()->first;
						if (potencias[potencia][0] != i && potencias[potencia][1] != i) {
							res.push_back(i);
						}
					} else {
						res.push_back(i);
					}
				}
			}
		} else {
			// Tuve demasiadas potencias como para rellenar, tengo que agregar uno solo
			for (int i = 0; i < n; i++) {
				if (usable[i] && factores[i].size() <= k/2) {
					bool puede = true;
					if (factores[i].size() == 1) {
						ll potencia = factores[i].begin()->first;
						puede = potencias[potencia][0] != i && potencias[potencia][1] != i;
					}
					if (puede) {
						res.clear();
						unordered_set<ll> potencias_agregadas;
						res.push_back(i);
						for (auto& factor : factores[i]) {
							ll potencia = factor.first;
							res.push_back(potencias[potencia][0]);
							res.push_back(potencias[potencia][1]);
							potencias_agregadas.insert(potencia);
						}

						for (auto& potencia : potencias) {
							if (res.size() == k) break;
							if (potencia.second.size() >= 2) {
								ll num = potencia.first;
								if (potencias_agregadas.count(num) == 0) {
									res.push_back(potencia.second[0]);
									res.push_back(potencia.second[1]);
								}
							}
						}
						break;
					}
				}
			}
		}

	}

	if (res.size() == k) {
		for (int elem : res) {
			cout << nums[elem] << " ";
		}
	} else {
		cout << 0;
	}
	cout << endl;

}

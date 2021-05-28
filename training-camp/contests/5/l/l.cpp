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

struct Envelope {
	pair<ll, ll> dims;
	ll index;

	bool operator<(const Envelope& other) const {
		return this->dims < other.dims;
	}
};

int main() {
	IOS;

	ll n;
	cin >> n;
	pair<ll, ll> card;
	cin >> card.first >> card.second;


	vector<Envelope> envelopes;
	forn (i) {
		pair<ll, ll> envelope;
		cin >> envelope.first >> envelope.second;
		if (envelope.first > card.first && envelope.second > card.second) {
			envelopes.push_back({envelope, i});
		}
	}

	if (envelopes.empty()) {
		cout << 0 << endl;
		return 0;
	}

	sort(all(envelopes));


	ll env_q = envelopes.size();
	vector<ll> longest(env_q, 1);
	vector<ll> next(env_q, env_q);
	for (ll i = env_q - 1; i >= 0; i--) {
		pair<ll, ll>& dimsi = envelopes[i].dims;
		for (ll j = i + 1; j < env_q; j++) {
			pair<ll, ll>& dimsj = envelopes[j].dims;
			if (
				dimsj.first > dimsi.first &&
				dimsj.second > dimsi.second &&
				longest[j] >= longest[i]
			) {
				longest[i] = longest[j] + 1;
				next[i] = j;
			}
		}
	}

	ll best = 0;

	for (ll i = 0; i < env_q; i++) {
		if (longest[i] > longest[best]) {
			best = i;
		}
	}

	cout << longest[best] << endl;
	ll curr = best;
	while (curr < env_q) {
		cout << envelopes[curr].index + 1 << " ";
		curr = next[curr];
	}



	return 0;
}

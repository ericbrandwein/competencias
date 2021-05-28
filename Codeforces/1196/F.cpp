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

struct Path {
    ll origin, dest, weight;

    bool operator<(const Path& other) const {
        return weight < other.weight || 
            (weight == other.weight && origin < other.origin) ||
            (weight == other.weight && origin == other.origin && dest < other.dest); 
    }

    void print() const {
        cout << origin << " --" << weight << "--> " << dest << endl;;
    }
};


bool combine(Path& first, Path& second, Path& combined) {
    bool can_combine = true;
    combined.weight = first.weight + second.weight;
    if (first.dest == second.origin) {
        combined.origin = first.origin;
        combined.dest = second.dest;
    } else if (first.origin == second.dest) {
        combined.origin = second.origin;
        combined.dest = first.dest;
    } else if (first.origin == second.origin) {
        combined.origin = second.dest;
        combined.dest = first.dest;
    } else if (first.dest == second.dest){
        combined.origin = second.origin;
        combined.dest = first.origin;
    } else {
        can_combine = false;
    }
    return can_combine;
}

void show_set(set<Path>& paths) {
    for (auto it = paths.begin(); it != paths.end(); it++) {
        it->print();
    }
    cout << "----------" << endl;
}


void add_paths(
    Path& min_path, set<Path>& paths, 
    map<ll, map<ll, ll>>& min_paths, ll amount_to_combine) {
    
    vector<Path> paths_to_combine;
    auto it = paths.begin();
    for (ll i = 0; it != paths.end() && i < amount_to_combine; i++, it++) {
        paths_to_combine.push_back(*it);    
    }

    for (ll i = 0; i < paths_to_combine.size(); i++) {
        Path& to_combine = paths_to_combine[i];
        Path combined;
        bool can_combine = combine(to_combine, min_path, combined);


        if (can_combine) {
            map<ll, ll>& path_lengths_from_origin = min_paths[combined.origin];
            auto it_min_path = path_lengths_from_origin.find(combined.dest);
            bool add_path = false;
            if (it_min_path != path_lengths_from_origin.end() && 
                it_min_path->second > combined.weight) {
                // Tenemos que borrar el path anterior
                auto it_erasable = paths.find(
                    {combined.origin, combined.dest, it_min_path->second});
                if (it_erasable == paths.end()) {
                    it_erasable = paths.find(
                        {combined.dest, combined.origin, it_min_path->second});
                }
                paths.erase(it_erasable);
                add_path = true;
            } else if (it_min_path == path_lengths_from_origin.end()) {
                add_path = true;
            }

            if (add_path) {
                // El camino actual al destino es mejor que el que teníamos antes
                path_lengths_from_origin[combined.dest] = combined.weight;
                min_paths[combined.dest][combined.origin] = combined.weight;
                paths.insert(combined);
            }
        }
    }
}

int main() {
	IOS;

    ll n, m, k;
    cin >> n >> m >> k;

    map<ll, map<ll, ll>> min_paths;  
    set<Path> paths;
    fore (i, 0, m) {
        Path actual;
        cin >> actual.origin >> actual.dest >> actual.weight;
        paths.insert(actual);
    }

    auto it_path = paths.begin();
    fore (i, 0, k) {
        min_paths[it_path->origin][it_path->dest] = it_path->weight;
        min_paths[it_path->dest][it_path->origin] = it_path->weight;
        it_path++;
    }

    fore (i, 0, k - 1) {
        Path min_path = *paths.begin();
        // min_path.print();
        // show_set(paths);
        paths.erase(paths.begin());
        add_paths(min_path, paths, min_paths, k - i - 1);
    }
    
    // paths.begin()->print();
    cout << paths.begin()->weight << endl;

	return 0;
}

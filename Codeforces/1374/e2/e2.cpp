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

struct Book {
	ll cost, index;

	bool const operator<(const Book& other) const {
		return this->cost < other.cost;
	}
};


int main() {
	IOS;

	ll books_per_person, n, m;
	cin  >> n >> m >> books_per_person;

	vector<Book> alice_books;
	vector<Book> bob_books;
	vector<Book> both_books;
	vector<Book> none_books;


	forn (i) {
		ll cost, alice, bob;
		cin >> cost >> alice >> bob;
		Book book = {cost, i};
		if (alice && bob) {
			both_books.push_back(book);
		} else if (alice) {
			alice_books.push_back(book);
		} else if (bob) {
			bob_books.push_back(book);
		} else {
			none_books.push_back(book);
		}
	}

	if (both_books.size() + min(bob_books.size(), alice_books.size()) < books_per_person) {
		cout << -1 << endl;
		return 0;
	}

	sort(alice_books.rbegin(), alice_books.rend());
	sort(bob_books.rbegin(), bob_books.rend());
	sort(both_books.rbegin(), both_books.rend());
	sort(none_books.rbegin(), none_books.rend());

    vector<Book> added_alice_books;
	vector<Book> added_bob_books;
	vector<Book> added_both_books;
	vector<Book> added_none_books;
    ll libros = 0;
	while (books_per_person > 0) {
		ll separated_cost = LONG_LONG_MAX;
		if (!bob_books.empty() && !alice_books.empty()) {
			separated_cost = bob_books.back().cost + alice_books.back().cost;
		}
		ll joint_cost = LONG_LONG_MAX;
		if (!both_books.empty()) {
			joint_cost = both_books.back().cost;
		}

		if (joint_cost < separated_cost) {
			added_both_books.push_back(both_books.back());
			both_books.pop_back();
            libros++;
		} else {
			added_alice_books.push_back(alice_books.back());
			added_bob_books.push_back(bob_books.back());
			alice_books.pop_back();
			bob_books.pop_back();
            libros += 2;
		}

		books_per_person--;
	}

	if (libros > m) {
		// Hay que cambiar separados por combinados
		while (libros > m && !both_books.empty()) {
			added_alice_books.pop_back();
			added_bob_books.pop_back();
			added_both_books.push_back(both_books.back());
			both_books.pop_back();
			libros--;
		}
		if (libros != m) {
			cout << -1 << endl;
			return 0;
		}
	} else if (libros < m) {
		// Hay que cambiar combinados por separados
		// Hay que fijarse si no es mejor agregar none_books
		while (libros < m && !alice_books.empty() && !bob_books.empty() && !added_both_books.empty()) {
			Book back_alice = alice_books.back();
			Book back_bob = bob_books.back();
			Book back_both = added_both_books.back();

			if (back_both.cost > back_alice.cost && back_both.cost > back_bob.cost) {
				if (
					!none_books.empty() &&
					none_books.back().cost + back_both.cost < back_alice.cost + back_bob.cost
				) {
					added_none_books.push_back(none_books.back());
					none_books.pop_back();
				} else {
					added_both_books.pop_back();
					both_books.push_back(back_both);
					alice_books.pop_back();
					added_alice_books.push_back(back_alice);
					bob_books.pop_back();
					added_bob_books.push_back(back_bob);
				}
			} else {
				break;
			}
			libros++;
		}

		// Todavía faltan agregar libros, agarramos los más chicos
		while (
			libros < m &&
			(!alice_books.empty() || !bob_books.empty() ||
				!both_books.empty() || !none_books.empty())
		) {
			vector<Book>* best_books = &alice_books;
			vector<Book>* best_added_books = &added_alice_books;

			if (!bob_books.empty() && (best_books->empty() ||
				bob_books.back().cost < best_books->back().cost)) {
				best_books = &bob_books;
				best_added_books = &added_bob_books;
			}

			if (!both_books.empty() && (best_books->empty() ||
				both_books.back().cost < best_books->back().cost)) {
				best_books = &both_books;
				best_added_books = &added_both_books;
			}

			if (!none_books.empty() && (best_books->empty() ||
				none_books.back().cost < best_books->back().cost)) {
				best_books = &none_books;
				best_added_books = &added_none_books;
			}

			best_added_books->push_back(best_books->back());
			best_books->pop_back();

			libros++;
		}
	}


	ll total = 0;
	for (Book b : added_alice_books) {
		total += b.cost;
	}
	for (Book b : added_bob_books) {
		total += b.cost;
	}
	for (Book b : added_both_books) {
		total += b.cost;
	}
	for (Book b : added_none_books) {
		total += b.cost;
	}

	cout << total << endl;
	for (Book b : added_alice_books) {
		cout << b.index + 1 << " ";
	}
	for (Book b : added_bob_books) {
		cout << b.index + 1 << " ";
	}
	for (Book b : added_both_books) {
		cout << b.index + 1 << " ";
	}
	for (Book b : added_none_books) {
		cout << b.index + 1 << " ";
	}
	cout << endl;

	return 0;
}

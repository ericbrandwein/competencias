#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/STACK: 20000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
//using ll = __int128;
using ld = long double;
//#define all(x) x.begin(), x.end()
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPSILON 0.0000001

int card_to_idx(char card) {
    switch (card) {
        case 'A': return  0;
        case '2': return  1;
        case '3': return  2;
        case '4': return  3;
        case '5': return  4;
        case '6': return  5;
        case '7': return  6;
        case '8': return  7;
        case '9': return  8;
        case 'D': return  9;
        case 'Q': return 10;
        case 'J': return 11;
        case 'K': return 12;
    }
    exit(1);
}

int main() {
    // IOS;
    ll n, k;
    cin >> n >> k;

    vector<vector<int>> p(n, vector<int>(13, 0));
    int wildcard_holder = k - 1;
    bool can_pass_wildcard = false;
    int current_player = k - 1;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto card : s) p[i][card_to_idx(card)]++;
    }

    auto next = [&]() {
        return current_player = (current_player + 1 + n) % n;
    };

    auto has_won = [&](int player) {
        bool has_four_of_the_same = false;
        int winning_card = 99;
        int total_cards = 0;
        for (int i = 0; i < 13; i++) {
            int card_amount = p[player][i];
            if (card_amount == 4) {
                has_four_of_the_same = true;
                winning_card = i;
            }
            total_cards += card_amount;
        }
        if (wildcard_holder == player) total_cards++;
        return has_four_of_the_same && total_cards == 4 ? winning_card : 99;
    };

    int winner = -1;
    auto someone_won = [&]() {
        int current_wins = has_won(current_player);
        int previous_wins = has_won((current_player + 1) % n);
        winner = current_wins < previous_wins ? current_player : (current_player + 1) % n;
        return current_wins != 99 || previous_wins != 99;
    };

    {
        int winning_card = 99;
        int winning_player = 99;
        for (int i = 0; i < n; i++) {
            int wins = has_won(i);
            if (wins != 99 && wins < winning_card) {
                winning_player = i + 1;
                winning_card = wins;
            }
        }
        if (winning_card != 99) {
            cout << winning_player << endl;
            return 0;
        }
    }

    while (!someone_won()) {
        if (wildcard_holder == current_player && can_pass_wildcard){
            wildcard_holder = next();
            can_pass_wildcard = false;
            continue;
        }
        can_pass_wildcard = true;

        int least_amount = 99;
        for (int i = 0; i < 13; i++)
            if (p[current_player][i] != 0 && p[current_player][i] < least_amount)
                least_amount = p[current_player][i];
        for (int i = 0; i < 13; i++)
            if (p[current_player][i] == least_amount) {
                p[current_player][i]--;
                p[next()][i]++;
                break;
            }
    }

    cout << winner + 1 << endl;

    return 0;
}
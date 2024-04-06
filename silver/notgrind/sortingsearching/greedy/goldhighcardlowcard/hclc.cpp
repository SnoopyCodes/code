#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> deck;
vector<int> elsie;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N; cin >> N;
    N *= 2;
    deck.resize(N);
    elsie.resize(N / 2);
    for (int i = 0; i < N / 2; i++) {
        cin >> elsie[i];
        elsie[i]--;
    }
    for (int i = 0; i < N; i++) { deck[i] = i; }
    for (int i = 0; i < N / 2; i++) { deck[elsie[i]] = -1; } //print elsie
    //ok lets use a sorted set then
    set<int> bessieg;
    set<int> bessiel;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (count < N / 4) {
            if (deck[i] != -1) { bessiel.insert(deck[i]); count++; }
        }   else {
            if (deck[i] != -1) { bessieg.insert(deck[i]); }
        }
    }
    //okay if we can get a point then get a point. save the top half of b's deck for the first half, lower for last
    //in first half:
    //use the smallest int greater than whatever elsie shows
    //if there isn't any, use the smallest instead
    // for (auto it : bessieg) { cout << it << " "; }
    // cout << "\n";
    // for (auto it : bessiel) { cout << it << " "; }
    // cout << "\n";
    count = 0;
    for (int i = 0; i < N / 4; i++) {
        int greater = *bessieg.upper_bound(elsie[i]);
        if (greater > elsie[i]) {
            // cout << greater << "+" << elsie[i] << "\n";
            count++;
            bessieg.erase(greater);
        }   else {
            // cout << *bessieg.begin() << "-" << elsie[i] << "\n";
            bessieg.erase(*bessieg.begin());  //remove the smalelst
        }
    }
    for (int i = N / 4; i < N / 2; i++) {
        auto itl = bessiel.lower_bound(elsie[i]);
        int lower = *(--itl);
        if (lower < elsie[i]) {
            // cout << lower << "+" << elsie[i] << "\n";
            count++;
            bessiel.erase(lower);
        }   else {
            //  cout << *bessiel.rbegin() << "-" << elsie[i] << "\n";
            bessiel.erase(*bessiel.rbegin());  //remove the greatest
        }
    }
    cout << count;
}
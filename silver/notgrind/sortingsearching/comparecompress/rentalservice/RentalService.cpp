#include <bits/stdc++.h>

using namespace std;

struct Store {
    long long prev;  //money from before
    int pay, max;
    long long pgal;  //gallons needed to get here
    long long money() {
        return prev + pay * max;
    }
};
bool cmp(int x, int y) { return x > y; }
bool compare(const Store &s1, const Store &s2) { return s1.pay > s2.pay; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int N, M, R;
    cin >> N >> M >> R;
    vector<long long> cows(N+1);
    cows[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> cows[i];
    }
    vector<Store> stores(M+1);
    stores[0].pay = 0; stores[0].max = 0; stores[0].pgal = 0; stores[0].prev = 0;
    for (int i = 1; i <= M; i++) {
        cin >> stores[i].max >> stores[i].pay;
    }
    vector<long long> rent(R+1);
    rent[0] = 0;
    for (int i = 1; i <= R; i++) {
        cin >> rent[i];
    }
    sort(cows.begin() + 1, end(cows), cmp);  //reverse in order to figure out milk production if we keep n cows
    sort(rent.begin() + 1, end(rent), cmp);  //reverse in order to figure out money if we sell m cows
    sort(stores.begin() + 1, end(stores), compare); //stores that pay the most first
    for (int i = 1; i <= N; i++) { cows[i] += cows[i-1]; }
    for (int i = 1; i <= M; i++) { stores[i].prev = stores[i-1].money(); stores[i].pgal = stores[i-1].pgal + stores[i-1].max; }
    for (int i = 1; i <= R; i++) { rent[i] += rent[i-1]; }
    long long money = 0;
    int store = 0;
    for (int i = 0; i < N; i++) {  //if we keep i cows, how much can we make?
        long long iter = rent[min(N-i, R)];
        while (store <= M && cows[i] >= stores[store].pgal + stores[store].max) { store++; }
        if (store > M) {
            iter += stores[M].money();
        }   else {
            int left = cows[i] - stores[store].pgal;
            iter += stores[store].prev + stores[store].pay * left;
        }
        if (money < iter) { money = iter; }
    }
    cout << money << "\n";
    //way it works:
    //at a certain point it makes more money to sell off cows than use them to make milk
    //pfr[n]
}
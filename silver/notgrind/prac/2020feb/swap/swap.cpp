#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> vm;
vector<int> cows;
int dummy[100000];
void swap(int i, int j) {
    int temp = cows[i];
    cows[i] = cows[j];
    cows[j] = temp;
}
void iter(int it) {
    for (int i = 0; i < cows.size(); i++) {
        dummy[vm[it][i]] = cows[i];  //what this says is that the new position of cow i is at dummy[vm[it][i]]
    }
    for (int i = 0; i < cows.size(); i++) {
        cows[i] = dummy[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int N; cin >> N;
    int M; cin >> M;
    int K; cin >> K;
    //can full simulate one time
    vector<pair<int, int>> swaps(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        swaps[i].first = a; swaps[i].second = b;
    }
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cows[i] = i;
    }
    //so first simulate it once  //10^7
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < (swaps[i].second - swaps[i].first) / 2+1; j++) {
            swap(swaps[i].first+j, swaps[i].second-j);
        }
    }
    K--;
    int it = 0;
    int shifts = 1;
    vm.resize(31, vector<int>(N));
    for (int i = 0; i < N; i++) {
        vm[0][cows[i]] = i;  //essentially, vm[iteration][i] tells you where a cow i will go to.
    }
    while (shifts <= K) {  //10^5 * 30
        iter(it);
        K -= shifts;
        it++;
        shifts *= 2;
        for (int i = 0; i < N; i++) {
            vm[it][cows[i]] = i;  //essentially, vm[iteration][i] tells you where a cow i will go to.
        }
    }
    while (K > 0) {
        while (shifts > K) { it--; shifts /= 2; }
        iter(it);
        K -= shifts;
    }
    for (int i = 0; i < N; i++) {
        cout << cows[i]+1 << "\n";
    }
}
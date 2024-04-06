#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> original;
vector<int> shifted;
vector<int> shiftmax;
vector<bool> numbers;
int bsearch(int x) {
    int s = 0;
    int e = original.size();
    while (s < e) {
        int m = (s + e + 1) / 2;
        if (original[m].first == x) { return original[m].second; }
        else if (original[m].first < x) { s = m; }
        else { e = m-1; }
    }
    if (original[s].first == x) { return original[s].second; }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    original.resize(K);
    shiftmax.resize(K);
    shifted.resize(K);
    numbers.resize(N); for (int i = 0; i < N; i++) { numbers[i] = true; }
    for (int i = 0; i < K; i++) {
        cin >> original[i].first; original[i].second = i;
        numbers[original[i].first-1] = false;
    }
    for (int i = 0; i < K; i++) {
        cin >> shifted[i];
        numbers[shifted[i]-1] = false;
    }
    sort(original.begin(), original.end());
    for (int i = 0; i < K; i++) {
        int idx = bsearch(shifted[i]);
        if (idx != -1) {
            int shift = i - idx;
            if (shift < 0) { shift += K; }
            shiftmax[shift]++;
        }
    }
    int mcycle = 0;
    for (int i = 0; i < K; i++) { mcycle = max(mcycle, shiftmax[i]); }
    vector<int> copy(K);
    shiftmax.clear(); shiftmax.resize(K);
    for (int i = 0; i < K; i++) { copy[i] = shifted[K-1-i]; }
    for (int i = 0; i < K; i++) {
        int idx = bsearch(copy[i]);
        if (idx != -1) {
            int shift = i - idx;
            if (shift < 0) { shift += K; }
            shiftmax[shift]++;
        }
    }
    for (int i = 0; i < K; i++) { mcycle = max(mcycle, shiftmax[i]); }
    for (int i = 0; i < N; i++) { mcycle += numbers[i]; }
    cout << mcycle << "\n";

}
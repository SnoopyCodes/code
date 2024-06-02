#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    vector<int> pos(N);  //position of ball i
    vector<int> real(N);  //what ball is at position i
    for (int i = 0; i < N; i++) {
        pos[i] = i;
        real[i] = i;
    }
    for (int i = 0; i < Q; i++) {
        int x; cin >> x; x--;
        int ball = pos[x];  //positon of ball
        if (ball != N - 1) {
            pos[x]++;  //move right
            pos[real[ball+1]]--;  //move left
            swap(real[ball], real[ball+1]);
        }   else {
            pos[x]--;
            pos[real[ball-1]]++;
            swap(real[ball], real[ball-1]);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << real[i]+1;
        if (i != N - 1) { cout << " "; }
    }
}
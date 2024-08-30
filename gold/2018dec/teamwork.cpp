#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> skills(N);
    for (int i = 0; i < N; i++) {
        cin >> skills[i];
    }
    //how to form groups
    //wait at every single one we can try to form groups of size K and see how that goes
    //we want at every point to maintain the maximum amount of thing
    //bruh wtf i am very bad
}
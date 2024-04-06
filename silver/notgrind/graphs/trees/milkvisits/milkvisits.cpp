#include <bits/stdc++.h>

using namespace std;
struct Cow{
    bool milk;
    int farm;
    vector<int> adj;
};
vector<Cow> cows;
vector<bool> visited;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("milkvisits.in", "r", stdin);
    //freopen("milkvisits.out", "w", stdout);
    int N, M;
    string s;
    cows.resize(M);
    cin >> N >> M >> s;
    vector<bool> v(N);

    for (int i = 0; i < N; i++) {
        v[i] = s.at(i) == 'H';
    }
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        cows[a].adj.push_back(b);
        cows[b].adj.push_back(a);
    }
    for (int m = 0; m < M; m++ ) {
        int s, e;
        string milke;
        bool milk;
        cin >> s >> e >> milke; s--; e--;
        milk = milke == "H";
    }
    
}
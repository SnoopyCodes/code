#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll exp(ll x, int p) {
    ll res = 1;
    while (p > 0) {
        if (p % 2 & 1) { res = res * x % MOD; }
        x = x * x % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("poetry.in", "r", stdin);
    // freopen("poetry.out", "w", stdout);
    int N, M, K; cin >> N >> M >> K;
    vector<int> rhyme(N);
    vector<int> len(N);
    for (int i = 0; i < N; i++) {
        cin >> len[i] >> rhyme[i]; rhyme[i]--;
    }
    vector<int> scheme(26);
    for (int i = 0; i < M; i++) {
        char c; cin >> c;
        scheme[c - 65]++;
    }
    vector<ll> ways(K);
    vector<int> classes(N);
    ways[0] = 1;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            if (len[j] + i > K) { continue; }
            if (len[j] + i == K) { classes[rhyme[j]] = (classes[rhyme[j]] + ways[i]) % MOD; continue; }
            ways[i + len[j]] = (ways[i + len[j]] + ways[i]) % MOD;
        }
    }
    //ok mission accomplished
    //now actually try to have skill
    //goddamn wait this might be hard
    //we have some rhyme classes (up to 5000)
    //we have some ways to form them
    //we need to select scheme amount at most of classes
    //say we have a set selected
    //say we remove all zero rhyme classes
    auto compress = [&](vector<int> &v) {
        vector<int> comp;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 0) { comp.push_back(v[i]); }
        }
        return comp;
    };
    rhyme = compress(classes);
    N = rhyme.size();
    scheme = compress(scheme);
    int C = scheme.size();
    //now what
    //let each scheme be a unit
    //and now the question is how do we paint these units
    //simply select for each unit a color
    //i am have big brain damage
    //ways for each color
    ways.clear(); ways.resize(C+1);
    ways[0] = 1;
    for (int i = 0; i < C; i++) {
        ll way = 0;
        for (int j = 0; j < N; j++) {
            ways[i+1] = (ways[i+1] + exp(rhyme[j], scheme[i]) * ways[i] % MOD) % MOD;
        }
    }
    cout << ways[C] << "\n";
    //not overflow issue
    //additionally we get exactly 1/3 of test cases so it is likely that this was planned for
    //are we overcounting perhaps?
    //where?
    //why do we get more when we do all of the same type?
    //step 1
    //calculate rhyme[i], the ways to end with the ith rhyme class
    //step 2
    //the number of ways to fill each scheme set is rhyme[j] ** scheme[i]
    //
}
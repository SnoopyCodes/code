#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> dsu;
vector<int> sizes;
int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) { return; }
    if (sizes[u] < sizes[v]) { swap(u, v); }
    sizes[u] += sizes[v];
    dsu[v] = u;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    dsu.resize(K);
    sizes.resize(K, 1);
    for (int i = 0; i < K; i++) {
        dsu[i] = i;
    }
    vector<int> interviews(N);
    priority_queue<array<ll, 2>> pq;
    for (int i = 0; i < N; i++) {
        cin >> interviews[i];
        if (i < K) { pq.push({-interviews[i], i}); }
    }
    /*simulation*/{
        int i = K;
        while (i < N) {  //ok lets go
            ll t = -pq.top()[0];
            vector<int> farmers{(int) pq.top()[1]};
            pq.pop();
            while (!pq.empty() && -pq.top()[0] == t) {
                farmers.push_back({(int)pq.top()[1]});
                pq.pop();
            }
            //okay wait so we can't push teh farmers back into queue
            //then what
            //uhhh
            //ok wait then merge all of the cows that
            //we can interview at this time together
            //since thats all the same
            //okay nice but thats wrong for some reason :dead:
            //bruh this is brain damaged
            //how do i not know this
            //ok then so its like go backwards bruh
            for (int j = 1; j < farmers.size(); j++) {
                merge(farmers[j], farmers[j - 1]);
            }
            for (int j = 0; j < farmers.size(); j++) {
                pq.push({-(t + interviews[i]), find(farmers[0])});
                i++;
            }
        }
    }
    //simulate 1 more time
    ll t = -pq.top()[0];
    vector<int> farmers{(int) pq.top()[1]};
    pq.pop();
    while (!pq.empty() && -pq.top()[0] == t) {
        farmers.push_back({(int)pq.top()[1]});
        pq.pop();
    }
    for (int j = 1; j < farmers.size(); j++) {
        merge(farmers[j], farmers[j - 1]);
    }
    int f = farmers[0];
    cout << t << "\n";
    for (int i = 0; i < K; i++) {
        cout << (find(i) == f);
    }
    //so every single like
    //farmer is merged together
    //
}
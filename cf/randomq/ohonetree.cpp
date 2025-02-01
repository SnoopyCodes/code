#include <bits/stdc++.h>
#define long int64_t
using namespace std;

struct DSU {
    int N;
    vector<int> root, sizes;
    void init(int _N) {
        int N = _N;
        root.resize(N);
        sizes.resize(N, 1);
        for (int i = 0; i < N; i++) { root[i] = i; }
    }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (sizes[ru] < sizes[rv]) { swap(ru, rv); }
        sizes[ru] += sizes[rv];
        root[rv] = ru;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //DSU!
    DSU zero; zero.init(N);
    DSU one; one.init(N);
    //very easy calculation is this even worth doing
    //lets just do it
    //wait it is not as easy as i think 
    //connect all 1 edges together
    //connect zero-edges together
    //1->0 is ok
    //0->1 not ok
    //we can go only from 1-edges
    //wait ok this is fine
    vector<bool> inz(N), ino(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, t; cin >> u >> v >> t; u--; v--;
        if (t == 0) {
            inz[u] = inz[v] = true;
            zero.merge(u, v);
        }   else {
            ino[u] = ino[v] = true;
            one.merge(u, v);
        }
    }
    //go!
    long answer = 0;
    vector<bool> donez(N), doneo(N);
    for (int i = 0; i < N; i++) {
        if (inz[i] && !donez[zero.find(i)]) {
            int sz = zero.sizes[zero.find(i)];
            answer += (long) sz * (sz - 1);
            donez[zero.find(i)] = true;
        }
        if (ino[i] && !doneo[one.find(i)]) {
            int sz = one.sizes[one.find(i)];
            answer += (long) sz * (sz - 1);
            doneo[one.find(i)] = true;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (!ino[i] || !inz[i]) { continue; }
        answer += (long) (zero.sizes[zero.find(i)] - 1) * (one.sizes[one.find(i)] - 1);
    }
    //notes: to iterate over a component once in dsu, just check if find[i] == i
    
    cout << answer << "\n";
}
#include <bits/stdc++.h>

using namespace std;
int N; string s;
vector<int> dna;
int doStuff(int K, int L) {
    set<int> starts;
    for (int i = 0; i <= N - K; i++) {
        int idx = i;
        string beg = s.substr(i, L);
        string cur = s.substr(i, L);
        for (int j = i+1; j + L <= i + K; j++) {
            cur = cur.substr(1, cur.size()-1);
            cur += s[j + L - 1];
            for (int x = 0; x < L; x++) {
                if (beg[x] > cur[x]) { idx = j; beg = cur; break; }
                else if (beg[x] < cur[x]) { break; }
            }
        }

        starts.insert(idx);
    }
    return starts.size();
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //N^2 possible things
    //and for each one check the lexico min of substr length (naively N^2)
    //and put that in
    cin >> N;
    cin >> s;
    dna.resize(N+1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            //find stuff
            dna[doStuff(i, j)]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << dna[i] << "\n";
    }
}
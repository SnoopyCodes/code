#include <bits/stdc++.h>
using namespace std;

static const int NEG = -1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; 
        cin >> N;
        string S; 
        cin >> S;

        vector<vector<int>> child(N + 1);
        for (int i = 2; i <= N; ++i) {
            int p; cin >> p;
            child[p].push_back(i);
        }

        auto idOf = [&](char ch)->int {
            if (ch == 'T') return 0;
            if (ch == 'J') return 1;
            return 2; // 'V'
        };

        // Build a postorder
        vector<int> order; order.reserve(N);
        {
            vector<int> st = {1};
            while (!st.empty()) {
                int u = st.back(); st.pop_back();
                order.push_back(u);
                for (int v : child[u]) st.push_back(v);
            }
        }

        // Subtree color counts
        vector<array<int,3>> sub(N + 1, {0,0,0});
        for (int i = (int)order.size() - 1; i >= 0; --i) {
            int u = order[i];
            array<int,3> acc{0,0,0};
            for (int v : child[u]) {
                acc[0] += sub[v][0];
                acc[1] += sub[v][1];
                acc[2] += sub[v][2];
            }
            acc[idOf(S[u-1])]++; // the node itself
            sub[u] = acc;
        }

        array<int,3> tot = sub[1];

        // Map ordered color pairs (a != b) to indices 0..5
        int pairIdx[3][3];
        for (int a=0;a<3;a++) for (int b=0;b<3;b++) pairIdx[a][b] = -1;
        int idx = 0;
        for (int a=0;a<3;a++) for (int b=0;b<3;b++) if (a!=b) pairIdx[a][b] = idx++;

        const int P = 6;
        vector<vector<int>> base(P, vector<int>(N + 1, NEG));
        for (int a=0;a<3;a++) for (int b=0;b<3;b++) if (a!=b) {
            int p = pairIdx[a][b];
            for (int u=2; u<=N; ++u) { // edge above root doesn't exist
                base[p][u] = sub[u][a] - sub[u][b];
            }
        }

        // best[u;p] = max base[v;p] over v in subtree(u) (including v=u if u!=1)
        // childBest[u;p] = max best[child;p] over children (proper descendants only)
        vector<vector<int>> best(P, vector<int>(N + 1, NEG));
        vector<vector<int>> childBest(P, vector<int>(N + 1, NEG));
        for (int p=0; p<P; ++p) {
            for (int i = (int)order.size() - 1; i >= 0; --i) {
                int u = order[i];
                int cm = NEG;
                for (int v : child[u]) cm = max(cm, best[p][v]);
                childBest[p][u] = cm;
                best[p][u] = max(base[p][u], cm);
            }
        }

        // 0 cuts
        int keep0 = max({tot[0], tot[1], tot[2]});

        // 1 cut
        int keep1 = 0;
        for (int a=0;a<3;a++) for (int b=0;b<3;b++) if (a!=b) {
            int p = pairIdx[a][b];
            int mx = NEG;
            for (int u=2; u<=N; ++u) mx = max(mx, base[p][u]);
            if (mx > NEG) keep1 = max(keep1, tot[b] + mx);
        }

        int bestKeep = max(keep0, keep1);

        // 2 cuts (3 blocks): evaluate both disjoint and nested for all permutations
        vector<int> colors = {0,1,2};
        int keep2 = NEG;

        auto upd_disjoint = [&](int c1, int c2, int c3) {
            int p1 = pairIdx[c1][c3];
            int p2 = pairIdx[c2][c3];
            int bestAll = NEG;

            for (int u = 1; u <= N; ++u) {
                // gather top/second over children for p1 and p2
                int m1a = NEG, m1b = NEG; int i1 = -1;
                int m2a = NEG, m2b = NEG; int i2 = -1;
                for (int v : child[u]) {
                    int x1 = best[p1][v];
                    if (x1 > m1a) { m1b = m1a; m1a = x1; i1 = v; }
                    else if (x1 > m1b) m1b = x1;

                    int x2 = best[p2][v];
                    if (x2 > m2a) { m2b = m2a; m2a = x2; i2 = v; }
                    else if (x2 > m2b) m2b = x2;
                }
                int pairSum = NEG;
                if (i1 != -1 && i2 != -1) {
                    if (i1 != i2) {
                        pairSum = m1a + m2a;
                    } else {
                        if (m2b > NEG) pairSum = max(pairSum, m1a + m2b);
                        if (m1b > NEG) pairSum = max(pairSum, m1b + m2a);
                    }
                }
                if (pairSum > NEG) bestAll = max(bestAll, tot[c3] + pairSum);
            }
            return bestAll;
        };

        auto upd_nested = [&](int c1, int c2, int c3) {
            int pA = pairIdx[c2][c3];
            int pD = pairIdx[c1][c2];
            int bestAll = NEG;
            for (int a = 2; a <= N; ++a) { // ancestor cut cannot be at root
                int vA = base[pA][a];
                int deep = childBest[pD][a];
                if (vA > NEG && deep > NEG) {
                    bestAll = max(bestAll, tot[c3] + vA + deep);
                }
            }
            return bestAll;
        };

        sort(colors.begin(), colors.end());
        do {
            int c1 = colors[0], c2 = colors[1], c3 = colors[2];
            int d = upd_disjoint(c1, c2, c3);
            int nst = upd_nested(c1, c2, c3);
            keep2 = max(keep2, max(d, nst));
        } while (next_permutation(colors.begin(), colors.end()));

        if (keep2 > NEG) bestKeep = max(bestKeep, keep2);

        cout << (N - bestKeep) << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;
int SN;
vec<int> seg;
void upd(int p, int v) {
    seg[p + SN] = v;
    for (p = (p + SN) / 2; p > 0; p /= 2) {
        seg[p] = max(seg[2 * p], seg[2 * p + 1]);
    }
}
int qry(int l, int r) {
    int res = 0;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res = max(res, seg[l++]); }
        if (r & 1) { res = max(res, seg[--r]); }
    }
    return res;
}

bool cmp(arr<int, 3> a1, arr<int, 3> a2) { return a1[1] < a2[1]; }
bool cmp2(arr<int, 2> a1, arr<int, 2> a2) {
    if (a1[0] == a2[0]) { return a1[1] > a2[1]; }
    return a1[0] < a2[0];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vec<arr<int, 2>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i][0];
        A[i][1] = i;
    }
    sort(A.begin(), A.end(), cmp2);

    SN = N;
    seg.resize(2 * SN);
    
    vec<arr<int, 3>> queries(Q);
    for (int q = 0; q < Q; q++) {
        int r, x; cin >> r >> x;
        queries[q] = {r, x, q};
    }
    sort(queries.begin(), queries.end(), cmp);

    vec<int> ans(Q);
    int i = 0;
    for (int q = 0; q < Q; q++) {
        auto [r, x, qq] = queries[q];
        while (i < N && A[i][0] <= x) {
            auto [v, p] = A[i];
            int lis = qry(0, p);
            upd(p, lis+1);
            i++;
        }
        ans[qq] = qry(0, r);
    }

    for (int q = 0; q < Q; q++) {
        cout << ans[q] << "\n";
    }
}
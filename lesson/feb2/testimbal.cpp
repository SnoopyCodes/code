#include <bits/stdc++.h>

using namespace std;

stringstream in;

namespace mine {

#define long int64_t

long cnt(vector<int> &v) {  //# of subarrays where this value doesn't appear
    if (v.empty()) { return 0; }
    long res = (long) (v[0]) * (v[0] + 1) / 2;
    for (int i = 0; i < v.size() - 1; i++) {
        int d = v[i + 1] - v[i];
        res += (long) d * (d - 1) / 2;
    }
    return res;
}

long solve() {
    int N; in >> N;
    vector<vector<int>> appear(1e6 + 1);
    for (int i = 0; i < N; i++) {
        int x; in >> x; appear[x].push_back(i);
    }
    long ans = (long) -N * (N + 1) / 2;
    for (int i = 1; i <= 1e6 ; i++) {
        vector<int> cur = appear[i - 1];
        cur.push_back(N);
        ans += cnt(cur);
        for (int x : appear[i]) {
            cur.push_back(x);
        }
        sort(cur.begin(), cur.end());
        ans -= cnt(cur);
    }
    return ans;
}

}
namespace other {

    #define long int64_t
long solve() {
    int N; in >> N;
    vector<int> A(N);
    vector<queue<int>> qs(N + 2);
    for (int i = 0; i < N; i++) {
        in >> A[i];
        qs[A[i]].push(i);
    }
    for (int i = 1; i <= N + 1; i++) {
        qs[i].push(N);
    }
    vector<int> cl(N), cr(N);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < N; i++) {
        while (st.top() != -1 && A[st.top()] < A[i]) { st.pop(); }
        cl[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) { st.pop(); }
    st.push(N);
    for (int i = N - 1; i > -1; i--) {
        while (st.top() != N && A[st.top()] <= A[i]) { st.pop(); }
        cr[i] = st.top();
        st.push(i);
    }
    //we know where it is max.
    //num subarrays where it does not find A[i] + 1 - num subarrays where it is max
    long ans = 0;
    map<int, int> last;
    for (int i = 0; i < N; i++) {
        qs[A[i]].pop();
        int l;
        int r = min(qs[A[i] + 1].front(), qs[A[i]].front());
        if (!last.count(A[i] + 1)) {
            l = -1;
        }   else {
            l = last[A[i] + 1];
        }
        ans += (long) (i - l) * (r - i);
        ans -= (long) (i - cl[i]) * (cr[i] - i);
        // cout << l << " " << r << "\n";
        // cout << cl[i] << " " << cr[i] << "\n";
        // cout << ans << "\n";
        // cout << "\n";
        last[A[i]] = i;
    }
    return ans;
}

}
#define long int64_t
int main() {
    cin.tie(0) ->sync_with_stdio(0);
    int T = 10;
    int t = 0;
    while (t < T) {
        int N = 100000;
        vector<int> G(N);
        for (int i = 0; i < N; i++) {
            int x = rand() % N + 1;
            G[i] = x;
        }
        G = {4,2, 1, 3};
        in << N << "\n";
        for (int i = 0; i < N; i++) {
            in << G[i] << " ";
        }
        long r1 = mine::solve();
        in << N << "\n";
        for (int i = 0; i < N; i++) {
            in << G[i] << " ";
        }
        long r2 = other::solve();
        if (r1 != r2) {
            // cout << N << "\n";
            // for (int i = 0; i < N; i++) {
            //     cout << G[i] << " ";
            // }
            // cout << "\n";
            cout << r1 << "\n";
            cout << r2 << "\n";
            break;
        }
        t++;
    }
    if (t == T) { cout << "YAY" << "\n"; }
    else { cout << "BRUH" << "\n"; }
}
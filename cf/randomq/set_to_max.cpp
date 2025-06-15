#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

void solve() {
    int N; std::cin >> N;
    vector<int> A(N), B(N + 1, N + 1);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--;
    }
    bool bad = false;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        B[i]--;
        if (A[i] > B[i]) { bad = true; }
    }
    if (bad) { std::cout << "no" << "\n"; return; }
    vector<int> la(N, -1), lb(N, -1), ra(N, N), rb(N, N);
    for (int i = 1; i < N; i++) {
        int j = i - 1;
        if (A[j] <= A[i]) while (j != -1 && A[j] <= A[i]) { j = la[j]; }
        la[i] = j;
        j = i - 1;
        if (B[j] >= B[i]) while (j != -1 && B[j] >= B[i]) { j = lb[j]; }
        lb[i] = j;

        i = N - i - 1;
        j = i + 1;
        if (A[j] <= A[i]) while (j != N && A[j] <= A[i]) { j = ra[j]; }
        ra[i] = j;
        j = i + 1;
        if (B[j] >= B[i]) while (j != N && B[j] >= B[i]) { j = rb[j]; }
        rb[i] = j;
        i = N - i - 1;
    }
    bool ok = true;
    vector<int> hate(N, -1), myself(N, -1);
    for (int i = 0; i < N; i++) {
        hate[A[i]] = i;
        bool y;
        if (hate[B[i]]) {
            //if there is no right one yet
            y |= A[i] == B[i] || 
        }

        ok |= y;
    }

    if () { std::cout << "Yes" << "\n"; }
    else { std::cout << "No" << "\n"; }

}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
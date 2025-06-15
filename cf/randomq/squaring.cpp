#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long double> log(N);
    for (int i = 0; i < N; i++) {
        log[i] = std::log10((long double) A[i]);
    }
    //convert into log2?
    //ok hold on
    //this will probably not work.
    //we are holding the log2 representation
    long double max_log = 0;
    long double count = 0;
    bool one = false;
    for (int i = 0; i < N; i++) {
        if (log[i] < max_log) {
            if (log[i] == 0) { one = true; break; }
            count += std::ceil(std::log2(max_log/log[i]));
            max_log = log[i] * std::pow((long double) 2, std::ceil(std::log2(max_log/log[i])));
        }   else {
            max_log = log[i];
        }
    }
    if (one) { cout << -1 << "\n"; }
    else { cout << count << "\n"; }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
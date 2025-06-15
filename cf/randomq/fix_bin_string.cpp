#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout;

void solve() {
    int N, K; cin >> N >> K;
    vector<bool> string(N);
    vector<int> sections;
    std::string x; cin >> x;
    int cur = 0, ct = 0;
    int prev = -1;
    for (int i = 0; i < N; i++) {
        string[i] = x[i] == '1';
        if (prev == string[i] || prev == -1) {
            cur++;
        }   else {
            sections.push_back(cur);
            if (cur != K) { ct++; }
            cur = 1;
        }
        prev = string[i];
    }
    if (cur != K) { ct++; }
    sections.push_back(cur);

    if (ct == 0) {
        cout << N << "\n";
    }   else if (ct == 1) {
        int ind = max_element(sections.begin(), sections.end()) - sections.begin();
        if (ind % 2 == (sections.size() - 1) % 2) {
            cout << (ind + 1) * K << "\n";
        }   else {
            cout << -1 << "\n";
        }
    }   else if (ct == 2) {
        int min_ind = -1;
        int max_ind = -1;
        vector<int> diff;
        for (int i = 0; i < sections.size(); i++) {
            if (sections[i] != K) {
                diff.push_back(i);
            }
        }
        if (sections[diff[0]] < sections[diff[1]]) { min_ind = diff[0]; max_ind = diff[1]; }
        else { min_ind = diff[1]; max_ind = diff[0]; }
        // cout << min_ind << " " << max_ind << "\n";
        if (min_ind < max_ind) {
            if (max_ind != sections.size() - 1 || min_ind % 2 != max_ind % 2 || min_ind % 2 != 0) {
                cout << -1 << "\n";
            }   else {
                cout << min_ind * K + sections[min_ind] << "\n";
            }
        }   else {
            if (min_ind != sections.size() - 1 || min_ind % 2 != max_ind % 2) {
                cout << -1 << "\n";
            }   else {
                cout << max_ind * K + K - sections[min_ind] << "\n";
            }
        }
    }   else {
        cout << -1 << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
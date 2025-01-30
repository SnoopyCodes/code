#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    //two ways to solve: one with monotonic stack, and one with dnc
    //i should definitely implement a dnc approach soon the idea is very applicable
    vector<int> cl(N), cr(N);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < N; i++) {
        
    }
}
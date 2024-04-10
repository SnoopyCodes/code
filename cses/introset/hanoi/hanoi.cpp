#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    //okay very interesting
    stack<int> one;
    stack<int> two;
    stack<int> three;
    for (int i = 0; i < N+1; i++) {
        one.push(i);
    }
    two.push(0);
    three.push(0);
    vector<array<int, 2>> instruct;
    if (N == 1) {
        cout << 1 << "\n" << "1 3" << "\n";
        return 0;
    }   else if (N == 2) {
        cout << 3 << "\n";
        cout << "1 2" << "\n" << "1 3" << "\n" << "2 3" << "\n";
    }
    //okay so always put the next bottom on 3 i think keeps it simple
    //
    for (int i = 0; i < N; i++) {

    }
}
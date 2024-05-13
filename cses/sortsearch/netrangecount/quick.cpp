#include <bits/stdc++.h>

using namespace std;
struct range {
    int s, e, i;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> open;
    vector<int> close;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        open.push_back(a);
        close.push_back(b);
    }
    //we need to reorder everything
    //turn the open and close into a map tbh
    //
    sort(open.begin(), open.end());
    sort(close.begin(), close.end());
    int op = 0;
    vector<int> contains(N);
    vector<int> contained(N);
    map<int, int> closed; //openindex, morethan
    priority_queue<array<int, 2>> opened;  //closetime, index
    for (int i = 0; i < N; i++) {  //for every close
        while (op != N && open[op] <= close[i]) {

        }
    }
    for (int i = 0; i < N; i++) {
        cout << contains[i];
        if (i != N - 1) { cout << " "; }
    }
    cout << "\n";
    for (int i = 0;i  < N; i++) {
        cout << contained[i];
        if (i != N - 1) { cout << " "; }
    }
}
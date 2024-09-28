#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //can we not move left, move right?
    //this is a really boring constructive i think
    int N; cin >> N;
    vector<int> A(N);
    int dist = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        dist += A[i];
    }
    bool right = true;
    int i = 0;
    string s = "";
    while (dist > 0) {
        //if we are right, we are on i
        //so first if A[i].5 > 2 we keep moving right
        //if we reach N-1.5 then 
        if (right) {
            if (i < N && A[i] > 1 || ((i == 0 || A[i-1] == 0) && A[i] == 1)) {
                A[i]--;
                i++;
                s += 'R';
            }   else {
                right = false;
                dist++;
            }
        }   else {
            if (i > 0 && A[i-1] > 1 || ((i == N || A[i] == 0) && A[i-1] == 1)) {
                A[i-1]--;
                i--;
                s += 'L';
            }   else {
                right = true;
                dist++;
            }
        }
        dist--;
    }
    cout << s << "\n";

}
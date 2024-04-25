#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    map<int, array<int, 2>> last;  //last occurrence of x, times happened
    vector<int> prev(N+1);
    int begin = 1;  //if less than it ignore
    int cur = 0;
    ll amt = 0;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        prev[i] = x;
        if (last[x][0] < begin) { cur++; }  //not in our sequence
        if (cur > K) {
            //cut off the previous one that isnt working
            //find the next one that is working
            int li = last[prev[begin]][0];
            while (cur > K) {
                last[prev[begin]][1]--;
                if (last[prev[begin]][1] == 0) { cur--; }
                begin++;
            }
        }
        amt += i - begin + 1;
        
        last[x][0] = i;
        last[x][1]++;
    }
    cout << amt << "\n";
}
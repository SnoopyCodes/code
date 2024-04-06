#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int, int>> moves;  //first is cost of taking even, second is cost of taking odd
vector<ll> sfx;  //gives the sum to end not including this index
void solve() {
    int N, M, K; cin >> N >> M >> K;
    moves.clear();
    sfx.clear();
    moves.resize(M);
    sfx.resize(M);
    int cur = 0;
    bool valid = true;
    for (int i = 0; i < M; i++) {
        moves[i].first = 0, moves[i].second = 0;
        int me = INT_MAX, mo = INT_MAX;
        for (int j = 0; j < K; j++) {
            int x; cin >> x;
            if (x % 2 == 0) { moves[i].second = max(moves[i].second, x); me = min(me, x); }
            else { moves[i].first = max(moves[i].first, x); mo = min(mo, x); }
        }
        if (moves[i].first == 0) { moves[i].first = -me; }  //if there is no odd ones (bc there is no first) then taking even gives smallest odd
        else if (moves[i].second == 0) { moves[i].second = -mo; }
        cur += min(moves[i].first, moves[i].second);  //如果最小在偶数，选奇数因为这会损失最小数的球
        if (cur >= N) { valid = false; }
    }
    if (!valid) { cout << -1 << "\n"; return; }
    int largesum = 0;
    cur = 0;
    for (int i = M-2; i >= 0; i--) {
        int a = min(moves[i+1].first, moves[i+1].second);  //the thing to add
        //for each index find the minimum max sum from here on out
        cur += a;
        largesum += a;
        largesum = max(cur, largesum);
        sfx[i] = largesum;
        if (cur < 0) { cur = 0; }
    }
    cur = 0;
    for (int i = 0; i < M; i++) {
        if (sfx[i] + cur + moves[i].first < N && cur + moves[i].first < N) {  //如果我们用最好的方式打，从现在没事儿
            cout << "Even";
            if (i != M-1) { cout << " "; }
            cur += moves[i].first;
        }   else {
            cout << "Odd";
            if (i != M-1) { cout << " "; }
            cur += moves[i].second;
        }
    }
    cout << "\n";
    //alright now what
    //先确定E不会输--选最小的可能.如果超越N，就会输。
    //回头如果要改选择就可以用前缀和或者后缀和找到最大能让的
    //每一轮我们只管最大或小的偶数和奇数。
    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T) { T--; solve(); }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, M, K;
vector<map<int, int>> dp;  //stores the tower size and how many towers it has, and then the next highest, then the next, and so on
map<int, int> m;
void see(int x) {  //bs for next towers, then add your own on to it
    int s = x, e = N;
    while (e > s - 1) {
        int mid = (s + e) / 2;
        if (m[mid] >= K + m[x]) { e = mid+1; }
        else { s = mid; }
        //hope s works
    }
    if (m[s] < K + m[x]) { //notsob this is the easiest part
        dp[x][1] = m[x];
    }   else {  //add to the highest tower, and take the remainders into a second
        map<int, int> thing = dp[s];
        auto &it = (thing.rbegin());
        while (m[x] != 0) {
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //first take a graph as an exapmle
    //draw edges from distinct weights to other distinct weights where they are K away
    //what is optimal? this is greedy
    //stick as many cows on the first as possible, then next, and so on
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a *= -1;
        m[a] = b;
    }
    ll total = 0;  //might overflow?
    for (int i = N - 1; i >= 0; i--) {
        see(i);
    }

    for (auto &x : dp[0]) {
        
    }
    
    
}
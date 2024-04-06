#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*Given an array containing integers only 0s and 1s, find the maximum length of any subarray that has an equal number of 0s and 1s.

Input (from terminal / stdin)
The first line contains integer N, 1<=N<=1e5.
The second line contains the N integers 0s and 1s.

Output (to terminal / stdout)
Report the maximum length of any subarray containing the same number of 0s and 1s.

Sample input
5
1 1 0 1 0

Sample output
4*/
vector<ll> v;
vector<ll> zeros;
vector<ll> ones;
vector<ll> diff;
struct troll {
    bool visited;
    int small, large;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int N; cin >> N;
    v.resize(N); zeros.resize(N+1); ones.resize(N+1);
    diff.resize(N+1);
    map<int, troll> m; //value, visited, min, max
    m[0] = {true, -1, -1};  //will always start at 0
    for (int i = 0; i < N; i++) { cin >> v[i]; }
    for (int i = 0; i < N; i++) {
        zeros[i+1] = zeros[i] + (v[i] == 0);
        ones[i+1] = ones[i] + (v[i] == 1);
        diff[i+1] = ones[i+1] - zeros[i+1];
        if (m[diff[i+1]].visited) {
            m[diff[i+1]].large = i;    
        }   else {
            m[diff[i+1]].visited = true;
            m[diff[i+1]].small = i;
            m[diff[i+1]].large = i;
        }
    }
    int longest = 0;
    for (auto &p : m) {
        //choose 2
        //if (p.first == 0) { c += p.second; }
        longest = max(longest, p.second.large - p.second.small);
        //cout << p.second.large << " " << p.second.small << "\n";
    }
    //wait im not thinking
    //across all subarrays stupid
    //omg
    //find the number of arrays where zeros[i] - zeros[x] = ones[i] - ones[x]
    //so where the difference between the ones and zeros are the same
    cout << longest << "\n";
}
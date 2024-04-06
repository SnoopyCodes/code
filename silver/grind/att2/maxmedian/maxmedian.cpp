#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int N, K;
bool valid(int x) {
    //find subarray length K with the largest median
    //does adding elements to it ever help? yea, but our goal is only to check if there is a valid array lenght k where 
    //# elements >= x > K/2
    //create a pfx array based on whether index i >= x
    //next we need to find indexes i and j such that pfx[i] - pfx[j-1] > K/2
    //okay they used a stupid function based also on greater or less
    vector<int> f(N);
    int more = 0, less = 0;
    	for (int i = 0; i < N; i++) {
			/*
			 * If a[i] is greater than or equal to the median, it
			 * contributes 1 to f(i) Otherwise if it less than the median,
			 * it contributes -1 to f(i)
			 */
            if (v[i] >= x) { more++; }
            else {less++; }
            f[i] = more - less;
		}

    //now iterate through it and keep track of the lowest f value
    int least = 0;
    for (int i = K-1; i < N; i++) {
        least = min(least, f[i-K]);
        if (f[i] - least > 0) { return true; }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //just binary search on the median
    int s = 1, e = N;
    while (e > s + 1) {
        int m = (s + e) / 2;
        if (valid(m)) { s = m; }
        else { e = m; }
    }
    cout << s;
}
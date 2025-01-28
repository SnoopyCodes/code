/*
 * Replace chalk
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("in.txt", "r", stdin);
	int N;
	ll K;
	cin >> N >> K;
	vector<int> C(N);
	for(int j=0; j<N; j++)
		cin >> C[j];

    K %= accumulate(begin(C), end(C), 0LL);
	int ans = -1;
    for(int i=0; i<N; i++)
        if((K -= C[i]) < 0) {
            ans = i;
            break;
		}

	cout << ans << '\n';
	return 0;
}


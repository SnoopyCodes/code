//### Beauty sum II

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N; //num of integers
	
	int A[N];
	for(int j=0; j<N; j++)
		cin >> A[j];
	
	//prefix max and suffix min
	int prefix[N], suffix[N];
	prefix[0] = A[0];
	suffix[N-1] = A[N-1];
	
	for(int j=1; j<N; j++)
		prefix[j] = max(prefix[j-1], A[j]);
		
	for(int j=N-2; j>=0; j--)
		suffix[j] = min(suffix[j+1], A[j]);
	
	int ans = 0; //beauty sum
	for(int j=1; j<N-1; j++) {
		if(A[j]>prefix[j-1] && A[j]<suffix[j+1])
			ans += 2;
		else if(A[j]>A[j-1] && A[j]<A[j+1])
			ans += 1;		
	}
	
	cout << ans << '\n';
	return 0;
}


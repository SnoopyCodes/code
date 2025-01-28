//### K-th smallest fraction

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, K; 
	cin >> n >> K; //num of integers in A and K-th smallest fraction
	int A[n];
	for(int j=0; j<n; j++)
		cin >> A[j];
		
    double left = 0, right = 1;
    int p = 0, q = 1; //p/q is the K-th smallest fraction
	int cnt = 0;  //num of fractions obtained that are <= threshold

    while(true) {
        double mid = (right + left) / 2.0; //threshold
        cnt = 0; 
		p = 0; q = 1;
        for(int i=0, j=0; i<n; i++) {
            while(j<n && A[i] > mid*A[j]) 
				j++;
			//j is the first index s.t. A[i]/A[j] <= mid	
			
            cnt += n - j;
            
			if(j<n && p*A[j] < q*A[i]) {
                p = A[i]; //p/q is the largest fraction <= mid
                q = A[j];
            }
        }
	    if(cnt == K) 
			break;
        if(cnt < K) 
			left = mid;
        else 
			right = mid;
    }
	cout << p*100000LL+q << '\n';
	return 0;
}


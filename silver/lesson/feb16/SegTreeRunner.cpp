/*
 * Test the segment tree implementation for range sum, max, and min.
 */
#include <bits/stdc++.h>
#include "SegmentTreeMax.h"
#include "SegmentTreeMin.h"
#include "SegmentTreeSum.h"

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;

	int A[N]; //original array
	for(int j=0; j<N; j++)
		cin >> A[j];
	
	SegmentTreeMax st1(N);
	SegmentTreeMin st2(N);
	SegmentTreeSum st3(N);
	
	st1.buildSegTree(A);
	st2.buildSegTree(A);
	st3.buildSegTree(A);
	
	for(int j=0; j<Q; j++) {   //process the queries
		int pos, val;
		cin >> pos >> val;

		st1.addValue(pos, val);
		st2.addValue(pos, val);
		st3.addValue(pos, val);

		int x, y;
		cin >> x >> y;
		
		int mx = st1.query(x, y);
		int mn = st2.query(x, y);
		int sm = st3.query(x, y);

		cout << mx << " " << mn << " " << sm << '\n';
	}
	return 0;
}


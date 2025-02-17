/*
 * Segment tree for the maximum value between two positions of an array.
 * (Range max)
 */
#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeMax {
	int n; //length of underlying array (0-indexed)
	vector<int> tree; //array for the segment tree (0-indexed)

	SegmentTreeMax(int _n) {
		n = _n;
		tree.resize(4*n, 0);
	}
	
	//query on the original array a[x...y]
	int query(int x, int y) {
		return query(x, y, 1, 0, n-1);
	}
	
	int query(int x, int y, int p, int low, int high) {
		if(x>y) return INT_MIN/2;
		if(low>=x && high<=y) return tree[p];
		
		int mid = (low+high)/2;
		int left = query(x, min(y, mid), p*2, low, mid);
		int right = query(max(x, mid+1), y, p*2+1, mid+1, high);
		return max(left, right);
	}
	
	//add v at position x
	void addValue(int x, int v) {
		addValue(x, v, 1, 0, n-1);
	}
	
	void addValue(int x, int v, int p, int low, int high) {
		if(low==high) {
			tree[p]+=v; 
			return; 
		}
		
		int mid = (low+high)/2;
		if(x<=mid) 
			addValue(x, v, p*2, low, mid);
		else 
			addValue(x, v, p*2+1, mid+1, high);
	
		tree[p] = max(tree[p*2], tree[p*2+1]);
	}
	
	void buildSegTree(int A[]) {
		for(int j=0; j<n; j++)
			addValue(j, A[j]);
	}
};

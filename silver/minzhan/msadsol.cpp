//### Min sum absolute difference

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("in.txt", "r", stdin);
	int n; cin >> n;
	vector<ll> nums1(n), nums2(n);
	
	for(int j=0; j<n; j++)
		cin >> nums1[j];
		
	for(int j=0; j<n; j++)
		cin >> nums2[j];

    ll ans = 0;
    ll gain = 0;
    set<ll> s(begin(nums1), end(nums1));

    for(int i=0; i<n; i++) {
      	ll diff = abs(nums1[i] - nums2[i]);
      	ans += diff;
      	if(diff <= gain) continue;

      	auto it = s.lower_bound(nums2[i]);      
      	if(it != s.end()) 
        	gain = max(gain, diff - abs(*it - nums2[i]));
      	
		if(it != s.begin()) 
        	gain = max(gain, diff - abs(*prev(it) - nums2[i])); 
    }
    cout << (ans-gain) % MOD << '\n';
    return 0;
}

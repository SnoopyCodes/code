#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

vector<int> seg;
int SN;
int hasv;
int query(int p) {
    int res = 0;
    if (p < 0) { return hasv; }
    for (p = p + SN; p > 0; p /= 2) {
        res = max(res, seg[p]);
    }
    return res;
}
void alter(int l, int r, int val) {
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            seg[l] = max(val, seg[l]);
            l++;
        }
        if (r & 1) {
            r--;
            seg[r] = max(val, seg[r]);
        }
    }
}

const int B = 256;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vec<int> vote(N);
    vec<int> cnt(N);
    rep(i, N) {
        cin >> vote[i]; vote[i]--;
        cnt[vote[i]]++;
    }
    //search to the RIGHT for the RIGHTMOST element >= MAXVOTES - x
    //what the problem is asking is: find the pair of elements with 
    //sum of cnts >= MAX where none are 0, with greatest distance
    //between them
    //now update a value.
    //this affects nothing if there is an index to the right of it
    //and it is larger.
    //however, if it is actually now larger than any to the right
    //is this dsu?
    //hold on no way
    //wait desperation 
    //BATCH PROCESSING
    //BATCH BY sqrt(N)
    //query right and left
    //for each of the left and right, query
    //make it distance based?
    //no grpah problems :(
    //what if we just did the normal thing?
    //we might be stupid i think that literally works
    //
    SN = N;
    rep(q, Q) {
        int i, x; cin >> i >> x; i--; x--;
        cnt[vote[i]]--;
        vote[i] = x;
        cnt[vote[i]]++;
        int most = *max_element(cnt.begin(), cnt.end());
        if (most == N) { cout << 0 << "\n"; continue; }
        int ans = 0;
        hasv = -1;

        seg.clear(); seg.resize(2 * SN);
        rep(i, -N) {
            if (cnt[i] == 0) { continue; }
            if (hasv == -1) { hasv = i; }
            int f = query(most - cnt[i] - 1);
            ans = max(f - i, ans);
            alter(0, cnt[i], i);
        }
        cout << ans << "\n";
    }
}
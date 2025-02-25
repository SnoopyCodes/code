#include <bits/stdc++.h>

#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

using namespace std;

#define long int64_t

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    //wtf
    //basically largest subsequence
    //wait this isnt even sequence reversal tysm
    //is this just lazy sparse segtree
    //we need a specific length
    //chat.. is this real..
    //we want to stick as many 1's in front as we can
    //without running out of space
    //we can skip some number of 0's
    //call it "leeway"
    //we query for the left half first.
    //it will return some value and some remaining "leeway", if there is any
    //this problem.. is boring af and just annoying
    //lowkey segtree is cool i just don't really like segtree problems yeah
    //ok there is definitely an offline way but what is the offline way
    //store a set with segments alternating parities of lengths, iset is ok
    //it is impossible to iterate over segments manually to find what to "skip"
    //square root decomp *sigh*
    //idek which ones better
    multiset<arr<int, 2>> ms;
    ms.insert({0, N});
    rep(m, M) {
        int l, r; cin >> l >> r; l--; r--;
        //find where the left bound falls
        //c'est la depression
        auto lb = (*(--ms.upper_bound({l, 0})));
        auto rb = (*(--ms.upper_bound({r, 0})));
        if (lb == rb) {
            //split this one
            ms.erase(lb);
            if (l != lb[0])
            ms.insert({lb[0], l - lb[0]});
            ms.insert({l, r - l + 1});
            ms.insert({r, lb[0] + lb[1] - r});
        }   else {
            //we split it into 4??
        }
    }
    cout << "\n";
    for (auto const&[l, len] : ms) {
        cout << l << " " << len << "\n";
    }
    
}
#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string heard; cin >> heard;
    int N = heard.size();
    map<char, int> m;
    rep(i, N) {
        if (!m.count(heard[i])) {
            m[heard[i]] = m.size();
        }
    }
    int B = m.size();
    vec<int> hum(N);
    vec<map<int, int>> before(B);
    rep(i, N) {
        hum[i] = m[heard[i]];
        if (i > 0) {
            before[hum[i]][hum[i-1]]++;
        }
    }

    vec<int> best(1 << B, N);
    best[0] = 0;
    rep(mask, 1 << B) {
        rep(b, B) {
            if (mask & 1 << b) { continue; }
            int amt = 0;
            rep(bef, B) {
                if (mask & 1 << bef) { continue; }
                amt += before[b][bef];
            }
            best[mask | 1 << b] = min(best[mask | 1 << b], best[mask] + amt);
        }
    }
    cout << best[(1 << B) - 1] + 1 << "\n";
}
/*
okay lets just skip the subtask i guess
we have 20 possible letters
1e5 thing
a simple upper bound is # of appearances of a letter inside there

eee
effe however makes it more?
mhm
consider the interaction between two characters:
a, b
we can try "building" the string. start with a certain character, suppose a.
then, we can try adding each alphabet letter. we can "build." so start with character
and add a character DIRECTLY afterwards. then, for all instances of this character, we want to add to a subsequence, if it exists already. and we can do this very easily! if the character before us is in the subsequence already, then we are OK!
LETS FREAKING GO CHAT I FEEL SO GOOD
precomp for each character a set of those that appears right before it
N^2 * 2^N...
*/
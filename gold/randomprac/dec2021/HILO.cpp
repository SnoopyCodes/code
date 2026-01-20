#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    cout << 0 << "\n";
    vt<int> p(N), ind(N);
    rep(i, 0, N) {
        cin >> p[i], p[i]--, ind[p[i]] = i;
    }
    //find for each value the first value larger with a smaller ind
    //because when both are LO, it turns off.
    vt<int> first(N, N);
    vt<int> bruh(N, -1);
    vt<vt<int>> del(N + 1);
    for (int i = N - 1; i > -1; i--) {
        int j = i + 1;
        while (j < N && ind[i] < ind[j]) {
            j = first[j];
        }
        first[i] = j;
        del[j].add(i);
    }
    vt<vt<int>> add(N + 1);
    rep(i, 1, N) { //closest lesser value
        int j = i - 1;
        while (j > -1 && p[i] < p[j]) {
            j = bruh[j];
        }
        bruh[i] = j;
        // cout << i << " " << j << "\n";
        if (j != -1) add[j].add(i);
    }
    vt<int> state(N, 1);
    vt<int> on(N);
    set<int> hilo;
    rep(i, 0, N) {
        if (bruh[i] == -1) {
            hilo.insert(i);
            // cout << i << " ";
        }
    }
    // cout << "\n";
    int ans = 0;
    rep(i, 0, N) {
        //things to consider: in front of us, is there a HI?
        assert(hilo.find(ind[i]) != end(hilo));
        auto it = hilo.find(ind[i]);
        if (it-- != begin(hilo)) {
            auto k = *it;
            if (state[k] == 1) {
                ans -= on[k];
                on[k] = 1; //this guy is locked in (hes the hi to our lo)
                ans += on[k];
            }
        }

        state[ind[i]] = 0;
        ans -= on[ind[i]];
        on[ind[i]] = 0;

        for (int j : add[ind[i]]) {
            int x = p[j];
            //what's important? if we add amidst a HILO, then
            //update HI, update ourselves.
            //if we add into LO, then update ourselves
            // cout << "inserting " << x << endl;
            auto it = hilo.insert(j).first;
            if (++it != end(hilo)) {
                int k = *it;
                if (state[k] == 0) {
                    ans -= on[j];
                    on[j] = 1;
                    ans += on[j];
                    if ((--it)-- != begin(hilo)) {
                        k = *it;
                        if (state[k] == 1) {
                            ans -= on[k];
                            on[k] = 0;
                        }
                    }
                }
            }
        }

        for (int j : del[i]) {
            //we are deleting value j remember
            // cout << "deleting " << j << "\n";
            
            it = hilo.find(ind[j]);
            assert(it != end(hilo));
            //if one in front is hi and behind is lo, do nothing
            //if one in front is hi and behind is hi/nothing, update front
            //if in front is lo, do nothing
            if (it-- != begin(hilo)) {
                auto k = *it;
                if (state[k] != 0) {
                    if (++++it != end(hilo)) {
                        auto l = *it;
                        //this is indeed happening
                        if (state[l] == 1) {
                            ans -= on[k];
                            on[k] = 0;
                        }
                    }   else {
                        ans -= on[k];
                        on[k] = 0;
                    }
                }
            }
            hilo.erase(ind[j]);
        }
        // cout << "round " << i+1 << "\n";
        // cout << "HILO: ";
        // for (int x : hilo) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        
        cout << ans << "\n";
    }
}
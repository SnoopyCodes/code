#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
    template<class...A> mt(int n = 0, A... r) : vt<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vt<T> {
    mt(int n = 0, const T &def = T()) : vt<T>(n, def) {} };

void solve() {
    int N; cin >> N;
    vt<ii<3>> segs(N);

    auto cmpl = [](ii<3> a, ii<3> b) {
        return a[0] != b[0] ? a[0] < b[0]
            : a[1] != b[1] ? a[1] < b[1]
                : a[2] < b[2];
    };
    auto cmpr = [](ii<3> a, ii<3> b) {
        return a[1] != b[1] ? a[1] < b[1]
            : a[0] != b[0] ? a[0] < b[0]
                : a[2] < b[2];
    };

    set<ii<3>, decltype(cmpl)> sl(cmpl);
    set<ii<3>, decltype(cmpr)> sr(cmpr);

    long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> segs[i][0] >> segs[i][1];
        segs[i][2] = i;
        total += segs[i][1] - segs[i][0];
        sl.insert(segs[i]);
        sr.insert(segs[i]);
    }

    while (N > 1) {
        int i = (*sl.begin())[2];
        int j = (*--sr.end())[2];
        if (i == j) {
            int k = (*----sr.end())[2];
            int l = (*++sl.begin())[2];
            cout << i << "\n";
            cout << segs[i][0] << " " << segs[i][1] << "\n";
            cout << segs[l][0]  << " " << segs[k][1] << "\n";
            if (segs[i][1] - segs[l][0] > segs[k][1] - segs[i][0]) {
                i = l;
            }   else if (segs[i][1] - segs[l][0] < segs[k][1] - segs[i][0]) {
                j = k;
            }   else {
                //which one has the other bound more potential to be used later?
                //
                if (segs[l][1] - segs[i][0] < segs[i][1] - segs[k][0]) {
                    
                }
            }
            cout << i << " " << j << "\n";
        }
        int l = segs[i][0];
        int r = segs[j][1];
        sl.erase(segs[j]);
        sr.erase(segs[i]);
        sl.erase(segs[i]);
        sr.erase(segs[j]);
        total += r - l;
        N -= 2;
        assert(size(sl) == N && size(sr) == N);
    }
    cout << total << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
#define rep(i,a,b) for(auto i=(a); i <(b);i++)
void solve() {
    int N, M; cin >> N >> M;
    vt<int> A(N); rep(i,0,N) cin >> A[i];
    vt<int> B(M); rep(i, 0, M) cin >> B[i];
    int k = A[0];
    int ki = -1;

    ranges::sort(A);
    for (int i = N -1 ; i >-1; i--) if (A[i] == k) { ki = i; break; }
    int suff = N - ki;
    /*
    query for a certain difficulty problem, how many will solve it and Kevin doesn't
    */
    vt<int> solve(M);
    rep(i, 0, M) {
        int d = B[i];
        int first_solve = ranges::lower_bound(A, d) - begin(A);
        //with suff, first_solve - ki
        if (first_solve <= ki) {
            solve[i] = 1;
        }   else {
            solve[i] = suff - (first_solve - ki) + 1;
        }
    }
    ranges::sort(solve);
    /*
    so for a given k, the answer is B[k-1] + B[2k-1]...
    which should be brute forceable via harmonic series sum?
    */
    
    rep(kk, 1, M + 1) {
        long sum = 0;
        for (int ind = kk - 1; ind < M; ind += kk) {
            sum += solve[ind];
        }
        cout << sum << " \n"[kk == M];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}
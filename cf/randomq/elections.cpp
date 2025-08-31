#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    int N, C; cin >> N >> C;
    vt<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    //for any candidate i any other j < i and A[j] < A[i] must be excluded.
    //but also for any j < i & A[j] > A[i] they must also be excluded.
    //point 1 is incorrect.
    //for all j < i if A[j] >= A[i] they must be excluded.
    //if it is not the leftmost maximum after that, we must exclude all people to the left of it
    //if it is STILL not, simply add one.
    vt<int> suff_max(N + 1);
    for (int i = N - 1; i > -1; i--) {
        suff_max[i] = max(suff_max[i + 1], A[i]);
    }
    //we could technically bring in iset, but is there a better way?
    //investigate further.
    //for if there exist j < i where A[j] > A[i]:
    //those must be removed.
    //find a solution in O(N)
    //:skull: wait i thought undecided voted for people who are 
    //ok fine then its the prefix sum. and just add one if 
    //holy bruh its too easy
    long sum = C;
    int rmax = -1;
    #define EN " \n"[i == N - 1]
    //forgot to fight detail: if the first one gets all the votes!
    for (int i = 0; i < N; i++) {
        if (rmax < A[i] && A[i] == suff_max[i] && (i == 0 || A[0] + C < A[i])) {
            cout << 0 << EN;
        }   else {
            int ans = i;
            if (A[i] + sum >= suff_max[i]) {
                cout << ans << EN;
            }   else {
                cout << ans + 1 << EN;
            }
        }
        rmax = max(A[i], rmax);
        sum += A[i];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
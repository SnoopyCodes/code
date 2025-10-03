#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vt<int> cl(N, -1), cr(N, N); //closest left(eq) larger, right larger
    for (int i = 1; i < N; i++) {
        int j = i - 1;
        while (j != -1 && A[i] > A[j]) { j = cl[j]; }
        cl[i] = j;
    }
    for (int i = N - 2; i > -1; i--) {
        int j = i + 1;
        while (j != N && A[i] >= A[j]) { j = cr[j]; }
        cr[i] = j;
    }
    /*
    a is # of left elements, b is # of right elements.
    V is actual value.
    for i <= min(a, b):
        ans[i] += V * i
    for min(a, b) < i <= max(a, b)
        ans[i] += V * (a)
    for max(a, b) < i <= (a + b - 1):
        ans[i] += V * (a + b - 1 - i)
    */
    vt<long> sum(N + 3), mult(N + 3);
    for (int i = 0; i < N; i++) {
        int l = i - cl[i];
        int r = cr[i] - i;
        auto [minv, maxv] = minmax(l, r);

        mult[       1] += A[i];
        mult[minv + 1] -= A[i];

        sum[minv + 1] += (long) A[i] * minv;
        sum[maxv + 1] -= (long) A[i] * minv;

        int len = l + r - 1;
        sum [maxv + 1] += (long) A[i] * (len + 1);
        sum [len  + 1] -= (long) A[i] * (len + 1);
        mult[maxv + 1] -= A[i];
        mult[len  + 1] += A[i];
    }
    long cur_mult = 0, cur_sum = 0;
    for (int i = 1; i <= N; i++) {
        cur_mult += mult[i];
        cur_sum += sum[i];
        cout << i * cur_mult + cur_sum << "\n";
    }
}
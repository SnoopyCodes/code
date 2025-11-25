import java.util.*;
import java.io.*;
public class mainframe {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    Comparator<int[]> cmp = (a, b) -> {
        return a[0] != b[0] ? a[0] - b[0]
            : a[1] - b[1];
    };
    int sz, segtree[];
    void set(int i, int v) {
        segtree[i + sz] = v;
        for (i = (i + sz) / 2; i > 0; i /= 2) {
            segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
        }
    }
    int query(int l, int r) {
        int res = 0;
        for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
            if ((l & 1) != 0) { res += segtree[l++]; }
            if ((r & 1) != 0) { res += segtree[--r]; }
        }
        return res;
    }
    void solve() {
        int N = sc.nextInt(), A[][] = new int[N][2], B[][] = new int[N][2];
        for (int i = 0; i < N; i++) {
            A[i][0] = sc.nextInt() - i;
            A[i][1] = i;
        }
        sz = N;
        segtree = new int[2 * sz];
        for (int i = 0; i < N; i++) {
            B[i][0] = sc.nextInt() - i;
            B[i][1] = i;
        }
        Arrays.sort(A, cmp);
        Arrays.sort(B, cmp);
        int ord[] = new int[N];
        long ans = 0;
        for (int i = 0; i < N; i++) {
            if (A[i][0] != B[i][0]) {
                println(-1);
                return;
            }
            ord[A[i][1]] = B[i][1];
        }

        for (int i = 0; i < N; i++) {
            ans += query(ord[i], N);
            set(ord[i], 1);
        }

        println(ans);

    }
}

    public static void main(String[] args) { new beep().close(); }
    static class Scanner {
        private BufferedReader r;
        private StringTokenizer st;
        public Scanner(InputStream in) { r = new BufferedReader(new InputStreamReader(in)); }
        public String next() {
            try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) { return null; }
        }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }

}

import java.util.*;
import java.io.*;

public class ssc {
static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    void solve() {
        int N = sc.nextInt();
        int M = sc.nextInt();
        boolean[] set = new boolean[N + 1];
        long[] pref = new long[N + 1];
        ArrayList<int[]>[] C  = new ArrayList[N + 1];
        for (int i = 0; i < N + 1; i++) { C[i] = new ArrayList<>(); }
        for (int i = 0; i < M; i++) {
            int l = sc.nextInt() - 1, r = sc.nextInt(), s = sc.nextInt();
            C[l].add(new int[] { r, s });
            C[r].add(new int[] { l, -s });
        }
        boolean[] ok = { true }; //?????????????? i love java lambda

        var lambda = new Object() {
            void dfs(int u, long val) {
                set[u] = true;
                pref[u] = val;
                for (var e : C[u]) {
                    int v = e[0], s = e[1];
                    long res = pref[u] + s;
                    if (set[v] && pref[v] != res) {
                        ok[0] = false;
                    }   else if (!set[v]) {
                        dfs(v, res);
                    }
                }
            }
        };

        for (int i = 0; i < N; i++) {
            if (!set[i]) { lambda.dfs(i, 0); }
        }

        if (ok[0]) {
            println("YES");
            for (int i = 0; i < N; i++) {
                print(pref[i + 1] - pref[i] + " ");
            }
        }   else {
            println("NO");
        }
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
            } catch (Exception e) { }
            return null;
        }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }
}

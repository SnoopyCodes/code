import java.util.*;
import java.io.*;
public class advert {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    void solve() {
        int N = sc.nextInt();
        var DSU = new Object() {
            int[] par = new int[N];
            int[] size = new int[N];
            {
                for (int i = 0; i < N; i++) {
                    par[i] = i;
                    size[i] = 1;
                }
            }
            int find(int u) {
                if (par[u] != u) { par[u] = find(par[u]); }
                return par[u];
            }
            void unite(int u, int v) {
                u = find(u);
                v = find(v);
                if (u == v) { return; }
                if (size[u] < size[v]) { u ^= v; v ^= u; u ^= v; }
                size[u] += size[v];
                par[v] = u;
            }
        };
        int[][] H = new int[N][2];
        for (int i = 0; i < N; i++) {
            H[i] = new int[] { sc.nextInt(), i };
        }
        Arrays.sort(H, (a, b) -> {
            return a[0] != b[0] ? b[0] - a[0]
                : a[1] - b[1];
        });
        boolean[] alive = new boolean[N];
        long answer = 0;
        for (int i = 0; i < N; i++) {
            int k = H[i][0], j = H[i][1];
            alive[j] = true;
            if (j > 0 && alive[j - 1]) { DSU.unite(j, j - 1); }
            if (j < N - 1 && alive[j + 1]) { DSU.unite(j, j + 1); }
            answer = Math.max((long) k * DSU.size[DSU.find(j)], answer);
        }
        println(answer);
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

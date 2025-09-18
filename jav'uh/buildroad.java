import java.util.*;
import java.io.*;
public class buildroad { //replace class name

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    boolean B(int x) { return x != 0; }
    void solve() {
        int N = sc.nextInt();
        int M = sc.nextInt();
        li<Integer>[] G = new li[N];
        for (int i = 0; i < N; i++) { G[i] = new li(); }
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            G[u].add(v);
            G[v].add(u);
        }
        var add = new li<int[]>();
        var visited = new int[N];
        var dfs = new Object() {
            void go(int u) {
                visited[u] = 1;
                for (int v : G[u]) {
                    if (B(visited[v])) { continue; }
                    go(v);
                }
            }
        };

        for (int i = 0; i < N; i++) {
            if (!B(visited[i])) {
                dfs.go(i);
                if (B(i)) {
                    add.add(new int[]{ 1, i + 1 });
                }
            }
        }
        println(add.size());
        for (int[] p : add) {
            println(p[0] + " " + p[1]);
        }
    }
    class li<E> extends ArrayList<E> {}
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

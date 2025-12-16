import java.util.*;
import java.io.*;
public class buildroad { //replace class name

static class beep extends PrintWriter {
    BufferedReader br;
    Iterator<String> tokens;
    public beep() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
        tokens = br.lines()
                        .flatMap(line -> Arrays.stream(line.split("\\s+")))
                        .iterator();
        solve();
    }
    boolean B(int x) { return x != 0; }
    void solve() {

        int N = Integer.parseInt(tokens.next());
        int M = Integer.parseInt(tokens.next());
        var G = makegraph(N, M, false);
        var add = new li<Integer>();
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
                    add.add(i + 1);
                }
            }
        }
        println(add.size());
        for (int p : add) {
            println(1 + " " + p);
        }
    }
    int[][] makegraph(int N, int M, boolean directed) {
        int es[][] = new int[M][2], g[][] = new int[N][], d[] = new int[N];
        for (int i = 0; i < M; i++) {
            int u = Integer.parseInt(tokens.next()) - 1, v = Integer.parseInt(tokens.next()) - 1;
            es[i] = new int[]{ u, v };
            d[u]++;
            if (!directed) d[v]++;
        }
        for (int i = 0; i < N; i++) {
            g[i] = new int[d[i]];
            d[i] = 0;
        }
        for (var e : es) {
            int u = e[0], v = e[1];
            g[u][d[u]++] = v;
            if (!directed) g[v][d[v]++] = u;
        }
        return g;
    }

    class li<E> extends ArrayList<E> { E g(int i) { return get(i); } }
}

    public static void main(String[] args) { new beep().close(); }
}

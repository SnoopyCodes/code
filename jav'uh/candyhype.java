import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class candyhype {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    gg() {
        super(System.out);
        solve();
    }
    void solve() {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int R = sc.nextInt();
        int K = sc.nextInt();
        int C = sc.nextInt();
        int[][][] graph = new int[N][0][]; {
            int[] ds = new int[N];
            while (M --> 0)  {
                int u = sc.nextInt() - 1, v = sc.nextInt() - 1, w = sc.nextInt();
                graph[u] = app(graph[u], arr(v, w), ds[u]++);
                graph[v] = app(graph[v], arr(u, w), ds[v]++);
            }
            for (int i = 0; i < N; i++) {
                graph[i] = Arrays.copyOf(graph[i], ds[i]);
            }
        }
        /*
        finally done with input
        we move from this node to another <= K times which is just multisource dijkstra
        let the distance values be in { R, K }
        */

        long dists[][][] = new long[N][K][2];
        int vis[] = new int[N];
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> {
            return a[0] != b[0] ? Long.compare(a[0], b[0]) : a[1] != b[1] ? Long.compare(a[1], b[1]) : Long.compare(a[2], b[2]);
        });
        while (C --> 0) {
            dists[C][0] = new long[]{ 0, C };
            vis[C]++;
            pq.add(new long[]{ 0, C, C });
        }
        while (!pq.isEmpty()) {
            var pop = pq.poll();
            long d = pop[0];
            int from = (int) pop[1];
            int u = (int) pop[2];

            for (var e : graph[u]) {
                int v = e[0], dd = e[1];
                
            }
        }
    }
    int[] arr(int... a) { return a; }
    int[] app(int a[], int e, int sz) {
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * sz + 1); }
        a[sz] = e;
        return a;
    }
    <T> T[] app(T[] a, T e, int sz) {
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * sz + 1); }
        a[sz] = e;
        return a;
    }
}

    public static void main(String[] args) { new gg().close(); }
static class Scanner extends StreamTokenizer {
    Scanner(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        resetSyntax();
        whitespaceChars(0, ' ');
        wordChars(' ' + 1, 255);
    }
    String next() { try { nextToken(); return sval; } catch(Exception e){ return null; } }
    int nextInt() { return Integer.parseInt(next()); }
    long nextLong() { return Long.parseLong(next()); }
}

    static class li<E> extends ArrayList<E> {}
}

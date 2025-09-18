import java.util.*;
import java.io.*;
public class dijkstra {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    record State(int u, long d) {}
    void solve() {
        int N = sc.nextInt();
        int M = sc.nextInt();
        li<int[]>[] G = new li[N];
        for (int i = 0; i < N; i++) { G[i] = new li(); }
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt() - 1, v = sc.nextInt() - 1, c = sc.nextInt();
            G[u].add(new int[]{ v, c });
        }
        long[] dist = new long[N]; Arrays.fill(dist, (long) 1e18);

        var pq = new PriorityQueue<State>((a, b) -> {
            if (dist[a.u] == dist[b.u]) { return a.u - b.u; }
            return Long.compare(dist[a.u], dist[b.u]);
        });
        dist[0] = 0;
        pq.add(new State(0, 0));
        while (!pq.isEmpty()) {
            var s = pq.poll();
            if (s.d != dist[s.u]) { continue; }
            for (var e : G[s.u]) {
                int v = e[0], d = e[1];
                if (dist[s.u] + d < dist[v]) {
                    dist[v] = dist[s.u] + d;
                    pq.add(new State(v, dist[v]));
                }
            }
        }
        print((new State(0, 0).toString()));
        for (int i = 0; i < N; i++) {
            print(dist[i] + (i == N - 1 ? "\n" : " "));
        }
    }
    class li<E> extends ArrayList<E>{}
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

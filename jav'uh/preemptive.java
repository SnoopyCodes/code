import java.util.*;
import java.io.*;
import java.util.function.*;
public class preemptive {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
void solve() {
    int N = sc.nextInt(), M = sc.nextInt();
    int[][] E = new int[M][];
    ArrayList<Integer>[] G = new ArrayList[N];
    for (int i =0; i < N; i++) G[i] = new ArrayList<>();
    int is_bridge[][] = new int[N][N];
    for (int i = 0; i < M; i++) {
        E[i] = new int[]{ sc.nextInt() - 1, sc.nextInt() - 1 };
        G[E[i][0]].add(E[i][1]);
        G[E[i][1]].add(E[i][0]);
    }
    for (int i = 0; i < M; i++) {
        var dsu = new Object() {
            int[] p = new int[N];
            { for (int i = 0; i < N; i++) p[i] = i; }
            int find(int u) {
                if (p[u] != u) {
                    p[u] = find(p[u]);
                }
                return p[u];
            }
            void union(int u, int v) {
                u = find(u); v = find(v);
                if (u == v) { return; }
                if (Math.random() < 0.5) { p[u] = v; }
                else { p[v] = u; }
            }
        };
        for (int j = 0; j < M; j++) if (j != i) {
            dsu.union(E[j][0], E[j][1]);
        }
        int u = E[i][0], v = E[i][1];
        is_bridge[u][v] = is_bridge[v][u] = dsu.find(E[i][0]) != dsu.find(E[i][1]) ? 1 : 0;
    }
    int dist[] = new int[N];
    int amt_bridge[] = new int[N];
    for (int i = 0; i < N; i++) dist[i] = 1 << 10;
    dist[0] = 0;
    int[] q = new int[N];
    q[0] = 0;
    int s = 0, e = 1;
    while (s < e) {
        int u = q[s++];
        for (int v : G[u]) {
            if (dist[v] == 1 << 10) {
                amt_bridge[v] = amt_bridge[u] + is_bridge[u][v];
                dist[v] = dist[u] + 1;
                q[e++] = v;
            }
        }
    }
    println(dist[N-1] - amt_bridge[N-1]);
}


    gg() {
        super(System.out);
        int T = sc.nextInt(); while (T --> 0) solve();
    }
    
}

    public static void main(String[] args) { new gg().close(); }
}

import java.util.*;
import java.io.*;
import java.util.function.*;
public class chudwig {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    int N, alive[], s[], w[];
    double f[], g[];
    ArrayList<Integer>[] T;
    void dfs(int u) {
        for (int v : T[u]) {
            dfs(v);
            alive[u] |= alive[v];
            w[u] += w[v] + alive[v];
            s[u] += s[v] + 1;
        }
        if (alive[u]>0) {
            for (int v : T[u]) if (alive[v]>0) {
                g[u] += (1 + g[v] * w[u] / (w[u] + 1) + f[v] / (w[u] + 1))
                    * (w[v] + 1) / w[u];
            }
            if (!T[u].isEmpty()) {
                f[u] = g[u] + (double) s[u] / w[u] - 1;
            }
        }
    }
    void solve() {
        N = sc.nextInt(); int M = sc.nextInt();
        T = new ArrayList[N];
        for (int i = 0; i < N; i++) T[i] = new ArrayList<>();
        alive = new int[N];
        f = new double[N];
        s = new int[N];
        g = new double[N];
        w = new int[N];
        while (M --> 0) {
            int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
            if (v == N) {
                f[u] = 1;
                alive[u] = 1;
            }   else {
                T[u].add(v);
            }
        }
        dfs(0);
        printf("%.3f\n", f[0]);
    }


    gg() {
        super(System.out);
        int T = sc.nextInt(); while (T --> 0) solve();
    }

    
}

    public static void main(String[] args) { new gg().close(); }
}

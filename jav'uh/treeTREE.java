import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class treeTREE {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    gg() {
        super(System.out);
        int T = sc.nextInt();
        while (T --> 0)
        solve();
    }
    void solve() {
        int N = sc.nextInt(), K = sc.nextInt();
        int T[][] = new int[N][0];
        {
            int D[] = new int[N];
            for (int i = 0; i < N - 1; i++) {
                int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
                T[u] = append(T[u], v, D[u]++);
                T[v] = append(T[v], u, D[v]++);
            }
            for (int i = 0; i < N; i++) T[i] = Arrays.copyOf(T[i], D[i]);
        }
        var funcs = new Object() {
            long ans = N;
            int dfs(int u, int p) {
                int subsizes[] = new int[T[u].length];
                int sum = 0;
                int pi = -1;
                for (int i = 0; i < T[u].length; i++) {
                    if (T[u][i] == p) { pi = i; continue; }
                    subsizes[i] = dfs(T[u][i], u);
                    sum += subsizes[i];
                }

                if (pi != -1) subsizes[pi] = N - sum - 1;
                for (int i = 0; i < T[u].length; i++) {
                    if (N - subsizes[i] >= K) {
                        ans += subsizes[i];
                    }
                }

                sum++;
                return sum;
            }
        };
        funcs.dfs(0, -1);
        println(funcs.ans);
    }
    int[] append(int a[], int e, int sz) {
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

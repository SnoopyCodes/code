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
        li<int[]> add = new li();
        int[] visited = new int[N];
        var dfser = new Object() {
            void dfs(int u) {
                visited[u] = 1;
                for (int v : G[u]) {
                    if (B(visited[v])) { continue; }
                    dfs(v);
                }
            }
        };
 
        for (int i = 0; i < N; i++) {
            if (!B(visited[i])) {
                dfser.dfs(i);
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

    class li<E> extends ArrayList<E> { E g(int i) { return get(i); } }
}
    static class Scanner extends StreamTokenizer{
        Scanner(InputStream i) { super(new BufferedReader(new InputStreamReader(i)));
        resetSyntax(); whitespaceChars(0, ' '); wordChars('!', 255); }
        String next() {try{ nextToken(); return sval; }catch(Exception e){return null;}}
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }


    public static void main(String[] args) { new beep().close(); }
}

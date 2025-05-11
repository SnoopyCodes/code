import java.util.*;
import java.io.*;
class Chef extends PrintWriter{
    Scanner sc = new Scanner();
    public Chef() { super(System.out); }
    void dfs(int u, ArrayList<Integer>[] G, boolean[] visited) {
        visited[u] = true;
        for (int v : G[u]) {
            if (visited[v]) { continue; }
            dfs(v, G, visited);
        }
    }
    boolean check(boolean[] visited, boolean rev) {
        for (int i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                println("NO");
                println((rev ? (i + 1) : 1) + " " + (rev ? (1) : i + 1));
                return false;
            }
        }
        return true;
    }
    void cook() {
        int N = sc.nextInt(),
            M = sc.nextInt();
        boolean[] visited = new boolean[N];
        ArrayList<Integer>[] con = new ArrayList[N];
        ArrayList<Integer>[] rcon = new ArrayList[N];
        for (int i = 0; i < N; i++) { con[i] = new ArrayList(); rcon[i] = new ArrayList(); }
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt() - 1,
                v = sc.nextInt() - 1;
            con[u].add(v);
            rcon[v].add(u);
        }

        dfs(0, con, visited);
        if (!check(visited, false)) { return; }
        visited = new boolean[N];
        dfs(0, rcon, visited);
        if (!check(visited, true)) { return; }
        println("YES");
    }
}
public class comp {
    public static void main(String[] args) {
        Chef fugel = new Chef();
        fugel.cook();
        fugel.close();
    }
}

// class Scanner {
//     BufferedReader r; StringTokenizer st;
//     public Scanner() { r = new BufferedReader(new InputStreamReader(System.in)); }
//     String next() {
//         try {
//             while (st == null || !st.hasMoreTokens())
//                 st = new StringTokenizer(r.readLine());
//             return st.nextToken();
//         } catch (Exception e) { }
//         return null;
//     }
//     int nextInt() { return Integer.parseInt(next()); }
//     double nextDouble() { return Double.parseDouble(next()); }
//     long nextLong() { return Long.parseLong(next()); }
// }
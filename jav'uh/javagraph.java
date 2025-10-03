import java.util.*;
import java.io.*;

public class javagraph {
    static int dfs(ArrayList<Integer>[] con, boolean[] visited, int u) {
        visited[u] = true;
        int trav = 0;
        for (int v : con[u]) {
            if (visited[v]) { continue; }
            dfs(con, visited, u);
            trav++;
        }
        return trav;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); //number of nodes
        int M = sc.nextInt(); //number of edges
        int Q = sc.nextInt();
        ArrayList<Integer>[] con = new ArrayList[N];
        for (int i = 0; i < M; i++) { //assumes nodes are 1-indexed
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            con[u].add(v);
            con[v].add(u);
        }
        while (Q --> 0) {
            System.out.println(dfs(con, new boolean[N], sc.nextInt()));
        }
    }
}
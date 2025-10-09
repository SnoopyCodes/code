import java.util.*;
import java.io.*;

public class javagraph {
    static void dfs(ArrayList<Integer>[] con, int[] color, int u, int c) {
        color[u] = c;
        for (int v : con[u]) {
            if (color[v] != -1) { continue; } //has already been visited
            dfs(con, color, u, c);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); //number of nodes
        int M = sc.nextInt(); //number of edges
        ArrayList<Integer>[] con = new ArrayList[N];
        int[] order = new int[N];
        for (int i = 0; i < N; i++) {
            order[i] = sc.nextInt() - 1;
        }
        for (int i = 0; i < M; i++) { //assumes nodes are 1-indexed
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            con[u].add(v);
            con[v].add(u);
        }
        boolean can = true;
        int[] color = new int[N];
        for (int i = 0; i < N; i++) {
            color[i] = -1; //-1 is no color
        }
        for (int i = 0; i < N; i++) {
            if (color[i] != -1) {
                dfs(con, color, i, i);
            }
            can &= color[i] == color[order[i]];
        }
        System.out.println(can); //true/false-- can/cannot be sorted
    }
}
import java.io.*;
import java.util.*;
 
public class bridge {
    static ArrayList<Integer>[] con;
    static int[] back;
    static int euler = 0;
    static ArrayList<Integer[]> bridge;
    static Integer[] mp(int a, int b) { return new Integer[]{a, b}; }
    static void dfs(int u, int p) {
        int in = back[u] = euler++;
        for (int v : con[u]) {
            if (v == p) { continue; }
            if (back[v] == -1) { dfs(v, u); }
            back[u] = Math.min(back[u], back[v]);
        }
        if (back[u] == in && p != -1) { bridge.add(new Integer[]{u+1, p+1}); }
    }
 
    public static void main(String[] args) throws IOException {
        int N = io.I(), M = io.I();
        con = new ArrayList[N];
        for (int i = 0; i < N; i++) { con[i] = new ArrayList(); }
        back = new int[N];
        Arrays.fill(back, -1);
        bridge = new ArrayList();
        for (int i = 0; i < M; i++) {
            int u = io.I() - 1, v = io.I() - 1;
            con[u].add(v);
            con[v].add(u);
        }
        for (int i = 0; i < N; i++) {
            if (back[i] == -1) { dfs(i, -1); }
        }
        io.println(bridge.size());
        
        for (var x : bridge) {
            io.println(x[0] + " " + x[1]);
        }
        io.close();
    }
 
    static Kattio io = new Kattio();
    static class Kattio extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;
        public Kattio() { this(System.in, System.out); }
        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        public String S() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (IOException e) {}
            return null;
        }
        public int I() { return Integer.parseInt(S()); }
        public double D() { return Double.parseDouble(S()); }
        public long L() { return Long.parseLong(S()); }
    }
}
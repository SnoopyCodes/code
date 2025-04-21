import java.io.*;
import java.util.*;
 
public class art {
    static ArrayList<Integer>[] con;
    static int[] back, in;
    static int euler = 0;
    static ArrayList<Integer> art;
    static void dfs(int u, int p) {
        in[u] = back[u] = euler++;
        int ct = 0;
        boolean is = false;
        for (int v : con[u]) {
            if (v == p) { continue; }
            if (back[v] == -1) {
                dfs(v, u);
                ct++;
                back[u] = Math.min(back[u], back[v]);
                if (back[v] >= in[u] && p != -1) { is = true; }
            }   else { back[u] = Math.min(back[u], in[v]); }
        }
        
        if (p == -1 && ct > 1) { is = true; }
        if (is) { art.add(u + 1); }
    }
    public static void main(String[] args) throws IOException {
        int N = io.I(), M = io.I();
        con = new ArrayList[N];
        in = new int[N];
        for (int i = 0; i < N; i++) { con[i] = new ArrayList(); }
        back = new int[N];
        Arrays.fill(back, -1);
        art = new ArrayList();
        for (int i = 0; i < M; i++) {
            int u = io.I() - 1, v = io.I() - 1;
            con[u].add(v);
            con[v].add(u);
        }
        for (int i = 0; i < N; i++) {
            if (back[i] == -1) { dfs(i, -1); }
        }
        io.println(art.size());
        
        for (int x : art) {
            io.println(x);
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
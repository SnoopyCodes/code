import java.io.*;
import java.util.*;
public class tarjan {
    static ArrayList<Integer>[] con;
    static int[] back, in_cc, in;
    static int euler = 0, cc = 0;
    static Stack<Integer> path;
    static void dfs(int u) {
        in[u] = back[u] = euler++;
        path.add(u);
        for (int v : con[u]) {
            if (back[v] == -1) { dfs(v); back[u] = Math.min(back[v], back[u]); }
            else if (in_cc[v] == -1) { back[u] = Math.min(back[u], in[v]); }
        }
        if (back[u] != in[u]) { return; }
        while (in_cc[u] == -1) {
            int v = path.pop();
            in_cc[v] = cc;
        }
        cc++;
    }
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int N = io.Int();
        int M = io.Int();
        con = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            con[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            int u = io.Int() - 1, v = io.Int() - 1;
            con[u].add(v);
        }
        back = new int[N]; Arrays.fill(back, -1);
        in_cc = new int[N]; Arrays.fill(in_cc, -1);
        in = new int[N]; Arrays.fill(in, -1);
        path = new Stack<>();
        for (int i = 0; i < N; i++) {
            if (back[i] == -1) { dfs(i); }
        }
        io.println(cc);
        for (int i = 0; i < N; i++) {
            io.print(in_cc[i] + 1 + " ");
        }
        io.close();
    }
 
    static class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;
    public Kattio() { this(System.in, System.out); }
    public Kattio(InputStream i, OutputStream o) {
    super(o);
    r = new BufferedReader(new InputStreamReader(i));
    }
    public String next() {
    try {
    while (st == null || !st.hasMoreTokens())
    st = new StringTokenizer(r.readLine());
        return st.nextToken();
    } catch (IOException e) {}
    return null;
    }
    public int Int() { return Integer.parseInt(next()); }
    public double Double() { return Double.parseDouble(next()); }
    public long Long() { return Long.parseLong(next()); }
    }
}
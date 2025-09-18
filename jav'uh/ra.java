import java.util.*;
import java.io.*;
public class ra {
 
static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    void solve() {
        int N = sc.nextInt();
        var T = new int[N << 1];
        var room = new int[N];
        var ord = new ArrayList<Integer>();
        ord.ensureCapacity(N << 1);
        for (int i = 0; i < 2 * N; ++i) { ord.add(i); }
        var open = new int[N];
        for (int i = 0; i < N; ++i) {
            open[i] = N - i;
            T[i << 1] = sc.nextInt();
            T[i << 1 | 1] = sc.nextInt();
        }
        Collections.sort(ord, (i, j) -> {
            return T[i] == T[j] ? (i & 1) - (j & 1) : T[i] - T[j];
        });
        int ans = 0;
        int pt = N;
        for (int i : ord) {
            if ((i & 1) == 0) {
                room[i >> 1] = open[--pt];
                ans = Math.max(ans, N - pt);
            }   else {
                open[pt++] = room[i >> 1];
            }
        }
        StringBuilder a = new StringBuilder();
        a.append(ans).append('\n');
        for (int r : room) a.append(r).append(' ');
        println(a);
    }
}
 
    public static void main(String[] args) { new beep().close(); }
    static class Scanner {
        private BufferedReader r;
        private StringTokenizer st;
        public Scanner(InputStream in) { r = new BufferedReader(new InputStreamReader(in)); }
        public String next() {
            try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) { }
            return null;
        }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }
}

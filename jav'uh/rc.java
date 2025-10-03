import java.util.*;
import java.io.*;
public class rc {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    void solve() {
        int N = sc.nextInt();
        int[] T = new int[2 * N]; //time
        int[] D = new int[2 * N]; //delta
        ArrayList<Integer> ord = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            T[2 * i] = sc.nextInt();
            D[2 * i] = 1;
            T[2 * i + 1] = sc.nextInt();
            D[2 * i + 1] = -1;
        }
        for (int i = 0; i < 2 * N; i++) { ord.add(i); }
        Collections.sort(ord, (i, j) -> {
            return T[i] - T[j];
        });
        int ans = 0;
        int cur = 0;
        for (int i : ord) {
            cur += D[i];
            ans = Math.max(ans, cur);
        }
        System.out.println(ans);
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

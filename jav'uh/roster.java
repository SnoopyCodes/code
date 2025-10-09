import java.util.*;
import java.io.*;
public class roster {

static class beep extends PrintWriter {
    Scanner sc;
    public beep() throws IOException {
        super(System.out);
        var now = System.currentTimeMillis();
        sc = new Scanner(new FileReader("in.txt"));
        int T = sc.nextInt();
        while (T --> 0) { solve(); }
        var after = System.currentTimeMillis();
        System.out.println(after - now);
    }
    String alpha = "QWERTYUIOP||ASDFGHJKL||ZXCVBNM";
    void solve() {
        int N = sc.nextInt();
        int M = sc.nextInt();
        String[] nam = new String[N];
        String[] ans = new String[M];
        for (int i = 0; i < N; i++) {
            nam[i] = sc.next();
        }
        
        for (int i = 0; i < M; i++) { //test this string
            String name = sc.next();
            boolean found_match = false;
            for (int j = 0; j < N; j++) { //test if matches
                int K = name.length();
                String test = nam[j];
                if (K != test.length()) { continue; }
                boolean ok = true;
                for (int k = 0; k < K; k++) {
                    int i1 = alpha.indexOf(name.charAt(k));
                    int i2 = alpha.indexOf(test.charAt(k));
                    if (Math.abs(i1 - i2) > 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    found_match = true;
                    ans[i] = test;
                    break;
                }
            }
            if (!found_match) {
                ans[i] = name;
            }
        }
        Arrays.sort(ans);
        // for (int i = 0; i < M; i++) {
        //     print(ans[i] + (i < M - 1 ? " " : "\n"));
        // }

    }
}

    public static void main(String[] args) throws IOException { new beep().close(); }
    static class Scanner {
        private BufferedReader r;
        private StringTokenizer st;
        public Scanner(FileReader f) { r = new BufferedReader(f); }
        public String next() {
            try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) { return null; }
        }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }

}

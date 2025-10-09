import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class ancientwizardcape {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        int T = sc.nextInt();
        while (T --> 0) { solve(); }
    }
    final int MOD = 676767677;
    void solve() {
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt() - 1;
        }
        int[][] arrange = new int[2][N];
        arrange[0][0] = 0;
        arrange[1][0] = 1;
        var F = new Object() {
            boolean set(int[] arr) { //can set
                for (int i = 1; i < N; i++) {
                    int d = A[i] - A[i - 1];
                    if (abs(d) > 1) { return false; }
                    else if (d == 1) {
                        if (arr[i - 1] != 0) { return false; }
                        arr[i] = 0;
                    }   else if (d == -1) {
                        if (arr[i - 1] != 1) { return false; }
                        arr[i] = 1;
                    }   else {
                        arr[i] = 1 - arr[i - 1];
                    }
                }
                int[] pref0 = new int[N + 1];
                int[] pref1 = new int[N + 1];
                for (int i = 0; i < N; i++) {
                    int eq1 = arr[i] == 1 ? 1 : 0;
                    pref0[i + 1] = pref0[i] + (1 - eq1);
                    pref1[i + 1] = pref1[i] + eq1;
                }
                for (int i = 0; i < N; i++) {
                    if (pref0[i] + pref1[N] - pref1[i + 1] != A[i]) {
                        return false;
                    }
                }
                return true;
            }
        };
        int ans = (F.set(arrange[0]) ? 1 : 0) + (F.set(arrange[1]) ? 1 : 0);
        println(ans);
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
            } catch (Exception e) { return null; }
        }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }

}

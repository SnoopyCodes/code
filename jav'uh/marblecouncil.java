import java.util.*;
import java.io.*;
public class marblecouncil {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    beep() {
        super(System.out);
        int T = sc.nextInt();
        while (T --> 0)
        solve();
    }
    final int MOD = 998244353;
    void solve() {
        int N = sc.nextInt();
        int freq[] = new int[N];
        for (int i = 0; i < N; i++) {
            freq[sc.nextInt() - 1]++;
        }
        Arrays.sort(freq);
        //so what's the dp in the end?
        //we can add partitions of a for each a in freq[i]
        //{} -> {2, 2} {2}{2}
        //{1} -> {1}{2, 2} {1}{2}{2}

        //{}
        //{1} {2, 2}
        //{1} {2} {2}
        //{2, 2}
        long dp[] = new long[N + 1];
        dp[0] = 1;
        for (int i = 0; i < N; i++) {
            if (freq[i] == 0) { continue; }
            for (int j = N - freq[i]; j > -1; j--) {
                dp[freq[i] + j] = (dp[freq[i] + j] + dp[j] * freq[i]) % MOD;
            }
        }
        long ans = 0;
        for (int i = freq[N-1]; i <= N; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        println(ans);
    }
}

    public static void main(String[] args) { new beep().close(); }
    static class Scanner {
        BufferedReader r;
        StringTokenizer st;
        Scanner(InputStream in) { r = new BufferedReader(new InputStreamReader(in)); }
        String next() {
            try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) { return null; }
        }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }

}

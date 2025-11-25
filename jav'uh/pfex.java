import java.util.*;
import java.io.*;
public class pfex {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    void solve() {
        Scanner kb = new Scanner(System.in);
        int N = kb.nextInt();
        int[] array = new int[N];
        for (int i = 0; i < N; i++) {
            array[i] = kb.nextInt();
        }

        int ans = 0;
        int[] first_mod_pref = new int[7]; //first_mod_pref[i] = first index with prefix sum % 7 = 0
        Arrays.fill(first_mod_pref, -2); //-2 represents none found yet
        first_mod_pref[0] = -1; //start with empty array
        int mod_pref_sum = 0; //the current sum % 7

        for (int i = 0; i < N; i++) {
            mod_pref_sum = (mod_pref_sum + array[i]) % 7;
            int left_bound = first_mod_pref[mod_pref_sum];
            if (left_bound == -2) { //doesn't exist
                first_mod_pref[mod_pref_sum] = i;
            }   else {
                //the subarray is (left_bound, r] so the length is r - left_bound
                ans = Math.max(ans, i - left_bound);
            }
        }

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

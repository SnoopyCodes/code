import java.util.*;
import java.io.*;
public class WeakLink {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        int T = sc.nextInt();
        while (T --> 0) { solve(); }
    }
    final int MOD = 1000000007;
    void solve() {
        int N = sc.nextInt();
        long X = sc.nextLong();
        li<Long> dupl = new li(), dupr = new li();
        while (X > 1) {
            long nxt = (X + 1) / 2;
            dupl.add(nxt);
            dupr.add(X - 1);
            X = nxt;
        }
        
        long[] l = new long[N];
        long[] r = new long[N];
        Integer[] ord = new Integer[N];
        for (int i = 0; i < N; i++) {
            ord[i] = i;
            l[i] = sc.nextLong();
            r[i] = sc.nextLong();
        }
        Arrays.sort(ord, (i, j) -> {
            return l[i] != l[j] ? Long.compare(l[i], l[j])
                : Long.compare(r[i], r[j]);
        });
        li<Long> L = new li<>(), R = new li<>();
        long curl = 0, curr = 0;
        for (int i : ord) {
            if (l[i] > curr) {
                if (curr != 0) {
                    L.add(curl);
                    R.add(curr);
                }
                curl = l[i];
                curr = r[i];
            }   else {
                curr = Math.max(curr, r[i]);
            }
        }
        L.add(curl);
        R.add(curr);
        long ans = 0;
        for (int i = 0; i < L.size(); i++) {
            curl = L.g(i);
            curr = R.g(i);
            for (int j = 0; j < dupl.size(); j++) {
                long tl = dupl.g(j), tr = dupr.g(j);
                //find intersection
                long inter = 0;
                if (!(tl > curr || curl > tr)) {
                    inter = Math.min(curr, tr) - Math.max(curl, tl) + 1;
                }
                ans = (ans + (j + 1) * inter) % MOD;
            }
        }
        println(ans);
    }
    class li<E> extends ArrayList<E>{ E g(int i) { return get(i); } }
}

    public static void main(String[] args) { new beep().close(); }

}

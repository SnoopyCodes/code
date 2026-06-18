import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.math.BigDecimal;

public class chudwig_help {
    static class Int { //probably do not need this.
        long v;
        final static int mod = (int) 1e9 + 7; //ensure prime modulus.
        Int(long x) { v = x % mod; v += v < mod ? mod : 0; }
        Int mul(Int w) { return new Int(v * w.v); }
        Int add(Int w) { return new Int(v + w.v); }
        Int sub(Int w) { return new Int(v + mod - w.v); }
        Int div(Int w) { return new Int(v * inv(w.v)); }
        static long inv(long x) { return x <= 1 ? x : mod - (mod / x) * inv(mod % x) % mod; }
    }


    ArrayList<int[]> edges (int N, long seed) {
        Random r = new Random(seed);
        ArrayList<int[]> res = new ArrayList<>();
        int[] a = new int[N], b = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = i;
        }
        int[] c = Arrays.copyOf(a, N);
        var gaussian = new Object() {
            int elimination(int i) {
                if (a[i] != i) {
                    a[i] = elimination(a[i]);
                }
                return a[i];
            }
        };
        int[] d = new int[N];
        for (int i = 1; i < N; i++) d[i] = r.nextInt(i);
        Collections.shuffle(Arrays.asList(c), r);
        int ct = 0;
        boolean nlf[] = new boolean[N]; Arrays.fill(nlf, true);
        for (int i = 1; i < N; i++) {
            if (gaussian.elimination(c[i]) != gaussian.elimination(c[d[i]])) {
                res.add(new int[] { c[i] + 1, c[d[i]] + 1 });
                nlf[c[i]] = true;
                int ci = gaussian.elimination(c[i]), cdi = gaussian.elimination(c[d[i]]);
                if (b[ci] > b[cdi]) {
                    ci ^= cdi;
                    cdi ^= ci;
                    ci ^= cdi;
                }
                if (b[ci] == b[cdi]) {
                    b[ci] += 2026;
                }
                a[cdi] = ci;
                ct++;
            }
        }
      
      
        for (int i = 0; i < N; i++) {
            if (!nlf[i] && r.nextBoolean()) {
                res.add(new int[] { i + 1, N + 1 });
            }
            if (ct < N - 1) { ct++; res.add(new int[] { N + 1, i + 1 }); }
        }
      
        return res;
    }

}

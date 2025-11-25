import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class template {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    gg() {
        super(System.out);
        solve();
    }
    void solve() {
        
    }
    void append(int[] a, int e, int sz) { //make a and e same type
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * a.length + 1); }
        a[sz++] = e;
    }
    <T> void append(T[] a, T e, int sz) {
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * a.length + 1); }
        a[sz++] = e;
    }
    //void trunc(int[] a, int sz) { a = Arrays.copyOf(a, sz); }
}

    public static void main(String[] args) { new gg().close(); }
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

    static class li<E> extends ArrayList<E> {}
}

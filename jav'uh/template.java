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
    int[] arr(int... a) { return a; }
    int[] app(int a[], int e, int sz) {
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * sz + 1); }
        a[sz] = e;
        return a;
    }
    <T> T[] app(T[] a, T e, int sz) {
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * sz + 1); }
        a[sz] = e;
        return a;
    }
}

    public static void main(String[] args) { new gg().close(); }
static class Scanner extends StreamTokenizer {
    Scanner(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        resetSyntax();
        whitespaceChars(0, ' ');
        wordChars(' ' + 1, 255);
    }
    String next() { try { nextToken(); return sval; } catch(Exception e){ return null; } }
    int nextInt() { return Integer.parseInt(next()); }
    long nextLong() { return Long.parseLong(next()); }
}

    static class li<E> extends ArrayList<E> {}
}

import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class rangeop {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    gg() {
        super(System.out);
        int T = sc.nextInt();
        while (T --> 0)
        solve();
    }
    void solve() {
        int N = sc.nextInt();
        long B[] = new long[N + 1];
        for (int i = 0; i < N; i++) {
            B[i + 1] = B[i] + sc.nextInt();
        }
        long ans = B[N];
        for (int i = 0; i <= N; i++) {
            B[i] = (long) i * (i + 1) - B[i];
        }


        int mini = 0;
        long best = B[1] - B[0];
        for (int i = 1; i < N; i++) {
            if (B[i] < B[mini]) {
                mini = i;
            }
            best = max(best, B[i + 1] - B[mini]);
        }
        println(ans + best);
    }
}
    public static void main(String[] args) { new gg().close(); }
    static class li<E> extends ArrayList<E> {}
    static class Scanner extends StreamTokenizer {
        Scanner(InputStream in) { super(new BufferedReader(new InputStreamReader(in))); }
        String next() {try{return nextToken() == TT_WORD ? sval
        : Long.toString((long)nval); }catch(Exception e){return null;}}
        int nextInt()  { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }
}

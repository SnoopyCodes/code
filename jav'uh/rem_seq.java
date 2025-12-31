import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class rem_seq {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    gg() {
        super(System.out);
        int T = sc.nextInt();
        while (T --> 0)
        solve();
    }

    boolean okay(long X, long Y, long V, long K) {
        while (X > 0 && V >= Y) {
            long rem = V / Y;
            long diff = V - (rem * Y - 1);
            long iter = min(X, (diff - 1) / rem + 1);

            X -= iter;
            V -= iter * rem;
            
        }
        return V >= K;
    }
    void solve() {
        flush();
        long X = sc.nextInt();
        long Y = sc.nextLong(), K = sc.nextLong();
        long s = 0, e = (long) 1e12 + 1;
        while (s + 1 < e) {
            long m = (s + e) / 2;
            if (okay(X, Y, m, K)) {
                e = m;
            }   else {
                s = m;
            }
        }
        if (!okay(X, Y, e, K) || e == 1e12 + 1) {
            println(-1);
        }   else {
            println(e);
        }
    }
}

    public static void main(String[] args) { new gg().close(); }
    // static class Scanner extends StreamTokenizer{
    //     Scanner(InputStream i) { super(new BufferedReader(new InputStreamReader(i)));
    //         resetSyntax();
    //                     whitespaceChars(0, ' ');    // whitespace = ASCII <= space
    //         wordChars('!', 255);        // treat everything from '!' (33) up as word chars
    //     }
    //     String next() {try{nextToken();}catch(Exception e){return null;} return sval; }
    //     int nextInt() { return Integer.parseInt(next()); }
    //     long nextLong()  { return Long.parseLong(next()); }
    // }

    static class Scanner extends StreamTokenizer{
        Scanner(InputStream i) { super(new BufferedReader(new InputStreamReader(i)));
        resetSyntax(); whitespaceChars(0, ' '); wordChars('!', 255); }
        String next() {try{ nextToken(); return sval; }catch(Exception e){return null;}}
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
    }

    static class li<E> extends ArrayList<E> {}
}

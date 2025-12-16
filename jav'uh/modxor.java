import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class modxor {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    Random rng = new Random(25);
    gg() {
        super(System.out);
        int T = sc.nextInt(); while (T --> 0)
        solve();
    }
    int msb(int x) {
        return Integer.highestOneBit(x);
    }
    void solve() {
        // int C = sc.nextInt(), X = sc.nextInt();
        int C = rng.nextInt(1, 1 << 10), X = rng.nextInt(1, 1 << 10);
        if (msb(C) != msb(X)) {
            println(X ^ C);
        }   else if (msb(C) == msb(X)) {
            //clearly this is the problem
            //suppose ans = k
            //k > X
            //(k ^ C) mod k = X
            //let msb be B
            //we can't have msb(k) > msb(C)
            //kid named xor:
            //k ^ C = X + k
            //where k ^ C > k
            //wtf am i doing
            //of course this works
            //if x == c it works of course it works
            //i posit if there is a bit of x not in c then it is impossible
            if ((C | X) > C) {
                println(-1);
            }   else {
                int n = (1 << 30) + (C - X) / 2;
                //n ^ C = n + X
                //ignore 1 << 30 for now
                //consider bits set in both X and C

                if ((n ^ C) % n != C) {
                    println("??");
                }
                println(n);
            }
            
        }
    }
    int[] append(int a[], int e, int sz) {
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * sz + 1); }
        a[sz] = e;
        return a;
    }
    <T> T[] append(T[] a, T e, int sz) {
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

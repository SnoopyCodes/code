import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class planetq1 {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    gg() {
        super(System.out);
        solve();
    }
    void solve() {
        int N = sc.nextInt(), Q = sc.nextInt();
        int LG = 30;
        int jump[][] = new int[N][LG];
        for (int i = 0; i < N; i++) jump[i][0] = sc.nextInt() - 1;
        for (int j = 1; j < LG; j++) {
            for (int i = 0; i < N; i++) {
                jump[i][j] = jump[jump[i][j-1]][j-1];
            }
        }
        while (Q --> 0) {
            int i = sc.nextInt() - 1;
            int k = sc.nextInt();
            for (int b = 0; k > 0; b++) {
                if ((k & 1 << b) != 0) {
                    k -= 1 << b;
                    i = jump[i][b];
                }
            }
            println(i + 1);
        }
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

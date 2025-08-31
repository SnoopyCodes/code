import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class bribe_better {
static class GG extends PrintWriter {
    boolean B(int x) { return x != 0; }
    int I(boolean b) { return b ? 1 : 0; }
    Scanner sc;
    public GG() {
        super(System.out);
        sc = new Scanner(System.in);
        int T = sc.nextInt(); while (T --> 0) solve();
    }
    li<Integer>[] T;
    int BIG = (int) 1e9;
    void solve() {
        int N = sc.nextInt();
        var teams = sc.next().toCharArray();
        var t = new int[N];
        for (int i = 0; i < N; i++) {
            t[i] = teams[i] == 'T' ? 0 : teams[i] == 'J' ? 1 : 2;
        }
        T = new li[N];
        var dp = new int[N][3][8];
        for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) fill(dp[i][j], BIG);
        for (int i = 1; i < N; i++) {
            int p = sc.nextInt() - 1;
            T[p].a(i);
        }
        for (int u = N - 1; u > -1; u--) {
            for (int c = 0; c < 3; c++) {
                //chat is so smart
                int ac = (c + 1) % 3, bc = (c + 2) % 3;
                var attach = new int[4]; fill(attach, BIG);
                var detach = new int[4]; fill(detach, BIG);
                for (int v : T[u]) {
                    for (int m = 0; m < 4; m++) {

                    }
                }
            }
        }
        int ans = BIG;
        for (int c = 0; c < 3; c++) {
            for (int bm = 0; bm < 8; bm++) {
                ans = min(ans, dp[0][c][bm]);
            }
        }
    }

    class li<E> extends ArrayList<E> {
        E g(int i) { return get(i); }
        void a(E e) { add(e); }
    }
}
public static void main(String[] args) { new GG().close(); }
}

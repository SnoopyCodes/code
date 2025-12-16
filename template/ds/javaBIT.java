// package template.ds;

import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class javaBIT {

static class gg extends PrintWriter {
    Scanner sc = new Scanner();

    long fen[];
    int len;
    void init(int l) {
        fen = new long[l + 1];
        len = l;
    }
    void add(int i, long v) {
        for (i++; i <= len; i += i & -i) fen[i] += v;
    }
    long q(int l, int r) { //[l, r)
        long res = 0;
        for (;r > 0; r -= r & -r) res += fen[r];
        for (;l > 0; l -= l & -l) res -= fen[l];
        return res;
    }


    gg() {
        super(System.out);
        solve();
    }
    void solve() {
        int N = sc.nextInt(), Q = sc.nextInt();
        init(N);
        long A[] = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            add(i, A[i]);
        }
        while (Q --> 0) {
            int t = sc.nextInt();
            if ((t & 1) == 1) {
                int i = sc.nextInt() - 1;
                int v = sc.nextInt();
                add(i, v - A[i]);
                A[i] = v;
            }   else {
                println(q(sc.nextInt() - 1, sc.nextInt()));
            }
        }
        
    }
}

    public static void main(String[] args) { new gg().close(); }
    static class Scanner {
		private BufferedReader r;
		private StringTokenizer st;
        Scanner() { r = new BufferedReader(new InputStreamReader(System.in)); }
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
    }

    static class li<E> extends ArrayList<E> {}
}

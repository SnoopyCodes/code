import java.util.*;
import java.io.*;

public class Prateek2 {
	public static void main(String[] args) throws IOException {
		Chef fugel = new Chef();
		fugel.close();
	}
	
	static class Chef extends PrintWriter {
		Scanner sc; int tt = 1;
		public Chef() throws IOException {
			super(System.out);
			sc = new Scanner(new File("prateek.dat".toLowerCase()));
			int T = sc.nextInt(); sc.nextLine();
			for (;tt <= T; tt++) { cook();	}
		}
		
		int lev(String a, String b) {
			//think about editing b to make it a
			int N = a.length(), M = b.length();
			int[][] dp = new int[N][M];  //cost to make 0...i match and 0...j match
			for (int i = 0; i < N; i++) {
				Arrays.fill(dp[i], 100);
				for (int j = 0; j < M; j++) {
					int cur = a.charAt(i) == b.charAt(j) ? 0 : 1;
					if (i > 0) { dp[i][j] = Math.min(dp[i][j], dp[i-1][j] + 1); }
					else { dp[i][j] = Math.min(dp[i][j], j + cur); }
					if (j > 0) { dp[i][j] = Math.min(dp[i][j], dp[i][j-1] + 1); }
					else { dp[i][j] = Math.min(dp[i][j], i + cur); }
					if (i > 0 && j > 0) { dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1] + cur); }
				}
			}
			return dp[N-1][M-1];
		}
		int[] dsu, size;
		int find(int u) {
			if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
			return dsu[u];
		}
		boolean merge(int u, int v) {
			u = find(u);
			v = find(v);
			if (u == v) { return false; }
			if (size[u] < size[v]) { u ^= v; v ^= u; u ^= v; }
			size[u] += size[v];
			dsu[v] = u;
			return true;
		}
		void cook() {
			int N = sc.nextInt();
			int A = sc.nextInt();
			int B = sc.nextInt();
			int D = sc.nextInt();
			String[] word = new String[N];
			for (int i = 0; i < N; i++) {
				word[i] = sc.next();
			}
			List<edge> edges = new ArrayList<>();
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					int c = B + lev(word[i], word[j]) * D;
					if (c >= A) { continue; }
					edges.add(new edge(i, j, c));
				}
			}
			Collections.sort(edges);
			dsu = new int[N];
			size = new int[N];
			Arrays.fill(size, 1);
			for (int i = 0; i < N; i++) {
				dsu[i] = i;
			}
			int ans = A * N;
			for (edge e : edges) {
				if (merge(e.u, e.v)) {
					ans -= A;
					ans += e.c;
				}
			}
			printf("Case #%d: %d\n", tt, ans);
		}
		static class edge implements Comparable<edge>{
			int u, v, c;
			public edge(int _u, int _v, int _c) { u = _u; v = _v; c = _c; }
			public int compareTo(edge o) {
				return c - o.c;
			}
		}
	}
	
}
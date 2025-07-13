import java.util.*;
import java.io.*;
 
public class test {
	static class Chef extends PrintWriter {
		
		void cook() {
			int N = sc.nextInt(), M = sc.nextInt();
			int[][] company = new int[M + 1][];
			int[] cost = new int[M];
			for (int i = 0; i < M; i++) {
				cost[i] = sc.nextInt();
			}
			company[M] = new int[]{0};
			fast_graph has = new fast_graph(N, 200000);
			for (int i = 0; i < M; i++) {
				int k = sc.nextInt();
				company[i] = new int[k];
				for (int j = 0; j < k; j++) {
					int u = sc.nextInt() - 1;
					has.add_edge(u, i);
					company[i][j] = u;
				}
			}
			long[] min_cost = new long[N]; Arrays.fill(min_cost, (long) 1e18);
			boolean[] b_done = new boolean[M + 1];
			var pq = new PriorityQueue<state>();
			pq.add(new state(M, 0));
			while (!pq.isEmpty()) {
				state ss = pq.poll();
				int b_u = ss.comp;
				long c = ss.cost;
				b_done[b_u] = true;
				for (int c_u : company[b_u]) {
					if (min_cost[c_u] != (long) 1e18) { continue; }
					min_cost[c_u] = c;
					for (int e = has.h[c_u]; e != -1; e = has.n[e]) {
						int b_v = has.e[e];
						if (!b_done[b_v]) { pq.add(new state(b_v, c + cost[b_v])); }
					}
				}
			}
			for (int i = 0; i < N; i++) {
				print(min_cost[i] + (i < N - 1 ? " " : "\n"));
			}
			
		}
		class state implements Comparable<state>{
			long cost; int comp;
			public state(int _c, long __c) { comp = _c; cost = __c; }
			public int compareTo(state o) {
				return Long.compare(cost, o.cost);
			}
		}
		class fast_graph {
			int[] e, h, n;
			int cur = 0;
			public fast_graph(int N, int M) {
				e = new int[M];
				h = new int[N]; Arrays.fill(h, -1);
				n = new int[M];
			}
			void add_edge(int u, int v) {
				n[cur] = h[u];
				e[cur] = v;
				h[u] = cur++;
			}
		}
		Scanner sc; int tt = 1;	public Chef() throws IOException {
			super(System.out);
			sc = new Scanner();
			cook();
		}
	}
	public static void main(String[] args) throws IOException {
		Chef fugel = new Chef();
		fugel.close();
	}
	static class Scanner {
		private BufferedReader r;
		private StringTokenizer st;
		public Scanner() {
			r = new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
	
		int nextInt() { return Integer.parseInt(next()); }
		double nextDouble() { return Double.parseDouble(next()); }
		long nextLong() { return Long.parseLong(next()); }
	}
	
}

import java.io.*;
import java.util.*;

public class bruh {

	public static void main(String[] args) {
		Kattio io = new Kattio();

		int n = io.nextInt();
		int m = io.nextInt();

		// Adjacency list of (neighbour, edge weight)
		List<Integer[]>[] neighbors = new ArrayList[n];
		for (int i = 0; i < n; i++) { neighbors[i] = new ArrayList<>(); }
		for (int i = 0; i < m; i++) {
			int a = io.nextInt() - 1;
			int b = io.nextInt() - 1;
			int c = io.nextInt();
			neighbors[a].add(new Integer[]{b, c});
		}

		// Initially set all distances to infinity
		long[] dist = new long[n];
		Arrays.fill(dist, Long.MAX_VALUE);

		// Dijkstra's algorithm
		PriorityQueue<Long[]> pq =
		    new PriorityQueue<>(Comparator.comparingLong(i -> i[1]));

		int start = 0;
		dist[start] = 0;  // The shortest path from a node to itself is 0
		pq.add(new Long[]{0L, (long)start});
		while (!pq.isEmpty()) {
			Long[] curr = pq.poll();
			long cdist = curr[0];
			int node = (Integer) curr[1];
			if (cdist != dist[node]) { continue; }
			for (Pair<Integer, Integer> i : neighbors[node]) {
				if (cdist + i.b < dist[i.a]) {
					pq.add(new Pair<>(dist[i.a] = cdist + i.b, i.a));
				}
			}
		}

		for (int i = 0; i < n - 1; i++) { io.print(dist[i] + " "); }
		io.println(dist[n - 1]);
		io.close();
	}

	//BeginCodeSnip{Kattio}
	static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
		// standard input
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
		// USACO-style file input
		public Kattio(String problemName) throws IOException {
			super(problemName + ".out");
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
		// returns null if no more input
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
	//EndCodeSnip
}
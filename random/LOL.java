import java.util.*;
import java.io.*;
public class LOL {
    static class Pair<K, V> {
		public K a;
		public V b;
 
		public Pair(K a, V b) {
			this.a = a;
			this.b = b;
		}
    }
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long[] dists = new long[N];
        ArrayList<Pair<Integer, Integer>>[] cities = new ArrayList[N];
        for (int i = 0; i < N; i++) { cities[i] = new ArrayList<>(); dists[i] = (long) 1e18; }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            int d = Integer.parseInt(st.nextToken());
            cities[u].add(new Pair<>(v, d));
        }
        dists[0] = 0;
        TreeSet<Integer> set = new TreeSet<>((a, b) -> {
            if (dists[a] == dists[b]) { return Integer.compare(a, b); }
            return Long.compare(dists[a], dists[b]);
        });
        set.add(0);
        while (!set.isEmpty()) {
            int u = set.pollFirst();
            for (Pair<Integer, Integer> to : cities[u]) {
                int v = to.a, d = to.b;
                if (dists[u] + d < dists[v]) {
                    set.remove(v);
                    dists[v] = dists[u] + d;
                    set.add(v);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            System.out.println(dists[i]);
        }
        br.close();
        pw.close();
    }
}
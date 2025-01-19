import java.io.*;
import java.util.*;
public class fatimah {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            boolean[][] hates = new boolean[N][N];
            TreeMap<String, Integer> ind = new TreeMap<>();
            for (int i = 0; i < N; i++) {
                String nam = sc.next();
                ind.put(nam, i);
            }
            for (int i = 0; i < M; i++) {
                String f = sc.next();
                String s = sc.next();
                int u = ind.get(f);
                int v = ind.get(s);
                hates[u][v] = true;
                hates[v][u] = true;
            }
            int ans = 0;
            for (int mask = 0; mask < 1 << N; mask++) {
                ArrayList<Integer> ar = new ArrayList<>();
                for (int b = 0; b < N; b++) {
                    if ((mask & 1 << b) != 0) {
                        ar.add(b);
                    }
                }
                boolean valid = true;
                for (int i = 0; i < ar.size(); i++) {
                    for (int j = i + 1; j < ar.size(); j++) {
                        if (hates[ar.get(i)][ar.get(j)]) {
                            valid = false;
                        }
                    }
                }
                if (valid) { ans = Math.max(ans, ar.size()); }
            }
            System.out.println("Case #" + (t + 1) + ": " + ans);
        }
    }
}
import java.util.*;
import java.io.*;
public class TD {

static class beep extends PrintWriter {
    Scanner in;
    public beep() throws IOException{
        super(System.out);
        in = new Scanner(System.in);
        int T = in.nextInt();
        while (T --> 0) { solve(); }
    }
    int[] dr = { 0, 0, -1, 1 }, dc = { 1, -1, 0, 0 };
    void solve() {
        int N = in.nextInt();
        int M = in.nextInt();
        char[][] grid = new char[N][M];
        int sr = 0, sc = 0, er = 0, ec = 0;
        Map<Integer, Integer> coin_ind = new TreeMap<>();
        int coinct = 0;
        for (int i = 0; i < N; i++) {
            grid[i] = in.next().toCharArray();
            for (int j = 0; j < M; j++) {
                char c = grid[i][j];
                if (c == 'S') {
                    sr = i;
                    sc = j;
                    grid[i][j] = 'G';
                }
                if (c == 'E') {
                    er = i;
                    ec = j;
                    grid[i][j] = 'G';
                }
                if (c == 'C') {
                    coin_ind.put(i * N + j, coinct++);
                }
            }
        }
        int bml = 1 << coinct;
        int[][][][] best = new int[N][M][bml][2];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < bml; k++) {
                    for (int l = 0; l < 2; l++) {
                        best[i][j][k][l] = 100000;
                    }
                }
            }
        }
        int[][] q = new int[N * M * bml * 2 * 10][];
        int s = 0, e = 0;
        best[sr][sc][0][0] = 0;
        q[e++] = new int[]{ sr, sc, 0, 0, 0 };
        
        while (s < e) {
            var pop = q[s++];
            int r = pop[0], c = pop[1], bm = pop[2], b = pop[3], dd = pop[4];
            if (dd != best[r][c][bm][b]) { continue; }
            if (grid[r][c] == 'B') { b = 1; }
            else if (grid[r][c] == 'C') {
                int ind = coin_ind.get(r * N + c);
                bm |= 1 << ind;
            }   else if (grid[r][c] == 'T') {
                if (best[sr][sc][bm][b] > dd) {
                    best[sr][sc][bm][b] = dd;
                    q[e++] = new int[]{ sr, sc, bm, b, dd };
                }
                continue;
            }
            int cost = b == 0 ? 2 : 1;
            for (int d = 0; d < 4; d++) {
                int nr = dr[d] + r;
                int nc = dc[d] + c;
                if (nr < 0 || nr == N || nc < 0 || nc == M) { continue; }
                if (grid[nr][nc] == '#') { continue; }
                if (dd + cost < best[nr][nc][bm][b]) {
                    best[nr][nc][bm][b] = dd + cost;
                    q[e++] = new int[]{ nr, nc, bm, b, dd + cost };
                }
            }
        }
        int ans = Math.min(best[er][ec][bml - 1][0], best[er][ec][bml - 1][1]);
        if (ans == 100000) {
            println("Get benched.");
        }   else {
            println((double) ans / 2);
        }
    }
}

    public static void main(String[] args) throws IOException { new beep().close(); }

}

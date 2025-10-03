import java.util.*;
import java.io.*;

public class bruh {
    static boolean[][] grid;
    static boolean[][] visited;
    static int[] dr = { 1, -1, 0, 0 }, dc = { 0, 0, -1, 1 };
    static boolean out_of_bounds(int r, int c) {
        return r < 0 || c < 0 || r == grid.length || c == grid[0].length;
    }
    static boolean traverse(int r, int c) { //row, column we are at.
        visited[r][c] = true; //mark as true so we don't come back
        if (r == grid.length - 1 && c == grid[0].length - 1) { return true; } //we are at the end.
        for (int d = 0; d < 4; d++) { //direction we move in
            int nr = r + dr[d]; //find new square we move to
            int nc = c + dc[d];
            if (out_of_bounds(nr, nc) || visited[nr][nc] || !grid[nr][nc]) { continue; } //do not go
            if (traverse(nr, nc)) { return true; }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        grid = new boolean[N][N];
        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            String line = sc.next();
            for (int j = 0; j < N; j++) {
                if (line.charAt(j) == '#') { grid[i][j] = false; }
                else { grid[i][j] = true; }
            }
        }
        if (traverse(0, 0)) { System.out.println(true); }
        else { System.out.println(false); }
    }
    class list {
        int[] d = new int[5];
        int len = 0;
        void add(int e) {
            if (len == d.length) { d = Arrays.copyOf(d, 2 * len); }
            d[len++] = e;
        }
    }
}
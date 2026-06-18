import java.util.*;
import java.io.*;
import java.lang.reflect.Field;

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
        okbruh b = new okbruh();
        b.name = "hey";
        b.d = 5;
        System.out.println(b.toString());
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
class okbruh {
    String name, name2;
    double d;
    int x;
    @Override
    public String toString() {
        Field[] fields = this.getClass().getDeclaredFields();
        StringBuffer sb = new StringBuffer();
        for (var f : fields) {
            try {
                sb.append((f.get(this)) != null ? f.getName() + " = " + f.get(this).toString() + "\n" : "");
            }   catch (Exception ignored) {}
        }
        return sb.toString().trim();
    }
}
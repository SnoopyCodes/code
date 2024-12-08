import java.io.*;
import java.util.*;

public class p12 {
	static boolean[][] grid;
	static boolean[][][] visited;
	static int[] dx = {0, 1, 0, -1};
	static int[] dy = {-1, 0, 1, 0};
	static boolean go(int r, int c, int d) {
		visited[r][c][d] = true;
		for (int i = 0; i < 4; i++) {
			int nd = (d + i) % 4;
			int nr = r + dy[nd];
			int nc = c + dx[nd];
			if (nr < 0 || nc < 0 || nr == grid.length || nc == grid[0].length) { return false; }
			if (!grid[nr][nc] && !visited[nr][nc][nd]) {
				return go(nr, nc, nd);
			}   else if (visited[nr][nc][nd]) { return true; }
		}
		return false;
	}
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("in.txt"));
		ArrayList<ArrayList<Boolean>> help = new ArrayList<>();
		int startr = 0, startc = 0;
		int cnt = 0;
		while (sc.hasNextLine()) {
			String s = sc.nextLine();
			help.add(new ArrayList<Boolean>());
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == '^') { startr = cnt; startc = i; }
				help.get(help.size() - 1).add(s.charAt(i) == '#');
			}
			cnt++;
		}
		int rowl = help.size();
		int coll = help.get(0).size();
		grid = new boolean[rowl][coll];
		visited = new boolean[rowl][coll][4];  //for each dir
		visited[startr][startc][0] = true;
		for (int i = 0; i < rowl; i++) {
			for (int j = 0; j < coll; j++) {
				grid[i][j] = help.get(i).get(j);
			}
		}
		int ans = 0;
		for (int i = 0; i < rowl; i++) {
			for (int j = 0; j < coll; j++) {
				if (i == startr && j == startc || grid[i][j]) { continue; }
                visited = new boolean[rowl][coll][4];
				grid[i][j] = true;
				if (go(startr, startc, 0)) { ans++; }
				grid[i][j] = false;
			}
		}
		System.out.println(ans);
	}
}
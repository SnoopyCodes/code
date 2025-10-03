import java.util.Scanner;
public class PathFinding {
	static boolean FindPath(char maze[][], boolean[][] visited, int r, int c, int N) {
		if (r == N || r < 0) { return false; } //if out of bounds, invalid.
		if (c == N || c < 0) { return false; }
        if (visited[r][c]) { return false; }
		if (maze[r][c] != '.') { return false; } //if impassable, invalid.
        if (r == N - 1 || c == N - 1) { return true; } //success
        visited[r][c] = true;
		if (FindPath(maze, visited, r, c - 1, N)
        ||  FindPath(maze, visited, r, c + 1, N)
        ||  FindPath(maze, visited, r + 1, c, N)
		||  FindPath(maze, visited, r - 1, c, N)) { return true; }
		return false; //all 4 directions, failed, failure.
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		char[][] maze = new char[N][N];
		for (int i = 0; i < N; i++) {
			String S = sc.next();
			for (int j = 0; j < N; j++) {
				maze[i][j] = S.charAt(j);
			}
		}
		if (FindPath(maze, new boolean[N][N], 0, 0, N)) { System.out.println(true); }
		else { System.out.println(false); }
	}
}
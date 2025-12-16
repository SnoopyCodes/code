import java.util.*;
import java.io.*;
public class aoc4 {

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(new File("in.txt"));
        ArrayList<String> input = new ArrayList<>();
        while (sc.hasNextLine()) {
            input.add((sc.nextLine()));
        }
        char[][] grid = new char[input.size()][input.get(0).length()];
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input.get(0).length(); j++) {
                grid[i][j] = input.get(i).charAt(j);
            }
        }

        int[] dr = { -1, -1, 1, 1, 1, -1, 0, 0 };
        int[] dc = { -1, 0, 1, 0, -1, 1, 1, -1 };
        int count = 0;
        int N = grid.length;
        int M = grid[0].length;
        int[][] q = new int[N * M][];
        int s = 0, e = 0;
        var F = new Object() {
            boolean inb(int r, int c) {
                return r >= 0 && c >= 0 && r < N && c < M;
            }
        };
        int[][] adj_rolls = new int[N][M];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != '@') { continue; }
                for (int d = 0; d < 8; d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if (!F.inb(nr, nc)) { continue; }
                    if (grid[nr][nc] == '@') { adj_rolls[i][j]++; }
                }
                if (adj_rolls[i][j] < 4) {
                    q[e++] = new int[]{ i, j };
                }
            }
        }
        
        while (s < e) {
            int r = q[s][0], c = q[s][1];
            s++;
            count++;
            for (int d = 0; d < 8; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (!F.inb(nr, nc)) { continue; }
                if (grid[nr][nc] == '@' && --adj_rolls[nr][nc] == 3) {
                    q[e++] = new int[] { nr, nc };
                }
            }
        }

        System.out.println(count);
    }

}

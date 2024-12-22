import java.util.*;
import java.io.*;

public class p16 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        ArrayList<String> ar = new ArrayList<>();
        while (sc.hasNextLine()) {
            ar.add(sc.nextLine());
        }
        int N = ar.size();
        int M = ar.get(0).length();
        TreeMap<Character, ArrayList<int[]>> map = new TreeMap<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char c = ar.get(i).charAt(j);
                if (c == '.') { continue; }
                var x = map.getOrDefault(c, new ArrayList<>());
                x.add(new int[]{i, j});
                map.put(c, x);
            }
        }
        boolean[][] on = new boolean[N][M];
        for (var x : map.keySet()) {
            var y = map.get(x);
            for (int i = 0; i < y.size(); i++) {
                for (int j = i + 1; j < y.size(); j++) {
                    var a1 = y.get(i);
                    var a2 = y.get(j);
                    int xd = a2[0] - a1[0];
                    int yd = a2[1] - a1[1];
                    int nx = a1[0];
                    int ny = a1[1];
                    while (nx > -1 && ny > -1 && nx < N && ny < M) { on[nx][ny] = true; nx -= xd; ny -= yd; }
                    nx = a2[0];
                    ny = a2[1];
                    while (nx > -1 && ny > -1 && nx < N && ny < M) { on[nx][ny] = true; nx += xd; ny += yd; }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j =0 ; j < M; j++) {
                if (on[i][j]) { count++; }
            }
        }
        System.err.println(count);
        sc.close();
    }
}

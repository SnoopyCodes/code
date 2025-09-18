import java.util.*; //please import your stuff
import java.io.*;
public class E {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), X = sc.nextInt();
        int[] p = new int[N];
        String[] n = new String[N];
        for (int i = 0; i < N; i++) {
            p[i] = sc.nextInt();
            n[i] = sc.next();
        }
        boolean[] done = new boolean[N];
        ArrayList<String> ans = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int minj = -1;
            for (int j = 0; j < N; j++) {
                if (done[j]) { continue; }
                if (minj == -1 || 
                    (p[j] < p[minj] || p[j] == p[minj] && n[j].compareTo(n[minj]) < 0)) {
                    minj = j;
                }
            }
            if (X >= p[minj]) {
                X -= p[minj];
                done[minj] = true;
                ans.add(n[minj]);
            }
        }
        for (String s : ans) {
            System.out.println(s);
        }
    }
}
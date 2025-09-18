import java.util.*;
import java.io.*;

public class make_graph {
    static record to(String v, int d) {}
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        var G = new Object() {
            to[][] gen() {
                to[][] R = new to[N][];
                int[] u = new int[M], v = new int[M];
                int[] d = new int[M];
                to ex = new to("", 0);
                Map<Integer, Integer> m = new TreeMap<>();
                for (int i = 0; i < M; i++) {
                    u[i] = sc.nextInt();
                    v[i] = sc.nextInt();
                    d[i] = sc.nextInt();
                    m.put(u[i], m.getOrDefault(u[i], 0) + 1);
                    m.put(v[i], m.getOrDefault(v[i], 0) + 1);
                }
                for (int i = 0; i < N; i++) {
                    
                }
                for (int i = 0; i < M; i++) {

                }

                return R;
            }
        }.gen();
    }
}

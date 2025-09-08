import java.util.*;
import java.io.*;

public class ex_java_comp_no {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), X = sc.nextInt();
        int[] p = new int[N];
        String[] n = new String[N];
        Integer[] ord = new Integer[N];
        for (int i = 0; i < N; i++) {
            ord[i] = i;
            p[i] = sc.nextInt();
            n[i] = sc.next();
        }
        li<String> list = new li();
        int sum = 0;
        Arrays.sort(ord, (i, j) -> {
            if (p[i] == p[j]) { return n[i].compareTo(n[j]); }
            return Integer.compare(p[i], p[j]);
        });
        Arrays.sort(ord, new Comparator<Integer>() {
            public int compare(Integer i, Integer j) {
                if (p[i] == p[j]) { return n[i].compareTo(n[j]); }
                return Integer.compare(p[i], p[j]);
            }
        });
        for (Integer i : ord) {
            if (sum + p[i] <= X) {
                sum += p[i];
                list.add(n[i]);
            }
        }
        
        /*O(N log N)
         * or
         * O(N^2) */
        list = new li();
        sum = 0;
        boolean[] done = new boolean[N];
        for (int i = 0; i < N; i++) {
            int minj = -1;
            for (int j = 0; j < N; j++) {
                if (done[j]) { continue; }
                if (minj == -1 || p[j] < p[minj]) { minj = j; }
            }
            done[minj] = true;
            if (sum + p[i] <= X) {
                list.add(n[minj]);
                sum += p[minj];
            }
        }

        System.out.println(list);
    }
    static class li<E> extends ArrayList<E> {}
    static class node {
        ArrayList<node> next;
        
    }
}
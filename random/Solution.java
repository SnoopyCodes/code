import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(new File("in.txt"));
        PrintWriter pw  = new PrintWriter(new File("out.txt"));
        int N = sc.nextInt();
        int M = sc.nextInt();
        HashMap<String, Integer> ind = new HashMap<>();
        String[] str = new String[N];
        for (int i = 0; i < N; i++) {
            str[i] = sc.next();
            ind.put(str[i], i);
        }
        for (int i = 0; i < M; i++) {
            int start = ind.get(sc.next());
            int end = ind.get(sc.next());
            int[] ways = new int[N];
            int[] dist = new int[N];
            for (int j = 0; j < N; j++) {
                dist[j] = 1000000000;
            }
            dist[start] = 1;
            ways[start] = 1;
            int[] queue = new int[N + 1];
            queue[0] = start;
            int s = 0, e = 1;
            while (e - s > 0) {
                int u = queue[s++];
                String us = str[u];
                for (int j = 0; j < us.length(); j++) {
                    for (int c = 0; c < 26; c++) {
                        String ns = us.substring(0, j) + (char) (c + 65) + us.substring(j + 1);
                        if (ind.get(ns) != null) {
                            int x = ind.get(ns);
                            if (dist[u] + 1 < dist[x]) {
                                dist[x] = dist[u] + 1;
                                queue[e] = x;
                                ways[x] = ways[u];
                                e++;
                            }   else if (dist[u] + 1 == dist[x]) {
                                ways[x] += ways[u];
                            }
                        }
                    }
                }
            }
            if (ways[end] == 0) {
                pw.println("Not Connected.");
            }   else {
                pw.println(dist[end] + " " + ways[end]);
            }
        }
        pw.close();
    }
}
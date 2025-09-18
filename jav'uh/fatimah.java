import java.io.*;
import java.util.*;
public class fatimah {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            var con = new TreeMap<String, HashSet<String>>();
            String[] names = new String[N];
            for (int i = 0; i < N; i++) {
                names[i] = sc.next();
                con.put(names[i], new HashSet<>());
            }
            for (int i = 0; i < M; i++) {
                String f = sc.next();
                String s = sc.next();
                con.get(f).add(s);
                con.get(s).add(f);
            }
            int ans = 0;
            for (int mask = 0; mask < 1 << N; mask++) {
                ArrayList<String> ar = new ArrayList<>();
                for (int b = 0; b < N; b++) {
                    if ((mask & 1 << b) != 0) {
                        ar.add(names[b]);
                    }
                }
                boolean valid = true;
                for (int i = 0; i < ar.size(); i++) {
                    for (int j = i + 1; j < ar.size(); j++) {
                        if (con.get(ar.get(i)).contains(ar.get(j))) {
                            valid = false;
                        }
                    }
                }
                if (valid) { ans = Math.max(ans, ar.size()); }
            }
            System.out.println("Case #" + (t + 1) + ": " + ans);
        }
    }
}
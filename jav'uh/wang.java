import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import static java.lang.Character.*;
// import static java.lang.Integer.*;
// import static java.lang.Double.*;
// import static java.lang.Long.*;

public class wang {
static class beep extends PrintWriter {
    Scanner sc = new Scanner(new File("wang.dat"));
    public beep() throws IOException {
        super("out.txt");
        int T = sc.nextInt();
        while (T --> 0) { solve(); }
    }
    void solve() {
        int N = sc.nextInt(), M = sc.nextInt();
        li<Integer>[] G = new li[N];
        String[] names = new String[N];
        TreeMap<String, Integer> to_int = new TreeMap<>();
        for (int i = 0; i < N; i++) {
            names[i] = sc.next();
            to_int.put(names[i], i);
            G[i] = new li<>();
        }
        while (M --> 0) {
            int u = to_int.get(sc.next());
            int v = to_int.get(sc.next());
            G[u].add(v);
        }

        int[] in = new int[N]; Arrays.fill(in, -1);
        int[] in_cc = new int[N]; Arrays.fill(in_cc, -1);
        var ccs = new li<li<Integer>>();
        var lambda = new Object() {
            int euler = 0, pt = 0, cc = 0;
            int[] path = new int[N];
            int dfs(int u) {
                int low = in[u] = euler++;
                path[pt++] = u;
                for (int v : G[u]) {
                    if (in[v] == -1) { low = min(low, dfs(v)); }
                    if (in_cc[v] == -1) { low = Math.min(low, in[v]); }
                }
                if (low != in[u]) { return low; }
                ccs.add(new li<>());
                while (in_cc[u] == -1) {
                    int v = path[--pt];
                    in_cc[v] = cc;
                    ccs.g(cc).add(v);
                }
                cc++;
                return low;
            }
        };
        for (int i = 0; i < N; i++) {
            if (in[i] == -1) { lambda.dfs(i); }
        }
        for (var cc : ccs) {
            Collections.sort(cc, (a, b) -> {
                return names[a].compareTo(names[b]);
            });
        }
        Collections.sort(ccs, (a, b) -> {
            return a.size() == b.size() ? names[a.g(0)].compareTo(names[b.g(0)])
                : b.size() - a.size();
        });
        for (int i = 0; i < ccs.size(); i++) {
            var cc = ccs.g(i);
            print("{");
            for (int j = 0; j < cc.size(); j++) {
                print(names[cc.g(j)] + (j == cc.size() - 1 ? "}" : ", "));
            }
            print(i == ccs.size() - 1 ? "\n" : ", ");
        }
    }

}
static class li<E> extends ArrayList<E> { E g(int i) { return get(i); } }

    public static void main(String[] args) throws IOException { new beep().close(); }
}

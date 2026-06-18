import java.util.*;
import java.io.*;
import java.util.function.*;
public class eulerian_un {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);

    gg() {
        super(System.out);
        int N = sc.nextInt();
        int M = sc.nextInt();
        li<Integer>[] G = new li[N];
        int deg[] = new int[N];
        for (int i = 0; i < N; i++) G[i] = new li();
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
            G[u].add(v);
            deg[u]++; deg[v]++;
            G[v].add(u);
        }
    }

    class li<E> extends ArrayList<E> {} //use 4 times to be worth b/c 32 chars & 11 to type ArrayList vs 2 for li
   
}

    public static void main(String[] args) { new gg().close(); }
static class Scanner extends StreamTokenizer {
    Scanner(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        resetSyntax();
        whitespaceChars(0, ' ');
        wordChars(' ' + 1, 255);
    }
    String next() { try { nextToken(); return sval; } catch(Exception e){ return null; } }
    int nextInt() { return Integer.parseInt(next()); }
    long nextLong() { return Long.parseLong(next()); }
}
}

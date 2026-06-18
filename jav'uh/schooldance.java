import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.util.function.*;
public class schooldance {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    
    

    void solve() {
        int N = sc.nextInt(), M = sc.nextInt(), K = sc.nextInt();
        int L = N + M;
        /*
        bipartite matching
        [1, N] is boys, [N + 1, L] is girls
        */

        int canmatch[][] = new int[L + 2][L + 2];
        int copy[][] = new int[L + 2][L + 2];
        for (int i = 1; i <= N; i++) {
            canmatch[0][i] = 1;
        }
        for (int i = N + 1; i <= L; i++) {
            canmatch[i][L + 1] = 1;
        }
        for (int i = 0; i < K; i++) {
            int u = sc.nextInt(), v = sc.nextInt() + N;
            canmatch[u][v] = 1;
            copy[u][v] = 1;
        }
        int iter = 0;

        while (true) {
            int[] par = new int[L + 2];
            Arrays.fill(par, -1);
            int[] q = new int[L + 2];
            int s = 0, e = 0;
            q[e++] = 0;
            par[0] = 0;
            while (s < e && par[L + 1] == -1) {
                int u = q[s++];
                for (int v = 0; v < L + 2; v++) {
                    if (par[v] == -1 && canmatch[u][v] > 0) {
                        q[e++] = v;
                        par[v] = u;
                    }
                }
            }
            if (par[L + 1] == -1) { break; }
            iter++;
            for (int u = L + 1; u != 0; u = par[u]) {
                canmatch[u][par[u]] += 1;
                canmatch[par[u]][u] -= 1;
            }
        }
        
        //nodes that cannot reach each other in the bfs but are connected originally
        //are matched.
        println(iter);
        for (int u = 1; u <= N; u++) {
            for (int v = N + 1; v <= L; v++) {
                if (copy[u][v] == 1 && canmatch[u][v] < 1) {
                    println(u + " " + (v - N));
                }
            }
        }
        
    }


    gg() {
        super(System.out);
        solve();
    }

    class li<E> extends ArrayList<E> {} //use 4 times to be worth b/c 32 chars & 11 to type ArrayList
   
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

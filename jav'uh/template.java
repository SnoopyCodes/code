import java.util.*;
import java.io.*;
import java.util.function.*;
public class template {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    
    void solve() {
    }


    gg() {
        super(System.out);
        // solve();
        var map = new DM<Integer, Integer>(() ->3);
        List<String> a = new li<>();
        Map<String, Integer> m = new HashMap<>();
        Function<String, Integer> ind = (s) -> {
            a.add(s);
            return a.size() - 1;
        };
        var z = m.computeIfAbsent("yo", ind);
        
    }

    class li<E> extends ArrayList<E> {} //use 4 times to be worth b/c 32 chars & 11 to type ArrayList vs 2 for li
   
    class DM<K,V> extends TreeMap<K,V>{
        Supplier<V> f;
        DM(Supplier<V> ff) { f = ff; }
        V val(K k){
            return computeIfAbsent(k, (a)->(f.get()));
        }
    } //120 chars? more with imports... 
    /*
    convenient class to map integer to thing and thing to Integer
    class must be comparable.
    e.g. for a graph of strings
    while (M -- > 0) {
        int u = map.ind(sc.next()), v = map.ind(sc.next());
        G[u].add(v) //do normal graph stuff
    }
    */
    <T> int ind(T k, Map<T, Integer> m, List<T> a) {
        return m.computeIfAbsent(k, (x) -> {
            a.add(x);
            return a.size() - 1;
        });
    }
   
    /*
    compared with
    li<Integer> G[] = new li[N];
    for (int i = 0; i < N; i++) G[i] = new li<>();
    while (M --> 0) {
        int u, v;
        
    }
    */
    class graph<T> {
        Map<T, Integer> h = new HashMap<>();
        li<Integer> nxt;
        li<T> e;
        void adde(T u, T v) {
            nxt.add(h.get(u));
            h.put(u, e.size());
            e.add(v);
        }
    } //for (var i = g.h.get(u); i != null; i = g.nxt.get(i)) { T v = e.get(i); }

    interface ff<T> { T op(T a, T b); } //same as BiFunction<T, T, T>
    record SegTree<T>(int n, T[] t, T d, ff<T> f) {
        void set(int i, T x) { for (t[i+=n] = x;i > 1; i >>= 1) t[i>>1] = f.op(t[i], t[i^1]); }
        T query(int l, int r) {
            T resl = d, resr = d;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) > 0) { resl = f.op(resl, t[l++]); }
                if ((r & 1) > 0) { resr = f.op(t[--r], resr); }
            }
            return f.op(resl, resr);
        }
    }
    
}

    public static void main(String[] args) { new gg().close(); }
// static class Scanner extends StreamTokenizer {
//     Scanner(InputStream in) {
//         super(new BufferedReader(new InputStreamReader(in)));
//         resetSyntax();
//         whitespaceChars(0, ' ');
//         wordChars(' ' + 1, 255);
//     }
//     String next() { try { nextToken(); return sval; } catch(Exception e){ return null; } }
//     int nextInt() { return Integer.parseInt(next()); }
//     long nextLong() { return Long.parseLong(next()); }
// }
}

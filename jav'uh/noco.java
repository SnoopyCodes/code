import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.util.function.*;
public class noco {

static class gg extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    
    void solve() {
        int[] IN = intarr(sc.nextLine());
        int N = IN[0], M = IN[1], A = IN[2], B = IN[3], C = IN[4];
        char[] a = sc.next().toCharArray();
        char[] b = sc.next().toCharArray();

    }
    String[] line(String spl) { return sc.nextLine().split(spl); }
    int[] intarr(String spl) { return Arrays.stream(line(spl)).mapToInt(Integer::parseInt).toArray(); }


    gg() {
        super(System.out);
        // solve();
    }

    class li<E> extends ArrayList<E> {} //use 4 times to be worth b/c 32 chars & 11 to type ArrayList vs 2 for li
   
    
    class DM<K,V> extends TreeMap<K,V>{ //basically just does computeIfAbsent(function) for a dict.
        Function<K, V> f;
        DM(Function<K, V> ff) { f = ff; }
        V q(K k){
            return computeIfAbsent(k, (a)->(f.apply(k)));
        }
    }
   
    record SegTree<T>(int n, T[] t, T d, BinaryOperator<T> f) {
        void set(int i, T x) { for (t[i+=n] = x;i > 1; i >>= 1) t[i>>1] = f.apply(t[i], t[i^1]); }
        T query(int l, int r) {
            T resl = d, resr = d;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) > 0) { resl = f.apply(resl, t[l++]); }
                if ((r & 1) > 0) { resr = f.apply(t[--r], resr); }
            }
            return f.apply(resl, resr);
        }
    }
}

    public static void main(String[] args) { new gg().close(); }
}

import java.util.*;
import java.io.*;
public class aoc5 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        long[][] ranges = new long[0][];
        int N = 0;
        while (true) {
            String ln = sc.nextLine();
            if (ln.equals("")) { break; }
            int b = ln.indexOf("-");
            ranges = append(ranges, new long[] {
                Long.parseLong(ln.substring(0, b)),
                Long.parseLong(ln.substring(b + 1))
            }, N++);
        }

        ranges = Arrays.copyOf(ranges, N);
        Arrays.sort(ranges, (a, b) -> Long.compare(a[0], b[0]));
        long curl = ranges[0][0], curr = ranges[0][1];
        long ans = 0;
        for (int i = 1; i < N; i++) {
            long l = ranges[i][0];
            long r = ranges[i][1];
            if (curr < l - 1) {
                ans += curr - curl + 1;
                curl = l;
                curr = r;
            }   else {
                curr = Math.max(curr, r);
            }
        }
        ans += curr - curl + 1;
        System.out.println(ans);


    }
    static <T> T[] append(T[] a, T e, int sz) {
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * sz + 1); }
        a[sz] = e;
        return a;
    }

}

class e {
    void set() {}
}
class f extends e {
    void set() {}
}

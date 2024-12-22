import java.util.*;
import java.io.*;

public class p14 {
    static long res;
    static int[] vals;
    static boolean bruh(long cur, int step) {
        if (step == vals.length) { return cur == res; }
        int v = 1;
        while (v <= vals[step]) { v *= 10; }
        return bruh(cur + vals[step], step + 1) | bruh(cur * vals[step], step + 1)
        | bruh(cur * v + vals[step], step + 1);
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        long ans = 0;
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            res = Long.parseLong(line.substring(0, line.indexOf(':')));
            String[] svals = line.substring(line.indexOf(':') + 2).split(" ");
            vals = new int[svals.length];
            for (int i = 0; i < svals.length; i++) {
                vals[i] = Integer.parseInt(svals[i]);
            }
            //how do you actually check for overflow?
            //if the things are like less is that good or bad
            if (bruh(vals[0], 1)) { ans += res; }
        }
        System.out.println(ans);
        sc.close();
    }
}
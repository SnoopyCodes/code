import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class aoc9 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        int[][] pts = new int[0][];
        int N = 0;
        /*
        we can find rectangles which, if intersected with, indicate 
        that it overlaps outside stuff
        */
        while (sc.hasNextLine()) {
            String ln = sc.nextLine();
            int b = ln.indexOf(",");
            pts = append(pts, new int[] {
                Integer.parseInt(ln.substring(0, b)),
                Integer.parseInt(ln.substring(b + 1))
            }, N++);
        }
        pts = Arrays.copyOf(pts, N);
        
        long ans = 0;
        
        
        System.out.println(ans);
    }
    static <T> T[] append(T[] a, T e, int sz) {
        if (sz == a.length) { a = Arrays.copyOf(a, 2 * sz + 1); }
        a[sz] = e;
        return a;
    }

}
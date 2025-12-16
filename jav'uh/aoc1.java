import java.util.*;
import java.io.*;
public class aoc1 {
    public static void main(String[] args) throws IOException {
        int cur = 50;
        Scanner sc = new Scanner(new File("in.txt"));
        int count = 0;
        while (sc.hasNext()) {
            String s = sc.next();
            int d = Integer.parseInt(s.substring(1));
            if (s.charAt(0) == 'L') {
                d = -d;
                if (cur == 0) { cur = 100; } //edge case
            }
            count += Math.abs(d / 100);
            d %= 100;
            
            int after = (cur + d + 100) % 100;
            //after == 0 is an edge case
            if (s.charAt(0) == 'L' && after > cur || after == 0) { count++; }
            else if (s.charAt(0) == 'R' && after < cur) { count++; }
            cur = after;
        }
        System.out.println(count);
    }
}

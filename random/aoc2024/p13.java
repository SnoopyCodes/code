import java.util.*;
import java.io.*;

public class p13 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        long ans = 0;
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            long res = Long.parseLong(line.substring(0, line.indexOf(':')));
            String[] svals = line.substring(line.indexOf(':') + 2).split(" ");
            int[] vals = new int[svals.length];
            for (int i = 0; i < svals.length; i++) {
                vals[i] = Integer.parseInt(svals[i]);
            }
            boolean valid = false;
            for (int mask = 0; mask < 1 << vals.length - 1; mask++) {
                long cur = vals[0];
                for (int i = 1; i < vals.length; i++) {
                    if ((mask & 1 << i - 1) != 0) {
                        cur *= vals[i];
                    }   else {
                        cur += vals[i];
                    }
                }
                if (cur == res) { valid = true; break; }
            }
            if (valid) { ans += res; }
        }
        System.out.println(ans);
        sc.close();
    }
}
import java.util.*;
import java.io.*;

public class aoc2 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        String[] ranges = sc.nextLine().split(",");
        long ans = 0;
        for (String range : ranges) {
            String[] splits = range.split("-");
            for (long i = Long.parseLong(splits[0]); i < Long.parseLong(splits[1]); i++) {
                String istr = Long.toString(i);
                for (int pref_len = 1; pref_len <= istr.length() / 2; pref_len++) {
                    if (istr.length() % pref_len != 0) { continue; }
                    int amt = istr.length() / pref_len;
                    String comp = "";
                    while (amt --> 0) {
                        comp += istr.substring(0, pref_len);
                    }
                    if (istr.equals(comp)) {
                        ans += i;
                        break;
                    }
                }
            }
        }
        System.out.println(ans);

    }
}

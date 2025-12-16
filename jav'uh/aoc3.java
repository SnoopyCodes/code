import java.util.*;
import java.io.*;

public class aoc3 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        long ans = 0;
        while (sc.hasNextLine()) {
            String s = sc.nextLine();
            int best = 0;
            for (int i = 0; i < s.length() - 1; i++) { //tens digit
                int tens_digit = s.charAt(i) - '0';
                for (int j = i + 1; j < s.length(); j++) { //units digit
                    int units_digit = s.charAt(j) - '0';
                    best = Math.max(tens_digit * 10 + units_digit, best);
                }
            }
            ans += best;
        }
        System.out.println(ans);
    }
}

import java.util.*;
import java.io.*;
public class secplay {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        int T = sc.nextInt();
        sc.nextLine();
        while (T --> 0) { solve(); }
    }
    void solve() {
        String S = sc.nextLine();
        String ans = "";
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (!(65 <= c && c < 65 + 26 || 97 <= c && c < 97 + 26)) {
                ans += c;
                continue;
            }
            boolean up = c < 65 + 26;
            if (up) {
                c -= 65;
                c = (char) (25 - c);
                c += 97;
            }   else {
                c -= 97;
                c = (char) (25 - c);
                c += 65;
            }
            ans += c;
        }
        println(ans);
    }
}

    public static void main(String[] args) { new beep().close(); }

}

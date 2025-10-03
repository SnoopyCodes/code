import java.util.*;
import java.io.*;
public class runfield {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        int T = sc.nextInt();
        while (T --> 0) { solve(); }
    }
    int cost(int[] str, char[] line, int pt, int pos) {
        if (line[pos] == '.') { return 1; }
        else {
            return str[pt];
        }
    }
    void solve() {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        var line = sc.next().toCharArray();
        int[] str = new int[M];
        for (int i = 0; i < M; i++) {
            str[i] = sc.nextInt();
        }
        int pt = M - 1;
        int ans = N;
        int pos = N - 1;
        while (pos >= 0 && cost(str, line, pt, pos) <= X) {
            X -= cost(str, line, pt, pos);
            ans--;
            if (line[pos] != '.') { pt--; }
            pos--;
        }
        println(ans);
    }
}

    public static void main(String[] args) { new beep().close(); }

}

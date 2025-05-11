// package jav'uh;
import java.util.*;
import java.io.*;
public class exponent {
    static final int MOD = (int) (1e9 + 7);
    static long pow(long x, int p) {
        long res = 1;
        while (p > 0) {
            if (p % 2 == 1) { res = res * x % MOD; }
            p /= 2;
            x = x * x % MOD;
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            System.out.println(pow(sc.nextInt(), sc.nextInt()));
        }
    }
}

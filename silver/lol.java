import java.util.*;
import java.io.*;

public class lol {
    static void solve(int M, int K) {
        int[] multiply = new int[32];
        int x = 0;
        for (int b = 0; b < 32; b++) {
            if ((M & 1 << b) > 0) {
                multiply[b]++;
                x++;
            }
        }
        //i don't remember what i'm doing
        if (x > K) {
            for (int b = 1; b < 32 && x > K; b++) {
                if ((M & 1 << b) > 0) {
                    x--;
                    multiply[b]--;
                    multiply[b-1] += 2;
                }
            }
        }   else if (x < K) {
            int last = 0; //last bit
            int mx = 0;
            for (int b = 1; b < 32 && x < K; b++) {
                if ((M & 1 << b) > 0) {
                    mx = b;
                    //how many can we flip? 
                    //1 0 1 becomes 0 1 3. 
                    int d = b - last - 1;
                    if (d > 0) {
                        multiply[b]--;
                        x--;
                        int c = b - 1;
                        while (c > last && x < K) {
                            x++;
                            multiply[c]++;
                            c--;
                        }
                        multiply[c] += 2;
                        last = b - 1;
                    }   else {
                        last = b;
                    }
                }
            }
            if (mx < K) {
                System.out.println(-1);
                return;
            }
        }
        //i think the maximum is literally 3
        System.out.println(3);
        for (int i = 0; i < 3; i++) {
            int res = 0;
            for (int b = 0; b < 32; b++) {
                if (multiply[b] > 0) {
                    multiply[b]--;
                    res += 1 << b;
                }
            }
            System.out.print(res + (i < 3 ? " " : "\n"));
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int M = sc.nextInt();
            int K = sc.nextInt();
            solve(M, K);
        }
        sc.close();
    }
}

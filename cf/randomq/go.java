// package cf.randomq;
import java.util.*;
public class go {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), M = sc.nextInt() - 1, sum = 0;
        sc.nextLine();
        while (M --> 0) sum += sc.nextLine().split(" ").length;
        System.out.println(sum);
    }
}

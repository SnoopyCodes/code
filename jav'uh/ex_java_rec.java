import java.util.*;
import java.io.*;

public class ex_java_rec {
    static record item(int p, String n) {}
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), X = sc.nextInt();
        item[] shop = new item[N];
        for (int i = 0; i < N; i++) {
            shop[i] = new item(sc.nextInt(), sc.next());
        }
        li<String> list = new li();
        int sum = 0;
        Arrays.sort(shop, (a, b) -> {
            return a.p == b.p ? a.n.compareTo(b.n) : a.p - b.p;
        });
        for (item i : shop) {
            if (sum + i.p <= X) {
                sum += i.p;
                list.add(i.n);
            }
        }
        System.out.println(list);
    }
    static class li<E> extends ArrayList<E> {}
}
import java.util.*;
import java.io.*;

public class ex_java_comp {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), X = sc.nextInt();
        Item[] shop = new Item[N];
        for (int i = 0; i < N; i++) {
            shop[i] = new Item(sc.nextInt(), sc.next());
        }
        Arrays.sort(shop);
        li<Item> list = new li();
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (sum + shop[i].price <= X) {
                list.add(shop[i]);
                sum += shop[i].price;
            }
        }
        System.out.println(list.toString());
    }
    static class li<E> extends ArrayList<E> {}
    static class Item implements Comparable<Item> { //interface. include Item in <>
        int price;
        String name;
        public Item(int p, String n) { price = p; name = n; }
        public int compareTo(Item i) { //must return integer
            //built in compareTo and Double.compare methods return integers.
            if (price == i.price) { return name.compareTo(i.name); }
            return Double.compare(price, i.price);
        }
        public String toString() {
            return name;
        }
    }
}
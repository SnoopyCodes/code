import java.io.*;
import java.util.*;

public class p3 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        int cnt = 0;
        while (sc.hasNextLine()) {
            String[] line = sc.nextLine().split(" ");
            ArrayList<Integer> list = new ArrayList<>();
            for (String s : line) {
                list.add(Integer.parseInt(s));
            }
            int prev = 0;
            boolean valid = true;
            for (int i = 0; i < list.size() - 1; i++) {
                int diff = list.get(i + 1) - list.get(i);
                if (prev * diff < 0) { valid = false; }
                prev = diff;
                diff = Math.abs(diff);
                if (diff < 1 || diff > 3) { valid = false; }
            }
            if (valid) { cnt++; }
        }
        System.err.println(cnt);
        sc.close();
    }
}

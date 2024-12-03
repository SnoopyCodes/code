import java.io.*;
import java.util.*;

public class p4 {
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("in.txt"));
        int cnt = 0;
        while (sc.hasNextLine()) {
            String[] line = sc.nextLine().split(" ");
            ArrayList<Integer> list = new ArrayList<>();
            for (String s : line) {
                list.add(Integer.parseInt(s));
            }
            boolean reallyvalid = false;
            for (int i = 0; i < list.size(); i++) {
                int rem = list.get(i);
                list.remove(i);
                int prev = 0;
                boolean valid = true;
                for (int j = 0; j < list.size() - 1; j++) {
                    int diff = list.get(j + 1) - list.get(j);
                    if (prev * diff < 0) { valid = false; }
                    prev = diff;
                    diff = Math.abs(diff);
                    if (diff < 1 || diff > 3) { valid = false; }
                }
                reallyvalid |= valid;
                list.add(i, rem);
            }
            if (reallyvalid) { cnt++; }
        }
        System.err.println(cnt);
        sc.close();
    }
}

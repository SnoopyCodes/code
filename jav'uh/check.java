import java.util.*;
import java.io.*;

public class check {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("out.txt"));
        Scanner ac = new Scanner(new File("ans.txt"));
        ArrayList<String> out_list = new ArrayList<>();
        ArrayList<String> ans_list = new ArrayList<>();
        while (sc.hasNext()) {
            out_list.add(sc.next());
        }
        while (ac.hasNext()) {
            ans_list.add(ac.next());
        }
        System.out.println(out_list.equals(ans_list));
    }
}

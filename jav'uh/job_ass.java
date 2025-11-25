import java.util.*;
import java.io.*;
public class job_ass {

static class beep extends PrintWriter {
    Scanner sc = new Scanner(System.in);
    public beep() {
        super(System.out);
        solve();
    }
    void solve() {
        int N = sc.nextInt(),
            M = sc.nextInt();
        String jobs[] = new String[M];
        Map<String, Integer> to_int = new TreeMap<>();
        for (int i = 0; i < M; i++) {
            jobs[i] = sc.next();
            to_int.put(jobs[i], i);
        }
        sc.nextLine();
        String fn[] = new String[N];
        String ln[] = new String[N];
        int yay[] = new int[N];
        int can[][] = new int[N][];
        Integer ord[] = new Integer[N];
        for (int i = 0; i < N; i++) {
            String line = sc.nextLine();
            String name[] = line.substring(0, line.indexOf(", ")).split(" ");
            String job_list[] = line.substring(line.indexOf("Jobs: ") + 6).split(", ");
            int score = (int) (100 * Double.parseDouble(line.split(", ")[1]) - 50);
            ord[i] = i;
            fn[i] = name[0];
            ln[i] = name[1];
            yay[i] = score;
            can[i] = new int[job_list.length];
            for (int j = 0; j < job_list.length; j++) {
                can[i][j] = to_int.get(job_list[j]);
            }
        }
        Arrays.sort(ord, (i, j) -> {
            return !fn[i].equals(fn[j]) ? fn[i].compareTo(fn[j])
                : ln[i].compareTo(ln[j]);
        });

    }
}

    public static void main(String[] args) { new beep().close(); }
}

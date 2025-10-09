import java.io.*;
import java.util.*;
 
public class tst {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(r.readLine());
        StringTokenizer st = new StringTokenizer(r.readLine());
        int[] nsv = new int[n];
        int[] vals = new int[n];
        
        for (int i = 0; i < n; i++) {
            vals[i] = Integer.parseInt(st.nextToken());
            int j = i - 1;
            while (j > -1 && vals[j] >= vals[i]) { j = nsv[j]; }
            nsv[i] = j;
        }

        StringBuilder sb = new StringBuilder();
        for(int e : nsv){
            sb.append(e+1).append(' ');
        }
        System.out.print(sb.toString());
    }
}

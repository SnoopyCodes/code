//### Sum of imbalance numbers

import java.io.*;
import java.util.*;
import static java.lang.Math.*;
public class imbalance {
	public static void main(String[] args) throws Exception {
		// BufferedReader br = new BufferedReader(new FileReader(("in.txt")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] A = new int[n];
		for(int j=0; j<n; j++)
			A[j] = Integer.parseInt(st.nextToken());
		
		System.out.println(sumImbalanceNumbers(A));
		br.close();
	}
	
	static long sumImbalanceNumbers(int[] A) {
	    long res = 0;
	    int n = A.length;

	    //left[i]: the most recent location of A[i] or A[i]+1 before i
	    int[] left = new int[n];

	    //seen[v]: the most recent location of v (in A from left to right)
	    int[] seen = new int[n+2];
	    Arrays.fill(seen, -1);
	    for(int i=0; i<n; i++) {
	        left[i] = max(seen[A[i]+1], seen[A[i]]);
	        seen[A[i]] = i;
	    }

	    //seen[v]: the most recent location of v (in A from right to left)
	    Arrays.fill(seen, n);
	    for(int i=n-1; i>=0; i--) {
	        res += (long)(i-left[i]) * (min(seen[A[i]], seen[A[i]+1]) - i);
	        seen[A[i]] = i;
	    }
	    return (res - n*(n+1L)/2) % (1_000_000_007);
	}
}

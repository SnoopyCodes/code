import java.util.*;
import java.io.*;
public class Prateek {
static int[] group, size;
static int ans = 0;
    public static void main(String[] args) throws FileNotFoundException {
        // TODO Auto-generated method stub
        Scanner kb = new Scanner(new File("prateek.dat"));
    	//Scanner kb = new Scanner(System.in);
        int testc = kb.nextInt();
        for(int i = 1; i<=testc; i++) {
            int n = kb.nextInt();
            int a = kb.nextInt();
            int b = kb.nextInt();
            int d = kb.nextInt();
            ans = 0;
            String[] grid = new String[n];
            group = new int[n]; size = new int[n];
            for(int j = 0; j<n; j++) {group[j] = j; size[j] = 1;}
            ArrayList<int[]> ord = new ArrayList<>();
            for(int j = 0; j<n; j++) {
            	grid[j] = kb.next();
            }
            int term = (a-b)/d;
            for(int j = 0; j<n; j++) {
                for(int k = j+1; k<n; k++) {
                	int fin = compute_Levenshtein_distanceDP(grid[k], grid[j]);
                	if(fin>term)continue;
                	ord.add(new int[] {fin,j,k});
                }
            }
            Collections.sort(ord, new Comparator<int[]>() {

				@Override
				public int compare(int[] o1, int[] o2) {
					// TODO Auto-generated method stub
					return Integer.compare(o1[0], o2[0]);
				}
            	
            });
            for(int[] arr: ord) {
            	int i1 = root(arr[1]); int i2 = root(arr[2]);
            	if(i1==i2) continue;
            	ans+=(b+arr[0]*d);
            	merge(i1, i2);
            }
            HashSet<Integer> inc = new HashSet<>();
            for(int j = 0; j<n; j++) {
            	int val = root(j);
            	if(!inc.contains(val)) {
            		inc.add(val); ans+=a;
            	}
            }
            System.out.println(ans);
        }
    }
    public static void merge(int a, int b) {
    	if(size[a]<size[b]) {
    		int temp = a; a = b; b = temp;
    	}
    	group[b] = a;
    	size[a]+=size[b];
    }
    public static int root(int a) {
    	return a==group[a]? a: root(group[a]);
    }
    static int compute_Levenshtein_distanceDP(String str1,
            String str2)
{

// A 2-D matrix to store previously calculated
// answers of subproblems in order
// to obtain the final

int[][] dp = new int[str1.length() + 1][str2.length() + 1];

for (int i = 0; i <= str1.length(); i++) 
{
for (int j = 0; j <= str2.length(); j++) {

// If str1 is empty, all characters of
// str2 are inserted into str1, which is of
// the only possible method of conversion
// with minimum operations.
if (i == 0) {
dp[i][j] = j;
}

// If str2 is empty, all characters of str1
// are removed, which is the only possible
//  method of conversion with minimum
//  operations.
else if (j == 0) {
dp[i][j] = i;
}

else {
// find the minimum among three
// operations below


dp[i][j] = minm_edits(dp[i - 1][j - 1]
+ NumOfReplacement(str1.charAt(i - 1),str2.charAt(j - 1)), // replace
dp[i - 1][j] + 1, // delete
dp[i][j - 1] + 1); // insert
}
}
}

return dp[str1.length()][str2.length()];
}

// check for distinct characters
// in str1 and str2

static int NumOfReplacement(char c1, char c2)
{
return c1 == c2 ? 0 : 1;
}

// receives the count of different
// operations performed and returns the
// minimum value among them.

static int minm_edits(int... nums)
{

return Arrays.stream(nums).min().orElse(
Integer.MAX_VALUE);
}
}
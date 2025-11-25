import java.util.*;

public class sorts {

    private final static int SIZE = 3;
    private final static int MAX = 20;

    public void itWorksRepeatably() {
        for (int i = 0; i < 1; i++) {
            A = new int[SIZE];
            tmp = new int[SIZE];
            Random generator = new Random();
            for (int a = 0; a < A.length; a++) {
                A[a] = generator.nextInt(MAX);
            }
            System.out.println(Arrays.toString(A));
            mergesort(0, SIZE);
            System.out.println(Arrays.toString(A));
            for (int j = 0; j < A.length - 1; j++) {
                if (A[j] > A[j + 1]) {
                    System.out.println("Should not happen");
                }
            }
        }
    }
    public static void main(String[] args) {
        new sorts().itWorksRepeatably();
    }
    int A[], tmp[];
    void mergesort(int l, int r) {
        if (l + 1 == r) { return; }
        int m = (l + r) >>> 1;
        mergesort(l, m);
        mergesort(m, r);
        int ll = l, rr = m;
        for (int i = l; i < r; i++) {
            tmp[i] = rr == r || ll < m && A[ll] < A[rr] ? A[ll++] : A[rr++];
        }
        for (int i = l; i < r; i++) {
            A[i] = tmp[i];
        }
    }
}


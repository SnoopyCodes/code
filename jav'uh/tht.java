import java.util.*;
import java.io.*;
import java.math.*;
public class tht {
    static class BI extends BigInteger {
        public BI(long a) { super(((Long) a).toString()); }
    }

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(new File("thehumantrapezoid.in"));
        
        long T = sc.nextLong();
        while (T --> 0) {

        BI Y = new BI(sc.nextLong());
        BI X = new BI(sc.nextLong());
        BI N = new BI(sc.nextLong());
        BigInteger need = (Y.subtract(X).abs().add(BI.ONE)).multiply(Y.add(X)).divide(BI.ONE.add(BI.ONE)).subtract(N);
        if (need.compareTo(BI.ZERO) < 0) { need = BI.ZERO; }
        System.out.println(need);

        }
    }
}

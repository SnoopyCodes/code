public class test {
    public static void main(String[] args) {
        int u = 5, v = 6;
        u ^= v ^= u;
        //v xors like expected
        //
        System.out.println(u + " " + v);
    }
}
